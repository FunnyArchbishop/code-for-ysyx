#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#ifndef N
#define N 9
#endif

int a[N];

void init() {
	for(int i = 0; i < N; i++)
		a[i] = i + 1;
}

int allpermu() {
	int i, j, k, t;
	for(i = 0; i < N; i++)
		printf("%d ", a[i]);
	printf("\n");
	k = N - 1;
	while(k > 0 && a[k - 1] >= a[k]) k--; // Êý×ÖµÄ½Ç¶È 
	if(k == 0) return 0;
	j = N - 1;
	while(a[k - 1] >= a[j]) j--;
	t = a[k - 1]; a[k - 1] = a[j]; a[j] = t;
	i = N - 1; j = k;
	while(i > j) {
		t = a[i]; a[i] = a[j]; a[j] = t;
		i--; j++;
	}
	return allpermu();
}

int main() {
	init();
	allpermu();
	return 0;
}
