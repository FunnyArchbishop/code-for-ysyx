#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void increment_True(int &x) {
	x += 1;
}

void increment(int x) {
	x += 1;
}

int main() {
	int x;
	scanf("%d",&x);
	increment(x);
	printf("%d\n",x);
	increment_True(x);
	printf("%d\n",x);
	return 0;
}
