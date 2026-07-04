#include "52TEST.h"

#ifdef TEST1
double distance(double x1, double y1, double x2, double y2)
{
	double dx = x2 - x1;
	double dy = y2 - y1;
	double dsquared = dx * dx + dy * dy;
	double result = sqrt(dsquared);

	return result;
}
void __swap(int &a, int &b) {
	int _a = a, _b = b;
	b = _a; a = _b;
}
int GCDbyEuclid(int a, int b) {
	if(a < b) __swap(a,b);
	int ans = a % b;
	if(ans == 0) return b;
	return GCDbyEuclid(b,ans);
}
#endif
