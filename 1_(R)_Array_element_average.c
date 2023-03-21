Array_element_avg.c
#include<stdio.h>
#define SIZE 10
int main() {
int x[10] = {4, 3, 7, -1, 7, 2, 0, 4, 2, 13};
int i, sum=0;
float av;
for(i=0; i<SIZE; i++)
sum = sum + x[i];
av = (float)sum / SIZE;
printf("The average of the numbers = %.2f\n", av);
return 0;
}
