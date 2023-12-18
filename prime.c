/*
Primzahlen prüfen
*/
#include <stdio.h>

int main(){
    int start = 2;
    int ende = 50;
    int j;
    // Eingabe des Bereiches
    printf("Bitte einen Bereich für die Primzahlsuche eingeben.\n");
    
    printf("start: ");
    scanf("%d", &start);
    fflush(stdin);
    if (start < 2) start = 2; // keine Startzahl kleiner als 2 zulasssen
    
    printf("ende: ");
    scanf("%d", &ende);
    fflush(stdin);
    if (ende < start) ende = start; // keine Endzahl kleiner als Startzahl zulasssen
    
    // Äußere Schleife durchläuft alle Zahlen des Bereiches (1 weglassen)
    for (int i = start; i <= ende; i++){
        // Innere Schleife durchläuft Zahlen von 2 bis < aktuelle Zahl
        for (j = 2; j < i; j++){
            if (i % j == 0){
                break;
            }
        }
        if (i == j){
            // ist primzahl
            printf("%d ist eine Primzahl.\n",i);
        }
    }
    
   printf("Ende\n"); 
   return 0; 
}