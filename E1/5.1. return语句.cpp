#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>

int is_leap_year(int &year) {
	year = year % 4 == 0 ? 0:1;
	return year == 0 && year == 1 ? 0:-1;
} 

double myround(double x) {
	int MidAdd = ceil(x) + floor(x);
	if(MidAdd > x * 2.0) return double(floor(x));
	return double(ceil(x));
	exit(-1);
}

int main() {
	double x;
	std::cin>>x;
	printf("%lf\n",myround(x));
	int y;
	scanf("%d",&y);
	is_leap_year(y);
	printf("%d",y);
	return 0;
}
