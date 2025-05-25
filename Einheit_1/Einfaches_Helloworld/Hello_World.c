#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Hello World\n");
    printf("\33[31mHelloworld\n");
    return EXIT_SUCCESS;
}

/*
Alles in einem Befehl kompilieren:
gcc -Wall -s -O3 -o hello_world Hello_World.c

Schritt für Schritt:
1. Präprozessor
gcc -E -o Hello_World.i Hello_World.c

2. Compiler
gcc -S -o Hello_World.s Hello_World.i

3. Assembler
gcc -c -o Hello_World.o Hello_World.s

4. Linker
gcc -o Hello_World Hello_World.o

*/
