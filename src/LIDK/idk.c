#include <stdio.h>
#include "LIDK/idk.h"
#include <stdint.h>

#include "L2/sym_lib_page_fault.h"
#include "L2/sym_probe.h"

void* sym_get_fn_address(char *symbol){
  // Elevate to be able to call kallsyms_lookup_name
  sym_elevate();  

  struct kallsymlib_info info;

  if (!kallsymlib_lookup(symbol, &info)) {
    fprintf(stderr, "%s : not found\n", symbol);
    while(1);
  }

  // Don't forget to lower
  sym_lower();

  return (void*)info.addr;
}

void sym_l2_init(){
  printf("sym_l2_init\n");
  sym_lib_page_fault_init();
  sym_probe_init();
}
