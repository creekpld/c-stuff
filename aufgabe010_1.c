/*
in der main geben sie einen radius ein.
eine funktion "kugel" berechnet das Kugelvolumen
und gibt es an die main zurück. Dort ausgeben.

wer die aufgabe fertig hat, und wem die aufgabe 2 zu schwer ist, 
der macht bitte noch ein menü drum. So dass sie viele Radien eingeben können
bis sie x für beenden eingeben.
(4/3*pi*r*r*r)
- http://www.schulminator.com/mathematik/kugel
- 
*/
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

float kugel(float radius){
    return (M_PI/3*4)*radius*radius*radius;
}

int main(){
    float radius = 0;
    printf("Bitte Radius eingeben: ");
    scanf("%f", &radius);
    fflush(stdin);
    printf("Kugelvolumen = %.3f\n", kugel(radius));
    
    return 0;
}