#include<stdio.h>
#include<stdlib.h>
#include<math.h>



int main() {
	int x = -10, y = 12, z = 0; 
	//1¡¢
	//orginal:
	if (x > 0 && x < 10);
	else
		printf("x is out of range.\n");
		
	//change:
	if(x <= 0 || x >= 10) printf("x is out of range.\n");
	
	//2¡¢
	//orginal:
	if (x > 0)
		printf("Test OK!\n");
	else if (x <= 0 && y > 0)
		printf("Test OK!\n");
	else
		printf("Test failed!\n");
	
	//change:
	if(y <= 0 && x <= 0) printf("Test failed!\n");
	else	printf("Test OK!\n");
		
	//4¡¢ 
	
	if (x<3 && y>3)
		printf("Test OK!\n");
	else if (y==3)
		printf("Test OK!\n");
	else if (z>3 && x>=3)
		printf("Test OK!\n");
	else if (z<=3 && y>=3)
		printf("Test OK!\n");
	else
		printf("Test failed!\n");
	
	return 0;
}
