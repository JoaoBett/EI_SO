#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>

#include "debug.h"
#include "memory.h"
#include "args.h"

int count_vowels(char* word);


int main(int argc, char *argv[]){
struct gengetopt_args_info args;
    if(cmdline_parser(argc,argv,&args) != 0)
    {
        exit(1);
    };
    if(argc < 2){
        printf("Uso: %s palavra1 palavra2 ...\n", argv[0]);
        return 1;
    }
    for(int i=1; i < argc; i++){
        int num_vowels = count_vowels(argv[i]);
        printf("A palavra %s tem %d vogais.",argv[i], num_vowels);
    }
    
    cmdline_parser_free(&args);

    return EXIT_SUCCESS;
}

int count_vowels(char* word){
    int count = 0;
    for(int i=0; word[i] != '\0';i++){
        char ch = tolower(word[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            count++;
        }
    }
    return count;
}