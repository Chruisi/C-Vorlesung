#include <stdlib.h>
#include <stdio.h>
#define NEEEDARGUMENTS 2 //es wird nur der Dateiname als Argument benötigt

int main(int argc, char *argv[]) {
    if(argc != NEEEDARGUMENTS){
        printf("You inputtet the wrong amount of arguments\n");
        return EXIT_FAILURE;
    }
    FILE *file = fopen(argv[1], "rb");
    char buffer[16];
    size_t bystesRead;
    size_t offset = 0;

    while((bystesRead =fread(buffer, 1, sizeof(buffer), file))>0){
        printf("%08lx: ", offset);

        //Ausgabe der Bytes in Hexadezimaldarstellung
        for(size_t i = 0; i<sizeof(buffer); i++){
            if(i < bystesRead){
                printf("%02x ", buffer[i]);
            }else{
                printf("   ");
            }
        }

        //Ausgabe als Buchstaben, wenn nicht druckbar wird ein Punkt an die Stelle gedruckt
        for(size_t i = 0; i < bystesRead; i++){
            if(isprint(buffer[i])){
                printf("%c", buffer[i]);
            }else{
                printf(".");
            }
        }

        printf("\n");
        offset = offset + bystesRead;
    }

    fclose(file);
    return EXIT_SUCCESS;
}