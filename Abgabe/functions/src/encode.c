#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "morse_tables.h"

char* encode_to_morse(const char* string_pointer) {
    puts("encode_to_morse() aufgerufen");
    size_t buffersize = 1024;
    size_t length = 0;
    char* morse = malloc(buffersize);
    if (!morse) {
        puts("Error allocating memory");
        return NULL;
    }
    morse[0] = '\0'; // Initialisierung

    for (int i = 0; string_pointer[i] != '\0'; i++) {
        const char* current_morse = NULL;
        int c = (int) string_pointer[i];

        if (c >= 'a' && c <= 'z') c -= 32; // zu Großbuchstaben

        if (c >= 'A' && c <= 'Z') {
            current_morse = morse_table[c - 65];
        } else if (c >= '(' && c <= '@') {
            current_morse = morse_table_symbols[c - 40];
        } else if (c == ' ') {
            current_morse = "   "; // Worttrennung
        } else {
            current_morse = "*"; // Unbekanntes Zeichen
        }

        size_t morse_len = strlen(current_morse);
        if (length + morse_len + 2 >= buffersize) {
            buffersize = (length + morse_len + 2) + 1024;
            char *new_morse = realloc(morse, buffersize);
            if (!new_morse) {
                free(morse);
                puts("Error reallocating memory");
                return NULL;
            }
            morse = new_morse;
        }
        strcat(morse, current_morse);
        strcat(morse, " ");
        length += morse_len + 1;
    }
    puts("encode_to_morse fertig() aufgerufen");
    return morse;
}