#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
/*
Erzeugen Sie folgendes Menü (egal ob while, oder do while Schleife):

Oberfäche -> o
Volumen    -> v
Beenden   -> x

Wenn Benutzer x, eingegeben hat, endet das Programm. In beiden anderen
Fällen (o, v) soll er die Länge, Breite und Höhe eines Quaders eingeben und 
das Volumen bzw. die Oberfläche berechnen.
*/
int main(){
    char eingabe;
    int laenge;
    int breite;
    int hoehe;
    // Schleife 
    do{
        // Menü Zeichnen
        printf("Oberfläche berechnen -> o \n");
        printf("Volumen berechnen    -> v \n");
        printf("Beenden              -> x \n");
        // Optionen eingeben
        scanf("%1c[rx]", &eingabe);
        fflush(stdin);
        
        // Oberfläche berechnen
        if (eingabe == 'o'){
            
            printf("Länge eingeben: ");
            scanf("%d", &laenge);
            fflush(stdin);
            
            printf("Breite eingeben: ");
            scanf("%d", &breite);
            fflush(stdin);
            
            printf("Oberfläche = %d \n", laenge*breite);
            
        // Volumen berechnen   
        }else if(eingabe == 'v'){  
                  
            printf("Länge eingeben: ");
            scanf("%d", &laenge);
            fflush(stdin);
            
            printf("Breite eingeben: ");
            scanf("%d", &breite);
            fflush(stdin);
            
            printf("Höhe eingeben: ");
            scanf("%d", &hoehe);
            fflush(stdin);
            printf("Volumen = %d \n", laenge*breite*hoehe);
            
        // Exit
        }else if(eingabe == 'x'){
            printf("Tschüss ...\n");
            
        // Falsche eingabe    
        }else{
            printf("Nur gültige Menüpunkte ...\n");
        }
    }
    while(eingabe != 'x');
    
    return 0;
}