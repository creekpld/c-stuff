/*
some useful unicode/utf8
▀ ▁ ▂ ▃ ▄ ▅ ▆ ▇ █ ▉ ▊ ▋ ▌ ▍ ▎ ▏ ▐ ░ ▒ ▓ ▔ ▕ ▖ ▗ ▘ ▙ ▚ ▛ ▜ ▝ ▞ ▟

the prototype
            ▐   
            ▐   
▐           ▐ ▐  
▐           ▐ ▐ ▐ 
▐ ▐       ▐ ▐ ▐ ▐ ▐
▐ ▐ ▐ ▐ ▐ ▐ ▐ ▐ ▐ ▐
4 2 1 1 1 2 6 4 3 2
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

/// Draws a Array of Integers as a Bargraph  ( UTF-8 capable Console Required! )
/// takes (Array of Integers 'arr', int 'size' (Number of Elements in Array), 
/// int 'hv' HighestValue in Array(0-99), int 'active' Row in Array (marked RED in Bargraph))
void drawGraph( int *arr, int size, int hv, int active){

   // Lines
   for (int i = hv; i > 0; i--){
       // Rows
       for (int j = 0; j < size; j++){
           
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
   for (int i = 0; i < size; i++ ){
      if ( arr[i] >= 10 ){
         printf("%d ", arr[i]);       
      }else{
         printf("%d  ", arr[i]);        
      }
   }
   printf("\n");
}

// compare function of cocktailsort
int compare( const void* a, const void* b)
{
     int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );

     if ( int_a == int_b ) return 0;
     else if ( int_a < int_b ) return -1;
     else return 1;
}
 
 // can be any swap function. This swap is optimized for numbers.
void swap(int *x, int *y) {
	if(x == y)
		return;
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
}
 // Cocktailsorts an Array of Integers 
 void cocktailsort(int *array, size_t n) {
     
     // ivars for Graph drawing
     char command[50];
     strcpy( command, "clear" );
     
	while(1) {
		// packing two similar loops into one
		char flag;
		size_t start[2] = {1, n - 1},
			   end[2] = {n, 0},
			   inc[2] = {1, -1};
		for(int it = 0; it < 2; ++it) {
			flag = 1;
			for(int i = start[it]; i != end[it]; i += inc[it]){
				if(array[i - 1] > array[i]) {
					swap(array + i - 1, array + i);
                    
                    if (it == 0){// draw Graph with Active Colum sorting to the Right
                        drawGraph(array, 30, 30, i);
                        usleep(100000);
                    }else{// draw Graph with Active Colum sorting to the Left
                        drawGraph(array, 30, 30, i - 1);
                        usleep(100000);
                    }
                    if(array[i - 1] > array[i]) system(command); // clear the console
                       
					flag = 0;
				}

            }
			if(flag) return;
		}
	}
}

int main(){

  // create an array of values
  int values[] = {25,4,8,11,17,13,6,20,10,29,12,23,2,15,3,7,1,19,18,16,14,9,5,30,22,27,21,24,28,26};
  drawGraph(values, 30, 30, 0);// draw the unsorted graph first

  // wait for user to start the sorting
  printf("Press a Key to start Sorting\n");
  getchar();

  // start sorting
  cocktailsort(values, 30);

  //end
  return 0;
}