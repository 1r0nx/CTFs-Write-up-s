#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void setup();
void print_stack(char *name_addr, char *info_addr);                                   


const char *pwn6 = "\n"
" _______   __       __  __    __         ______  \n"
"|       \\ |  \\  _  |  \\|  \\  |  \\       /      \\ \n"
"| $$$$$$$\\| $$ / \\ | $$| $$\\ | $$      |  $$$$$$\\\n"
"| $$__/ $$| $$/  $\\| $$| $$$\\| $$      | $$___\\$$\n"
"| $$    $$| $$  $$$\\ $$| $$$$\\ $$      | $$    \\ \n"
"| $$$$$$$ | $$ $$\\$$\\$$| $$\\$$ $$      | $$$$$$$\\\n"
"| $$      | $$$$  \\$$$$| $$ \\$$$$      | $$__/ $$\n"
"| $$      | $$$    \\$$$| $$  \\$$$       \\$$    $$\n"
" \\$$       \\$$      \\$$ \\$$   \\$$        \\$$$$$$ \n";


void vuln() {
    char info[32];
    char name[32];

    printf("What's your name?\n");
    printf("> ");

    fgets(name, 32, stdin);
    printf("Hello, ");
    printf(name); // there's a vulnerability here
    printf("\n");

    puts("Give me all your personal information (credit card number, SSN, all of it):");
    printf("> ");
    fgets(info, 64, stdin);
}

int main() {
    setup();
    puts(pwn6);
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
