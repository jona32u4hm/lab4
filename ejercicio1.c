// ejercicio1.c Jonatán Hidalgo Morales C4G083
//
#include <stdio.h>
#define SIZE 5


int matrix[SIZE][SIZE] = {
	{23,45,12, 8,80},
	{23,43,65, 3,98},
	{49,11,27,26, 9},
	{93,87,78,77, 3},
	{ 0,20,55,69, 5}
};
void printMatrix(int *matrix) { //imprime una matriz
		for(int i = 0; i < SIZE*SIZE; i++){
			printf("%d  ",*()matrix+i)); //imprimir posición
            if (i%SIZE == 5) printf("\n");//siguiente fila!
		}
	}
}

void bubbleSort(int *array){
    while(1){
        int sorted = 1;
        for (int i = 0; i < SIZE*SIZE - 1; i++){
            if ( *(array + i) > *(array + i + 1) ){
                int swapHolder = *(array+i);
                *(array+i) = *(array + i + 1);
                *(array + i + 1) = swapHolder;
                sorted = 0;
            }
        }        
        if(sorted) return;
    }
}


int *mptr = &matrix[0][0];

int main(){

    printf("la matriz es:");
    printMatrix(matrix);

    //convertir a un array:
	int array[SIZE*SIZE] = {};
	for ( int i = 0; i < SIZE*SIZE; i++){
		array[i] = *(mptr+i);
	}

    bubbleSort(array);

    for ( int i = 0; i < SIZE*SIZE; i++){
		printf("%d\n", array[i]); 
        *(mptr+i) = array[i];
	}
    
    printf("matriz ordenada:");
    printMatrix(matrix);
    return 0;

}


