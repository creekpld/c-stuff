#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
/*
Eine Zahl einlesen und Quersumme dieser Zahl ausgeben.
Quersumme von 123 ist 6, von 399 ist 21 usw.
*/

// Berechnet die Quersumme einer Zahl
int quersumme(int zahl) {
  int sum = 0;
  while (zahl > 0) {
    sum = sum + (zahl % 10);
    zahl = zahl / 10;
    printf ("swischensumme: %d\n", sum);
  }
  return sum;
}
  
int main () {
  // Variablen definieren
  int in_zahl, out_qersumme; 
  out_qersumme = 0;
  // Quersumme eingeben
  printf ("Bitte Zahl eingeben: "); 
  scanf ("%d", &in_zahl); 
  fflush(stdin);
  // Quersumme berechnen
  out_qersumme = quersumme(in_zahl);
  // Quersumme ausgeben 
  printf ("Die Quersumme von %d ist %d\n", in_zahl, out_qersumme); 

  return (0); 
}