/*
Lesen Sie in einer Funktion 4 Ganzzahlen ein
Wichtig aufsteigend geordnet, also z.B. 5 9 13 17.
Diese Funktion gibt den Median dieser Zahlen an
die main zurück. Dort ausgeben.

Für Median mal in Wikipedia gucken.
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int compare( const void* a, const void* b)
{
     int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );

     if ( int_a == int_b ) return 0;
     else if ( int_a < int_b ) return -1;
     else return 1;
}

// median von 4 zahlen
int median4(int i1, int i2, int i3, int i4){

    int arr[] = { i1,i2,i3,i4 };
    //int arr[] = { 88, 56, 100, 2, 25 };
    
    printf("Before sorting: \n");
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++ ){
        printf("%d ", arr[i]);
    }
    
    // sort
    qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), compare);
    
    printf("\nAfter sorting: \n");
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++ ){
        printf("%d ", arr[i]);
    }
    
    // median berechnen
    return (arr[1] + arr[2]) / 2;  
}

int main(){
   int zahl1;
   int zahl2;
   int zahl3;
   int zahl4;
   
   printf("Zahl 1 eingeben: ");
   scanf("%d", &zahl1);
   fflush(stdin);
   
   printf("\nZahl 2 eingeben: ");
   scanf("%d", &zahl2);
   fflush(stdin);
   
   printf("\nZahl 3 eingeben: ");
   scanf("%d", &zahl3);
   fflush(stdin);
   
   printf("\nZahl 4 eingeben: ");
   scanf("%d", &zahl4);
   fflush(stdin);
   
   printf("\nMedian = %d \n", median4(zahl1, zahl2, zahl3, zahl4));
   
   return 0; 
}