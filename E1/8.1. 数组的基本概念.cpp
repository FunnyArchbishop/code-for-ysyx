#include<stdio.h>
int main() {
	int copying[42] = {0};
	int copied[42] = {0,7,2,1,1,1,4,5,1,4,1,0,2,7,4,2,33550336};
	for(int i = 0; i < 42;i ++) 
		copying[i] = copied[i];
	return 0;
} 
