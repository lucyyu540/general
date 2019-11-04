/*
compile:
gcc -Wall -std=c99 -o sorting sorting.c
run:
./sorting num [input]

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
//function declarations
void f1(int, int *);
void f2(int, int *);
void f3(int, int *);
void f4(int, int *);
void mergeSort(int, int, int*);
void merge(int, int, int, int, int *);
void f5(int, int *);
void QuickSort(int, int, int*);
int Partition(int, int, int *);

int main(int argc, char * argv[]) {
	int option;
	if (argc < 3) {
		printf("Usage: sorting num [input]\n" );
		printf("num: 1, 2, 3, 4 or 5\n" );
		exit(1);
	}
	option = atoi(argv[1]);
	int size = argc-2;
	int array[size];
	printf("Original input: ");
	for (int i = 0 ; i < size ; i ++) {
		array[i] = atoi(argv[i+2]);
		printf("%d ", array[i]);
	}
	printf("\n");

	switch (option) {
		case 1: // bubble 
			f1(size, array);
		case 2: //selection
			f2(size, array);
		case 3: //insertion
			f3(size, array);

		case 4: //merge
			f4(size, array);
		case 5: //quick
			f5(size, array);


	}
	printf("Sorted output: ");
	for (int i = 0 ; i < size ; i ++) {
		printf("%d ", array[i]);
	}
	printf("\n");

}

void f1(int size, int * array) {
	for (int i = 0 ; i < size-1; i ++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (array[j] > array[j+1]) {
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}

void f2(int size, int * array) {
	for (int i = 0 ; i < size; i++) {
		//find the next min each iteration
		int smallest = array[i];
		for (int j = i; j < size ; j++) {
			if (array[j] < smallest) {
				smallest = array[j];
				array[j] = array[i];
				array[i] = smallest;
				
			}
		}
	}
}

void f3(int size, int * array) {
	//[0---unsorted-1][unsorted -----size-1]
	for (int i = 1 ; i < size; i ++) {
		//searching for a number smaller than array[i]
		int placement = 0;
		while (placement < i) {
			if (array[placement] < array[i]) {
				break;
			}
			placement ++;
		}
		//place it at appr index and shift all elements to the right 
		int temp = array[i];
		for (int j = i; j > placement; j--){
			array[j] = array[j-1];
		}
		array[placement] = temp;	
	}
}

void f4(int size, int * array) {
	mergeSort(0, size-1, array);


}

void mergeSort(int start, int end, int * A) {
	if (start == end) {
		
	}
	else {
		//split the array into halfs
		int mid = (start+ end)/2;
		
		mergeSort(start, mid, A);//first half
		mergeSort(mid+1, end, A);//second half
		merge(start, mid, mid+1, end, A);
	}
}

void merge(int f, int fe, int s, int se, int * A) {
	int temp[se-f+1];
	for (int i = 0; i < se-f+1; i++) {
		temp[i] = A[i+f];
	}
	int start = f;
	int ind = f;
	while (f <= fe || s <= se ) {
		if (f > fe) {
			A[ind] = temp[s-start];
			s++;
		}
		else if( s > se) {
			A[ind] = temp[f - start];
			f++;
		}
		else if(temp[f-start] < temp[s-start]) {
			A[ind] = temp[f-start];
			f++;
		}
		else {
			A[ind] = temp[s-start];
			s++;
		}
		ind++;
	}

}

void f5(int size, int * array) {
	QuickSort(0, size-1, array);
}

void QuickSort(int start, int end, int * array) {
	if (start < end) {
		int pivot = Partition(start, end, array);
		QuickSort(start, pivot - 1, array);// left of pivot
		QuickSort(pivot + 1, end, array); //right of pivot 
	}
}

int Partition (int start, int end, int * array) {
	int pivot = start;
	while(start < end) {
		while( array[start] <= array[pivot]) {
			start++;
		}
		while( array[end] > array[pivot]) {
			end --;
		}
		if (start < end) {
			int temp = array[start];
			array[start] = array[end];
			array[end] = temp;
		}
	}
	int temp = array[pivot];
	array[pivot] = array[end];
	array[end] = temp;
	pivot = end;
	return pivot;
}
