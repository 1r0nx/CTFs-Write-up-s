#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char blag_file[32];

// Ignore this function. It is just used to make
// the challenge work over the network.
void setup() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
}

void print_blag() {
    char blag[512];
    FILE *f = fopen(blag_file, "r");
    if (!f) {
        printf("Error: %s not found.\n", blag_file);
        exit(1);
    }
    int n = fread(blag, 1, 511, f);
    blag[n] = 0;
    printf(blag);
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
    strcpy(blag_file, "blag.txt");

    // say hello!
    printf("What is your name? ");
    fgets(name, 64, stdin);
    strtok(name, "\n"); // remove newline
    greet(name);

    // output blag
    printf("\nHere is my blag:\n\n");
    print_blag();
}
