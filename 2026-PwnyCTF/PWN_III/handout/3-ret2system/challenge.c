#include <stdio.h>
#include <stdlib.h>


void setup() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
}

int main() {
    setup();

    const char* logo =  "██████╗░░█████╗░██████╗░  ██████╗░\n"
                        "██╔══██╗██╔══██╗██╔══██╗  ╚════██╗\n"
                        "██████╔╝██║░░██║██████╔╝  ░█████╔╝\n"
                        "██╔══██╗██║░░██║██╔═══╝░  ░╚═══██╗\n"
                        "██║░░██║╚█████╔╝██║░░░░░  ██████╔╝\n"
                        "╚═╝░░╚═╝░╚════╝░╚═╝░░░░░  ╚═════╝░\n";

    char data[32]; 

    puts(logo);
    puts("Who wrote that silly assembly in my Super Secure Storage Service? I'm going to have to fix that...");
    printf("> data: ");

    gets(data);
    
    return 0;
}