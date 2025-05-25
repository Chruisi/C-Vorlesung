#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int fractionsInThousands[] = {1562, 1875, 2187, 2500, 2812, 3125, 3438, 3750, 4062, 4375, 5000, 5625, 5938, 6250, 6875, 7500, 7812, 8125, 8750, 9375 };
const char* sae_masse[] = {"5/32", "3/16", "7/32", "1/4", "9/32", "5/16", "11/32", "3/8", "13/32", "7/16", "1/2", "9/16", "19/32", "5/8", "11/16", "3/4", "25/32", "13/16", "7/8", "15/16"};

int main(const int argc, const char **argv) {
    if(argc != 2) {
        fputs("Bitte eine Zahl eingeben: ./lintosae 1.3125\n", stderr);
        return EXIT_FAILURE;
    }

    char *endptr;
    double wert = strtod(argv[1], &endptr);
    if(*endptr != '\0') {
        fputs("Ungültige Eingabe\n", stderr);
        return EXIT_FAILURE;
    }
    int wholeInch = (int)(wert);
    int fraction = (int)((wert - wholeInch) * 10000);

    __uint8_t index = 0;
    if (fraction > 9375) {
        ++wholeInch;
    }else{
        while (fraction > fractionsInThousands[index]) {
            ++index;
        }
    }
    
    printf("%d\"%s\n", wholeInch, sae_masse[index]);
    
    return EXIT_SUCCESS;	
}