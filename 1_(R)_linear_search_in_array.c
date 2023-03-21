#include <stdio.h>
#define SIZE 10
int LinearSearch(int [], int);
int main() {
int a[SIZE]= {9, 4, 5, 1, 7, 78, 22, 15, 96, 45};
int key, pos;
printf("Enter the Search Key\n");
scanf("%d", &key);
pos = LinearSearch(a, key);
if(pos==-1)
printf("The search key is not in the array\n");
else
printf("The search key %d is at location %d\n", key, pos+1);
return 0;
}


int LinearSearch (int b[ ], int skey) {
int i;

for (i=0; i < SIZE; i++)
{
    if(b[i]==skey)
        return i;

}

    return -1;

}
