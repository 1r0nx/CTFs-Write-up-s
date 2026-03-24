#include <stdlib.h>
#include <stdio.h>

void setup() {
    // you can ignore this. it's just here to make netcat work nicely
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
}

char *read_flag() {
    char *flag = calloc(0x100, 1);
    FILE *f = fopen("flag.txt", "r");
    int i = 0;
    if (f != NULL) {
        char c;
        while ((c = fgetc(f)) != EOF) {
            flag[i++] = c;
        }
    } else {
        printf("Couldn't open flag file!\n");
    }
    fclose(f);
    return flag;
}

// try to call this function!
void win() {
    puts(read_flag());
}

int main() {
    char buf[0x1000]; // 4096 / 8 = 512

    setup();

    printf("What's your name, friend? ");
    fgets(buf, sizeof(buf), stdin);
    printf("Nice to meet you, ");
    printf(buf);
    printf("Where are you from? ");
    fgets(buf, sizeof(buf), stdin);
    printf(buf);
    printf("sounds like a cool place.\n");

    return 0;
}