#include <whitespaces.h>
#include <ctype.h>
#include <stdbool.h>

bool removeWhiteSpaces(TWhiteSpaceRemoverHandle *handle, const char c, const WhiteSpaceRemoverCallback callback){
    if(!handle || !callback) return false;
    
    switch(handle->state){
        case PRETEXT:{
            if(isspace(c) || !isprint(c)){
                //In state bleiben
                ++handle->sourcepos;
            }
            else{
                handle->state = TEXT;
                callback(c, handle->sourcepos++, handle->cleanpos++); //mit dem ++ nach dem wert wird der alte wert an die funktion übergeben und dann um 1 erhöht
            }
            break;
        }

        case TEXT:{
            //
            if(isspace(c) || !isprint(c)){
                //In state bleiben
                handle->state = WHITESPACE;
                ++handle->sourcepos;
            }
            else{
                handle->state = TEXT;
                callback(c, handle->sourcepos++, handle->cleanpos++); //mit dem ++ nach dem wert wird der alte wert an die funktion übergeben und dann um 1 erhöht
            }
            break;
        }
        case WHITESPACE:{
            if(isspace(c) || !isprint(c)){
                //In state bleiben
                ++handle->sourcepos;
            }
            else{
                handle->state = TEXT;
                callback(' ', handle->sourcepos, handle->cleanpos++);
                callback(c, handle->sourcepos++, handle->cleanpos++); //mit dem ++ nach dem wert wird der alte wert an die funktion übergeben und dann um 1 erhöht
            }
            break;
        }
        default: {
            // TODO Fehlerausgabe
            handle->state = PRETEXT;
            handle->sourcepos = 0;
            handle->cleanpos = 0;
        }
    }

    return true;
};
