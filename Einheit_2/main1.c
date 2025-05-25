#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(const int argc, const char **argv){
    for(int i = 0; i<argc; ++i){
        printf("%d: %s\n", i, argv[i]);
    }
    return EXIT_SUCCESS;
}
