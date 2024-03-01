/**
* @file main.c
* @brief Description
* @date 2018-1-1
* @author name of author
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "debug.h"
#include "memory.h"
#include "args.h"

#define INVALID_INPUT -1

int main(int argc, char *argv[]){
	struct gengetopt_args_info args;

	if(cmdline_parser(argc, argv, &args_info) != 0) {
		ERROR(INVALID_INPUT, "Invalid input");
	}



	cmdline_parser_free(&args);
	return EXIT_SUCESS;
}



Recorrendo à linguagem C, elabore a aplicação “randpwd” que permite gerar palavras-passe aleatórias recorrendo a um dos
ficheiros virtuais /dev/random ou /dev/urandom. Um destes ficheiros deve ser aberto e lido pela aplicação para obter um
determinado número de bytes válidos com valores aleatórios. Consideram-se válidos todos os bytes que representem dígitos
(caracteres entre ‘0’ e ‘9’), letras maiúsculas (caracteres entre ‘A’ e ‘Z’) e minúsculas (caracteres entre ‘a’ e ‘z’). Após terminar
a leitura do ficheiro virtual, a aplicação deve apresentar a nova palavra-passe gerada no terminal e, de seguida, deve
armazenar a mesma num ficheiro em formato de texto.


Assim, a aplicação deve estar preparada para receber os seguintes 3 argumentos obrigatórios a partir da linha de
comandos:
• -i/--input: Caminho para um dos ficheiros virtuais /dev/random ou /dev/urandom. A aplicação apenas
deve aceitar um dos 2 caminhos mencionados, caso contrário, deve terminar com uma mensagem de erro
no canal de erro padrão;
• -o/--output: Caminho para o ficheiro de saída com a nova palavra-passe gerada.
• -l/--length: Valor inteiro para o tamanho da palavra-passe. A aplicação deve validar que este argumento
se encontra no intervalo inteiro [3,128], isto é, deve ser maior ou igual a 3 e inferior ou igual a 128. Caso
não se encontre no intervalo indicado, a aplicação deve terminar com uma apropriada mensagem de erro
no canal de erro padrão
