#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#define MAX 10
#define TIMES 20

int main() {
	srand(time(NULL));
	int a[MAX] = {0};
	int max_a = 0;
	for(int i = 0;i < TIMES; i++) {
		int r = rand() % MAX;
		++a[r];
		if(a[r] > max_a) max_a = a[r];
	}
	printf("0 1 2 3 4 5 6 7 8 9");
	for(int j = 0; j < max_a; j++) {
		printf("\n");
		for(int i = 0;i < MAX; i++) {
			if(a[i]) {
				printf("* ");
				a[i]--;
			} else {
				printf("  ");
			}
		}
	}
	system("pause");
	return 0;
} 
