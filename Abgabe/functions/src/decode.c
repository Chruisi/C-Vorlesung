#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <decode.h>

extern const char *morse_table[26];
extern const char *morse_table_symbols[26];

char morse_to_ascii_value(const char* code) {
    //puts("morse_to_ascii_value() aufgerufen");
    for (int i = 0; i < 26; i++) {
        if (strcmp(code, morse_table[i]) == 0) {
            return 65 + i; //65 => A, 97 => a
        }
    }
    for (int i = 0; i < 26; i++) {
        if (strcmp(code, morse_table_symbols[i]) == 0) {
            return 40 + i; //40 ist der start der sonderzeichen
        }
    }
    if (strcmp(code, "..--.-") == 0){
        return '_';
    }
    return '*'; //falls unbekannt
}

char* decode_to_ascii(const char* morse_input) {
    //puts("decode_to_ascii() aufgerufen");
    size_t input_len = strlen(morse_input);
    char* ascii = malloc(input_len + 1);
    if (!ascii) {
        puts("Error allocating memory");
        return NULL;
    }

    char buffer[16] = {0}; // Morse-Zeichen sind max. ~6 Zeichen lang
    int buf_index = 0;
    int space_count = 0;
    int ascii_index = 0;

    for (size_t i = 0; i <= input_len; i++) {
        char c = morse_input[i];
        if (c == '.' || c == '-' || c == '*') {
            buffer[buf_index++] = c;
            buffer[buf_index] = '\0';
            space_count = 0;
        } else if (c == ' ' || c == '\0') {
            if (buf_index > 0) {
                ascii[ascii_index++] = morse_to_ascii_value(buffer);
                buf_index = 0;
                buffer[0] = '\0';
            }
            space_count++;

            if (space_count >= 3) {
                ascii[ascii_index++] = ' ';
                space_count = 0;
            }
        }
    }

    ascii[ascii_index] = '\0';
    return ascii;
}
