import java.util.*;


public class Main {
	static int MAX_INT = 2147483646;
	public static void main(String[] args) {
		//get input of random numbers and put into array
		
		int n = args.length;
		int[] arr = new int[n];
		for (int i = 0 ; i < n; i ++) {
			arr[i] = Integer.parseInt(args[i]);
		}
		
		//int[] arr = {5,3,1,2,4};
		
		int count = switchSort(arr, arr.length*2, 0);
		System.out.println(count);
		
		
				
	}
	public static int[] swappedArray(int[] arr, int i, int j) {
		//System.out.printf("Switching indexes %d (%d) and %d (%d)\n", i, arr[i], j, arr[j]);
		int[] newArr = new int[arr.length];
		for (int x = 0; x< arr.length; x++) {
			if (x == i) {
				newArr[i] = arr[j];
			}
			else if (x ==j) {
				newArr[j] = arr[i];
			}
			else {
				newArr[x] = arr[x];
			}
		}
		return newArr;
		
	}
	public static int switchSort(int[] arr, int min, int level) {
		//printArr(arr);
		if (isSorted(arr)) {
			//System.out.println("Sorted! Level: " + level);
			return 0; //no more switches 
		}
		else {//still unsorted 
			int temp = MAX_INT;
			for (int i = 0 ; i < arr.length ; i ++) {//elements in array
				if (arr[i] % arr.length != 0) {//otherwise arr[i] will be switching with itself
					//go right arr[i] steps
					int right = (arr[i] + i) % arr.length;//new index
					int[] rightSwitch = swappedArray(arr, i, right);//local array
					//go left arr[i] steps
					int left = Math.floorMod(i-arr[i], arr.length);//new index 2 
					int[] leftSwitch = swappedArray(arr,i, left);//local array 2
					
					//recursion
					if (0 < min) {//
						min --;
						//System.out.print("Moving " + arr[i] + " Left --> ");
						int L = switchSort(leftSwitch, min, level+1) + 1; 
						temp = Math.min(L, temp);
						//System.out.print("Moving " + arr[i] + " Right --> ");
						int R = switchSort(rightSwitch, min, level+1) + 1;
						temp =  Math.min(temp, R);
					}
					//else stop going down this lane cus it might be endless
					
				}
			}
			return temp;
		}
	}
	
	public static void printArr(int[] arr) {
		for (int i = 0 ; i < arr.length; i ++) {
			System.out.print(arr[i] + ", ");
		}
		System.out.println();
	}
	
	public static boolean isSorted(int[] arr) {
		for (int i = 0 ; i < arr.length - 1 ; i++) {
			if (arr[i] > arr[i+1]) {
				return false;
			}
		}
		return true;
	}

}
