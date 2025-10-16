// ejercicio1.c Jonatán Hidalgo Morales C4G083
//
#include <stdio.h>
#define SIZE 4


int matrix[SIZE][SIZE] = {
	{23,45,12, 8,80},
	{23,43,65, 3,98},
	{49,11,27,26, 9},
	{93,87,78,77, 3},
	{ 0,20,55,69, 5}
};
void printMatrix(int matrix[SIZE][SIZE]) { //imprime una matriz
        for(int y = 0; y < SIZE; y++){
		for(int x = 0; x < SIZE; x++){
			printf("%d  ",matrix[x][y]); //imprimir posición
		}
		printf("\n");//siguiente fila!
	}
}

void bubbleSort(int *array){
    do{
        int notSorted = 0;
        for (int i = 0; i < SIZE*SIZE - 1; i++){
            if ( *(array + i) > *(array + i + 1) ){
                int swapHolder = *(array+i);
                *(array+i) = *(array + i + 1);
                *(array + i + 1) = swapHolder;
                notSorted = 1;
            }
        }        
    }while(notSorted)
}


int *mptr = &matrix;

int main(){

    //convertir a un array:
	int array[SIZE*SIZE] = {};
	for ( int i = 0; i < SIZE*SIZE; i++){
		array[i] = *(mptr+i);
	}

    bubbleSort(array);

    



}


