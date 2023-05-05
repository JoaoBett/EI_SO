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
#include "matrix.h"


#define INVALID_PARAMS -1

int main(int argc, char *argv[]){
struct gengetopt_args_info args_info;
    if(cmdline_parser(argc,argv,&args_info) != 0)
    {
        exit(1);
    };
    
	int ** M1 = matrix_new(args_info.m1r_arg,args_info.m1c_arg);
	if(M1 == NULL){
		fprintf(stderr, "Invalid Matrix");
		exit(INVALID_PARAMS);
	}

	int ** M2 = matrix_new(args_info.m1r_arg,args_info.m1c_arg);

	if(M2 == NULL){
		fprintf(stderr, "Invalid Matrix");
		//free matrix 1 :: matrix delete
		exit(INVALID_PARAMS);
	}

	matrix_fill(M1, args_info.m1r_arg,args_info.m1c_arg, 2);
	matrix_fill(M2, args_info.m2r_arg,args_info.m2c_arg, 4);

	matrix_print(M1, args_info.m1r_arg,args_info.m1c_arg);
	matrix_print(M2, args_info.m2r_arg,args_info.m2c_arg);

	int** m3 = matrix_mul(M1,M2,args_info.m1r_arg,args_info.m1c_arg,args_info.m2r_arg,args_info.m2c_arg);
	
	if(M3 == NULL){

	}

	matrix_delete(M1);
	M1 = NULL;
	matrix_delete(M2);
	M2 = NULL;

	return 0;
}