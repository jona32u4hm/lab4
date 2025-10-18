//ejercicio2.c Jonatán Hidalgo Morales C4G083
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *fgetw(FILE *file){// file get word :D
    int size = 1; 
    int character;

    do {
        character = fgetc(file);
    } while (character != EOF && !isalnum(character));
    if (character == EOF) {
        return NULL; 
    }
    char *word = (char *)malloc(size*sizeof(char));


    while(1){
        if (word == NULL) {
            perror("no se pudo allocar *word");
            ungetc(character, file); // Put the character back
            return NULL;
        }
        if(character == EOF ||  ! isalnum(character) ) {
            *(word -1 + size) = '\0';
            return word;  
        }
        *(word - 1 + size++) = character;
        word = (char *)realloc(word, size*sizeof(char));
        character =  fgetc(file);
    }
}

int main(int argc, char *argv[]){
    if (argc < 4){
		printf("uso: %s <Archivo> <Palabra a buscar> <Reemplazo>\n", argv[0]);
		return 1;
	}
    FILE *file;
    file = fopen(argv[1], "r");
    FILE *destiny;
    destiny = fopen("./output.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    
    while (1){
        char *word = fgetw(file); 
        if (word == NULL){
                 free(word);
                 fclose(file);
                 return 0;     
        } 
        if (!strcmp(word, argv[2])){
             strcpy(word, argv[3]);       
        }
        fprintf(destiny, "%s", word);
	fprintf(destiny, " ");
        free(word);
    }
    

}
