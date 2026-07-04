#include<cstdio>
#include<cstdlib>
int main() {
	int a,b;
	scanf("%d %d",&a,&b);
	while(a % b) {
		int c = a % b;
		a = b;
		b = c;
	}
	printf("%d\n",b);
	
	int i = 1,n;
	scanf("%d",&n);
	int r = 1,m = 1, s;
	while(i <= n) {
		if(i < 3) continue;
		s = r + m;
		r = m;
		m = s;
	}
	printf("%d\n",s);
	return 0;
}
