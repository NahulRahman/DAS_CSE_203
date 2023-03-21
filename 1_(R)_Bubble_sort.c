bubble_sort.c
#include <stdio.h>
#define SIZE 5
void BubbleSort(int [ ]);

int main() {
int a[SIZE]= {2, 1, 5, 3, 2};
int i;
printf("The elements of the array before sorting\n");
for (i=0; i < SIZE; i++)
		printf("%4d", a[i]);
BubbleSort(a);
printf("\n\nThe elements of the array after sorting\n");
for (i=0; i< SIZE; i++)
		printf("%4d", a[i]);
return 0;
}


void BubbleSort(int A[ ]) {
int i, pass, temp;
for (pass=1; pass < SIZE; pass++)
for (i=0; i < SIZE-1; i++)
if(A[i] > A[i+1]){
temp = A[i];
A[i] = A[i+1];
A[i+1] = temp;
}
}
