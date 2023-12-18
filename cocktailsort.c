/*
Cocktailsort
*/

#include <stdio.h>

 // can be any swap function. This swap is optimized for numbers.
void swap(int *x, int *y) {
	if(x == y)
		return;
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
}
 // Cocktailsort
 void cocktailsort(int *array, size_t n) {
	while(1) {
		// packing two similar loops into one
		char flag;
		size_t start[2] = {1, n - 1},
			   end[2] = {n, 0},
			   inc[2] = {1, -1};
		for(int it = 0; it < 2; ++it) {
			flag = 1;
			for(int i = start[it]; i != end[it]; i += inc[it])
				if(array[i - 1] > array[i]) {
					swap(array + i - 1, array + i);
					flag = 0;
				}
			if(flag)
				return;
		}
	}
}

int main(){


  return 0;
}