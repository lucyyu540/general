
/*
compile:
gcc -Wall -std=c99 -o general general.c
run:
./general [input]

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
void f4();
int f4recursive(int, int*);
int f4dynamic(int, int*);
void f5(int, int *);

int main(int argc, char * argv[]) {
	int c = argc-1;
	int numbers[c];
	for (int i = 0 ; i < c ; i++) {
		numbers[i] = atoi(argv[i+1]);
	}
	//most frequently occurring integer in an array
	f1(c, numbers);
	//find pairs in integer array whose sum = 10
	f2(c, numbers);
	//given 2 inteeger arrays, determine if the 2nd array is a rotated version of the 1st
	f3(c, numbers);
	//fibbonaci
	f4();
	//the only elements in an array that only occurs once
	f5(c , numbers);

}

void f1(int c, int * numbers) {
	int freq[c];
	for (int i = 0 ; i < c ; i ++) {
		int repeated = 0;
		for (int j = 0 ; j < i; j ++) {
			if (numbers[i] == numbers[j]) { //integer repeated
				freq[j] += 1;
				repeated = 1;
				break;
			}
		}
		if (!repeated) { //integer's first occurrence
			freq[i] = 1;
		}
	}
	//finding the max frequency count
	int maxInd = 0;
	for (int i = 0 ; i < c ; i ++) {
		if (freq[i] > freq[maxInd]) {
			maxInd = i;
		}
	}
	int max = numbers[maxInd];
	printf("The most frequently occurring integer is: %d at index %d\n", max, maxInd);
}

void f2(int c, int * numbers) {
	/**
	O(n^2)

	printf("O(n^2): Pairs that sum up to 10:\n");
	for (int i = 0; i < c; i ++) {
		if (i < c-1) {
			for (int j = i+1; j < c ; j ++) {
				if (numbers[i] + numbers[j] == 10) {
					printf("(%d, %d) at indices (%d, %d)\n", numbers[i], numbers[j], i , j);
				}
			}
		}
	}
	*/
	printf("O(n): Pairs that sum up to 10:\n");
	int min = 0;
	int max = 0;
	for (int i = 1 ; i < c ; i ++) {
		if (numbers[i] < numbers[min]) {
			min = i;
		}
		else if (numbers[i] > numbers[max]) {
			max = i;
		}
	}
	int * bucket = (int *) malloc((numbers[max] - numbers[min] + 1) * sizeof(int));
	for (int i = 0 ; i < c; i ++) {
		int num = numbers[i];
		int index;
		if (numbers[min] < 0) {
			index = num - numbers[min];
		}
		else {
			index = num + numbers[min];
		}
		bucket[index] = 1;
	}

	int set[c]; //ordered and without repeats
	int j = 0;
	for (int i = 0 ; i < numbers[max] - numbers[min] + 1 ; i ++) {
		if (bucket[i] == 1) {
			if (numbers[min] < 0) {
				set[j] = i + numbers[min];
			}
			else {
				set[j] = i - numbers[min];

			}
			j += 1;
		}
	}

	int start = 0;
	int end = j-1;
	while (start < end) {
		int m = set[start];
		int n = set[end];
		if (10 - m == n) {
			printf("(%d, %d)\n", m, n);
			start ++;
			end --;
		}
		else if (10 - m < n) {
			end --;
		}

		else if (10 - m > n) {
			start ++;
		}
	}

}

void f3(int c, int * numbers) {
	int n;
	int rotated[c];
	int i = 0;
	printf("Input second array of numbers\n");
	while (scanf(" %d" , &n) == 1) {
		if (i >= c) {
			printf("Not a rotational array\n");
			break;
		}
		rotated[i] = n;
		i ++;
		if ( getchar() == '\n') {
			if (i != c) {
				printf("Not a rotational array\n");
			}
			break;
		}
	}
	for (i = 0 ; i < c; i ++) {
		if (numbers[0] == rotated[i]) {
			for (int j = 0 ; j < c ; j ++) {
				int index = i + j;
				if (index > c - 1) {
					index = index - c;
				}
				if (numbers[j] != rotated[index]) {
					break;
				}
				if (j == c-1) {
					printf("Rotational array!\n");
					break;
				}

			}

		}

	}

}

void f4() {
	int n;
	printf("Enter number of Fibbonaci numbers: \n");
	scanf("%d" , &n);
	int * seq = (int * ) malloc( n * sizeof(int));
	for (int i = 0 ; i < n ; i ++) {
		seq[i] = -1;
	}
	//dynamic
	f4dynamic(n-1, seq);
	printf("Dynamic - Fibonacci sequence: ");
	for (int i = 0 ; i < n ; i ++) {
		printf("%d * ", seq[i]);
	}
	printf("\n");


	//recursive
	f4recursive(n-1, seq);
	printf("Recursive - Fibonacci sequence: ");
	for (int i = 0 ; i < n ; i ++) {
		printf("%d * ", seq[i]);
	}
	printf("\n");


	//iterative
	for (int i = 0 ; i < n ; i ++) {
		if (i == 0) {
			seq[i] = 1;
		}
		else if (i == 1) {
			seq[i] = 1;
		}
		else {
			seq[i] = seq[i-1] + seq[i-2];
		}
	}	
}
int f4dynamic(int i, int * seq) {
	if (seq[i] == -1) {
		if ( i == 0 ) {
			seq[i] = 1;
		}
		else if ( i == 1) {
			seq[i] = 1;
		}
		else {
			seq[i] = f4dynamic(i -1, seq) + f4dynamic(i-2, seq);

		}
		return seq[i];
	}
	else {
		return seq[i];
	}
	
}
int f4recursive(int i, int * seq) {
	if (i == 0 ) {
		seq[i] = 1;
	}
	else if (i == 1) {
		seq[i] = 1;
	}
	else {
		seq[i] = f4recursive(i - 1, seq) + f4recursive(i-2, seq);
	}
	return seq[i];
}



void f5(int c, int * numbers) {
	int minInd = 0;
	int maxInd = 0;
	for (int i = 0 ; i < c ; i ++) {
		if (numbers[i] > numbers[maxInd]) {
			maxInd = i;
		}
		else if (numbers[i] < numbers[minInd]) {
			minInd = i;
		}
	}
	int * neg;
	int * pos;
	if (numbers[minInd] < 0) {
		neg = (int * ) calloc((numbers[minInd] * -1 + 1), sizeof(int));
	}
	pos = (int * ) calloc ((numbers[maxInd] + 1), sizeof(int));

	for (int i = 0 ; i < c ; i ++) {
		int num = numbers[i];
		if (num < 0) {
			neg[num*-1] += 1;
		}
		else {
			pos[num] += 1;
		}
	}
	printf("Numbers that only occur once: ");
	for (int i = 0 ; i < (numbers[minInd] * -1 + 1) ; i ++) {
		if (neg[i] == 1) {
			printf("%d, ", i*-1);
		}
	}
	for (int i = 0 ; i < (numbers[maxInd] + 1) ; i ++) {
		if (pos[i] == 1) {
			printf("%d, ", i);
		}
	}
	printf("\n");


	
}
