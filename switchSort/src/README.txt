How to run:
1) to compile: javac Main.java
2) to run: java Main [input array]

Exercise description:
This exercise takes an array input and counts the least expensive cost to sort the array in ascending order. The sorting rule is as follows:
	Given an element A[i], it can switch its position with an element A[i] spots to its right or A[i] spots to its left. (If A[i] spots exceeds index boundaries, circle it back into boundary)
EXAMPLE:
input: 3, 1, 2
output: 2
explanation:
3, 1, 2 --> move 1 left by 1 spot (switch with 3)
1, 3, 2 --> move 2 right by 2 spots (switch with 3)
1, 2, 3 --> sorted with a total of 2 moves. 
