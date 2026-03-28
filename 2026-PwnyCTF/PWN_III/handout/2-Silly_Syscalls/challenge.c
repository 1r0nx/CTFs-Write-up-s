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
                        "██████╔╝██║░░██║██████╔╝  ░░███╔═╝\n"
                        "██╔══██╗██║░░██║██╔═══╝░  ██╔══╝░░\n"
                        "██║░░██║╚█████╔╝██║░░░░░  ███████╗\n"
                        "╚═╝░░╚═╝░╚════╝░╚═╝░░░░░  ╚══════╝\n";

    char* random_string = "/bin/sh";
    char data[32];

    puts(logo);
    puts("Oops, I forgot to remove some testing functions that were lying around. No more win function, so now"
        " it's definitely secure! ");
    printf("> data: ");

    gets(data);
    
    return 0;
}