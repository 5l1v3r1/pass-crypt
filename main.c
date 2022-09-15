#include <stdio.h>
#include <stdlib.h>
#include <string.h>




char* decrypt(const char* text);
char* encrypt(const char* text);

char* decrypt(const char* text){
    unsigned int lenght = strlen(text);
    char* res = (char*)malloc(lenght);
    for(unsigned int i = 0; i < lenght; i++){
        res[i] = ((i % 2) == 0) ? (char)((int)text[i]-2) : (char)((int)text[i]-1);
    }
    res[lenght] = '\0';
    return res;
}

char* encrypt(const char *text){
    unsigned int lenght = strlen(text);
    char* res = (char*)malloc(lenght+1);
    for(unsigned int i = 0; i < lenght; i++){
        res[i] = ((i % 2) == 0) ? (char)((int)text[i]+2) : (char)((int)text[i]+1);
    }
    res[lenght] = '\0';
    return res;
}

int main(int argc, char** argv){
    for(unsigned int i = 0; i < argc; i++){
        if(!strcmp(argv[i], "encrypt"))
        {char* d = argv[(i+1)]; printf("Encrypted: %s\n\r", encrypt(d));i++;};
        if(!strcmp(argv[i], "decrypt"))
        {char* d = argv[(i+1)]; printf("Decrypted: %s\n\r", decrypt(d));i++;};
    }
}