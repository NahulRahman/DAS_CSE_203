array_avg_user_input.c
#include<stdio.h>

int main()
{
    int n, sum=0;
    float avg;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("\nEnter %d values: ", n);
    for(int i=0; i<n;i++)
    {
        scanf("%d", &arr[i]);
        sum+=arr[i];
    }
    avg=(float)sum/n;

    printf("\nAvg is: %.2f", avg);
}
