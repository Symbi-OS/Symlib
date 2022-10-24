#include <stdio.h>
#include <stdlib.h>
#include "LINF/init.h"
#include "L2/init.h"
#include "LIDK/idk.h"

void sym_lib_init(){
  // Init kall sym lib
  /* printf("Manual Init symlib NYI\n"); */

  return;
  // Init inner layers. Must be done after kallsym_lib

  // Init L2
  sym_l2_init();

  // Discover CR3
  printf("Discover cr3 NYI\n");
  // Discover IDTR
  printf("Discover idtr NYI\n");

}
