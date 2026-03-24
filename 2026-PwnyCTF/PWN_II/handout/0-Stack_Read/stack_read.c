#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ignore this function. It is just used to make
// the challenge work over the network.
void setup() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
}

// Read the flag from flag.txt into buffer dest.
void read_flag(char* dest) {
    FILE *f = fopen("flag.txt", "r");
    if (!f) {
        puts("Error: flag.txt not found.");
        exit(1);
    }
    int n = fread(dest, 1, 15, f);
    dest[n] = 0;
}

void greet(char* name) {
    printf("Hello ");
    printf(name);
    printf("!\n");
}

void main() {
    char name[64];
    char flag[16];

    // setup
    setup();
    read_flag(flag);

    // say hello!
    while (1) {
        printf("What is your name? ");
        fgets(name, 64, stdin);
        strtok(name, "\n"); // remove newline
        greet(name);
    }
}
