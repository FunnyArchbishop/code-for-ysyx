#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*int Get1Number(int m) {
	return abs(m % 10);
}

int Get10Number(int m) {
	return Get1Number(m/10);
}*/

int main() {
	int x;
	scanf("%d",&x);
//	printf("The 1 Number: %d\nThe 10 Number: %d\n",Get1Number(x),Get10Number(x));
	printf("The 1 Number: %d\nThe 10 Number: %d\n",abs(x % 10),abs((x/10) % 10));
	return 0;
} 
