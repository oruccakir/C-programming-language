#include<stdio.h>
#include<stdlib.h>


int **give2DArray(int x_dim,int y_dim){

    int **array_pointer = (int **) malloc(x_dim * sizeof(int *));

    if(array_pointer != NULL){

        for(int i=0; i<x_dim; i++){

            array_pointer[i] = (int *) malloc(y_dim * sizeof(int));

            if(array_pointer[i] != NULL){

                for(int k=0; k<y_dim; k++){

                    array_pointer[i][k] = i*y_dim + k + 1;

                }

            }

        }

    }

    return array_pointer;

}


int ***give3DArray(int x_dim,int y_dim,int z_dim){

    int ***arr_ptr = (int ***)malloc(x_dim * sizeof(int **));

    if(arr_ptr != NULL){

        for(int i=0; i<x_dim; i++){

            arr_ptr[i] = (int **)malloc(y_dim * sizeof(int *));

            if(arr_ptr[i] != NULL){

                for(int k=0; k<y_dim; k++){

                    arr_ptr[i][k] = (int *) malloc(z_dim * sizeof(int));

                    if(arr_ptr[i][k] != NULL){

                        for(int j=0; j<z_dim; j++){

                            arr_ptr[i][k][j] = i*k*y_dim + j + 1;

                        }

                    }

                }

            }

        }

    }

    return arr_ptr;

}

void print2DArray(int **array_pointer,int x_dim,int y_dim){

    for(int i=0; i<x_dim; i++){
        for(int k=0; k<y_dim; k++){

            printf("%d ",array_pointer[i][k]);

        }
        printf("\n");
    }

}

void print3DArray(int ***arr_ptr,int x_dim,int y_dim,int z_dim){

    for(int i=0; i<x_dim; i++){

        for(int k=0; k<y_dim; k++){

            for(int j=0; j<z_dim; j++){
                printf("%d ",arr_ptr[i][k][j]);
            }
            printf("\n");
        }

        printf("\n");

    }

}


int main(){

    int **arr = give2DArray(10,5);
    print2DArray(arr,10,5);

    int ***arr1 = give3DArray(5,4,3);
    print3DArray(arr1,5,4,3);





    return 0;
}