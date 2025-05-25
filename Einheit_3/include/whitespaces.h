#ifndef _WHITESPACES_H_
#define _WHITESPACES_H_
#include <stdbool.h>
#include <stdlib.h>

typedef enum {
    PRETEXT,
    TEXT,
    WHITESPACE
} EWhiteSpaceRemoverState;

typedef struct {
    EWhiteSpaceRemoverState state;
    size_t sourcepos;
    size_t cleanpos;
} TWhiteSpaceRemoverHandle; //Hier werden die Daten in einer Struktur gehalten über die man die objekte steuert

typedef void (*WhiteSpaceRemoverCallback)(const char, const size_t, const size_t);

extern bool removeWhiteSpaces(TWhiteSpaceRemoverHandle *handle, const char c, const WhiteSpaceRemoverCallback callback);

#endif