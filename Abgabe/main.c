#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <getopt.h>
#include "decode.h"
#include "encode.h"
#include "help_functions.h"
#include "input_output.h"
#include "morse_tables.h"

int main(int argc, char **argv) {
    static struct option long_options[] = {
        {"programmer-info", no_argument, 0, 'p'},
        {"encode", optional_argument, 0, 'e'},
        {"decode", optional_argument, 0, 'd'},
        {"help", no_argument, 0, 'h'},
        {"out", required_argument, 0, 'o'},
        {0, 0, 0, 0}
    };

    int opt;
    char* result = NULL;
    char* input_argument = NULL;
    char* output_argument = NULL;
    bool e_flag, d_flag, output_file_flag, error_flag, default_flag;
    e_flag = d_flag = output_file_flag = error_flag = false;
    default_flag = true;

    while ((opt = getopt_long(argc, argv, "pe::d::ho:", long_options, NULL)) != -1) {
        switch (opt) {
            case 'p':
                default_flag = false;
                print_programmer_info();
                break;
            case 'd':
                default_flag = false;
                if (d_flag == false) {
                    d_flag = true;
                    if (optarg){
                        input_argument = optarg;
                    } else if (optind < argc && argv[optind][0] != '-') {
                        optarg = argv[optind];
                        ++optind;
                    } else {
                        optarg = NULL;
                    }
                    input_argument = optarg;
                }
                break;
            case 'h':
                default_flag = false;
                print_help();
                break;
            case 'o':
                default_flag = false;
                output_file_flag = true;
                output_argument = optarg;
                break;
            case '?':
                error_flag = true;
                break;
            case 'e':
                default_flag = false;
                if (e_flag == false) {
                    e_flag = true;
                    if (optarg){
                        input_argument = optarg;
                    } else if (optind < argc && argv[optind][0] != '-') {
                        optarg = argv[optind];
                        ++optind;
                        //printf("Option --mode mit manuell erkanntem Argument: %s\n", optarg);
                    } else {
                        optarg = NULL;
                    }
                    input_argument = optarg;
                }
                break;
        }
    }
    if (default_flag) {
        e_flag = true;
    }
    //printf("Nach dem Parsen: e_flag: %d, d_flag: %d, output_file_flag: %d\n", e_flag, d_flag, output_file_flag);
        if (e_flag && d_flag){
            puts("You can't encode and decode at the same time");
            return 1;
            }
        if (error_flag){
            print_error();
            return 1;
        }
        if (e_flag){
            char* text = input_to_string(input_argument);
            if (text == NULL) {
                free(text);
                return 1;
            }
            char* result = encode_to_morse(text);
            output_result(result, output_file_flag, output_argument);
            free(text);
            free(result);
        }
        if (d_flag){
            char* text = input_to_string(input_argument);
            if (text == NULL) {
                free(text);
                return 1;
            }
            char* result = decode_to_ascii(text);
            output_result(result, output_file_flag, output_argument);
            free(text);
            free(result);
        }
    return 0;
}

