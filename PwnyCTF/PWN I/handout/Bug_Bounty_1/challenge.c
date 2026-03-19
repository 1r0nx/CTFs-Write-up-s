#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void setup();
void print_stack(char *name_addr, char *number_addr);

const char *pwn1 = "\n"
" _______   __       __  __    __          __   \n"
"|       \\ |  \\  _  |  \\|  \\  |  \\       _/  \\  \n"
"| $$$$$$$\\| $$ / \\ | $$| $$\\ | $$      |   $$  \n"
"| $$__/ $$| $$/  $\\| $$| $$$\\| $$       \\$$$$  \n"
"| $$    $$| $$  $$$\\ $$| $$$$\\ $$        | $$  \n"
"| $$$$$$$ | $$ $$\\$$\\$$| $$\\$$ $$        | $$  \n"
"| $$      | $$$$  \\$$$$| $$ \\$$$$       _| $$_ \n"
"| $$      | $$$    \\$$$| $$  \\$$$      |   $$ \\\n"
" \\$$       \\$$      \\$$ \\$$   \\$$       \\$$$$$$\n";



void print_flag() {
    char c;
    FILE *f = fopen("flag.txt", "r");
    while ((c = fgetc(f)) != EOF) {
        putc(c, stdout);
    }
}

void vuln() {
    // In memory, you'll see this as:
    //      be ba fe ca 00 00 00 00
    // It looks kinda backwards because this system is little-endian.
    // Read more about endianness here: https://en.wikipedia.org/wiki/Endianness
    uint64_t number = 0xcafebabe; // change this number to win!
    char name[40]; 

    puts("Here's what the stack looks like before your input:");
    print_stack(name, (char *)&number);

    puts("What's your name?");
    printf("> ");

    // This is a dangerous function! It doesn't check the size of the input.
    // What happens if we send (a lot) more than 40 characters?
    gets(name);

    puts("Here's what the stack looks like after your input:");
    print_stack(name, (char *)&number);

    if (number != 0xcafebabe) {
        puts("You win! Here's the flag:");
        print_flag();
    } else {
        printf("The number is 0x%lx right now.\nTry again!\n",
               number);
    }     
}

int main() {
    setup();
    puts(pwn1);
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
void print_stack(char *name_addr, char *number_addr) {
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
        } else if ((char *)&stack[i] == number_addr) {
            printf("%-18s", "<-- number");
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