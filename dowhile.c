#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

int main(){
    char eingabe;
    double radius;
    // Menü
    do{
        printf("Kreisfläche berechnen -> r \n");
        printf("Beenden               -> x \n");
        // optionen eingeben
        scanf("%1c[rx]", &eingabe);
        fflush(stdin);
        
        if (eingabe == 'r'){
            printf("Radius eingeben: ");
            scanf("%lf", &radius);
            fflush(stdin);
            printf("\nKreisfläche = %.2f \n", radius*radius*M_PI);
            
            
        }else{
            printf("Nur gültige Menüpunkte ...\n");
        }
    }
    while(eingabe != 'x');
    
    return 0;
}