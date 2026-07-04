#define NDEBUG
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define LEN 8
int a[LEN] = { 1, 2, 2, 2, 5, 6, 8, 9 };

int is_sorted(void)
{
	int i;
	for (i = 1; i < LEN; i++)
		if (a[i-1] > a[i])
			return 0;
	return 1;
}

int mustbe(int start, int end, int number)
{
	int i;
	for (i = 0; i < start; i++)
		if (a[i] == number)
			return 0;
	for (i = end+1; i < LEN; i++)
		if (a[i] == number)
			return 0;
	return 1;
}

int contains(int n)
{
	int i;
	for (i = 0; i < LEN; i++)
		if (a[i] == n)
			return 1;
	return 0;
}

int binary_search(int number)
{
    int mid;

    assert(is_sorted());
    for(int start = 0, end = LEN - 1; start <= end; ) {
        assert(mustbe(start, end, number));
        mid = (start + end) / 2;
        if(a[mid] == number) {
            assert(mid >= start && mid <= end && a[mid] == number);
            return mid;
        } else if(a[mid] < number) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    assert(!contains(number));
    return -1;
}

double mysqrt(double y)
{


    
    return 0
}

int main()
{
    printf("%d\n", binary_search(2));
    return 0;
}