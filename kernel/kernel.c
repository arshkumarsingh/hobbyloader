#include "kernel.h"
#include "idt.h"

void kernel_main() {
    init_idt();
    char* video_memory = (char*) 0xB8000;
    video_memory[0] = 'K';
    video_memory[1] = 0x07;
    video_memory[2] = 'e';
    video_memory[3] = 0x07;
    video_memory[4] = 'r';
    video_memory[5] = 0x07;
    video_memory[6] = 'n';
    video_memory[7] = 0x07;
    video_memory[8] = 'e';
    video_memory[9] = 0x07;
    video_memory[10] = 'l';
    video_memory[11] = 0x07;
}

void _start() {
    kernel_main();
    while (1) {}
}
