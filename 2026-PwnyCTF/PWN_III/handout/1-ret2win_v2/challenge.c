#include <stdio.h>
#include <stdlib.h>

void win(int a, int b) {
    if (a == 0xdeadbeef && b == 0xcafebabe) {
        puts("You win!");
        char flag[64];
        FILE* f = fopen("flag.txt", "r");
        if (f == NULL) {
            puts("Error: Missing flag.txt.");
            exit(1);
        }
        int n = fread(flag, 1, 63, f);
        flag[n] = 0;
        fclose(f);
        puts(flag);
    } else {
        puts("What do you think you're doing?");
    }
}

void setup() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
}

int main() {
    setup();

    const char* logo =  "██████╗░░█████╗░██████╗░  ░░███╗░░\n"
                        "██╔══██╗██╔══██╗██╔══██╗  ░████║░░\n"
                        "██████╔╝██║░░██║██████╔╝  ██╔██║░░\n"
                        "██╔══██╗██║░░██║██╔═══╝░  ╚═╝██║░░\n"
                        "██║░░██║╚█████╔╝██║░░░░░  ███████╗\n"
                        "╚═╝░░╚═╝░╚════╝░╚═╝░░░░░  ╚══════n\n";

    char data[32]; // the compiler got mad at me when i didn't add a size, but trust me, it's unlimited!

    puts(logo);
    puts("Welcome to my Super Secure Storage Service! I found this pretty cool function called gets"
        " that will take an unlimited amount of data. that means unlimited storage for you! ");
    puts("Send some data and I'll store it for you, free of charge!");
    printf("> data: ");

    gets(data);
    
    return 0;
}