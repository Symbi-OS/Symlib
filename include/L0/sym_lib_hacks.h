#ifndef __SYM_LIB_HACKS__
#define __SYM_LIB_HACKS__
// License C 2021-
// Author: Thomas Unger
// Level: 0

// Hacks to run when lowered to prep for elevated execution.

#ifdef __GNUC__
#define VARIABLE_IS_NOT_USED __attribute__ ((unused))
#else
#define VARIABLE_IS_NOT_USED
#endif

// Touch all text pages in executable to prefault.
void sym_touch_every_page_text();

// Touch some stack pages to prefault
extern void sym_touch_stack();

#endif
