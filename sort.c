/*
▀ ▁ ▂ ▃ ▄ ▅ ▆ ▇ █ ▉ ▊ ▋ ▌ ▍ ▎ ▏ ▐ ░ ▒ ▓ ▔ ▕ ▖ ▗ ▘ ▙ ▚ ▛ ▜ ▝ ▞ ▟

{4,2,1,1,1,2,6,4,3,2}
      ▐   
      ▐   
▐     ▐▐  
▐     ▐▐▐ 
▐▐   ▐▐▐▐▐
▐▐▐▐▐▐▐▐▐▐
{4,2,1,1,1,2,6,4,3,2}

*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// COLORS
#define KNRM  "\x1B[0m" // NORMAL
#define KRED  "\x1B[31m"// RED
#define KGRN  "\x1B[32m"// GREEN
#define KYEL  "\x1B[33m"// YELLOW
#define KBLU  "\x1B[34m"// BLUE
#define KMAG  "\x1B[35m"// MAGENTA
#define KCYN  "\x1B[36m"// CYAN
#define KWHT  "\x1B[37m"// WHITE

void drawGraph( int *arr, int size, int hv, int active){
   
   //int valueCount = sizeof(arr) / sizeof(arr[0]);
    int valueCount = size;
   int highestValue = hv;
   
   // define system commands 
   char command[50];
   strcpy( command, "clear" );
   
   // Lines
   for (int i = highestValue; i > 0; i--){
       // Rows
       for (int j = 0; j < valueCount; j++){
           
           if ( arr[j] >= i ){
               if (active == j){
                 printf("%s▐  %s", KRED, KNRM);  
               }else{
                 printf("▐  ");  
               }
               
           }else{
               printf("   ");
           }
       }
       printf("\n");  
   }
   // print array values    
   for (int i = 0; i < valueCount; i++ ){
      if ( arr[i] >= 10 ){
         printf("%d ", arr[i]);       
      }else{
         printf("%d  ", arr[i]);        
      }
   }
   printf("\n");
   
   //usleep(50000);
   //system(command);
}

int compare( const void* a, const void* b)
{
     int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );

     if ( int_a == int_b ) return 0;
     else if ( int_a < int_b ) return -1;
     else return 1;
}

 void bubblesort(int *array, int length)
 {
     char command[50];
     strcpy( command, "clear" );
     
     int i, j;
     for (i = 0; i < length - 1; ++i) {

        for (j = 0; j < length - i - 1; ++j) {
            
            if (array[j] > array[j + 1]){
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
                drawGraph(array, 30, 30, j + 1);
                usleep(100000);
                    if (!(j < length - i - 1)) {
                        system(command);
                    }
            }
        }
     }
 }

int main(){
  // 
  //int values[] = {4,2,1,1,1,2,6,4,3,2};
  
  // NOT SORTED
  int values[] = {25,4,8,11,17,13,6,20,10,29,12,23,2,15,3,7,1,19,18,16,14,9,5,30,22,27,21,24,28,26};
  drawGraph(values, 30, 30, 0);
  
  // SORTED
  //qsort(values, sizeof(values) / sizeof(values[0]), sizeof(int), compare);
  bubblesort(values, 30);
  //drawGraph(values, 30, 30);
  return 0;
}