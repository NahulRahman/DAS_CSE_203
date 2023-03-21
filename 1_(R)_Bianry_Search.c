binay_search_in_array.c
#include <stdio.h>
#define SIZE 10
int BinarySearch(int [ ], int);
int main(){
int a[SIZE]= {3, 5, 9, 11, 15, 17, 22, 25, 37, 68};
int key, pos;
printf("Enter the Search Key\n");
scanf("%d",&key);
pos = BinarySearch(a, key);
if(pos == -1)
	printf("The search key is not in the array\n");
else
	printf("The search key %d is at location %d\n", key, pos+1);
return 0;
}


int BinarySearch (int A[], int skey){
    int low=0, high=SIZE-1, middle;
    while(low <= high){
    middle = (low+high)/2;
    if (skey == A[middle])
        return middle;
    else if(skey <A[middle])
        high = middle - 1;
    else
        low = middle + 1;
    }

return -1;
}
