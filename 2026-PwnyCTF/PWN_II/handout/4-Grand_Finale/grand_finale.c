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

void print_flag() {
    char flag[64];
    FILE *f = fopen("flag.txt", "r");
    if (!f) {
        puts("Error: flag.txt not found.");
        exit(1);
    }
    int n = fread(flag, 1, 63, f);
    flag[n] = 0;
    puts(flag);
}

void greet(char* name) {
    printf("Hello ");
    printf(name);
    printf("!\n");
}

void main() {
    char name[64];

    // setup
    setup();

    // say hello!
    while (1) {
        printf("What is your name? ");
        fgets(name, 64, stdin);
        strtok(name, "\n"); // remove newline
        greet(name);
    }
}
