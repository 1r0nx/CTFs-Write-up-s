#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void setup();
void print_stack(char *name_addr);


const char *pwn3 = "\n"
" _______   __       __  __    __         ______  \n"
"|       \\ |  \\  _  |  \\|  \\  |  \\       /      \\ \n"
"| $$$$$$$\\| $$ / \\ | $$| $$\\ | $$      |  $$$$$$\\\n"
"| $$__/ $$| $$/  $\\| $$| $$$\\| $$       \\$$__| $$\n"
"| $$    $$| $$  $$$\\ $$| $$$$\\ $$        |     $$\n"
"| $$$$$$$ | $$ $$\\$$\\$$| $$\\$$ $$       __\\$$$$$\\\n"
"| $$      | $$$$  \\$$$$| $$ \\$$$$      |  \\__| $$\n"
"| $$      | $$$    \\$$$| $$  \\$$$       \\$$    $$\n"
" \\$$       \\$$      \\$$ \\$$   \\$$        \\$$$$$$ \n";




void print_flag() {
    // bypasses some recent features in glibc to make your exploit easier
    __asm__("sub $0x8, %rsp");

    char c;
    FILE *f = fopen("flag.txt", "r");
    while ((c = fgetc(f)) != EOF) {
        putc(c, stdout);
    }
}

void vuln() {
    char name[48]; 

    puts("Here's what the stack looks like before your input:");
    print_stack(name);

    puts("What's your name?");
    printf("> ");

    // we don't call print_flag for you anymore. is there a way you can call it yourself?
    // read the pwn guides!
    gets(name);

    puts("Here's what the stack looks like after your input:");
    print_stack(name);
}

int main() {
    setup();
    puts(pwn3);
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

// Creates a visual representation of the stack
void print_stack(char *name_addr) {
    // get return address of previous frame
    char **rbp;
    __asm__("movq %%rbp, %0" : "=r"(rbp));
    char *prev_rbp = *rbp;
    char *return_addr = prev_rbp + 8;

    uint64_t *stack = (uint64_t *)name_addr;
    printf("\n");
    puts("+--------------------------------------------------------------+");
    for (int i = 0; (char *)&stack[i] <= return_addr; i++) {
        
        printf("|   %p: ", &stack[i]);
        for (int j = 0; j < 8; j++) {
            printf("%02hhx ", ((char *)&stack[i])[j]);
        }
      
        if ((char *)&stack[i] == name_addr) {
            printf("%-18s", "<-- name");
        } else if ((char *)&stack[i] == return_addr) {
            printf("%-18s", "<-- return address");
        } else {
            printf("%18s", "");
        }

        printf(" |\n");
    }
    puts("+--------------------------------------------------------------+");
    printf("\n");
}