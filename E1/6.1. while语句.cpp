#include<cstdio>
#include<ios>
#include<iostream>
using namespace std;
int main() {
	int i = 1,ans = 0;
	while(i <= 100) {
		if(i - i % 10 == 90) ans++;
		if(i % 10 == 9) ans++;
		i++;
	}
	printf("%d\n",ans);
	return 0;
} 
