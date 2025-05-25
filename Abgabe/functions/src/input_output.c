#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void output_result(char* result, char* argument){
    puts("output_result() aufgerufen");
    FILE* output = stdout;
    if (argument != NULL) {
        output = fopen(argument, "w");
        if (!output) {
            printf("Fehler beim Öffnen der Ausgabedatei %s", argument);
            return;
        }
    }

    fwrite(result, sizeof(char), strlen(result), output);
    fflush(output);
    if(output != stdout){
        fclose(output);
    }else if(output == stdout){
        puts("");
    }
}

char* input_to_string(char* argument){
    puts("input_to_string() aufgerufen");
    printf("Versuche zu öffnen: %s\n", argument);
    FILE* input_file = stdin;
    size_t bufsize = 1024;
    size_t len = 0;

    if (argument != NULL) {
        input_file = fopen(argument, "r");
        if (!input_file) {
            printf("Error trying to open File: %s\n", argument);
            return NULL;
        }
    }

    char* input = malloc(bufsize);
    if (!input) {
        puts("Error allocating Memory");
        if (input_file != stdin) fclose(input_file);
        return NULL;
    }

    int c;
    while ((c = fgetc(input_file)) != EOF) {
        if (len + 1 >= bufsize) {
            bufsize += 1024;
            char* temp = realloc(input, bufsize);
            if (!temp) {
                puts("Error reallocating Memory");
                free(input);
                if (input_file != stdin) fclose(input_file);
                return NULL;
            }
            input = temp;
        }
        input[len++] = (char)c;
    }

    input[len] = '\0';  // Nullterminator

    if (input_file != stdin) fclose(input_file);
    return input;
}