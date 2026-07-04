#include<cstdio>
#include<cstdlib>
#include<cmath>

void diamond(int line,char word) {
	if(line % 2 == 0) exit(-1);
	char hollow = ' ';
	int MainPoint = (line + 1) / 2;
	for(int i = 1;i <= line;i++){
		for(int j = 1;j <= line; j++) {
			if(abs(MainPoint - i) + abs(MainPoint - j) < MainPoint) printf("%c",word);
			else printf("%c",hollow);
		}
		printf("\n");
	} 
}

int main() {
	for(int i = 1;i <= 10;i++){
		
		
		for(int j = 1;j <= i;j++){
			printf("%d	",i*j);
		}
		printf("\n");
	}
	printf("\n\n");
	diamond(3,'*');
	diamond(5,'+');
	return 0;
}
