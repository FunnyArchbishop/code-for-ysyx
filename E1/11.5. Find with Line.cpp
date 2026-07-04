#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<ios>

int a[8] = {23, 45, 12, 67, 34, 89, 90, 11};
// #define TWO
#ifdef TWO
int main()
{
    srand((unsigned)time(NULL));
    int a[10], n = 0,m = 0;
    for(int i=0;i<10;i++) {
        a[i]=rand()%100;
        if(a[i] > n) n=a[i];
        else if(a[i] > m) m=a[i];
    }
    for(int i=0;i<10;i++) printf("%d ",a[i]);
    printf("\n%d\n",m);
    return 0;
} 
#endif

#define THREE
#ifdef THREE
int partition(int start, int end)
{
	int pivot = a[start];
	for(int i = start + 1; i <= end; i++) {
		if(a[i] < pivot) {
			int temp = a[i];
			for(int j = i; j > start; j--) {
				a[j] = a[j-1];
			}	//将a[start..i-1]向后移动一位
			a[start] = temp;
			start++;
		}
	}
	return start;
	/*从a[start..end]中选取一个pivot元素（比如选a[start]为pivot）;
	在一个循环中移动a[start..end]的数据，将a[start..end]分成两半，
	使a[start..mid-1]比pivot元素小，a[mid+1..end]比pivot元素大，而a[mid]就是pivot元素;
	return mid;*/
}
int order_statistic(int start, int end, int k)
{
    int mid = partition(start, end);
    if(mid == k) return a[mid];
    else if(mid > k) return order_statistic(start, mid-1, k);
    else return order_statistic(mid+1, end, k);
}

int main() 
{
    int k;
    scanf("%d", &k);
    printf("The %d-th smallest element is %d\n", k, order_statistic(0, 7, k-1));
    // printf("CIALLO\n");
    return 0;
}
#endif