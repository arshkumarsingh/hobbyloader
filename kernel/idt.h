#ifndef IDT_H
#define IDT_H

struct idt_entry {
    unsigned short base_low;
    unsigned short sel;
    unsigned char always0;
    unsigned char flags;
    unsigned short base_high;
} __attribute__((packed));

struct idt_ptr {
    unsigned short limit;
    unsigned int base;
} __attribute__((packed));

void init_idt();
void load_idt(unsigned int idt_ptr);
void memset(void* ptr, unsigned char value, unsigned int num);

#endif
