#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* HELP = "encryptor-help:\n\n--encrypt: will encrypt your text\n--decrypt: will decrypt your text\n";
unsigned int seed = 300; //DEFAULT SEED

char* decrypt(const char* text);
char* encrypt(const char* text);

char* decrypt(const char* text){
    unsigned int lenght = strlen(text);
    char* res = (char*)malloc(lenght);
    for(unsigned int i = 0; i < lenght; i++){
        res[i] = ((i % 2) == 0) ? (char)((int)text[i]-(rand() % 15)) : (char)((int)text[i]- (rand() % 5));
    }
    res[lenght] = '\0';
    return res;
}

char* encrypt(const char *text){
    unsigned int lenght = strlen(text);
    char* res = (char*)malloc(lenght+1);
    for(unsigned int i = 0; i < lenght; i++){
        res[i] = ((i % 2) == 0) ? (char)((int)text[i]+(rand() % 15)) : (char)((int)text[i]+(rand() % 5));
    }
    res[lenght] = '\0';
    return res;
}

int main(int argc, char** argv){
    unsigned char used = 0;
    for(unsigned int i = 0; i < argc; i++){
        if(!strcmp(argv[i], "--seed"))
        {srand(atoi(argv[(i+1)])); i++;}
        if(!strcmp(argv[i], "--encrypt"))
        {char* d = argv[(i+1)]; printf("Encrypted: %s\n\r", encrypt(d));i++; used = 1;};
        if(!strcmp(argv[i], "--decrypt"))
        {char* d = argv[(i+1)]; printf("Decrypted: %s\n\r", decrypt(d));i++; used = 1;};
    }

    if(used == 0) {printf("%s", HELP);exit(EXIT_FAILURE);};
    exit(EXIT_SUCCESS);
}