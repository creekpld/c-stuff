#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
/*
Berechnen Sie mittels einer while-Schleife die Summe der Zahlen von 1-100.
Ausgabe: "Die Summe der Zahlen von 1 - 100 ist 5050";
1 + 2 + 3 + 4 ... 100

fortgeschritten:
die Grenzen legen Sie per Eingabe fest, d.h. wenn ich ne 5 und ne 88 einlese,
werden die Zahlen von 5 bis 88 addiert.
*/

int main(){
    int start = 1;
    int counter = start;
    int ende = 100;
    int summe = start;
    
    printf("Startzahl eingeben: ");
    scanf("%d", &start);
    fflush(stdin);
    
    printf("Endzahl eingeben: ");
    scanf("%d", &ende);
    fflush(stdin);
    
    while (counter < ende){
      
        counter++;
        summe = summe + counter;
    } 
     printf("Die Summe von %d bis %d ist %d\n", start, ende, summe);
    
    getchar();
    return 0;
}