int conta_letra(char string, char *letra){
    int contador;
    for(int i = 0; i < strlen(string); i++){
        if(string[i] == letra){
            contador++;
        }
    }
    return contador;
}