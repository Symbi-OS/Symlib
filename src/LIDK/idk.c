#include <stdio.h>
#include "LIDK/idk.h"
#include <stdint.h>
#include <string.h>

#include "L2/sym_lib_page_fault.h"
#include "L2/sym_probe.h"

typedef unsigned long (*kallsyms_lookup_name_t)(const char *name);
static kallsyms_lookup_name_t kallsyms_lookup_name = NULL;

void parse_system_map() {
	const char* system_map_path = "/boot/System.map-5.14.0-symbiote+";

	unsigned long long addr;
	char type;
	char symbol[128];

	FILE* fp = fopen(system_map_path, "r");
	if (fp == NULL) {
		perror(system_map_path);
		return;
	}

	int n;
	while ((n = fscanf(fp, "%llx %c %s", &addr, &type, symbol)) != EOF) {
		if (strcmp(symbol, "kallsyms_lookup_name") == 0) {
			kallsyms_lookup_name = (kallsyms_lookup_name_t)addr;
			break;
		}
	}

	fclose(fp);
}

void* sym_get_fn_address(char *symbol) {
  // Initialization step: parse system map to get
  // the address of the kallsyms_lookup_name routine.
  if (kallsyms_lookup_name == NULL) {
	parse_system_map();
  }

  // Elevate to be able to call kallsyms_lookup_name
  sym_elevate();

  void* result = (void*)kallsyms_lookup_name(symbol);

  // Don't forget to lower
  sym_lower();

  return (void*)result;
}

void sym_l2_init(){
  printf("sym_l2_init\n");
  sym_lib_page_fault_init();
  sym_probe_init();
}
