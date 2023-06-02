#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include <string.h>

#include "debug.h"
#include "memory.h"
#include "args.h"
#include "outroficheiro.h"

#define INVALID_LEVEL -1

int main(int argc, char *argv[]){
struct gengetopt_args_info args;
    int level = 1;
    if(cmdline_parser(argc,argv,&args) != 0)
    {
        exit(1);
    };
    if(args.level_given){
        if(args.level_arg < 1 || args.level_arg > 3){
            ERROR(INVALID_LEVEL,"Invalid level:");
        }
        level = args.level_arg;
    }
    /*
    if(level == 1 || level == 3){
        for(size_t i=0; i < strlen(args.input_arg);i++){
            switch (args.input_arg[i]){
                case '0': args.input_arg[i] = 'x'; break;
                case '1': args.input_arg[i] = 'y'; break;
                case '2': args.input_arg[i] = 'z'; break;
                case '3': args.input_arg[i] = 'a'; break;
                case '4': args.input_arg[i] = 'b'; break;
                case '5': args.input_arg[i] = 'c'; break;
                case '6': args.input_arg[i] = 'd'; break;
                case '7': args.input_arg[i] = 'e'; break;
                case '8': args.input_arg[i] = 'f'; break;
                case '9': args.input_arg[i] = 'g'; break;
            }
        }
    }

    if(level == 2 || level == 3){
        for(size_t i=0; i < strlen(args.input_arg);i++){
            switch (args.input_arg[i]){
                case 'a': args.input_arg[i] = '1'; break;
                case 'e': args.input_arg[i] = '2'; break;
                case 'i': args.input_arg[i] = '3'; break;
                case 'o': args.input_arg[i] = '4'; break;
                case 'u': args.input_arg[i] = '5'; break;            
            }
        }
    }
    */

    process(args.input_arg, level);

    printf("%s\n",args.input_arg);

    cmdline_parser_free(&args);
    return EXIT_SUCCESS;
}
