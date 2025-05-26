#include <stdio.h>
#include <help_functions.h>

void print_programmer_info() {
    const char *json = "{\n"
        "  \"firstname\": \"Christian\",\n"
        "  \"surname\": \"Hartmann\",\n"
        "  \"branch_of_study\": \"TIT\",\n"
        "  \"contact\": \"hartmann.chris-it24@it.dhbw-ravensburg.de\"\n"
        "}";
    printf("%s\n", json);
}

void print_help() {
    puts("Options:\n");
    puts("Usage: morse [options]\n");
    puts("  -p, --programmer-info   Show programmer information\n");
    puts("  -e, --encode <text>     Encode text to Morse code\n");
    puts("  -d, --decode <morse>    Decode Morse code to text\n");
    puts("  -h, --help              Show this help message\n");
    puts("  -o, --out <file>        Output file for encoded/decoded text\n");
    puts("Keep in mind that you cant encode and decode at the same time!\n");
}

void print_error() {
    puts("Error: Invalid option or argument.\n");
    puts("Use -h or --help for usage information.\n");
}