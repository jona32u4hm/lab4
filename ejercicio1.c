// ejercicio1.c Jonatán Hidalgo Morales C4G083
//
#include <stdio.h>
#define SIZE 5


int matrix[SIZE][SIZE] = {
	{23,45,12, 8,80},
	{23,43,65, 3,98},
	{49,11,27,26, 9},
	{93,87,78,77, 3},
	{ 5,20,55,69, 0}
};
void printMatrix(int *matrix) { //imprime una matriz
		for(int i = 0; i < SIZE*SIZE; i++){
			printf("%d  ",*(matrix+i)); //imprimir posición
            if ((i+1)%SIZE == 0) printf("\n");//siguiente fila!
		}
}

void bubbleSort(int *array){
    
    int faltantes = SIZE*SIZE - 1; //es la cantidad de elementos por los que hace falta pasar en el loop a continuación

    while(1){ //loop infinito (roto por el return una vez cmpleta la tarea)
        int sorted = 1;// se va a cambiar a cero si se demuestra que todavía no estaba ordenada la matriz
        for (int i = 0; i < faltantes; i++){//esto pasa por todos los elementos necesarios y si encuentra un par que están mal, los intercambia
            if ( *(array + i) > *(array + i + 1) ){
                int swapHolder = *(array+i);
                *(array+i) = *(array + i + 1);
                *(array + i + 1) = swapHolder;
                sorted = 0; //todavía no estaba ordenada
            }

        }       
//algo muy loco es que después de darle una pasada, el algoritmo se lleva un elemento hacia un extremo y lo coloca en su lugar

        faltantes--;//entonces no hace falta revisar todos la próxima vez :> 
        if(sorted) return;
    }
}


int *mptr = &matrix[0][0];

int main(){

    printf("la matriz es:");
    printMatrix(mptr);

    //convertir a un array:
	int array[SIZE*SIZE] = {};
	for ( int i = 0; i < SIZE*SIZE; i++){
		array[i] = *(mptr+i);
	}

    bubbleSort(array);

    for ( int i = 0; i < SIZE*SIZE; i++){
        *(mptr+i) = array[i];
	}
    
    printf("matriz ordenada:");
    printMatrix(mptr);
    return 0;

}


