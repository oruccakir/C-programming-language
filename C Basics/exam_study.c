#include <stdio.h>
#define COL_NUMBER 4
#define ROW_NUMBER 4
int printMatrix(int mat[][COL_NUMBER]){

    int *strt = mat;
    int *start = &mat[0][0];
    int *end = &mat[ROW_NUMBER-1][COL_NUMBER];
    int *row_start=start;

    while (start != end)
    {
        start = row_start;

        while (start != row_start + COL_NUMBER)
        {
            printf("%d ",*start);
            start++;
        }

        printf("\n");
        
        row_start = row_start + COL_NUMBER;

    }

    return end - &mat[0][0];

}


int main(){

    int arr[20] = {1,2,4,123,4,1,1,1,1,11};
    int *ptr = arr;
    for(int i=0; i<20; i++){
        printf("%d ",*(ptr+i));
    }
    int *start = arr;
    int *end = &arr[20];

    printf("\n");

    printf("%d\n",sizeof(arr) / sizeof(int)); // here sizeof(arr) / sizeof(int) equal to end - start;

     int matrix[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    printf("%d\n",printMatrix(matrix));

}