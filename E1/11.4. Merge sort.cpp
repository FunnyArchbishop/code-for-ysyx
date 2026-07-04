#include <stdio.h>

#define LEN 8
int a[LEN] = { 5, 2, 4, 7, 1, 3, 2, 6 };

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

void quicksort(int start, int end)
{
	int mid;
	if (end > start) {
		mid = partition(start, end);
		quicksort(start, mid-1);
		quicksort(mid+1, end);
	}
}

void merge(int start, int mid, int end)
{
	int n1 = mid - start + 1;
	int n2 = end - mid;
	int left[n1], right[n2];
	int i, j, k;

	for (i = 0; i < n1; i++) /* left holds a[start..mid] */
		left[i] = a[start+i];
	for (j = 0; j < n2; j++) /* right holds a[mid+1..end] */
		right[j] = a[mid+1+j];

	i = j = 0;
	k = start;
	while (i < n1 && j < n2)
		if (left[i] < right[j])
			a[k++] = left[i++];
		else
			a[k++] = right[j++];

	while (i < n1) /* left[] is not exhausted */
		a[k++] = left[i++];
	while (j < n2) /* right[] is not exhausted */
		a[k++] = right[j++];
}

void sort(int start, int end)
{
	int mid;
	if (start < end) {
		mid = (start + end) / 2;
		printf("sort (%d-%d, %d-%d) %d %d %d %d %d %d %d %d\n", 
		       start, mid, mid+1, end, 
		       a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
		sort(start, mid);
		sort(mid+1, end);
		merge(start, mid, end);
		printf("merge (%d-%d, %d-%d) to %d %d %d %d %d %d %d %d\n", 
		       start, mid, mid+1, end, 
		       a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
	}
}

// #define MERGE
#ifdef MERGE
int main(void)
{
	sort(0, LEN-1);
	return 0;
}
#endif

#define QUICK
#ifdef QUICK
int main(void)
{
	quicksort(0, LEN-1);
	for(int i = 0; i < LEN; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
#endif

