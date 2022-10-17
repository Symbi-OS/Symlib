#ifndef __SYM_LIB_GET_ADDR__
#define __SYM_LIB_GET_ADDR__

#include <string.h>

// Get address of a mitigation jump function dynamically within Symlib
// (tf_jmp_to_c, df_jmp_to_c, etc.)
extern void* get_mitigation_addr(const char* symbol);

#endif

