/*
compile:
gcc -Wall -std=c99 -o general1 general1.c
run:
./general1 [input]

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

//function declarations
void f1(int, int *);
void f2(int, int *);
void f3(int, int *);
void f4();
void f5();
void mergeSort(int, int, int*);
void merge(int, int, int, int, int *);
void BS(int, int, int, int * );
void rotateArray(int, int *);
void findPivot(int *, int, int, int * );
void primeDP(int, int, int, int *);


int main(int argc, char * argv[]) {
	int c = argc-1;
	int numbers[c];
	for (int i = 0 ; i < c ; i++) {
		numbers[i] = atoi(argv[i+1]);
	}
	//common elements of 2 int arrays
	f1(c, numbers);
	//binary search sorted array
	f2(c, numbers);
	//binary sort rotated array
	f3(c, numbers);
	//find the first x prime numbers using dynamic programming
	f4();
	//print binary form of an int
	f5();


}

void f1(int c, int * numbers) {
	int n;
	int common[c];
	int ind = 0 ;
	printf("Input second array of numbers\n");
	while (scanf(" %d" , &n) == 1) {
		for (int i = 0 ; i < c; i ++) {
			if (n == numbers[i]) {
				int redundant = 0;//check for repeated common elm 
				for(int j = 0 ; j < c ; j ++) {
					if (n == common[j]) {
						redundant = 1;
						break;
					}
				}
				if (!redundant) {
					common[ind] = n;
					ind ++;
				}
				i = c; //common elm exists. stop checking. 
			}
		}
		if ( getchar() == '\n') {
			break;
		}
	}
	printf("Common elements: \n");
	for (int i = 0 ; i < ind ; i ++) {
		printf("%d ", common[i]);
	}
	printf(" \n");
}

void f2(int c, int * numbers) {
	mergeSort(0, c-1, numbers);// sort array
	printf("Sorted version of the array: ");
	for (int i = 0 ; i < c ; i ++) {
		printf("%d ", numbers[i]);
	}
	printf("\nBinary search for this number: \n");
	int n;
	scanf("%d" , &n);
	BS(n, 0, c-1, numbers);
}

void f3(int c, int * numbers) {
	rotateArray(c, numbers);
	printf("\nHere's a rotated version of the array: ");
	for (int i = 0 ; i < c; i ++) {
		printf("%d ", numbers[i]);
	}
	printf("\nBinary search for this number: \n");
	int n;
	scanf("%d" , &n);

	int pivot = 0;
	findPivot(&pivot, 1, c-1, numbers);
	printf("The pivot is: %d\n", pivot);
	if (n < numbers[c-1]) {
		BS(n, pivot, c-1, numbers);
	}
	else {
		BS(n, 0, pivot - 1, numbers);
	}
}

void f4() {
	int n;
	printf("The first x prime numbers. Enter x: \n");
	scanf("%d", &n);
	int R[n*n+1]; //list of all possible numbers
	int count = 0; 
	printf("The first %d prime numbers are:\n", n);
	primeDP(2, count, n, R);
}

void f5() {
	int n; 
	printf("Enter an integer: \n");
	scanf("%d", &n);
	printf("Integer in binary form: \n");
	int binary = 0;
	while (n > 1) {
		double digit = 0.0;
		int temp = n;
		while (temp > 1) {
			temp = temp/2;
			digit += 1;	
		}
		int subtractThis = pow(2.0, digit);
		n = n - subtractThis;
		binary = binary + pow(10.0, digit);
	}
	binary = binary + n; 
	printf("%d\n", binary);
	
	

}

void primeDP(int number, int count, int n, int * R) {
	if (count < n) {
		if (R[number] == -1) {// marked not prime

			primeDP(number+1, count, n, R);

		}
		else {//is prime 
			printf("%d\n", number);
			for (int i = number+1; i < n*n + 1; i++) {
				if ( i % number == 0) {//divisible by the num
					R[i] = -1;
				}
			}
			count ++;
			if (count < n) {
				primeDP(number+1, count, n, R);
			}

		}
	}

}

void BS(int n, int s, int e, int * A) {
	if (s > e) {
		printf("Number not found!\n");
	}
	else {
		int mid = (s+e)/2;
		if (n == A[mid]) {
			printf("Number found at index: %d\n", mid);
		}
		else if (n > A[mid]) {
			BS(n, mid+1, e, A);

		}
		else {
			BS(n, s, mid-1, A);
		}
	}
}

void findPivot(int * pivot, int s, int e, int *A) {
	//find the pivot
	if (s <= e) {
		int mid = (s+e)/2;
		if (A[mid] < A[mid-1]) {
			* pivot = mid; //found pivot stop searching 
		}
		else {//continue searching 
			findPivot(pivot, s, mid - 1, A);
			findPivot(pivot, mid+1, e, A);
		}
	}	
}

void rotateArray(int c, int * numbers) {
	mergeSort(0, c-1, numbers);//sort array
	printf("Sorted version of the array: ");
	for (int i = 0 ; i < c ; i ++) {
		printf("%d ", numbers[i]);
	}

	int pivot;
	//randomly pick pviot
	srand(time(0));
	pivot = (rand() % (c - 1)) + 1; // (random() % (upper - lower + 1)) + lower
	//saving temp
	int temp[pivot];
	for (int i = 0; i < pivot ; i ++) {
		temp[i] = numbers[i];
	}
	//shifting left
	int j = 0;
	for (int i = pivot; i < c ; i ++) {
		numbers[j] = numbers[i];
		j ++;
	}
	//inserting temp on right
	int k = 0; 
	for (int i = j; i < c ; i ++) {
		numbers[i] = temp[k];
		k++;
	}

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
