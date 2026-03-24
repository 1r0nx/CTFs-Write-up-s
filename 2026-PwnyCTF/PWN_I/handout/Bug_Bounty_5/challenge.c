#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void setup();
void print_stack(char *name_addr);


const char *pwn5 = "\n"
" _______   __       __  __    __        _______  \n"
"|       \\ |  \\  _  |  \\|  \\  |  \\      |       \\ \n"
"| $$$$$$$\\| $$ / \\ | $$| $$\\ | $$      | $$$$$$$\\\n"
"| $$__/ $$| $$/  $\\| $$| $$$\\| $$      | $$____  \n"
"| $$    $$| $$  $$$\\ $$| $$$$\\ $$      | $$    \\ \n"
"| $$$$$$$ | $$ $$\\$$\\$$| $$\\$$ $$       \\$$$$$$$\\\n"
"| $$      | $$$$  \\$$$$| $$ \\$$$$      |  \\__| $$\n"
"| $$      | $$$    \\$$$| $$  \\$$$       \\$$    $$\n"
" \\$$       \\$$      \\$$ \\$$   \\$$        \\$$$$$$ \n";

                                                

void vuln() {
    /*
     * We've removed the `print_stack` function from the previous challenges.
     * If you want to inspect the stack, use gdb!
     * This stuff is hard, so don't be afraid to ask for help :)
     */

    char name[48]; 

    printf("What's your name? I'll store it safely at %p\n", &name); // this address might be helpful!
    printf("> ");

    // We've completely removed print_flag... what can you do to get a flag yourself?
    gets(name);
}

int main() {
    setup();
    puts(pwn5);
    vuln();
    return 0;                                                            
}





/**
* You can ignore everything below this
*/

// Just to make things work over the network
void setup() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
}
