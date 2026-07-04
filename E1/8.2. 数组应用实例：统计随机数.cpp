#include <stdio.h>
#include <stdlib.h>
#define N 20

int a[N];

void gen_random(int lower_bound,int upper_bound) {
	int i;
	for (i = 0; i < N; i++)
		a[i] = rand() % (upper_bound - lower_bound) + lower_bound;
}

void print_random() {
	int i;
	for (i = 0; i < N; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main() {
	gen_random(10,20);
	print_random();
	return 0;
}
