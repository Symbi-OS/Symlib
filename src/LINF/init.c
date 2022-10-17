#include <stdio.h>
#include <stdlib.h>
#include "LINF/init.h"
#include "L2/init.h"
#include "LIDK/idk.h"

void sym_lib_init(){
  // Init kall sym lib
  /* printf("Manual Init symlib NYI\n"); */

  // HACK XXX
  char *path = "/boot/System.map-5.14.0-symbiote+";
  if (path) {
    // alternative path specified for kallsyms file
    // manually initialize library with this path
    if (!kallsymlib_init(path)) {
      fprintf(stderr, "ERROR: kallsymlib failed to initialize\n");
      fprintf(stderr, "Remember System map should be in /boot \n");
      exit(-1);
    }
  }

  return;
  // Init inner layers. Must be done after kallsym_lib

  // Init L2
  sym_l2_init();

  // Discover CR3
  printf("Discover cr3 NYI\n");
  // Discover IDTR
  printf("Discover idtr NYI\n");

}