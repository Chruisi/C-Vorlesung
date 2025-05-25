#include <stdlib.h>
#include <stdio.h>

void hexdump(FILE *file) {
    unsigned char buffer[16];
    size_t bytesRead;
    size_t offset = 0;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        // Print the offset
        printf("%08lx  ", offset);

        // Print the bytes in hexadecimal
        for (size_t i = 0; i < sizeof(buffer); i++) {
            if (i < bytesRead) {
                printf("%02x ", buffer[i]);
            } else {
                printf("   ");
            }
        }

        // Print the ASCII representation
        printf(" |");
        for (size_t i = 0; i < bytesRead; i++) {
            if (buffer[i] >= 32 && buffer[i] <= 126) {
                printf("%c", buffer[i]);
            } else {
                printf(".");
            }
        }
        printf("|\n");

        offset += bytesRead;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    hexdump(file);

    fclose(file);
    return EXIT_SUCCESS;
}