/*
ein x mit gewünschten zeilen auf der console ausgeben.
x    x
 x  x
  x
 x  x
x    x
*/
#include <errno.h>
#include <stdio.h>
#include <stddef.h>

// funktion zur geprüften eingabe einer zahl
/*
Allows
- leading spaces : " 123"
- trailing spaces : "123 "
- leading zeros : "0000000000000000000000000000000000123"
- Rescans nicely after error input.
Catches the following errors
- No input : ""
- Extra text after the number: "123 abc"
- Text before the number : "abc 123"
- Split number : "123 456"
- Overflow/underflow : "12345678901234567890"
- other : "--123"
Re-prompts on invalid input.
*/ 
int GetInteger(const char *prompt, int *i) {
  int Invalid = 0;
  int EndIndex;
  char buffer[100];
  do {
    if (Invalid)
      fputs("Falsche Eingabe! \n", stdout);
    Invalid = 1;
    fputs(prompt, stdout);
    if (NULL == fgets(buffer, sizeof(buffer), stdin))
      return 1;
    errno = 0;
  } while ((1 != sscanf(buffer, "%d %n", i, &EndIndex)) || buffer[EndIndex] || errno);
  return 0;
}

// zeichne ein X mit beliebiger Größe 
int main(){
    int zeilen = 5;
    GetInteger("Bitte Anzahl der Zeilen für die Größe des X eingeben: ", &zeilen);
    if (zeilen > 1000){printf("Zahl zu Groß, Abbruch.\n"); return 0;}
    // zeile
    for (int z = 1; z <= zeilen; z++){
        // spalte
        for (int s = 1; s <= zeilen; s++){
            if (z == s ||  s == zeilen - z + 1){
               printf("x"); 
            }else{
               printf(" ");  
            }
        }
        printf("\n");    
    }
    return 0;
}