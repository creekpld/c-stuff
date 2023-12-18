/*
Bubblesort
*/

#include <stdio.h>


void bubblesort(int *array, int length){
    int i, j; // ivars for the two integer positions for Comparison
    for (i = 0; i < length - 1; ++i) {
        printf("i=%d\n",i);
        for (j = 0; j < length - i - 1; ++j) {
            printf("j=%d\n",j);
            if (array[j] > array[j + 1]){
                printf("%d > %d\n",array[j] ,array[j + 1]);
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }else{
                printf("%d---%d\n",array[j] ,array[j + 1]);
            }
        }
    }
}

int main(){

    printf("Bubblesort Test\n");
    int zahlen[5] = {6,5,3,1,8};
    for(int i = 0; i < 5; i++){
        printf("%d ", zahlen[i]);
    } 
    printf("\n");
    bubblesort(zahlen, 5);

return 0;    
}