#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outroficheiro.h"

void process(char* texto, int level){
    if(level == 1 || level == 3){
        for(size_t i=0; i < strlen(texto);i++){
            switch (texto[i]){
                case '0': texto[i] = 'x'; break;
                case '1': texto[i] = 'y'; break;
                case '2': texto[i] = 'z'; break;
                case '3': texto[i] = 'a'; break;
                case '4': texto[i] = 'b'; break;
                case '5': texto[i] = 'c'; break;
                case '6': texto[i] = 'd'; break;
                case '7': texto[i] = 'e'; break;
                case '8': texto[i] = 'f'; break;
                case '9': texto[i] = 'g'; break;
            }
        }
    }

    if(level == 2 || level == 3){
        for(size_t i=0; i < strlen(texto);i++){
            switch (texto[i]){
                case 'a': texto[i] = '1'; break;
                case 'e': texto[i] = '2'; break;
                case 'i': texto[i] = '3'; break;
                case 'o': texto[i] = '4'; break;
                case 'u': texto[i] = '5'; break;            
            }
        }
    }
}
