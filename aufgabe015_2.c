/*
Funktion median soll int-
Zahlenarray übernehmen und median zurückgeben.

Mit verschiedenen großen Arrays testen
(gerade, ungerade Anzahl)
*/

#include <stdio.h>
#include <stdlib.h>

void printArray(int array[], int size){
    printf("Werte: ");
     for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n"); 
}

void append(int *array, int wert){

   //int newSize =  (sizeof(array) / sizeof(array[0]) + 1) * sizeof(array[0]);
   int size = (&array)[1] - array;
   int anzahlWerte = sizeof(array) / sizeof(array[0]);
   array = (int *)realloc(array, size + 1);// array um 1 erweitern
   array[anzahlWerte - 1] = wert; // neuen wert ins array stecken
}



int main(){

    char eingabe;
    int anzahl_Werte = 0;
    int *zahlen = (int *)calloc(anzahl_Werte, sizeof(int)); // leeres array erstellen
    // Menü
    do{
        printf("Median berechnen -> m \n");
        printf("Werte eingeben   -> w \n");
        printf("Beenden          -> x \n");
        // optionen eingeben
        scanf("%1c[mwx]", &eingabe);
        fflush(stdin);
        
        if(eingabe == 'm'){
            printf("%d werte.\n", anzahl_Werte);
            printArray(zahlen, anzahl_Werte);

        }if(eingabe == 'w'){

            printf("\n");
            printf("Wieviel Werte Möchten sie eingeben?:");
            scanf("%d", &anzahl_Werte);
            fflush(stdin);

            for (int i = 0; i < anzahl_Werte; i++){
                int wert;
                printf("\n");
                printf("Wert %d: ", i + 1);
                scanf("%d", &wert);
                fflush(stdin);
                append(zahlen, wert);
            }
            anzahl_Werte = sizeof(zahlen) / sizeof(int);

        }if(eingabe == 'x'){

        }
    }
    while(eingabe != 'x');
    
    return 0;

}