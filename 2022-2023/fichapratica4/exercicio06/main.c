#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "conta_letras.h"
#include "debug.h"
#include "args.h"

int main(int argc, char *argv[]){

    struct gengetopt_args_info args_info;
    if(cmdline_parser(argc,argv,&args_info) != 0)
    {
        exit(1);
    };
    

    if(argc != 3){
        fprintf(stderr, "Erro - Quantidade de parametros inválida\n");
        fprintf(stderr, "Usage: conta letra <string> <letra>\n");
        exit(1); //Numero "1" - execution failure       ----------      quer dizer que o programa fechou mas não da forma correta
    }

    /*
        ERROR(EXIT_FAILURE, "Sao precisos parametros") == linha 19 e 20
    */

    char *string = args_info.string_arg;
    char *letra = args_info.letra_arg;

    if(strlen(letra) != 1){
        fprintf(stderr, "Erro - Segundo parametro apenas pode ter um caracter\n");
        exit(EXIT_FAILURE);
        cmdline_parser_free(&args_info);
    }

    int contagem = conta_letra(string, letra[0]);

    printf("A letra %c aparece %d vezes em : %s", letra[0], contagem, string);

    cmdline_parser_free(&args_info);

    return 0;
}