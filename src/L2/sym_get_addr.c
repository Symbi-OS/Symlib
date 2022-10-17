#include "L2/sym_get_addr.h"
#include "L2/sym_lib_page_fault.h"
#include "L2/sym_probe.h"

void* get_mitigation_addr(const char* symbol) {
  if (strcmp(symbol, "df_jmp_to_c") == 0) {
    return &df_jmp_to_c;
  }
  if (strcmp(symbol, "tf_jmp_to_c") == 0) {
    return &tf_jmp_to_c;
  }
  if (strcmp(symbol, "int3_jmp_to_c") == 0) {
    return &int3_jmp_to_c;
  }
  if (strcmp(symbol, "db_jmp_to_c") == 0) {
    return &db_jmp_to_c;
  }
  return (void*)0;
}

