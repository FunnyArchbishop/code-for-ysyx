#include<stdio.h>
int main() {
	int i = 0;
	for(i = 0;i<=100;++i){
		//TODO
		continue;
	}
	printf("%d\n",i);
	
	i = 0;
	while(i <= 100) {
		i++;
		continue;
	}
	printf("%d\n",i);
	i = 0;
	while(i <= 100) {
		continue;
		i++;
	}
	printf("%d\n",i);
	return 0;
}
