#include <stdio.h>
#include <unistd.h>
#include <whitespaces.h>

void printSign(const char c, const size_t sourcepos, const size_t cleanpos){
    putchar(c);
};


int main(){
    if(!isatty(fileno(stdin))){
        char buffer[128];
        size_t length;
    

    TWhiteSpaceRemoverHandle handle ={
        .state = PRETEXT,
        .sourcepos = 0,
        .cleanpos = 0,
    };

    while(length = fread(buffer, sizeof(char), sizeof(buffer), stdin)){
        for (int i = 0; i<length; ++i){
            removeWhiteSpaces(&handle, buffer[i], printSign);
        }
    }
    printf("\n\n sourcepos=%ld, cleanpos=%ld\n");
    }
    else {
        fputs("Bitte Programm mit einer Pipe verbinden: cat xyz | removews\n", stderr);
    };

    return EXIT_SUCCESS;
}

//-> compilieren mit gcc -o removews -Wall -s -O3 main.c ./scr/whitespaces.c -I./include/
// benutzen mit cat <dateiname> | ./removews
