#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>

#define N 100

int swap(int &a, int &b)
{
    int _a = a;
    int _b = b;
    a = _b;
    b = _a;
    return 0;
}

int main()
{
    int a[N] = {0};
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; ++i) {
		scanf("%d",&a[i]);
	}
    for(int i = 0; i < n; i++) 
        for(int j = i; j > 0 && a[j] < a[j - 1] ; j--) 
            swap(a[j],a[j - 1]);
    for(int i = 0; i < n; i++) printf("%d ",a[i]);
    return 0;
}
