#include "idt.h"

struct idt_entry idt[256];
struct idt_ptr idtp;

void init_idt() {
    idtp.limit = (sizeof(struct idt_entry) * 256) - 1;
    idtp.base = (unsigned int) &idt;

    memset(&idt, 0, sizeof(struct idt_entry) * 256);

    load_idt((unsigned int) &idtp);
}

void load_idt(unsigned int idt_ptr) {
    __asm__ __volatile__ ("lidt (%0)" : : "r"(idt_ptr));
}

void memset(void* ptr, unsigned char value, unsigned int num) {
    unsigned char* p = (unsigned char*) ptr;
    for (unsigned int i = 0; i < num; i++) {
        p[i] = value;
    }
}
