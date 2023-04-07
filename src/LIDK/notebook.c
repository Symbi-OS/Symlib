// This is a place to put helper code for the notebooks
// used to document and communicate our results.
// The hope is this will help us hack through
// explanations quickly, and can later be separated
// nicely into the library.

#include "L0/sym_lib.h"
#include "L1/sym_interrupts.h"
#include <stdio.h>

// void sym_print_idt_entry_raw(unsigned char *idt_base, int index) {
void sym_print_active_idt_entry_raw(int index) {
    // Copy raw bytes
    struct dtr idtr;
    sym_store_idt_desc(&idtr);
    printf("idtr limit: %#x \n", idtr.limit);
    printf("idtr base : %#lx \n", idtr.base);

    unsigned char idt_entry[16];

    // memcpy from base + index * 16
    sym_memcpy(idt_entry, (void *)(idtr.base + index * 16), 16);
    
    // Print raw bytes as two 64 bit ints
    fprintf(stderr, "idt_entry[%d] = %#lx %#lx\n", index, *(uint64_t *)idt_entry, *(uint64_t *)(idt_entry + 8));

}