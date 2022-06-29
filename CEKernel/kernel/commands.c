#include "../cpu/idt.h"
#include "../cpu/isr.h"
#include "../cpu/timer.h"
#include "../drivers/display.h"
#include "../drivers/keyboard.h"

#include "util.h"
#include "mem.h"




void CMD__EXIT(){
    print_string("halting the CPU. Doei :(\n");
    asm volatile("hlt");
}

void CMD__CLEAR(){
    clear_screen();
    
}

void CMD__HELP() {
    print_string("\n ====================CE-Kernel====================");
    print_nl();
    print_string("EXIT : halts the CPU\nCLEAR : Clears the display\nVER : Displays the current version of CE-Kernel\nHELP : Showns this Menu\nECHO: Returns string you input");
    print_nl();
    print_string("\n =================================================");
}

void CMD_VER(){
    print_string("ver_22.06.25 \n");
}




// ECHO
void CMD_ECHO(){
    print_string("TYPE TO ECHO> ");
    init_keyboard_echo();
    
}
void execute_command_echo(char *input) {
   
    print_string(input);
    __EXIT_ECHO();

    
    
}
void __EXIT_ECHO(){
    print_string("\n ECHO DONE\n >");
    init_keyboard();
}

// ECHO