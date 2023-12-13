#include<stdio.h>
#include<stdlib.h>



void print2DArray(int **arr,int x,int y){

    if(arr == NULL){
        printf("Empty");
        return;
    }

    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("\n");

}

void print2DArrayDifferentSizes(int **arr,int x,int *size){

    if(arr == NULL){
        printf("Empty");
        return;
    }

    for(int i=0; i<x; i++){
        for(int j=0; j<*(size); j++){
            printf("%d ",arr[i][j]);
        }
        size++;
        printf("\n");
    }

    printf("\n");
    printf("\n");

}

void print3DArray(int ***arr,int x,int y,int z){

    if(arr == NULL){
        printf("Empty");
        return;
    }

    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            for(int k=0; k<z; k++){
                printf("%d ",arr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    printf("\n");
    printf("\n");

}

int **allocate2DArrayDifferentSizes(int x,int *size){

    int ** ARR = (int **) malloc(x*sizeof(int*));

    if(ARR != NULL){

        for(int i=0; i<x; i++){

            ARR[i] = (int *) malloc(*(size)*sizeof(int));

            if(ARR[i] != NULL){

                for(int j=0; j<*(size); j++)
                    ARR[i][j] = i*(*size)+ j + 1;

            }

            size++;

        }

    }
    
    return ARR;


}


int **allocate2DArray(int x,int y){

    int ** ARR = (int **) malloc(x*sizeof(int*));

    if(ARR != NULL){

        for(int i=0; i<x; i++){

            ARR[i] = (int *) malloc(y*sizeof(int));

            if(ARR[i] != NULL){

                for(int j=0; j<y; j++)
                    ARR[i][j] = i*y+ j + 1;

            }

        }

    }
    
    return ARR;
}

void deallocate2DArray(int **arr,int x){

     int *removed_arr = NULL;

    for(int i=0; i<x; i++){

        removed_arr = arr[i];

        free(removed_arr);

        arr[i] = NULL;

    }

    free(arr);

}

void deallocate3DArray(int ***arr,int x,int y){

    for(int i=0; i<x; i++){

        int **rm2 = NULL;

        for(int j=0; j<y; j++){

            int *rm1 = NULL;

            arr[i][j] = NULL;

            rm1 = arr[i][j];

            free(rm1);

        }

        rm2 = arr[i];

        arr[i]= NULL;

        free(rm2);

    }

    free(arr);

}

int ***allocate3DAarray(int x,int y,int z){

    int ***ARR = (int ***)malloc(x*sizeof(int**));
    
    if(ARR != NULL){

        for(int i=0; i<x; i++){

            ARR[i] = (int **) malloc(y*sizeof(int *));

            if(ARR[i] != NULL){

                for(int j=0; j<y; j++){

                    ARR[i][j] = (int *)malloc(z*sizeof(int));
                    
                    if(ARR[i][j] != NULL){

                        for(int k=0; k<z; k++){

                            ARR[i][j][k] = i*j*y + k + 1; 

                        }

                    }

                }

            }

        }

    }

    return ARR;

}



int main(){
    
    int ** arr = allocate2DArray(6,10);
    int ***arr1 = allocate3DAarray(6,8,10);
    int x = 6;
    int y = 10;
    print2DArray(arr,x,y);
    print3DArray(arr1,6,8,10);

    int size[5] = {1,5,6,7,8};
    int *ptr = size;
    int **arr2 = allocate2DArrayDifferentSizes(5,ptr);
    print2DArrayDifferentSizes(arr2,5,ptr);

    deallocate2DArray(arr,6);
    deallocate2DArray(arr2,5);
    deallocate3DArray(arr1,6,8);


    
    



}