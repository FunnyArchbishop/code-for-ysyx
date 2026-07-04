// #define NDEBUG
#include<stdio.h>
#include<stdlib.h>

#define LEN 8
int a[LEN] =  {1,2,2,2,5,6,7,8};

int binary_search(int number)
{
    int mid, start = 0, end = LEN - 1;
    
    while (start <= end) {
        mid = (start + end) / 2;
        if (a[mid] == number)
            start = mid + 1;
        else if (a[mid] < number)
            end = mid - 1;
        else
            return mid;
    }
    return -1;
}
int main()
{
    int number;
    scanf("%d", &number);
    int pos = binary_search(number);
    if (pos != -1)
        printf("The first element greater than %d is %d\n", number, a[pos]);
    else
        printf("No element greater than %d\n", number); 
    return 0;
}