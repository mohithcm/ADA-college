#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define X 2

int eval(int arr[], int x, int size){
	int power = 1, i, count = 0;
	double ans = arr[0];
	for (i = 1; i<size; i++){
		power *= x;
		ans += arr[i]*power;
		count ++;
	}
	return count;
}

void main(){
	FILE *fc, *fr;
	int n , *arr, i;
	system("rm Expo.txt");
	system("rm Count.txt");
	
	fc = fopen("Count.txt", "a");
	fr = fopen("Expo.txt", "a");
	
	for (n = 100; n<=1000; n+=100){
		arr = (int *)malloc(n*sizeof(int));
		for (i = 0; i<n; i++){
			arr[i] = i+1;
			fprintf(fr, "%d  ", arr[i]);
		}
		fprintf(fc, "%d  %d\n", n, eval(arr, X, n));
	}
	fclose(fc);
	fclose(fr);
}
