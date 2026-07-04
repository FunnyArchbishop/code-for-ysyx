#include<math.h>
#include<stdio.h>
/*
有一点需要注意，虽然结构体的成员名和变量名不在同一命名空间中，
但枚举的成员名却和变量名在同一命名空间中，所以会出现命名冲突。
例如这样是不合法的：

int main(void)
{
	enum coordinate_type { RECTANGULAR = 1, POLAR };
	int RECTANGULAR;
	printf("%d %d\n", RECTANGULAR, POLAR);
	return 0;
}
//wrong answer

*/
//////////////////////////////////////////////////////////////////
enum coordinate_type { RECTANGULAR, POLAR };
struct complex_struct {
	enum coordinate_type t;
	double a, b;
};
/*概念调用/IO层*/
struct complex_struct make_from_real_img(double x, double y)
{
	struct complex_struct z;
	z.t = RECTANGULAR;
	z.a = x;
	z.b = y;
	return z;
}

struct complex_struct make_from_mag_ang(double r, double A)
{
	struct complex_struct z;
	z.t = POLAR;
	z.a = r;
	z.b = A;
	return z;
}

double real_part(struct complex_struct z)
{
	if (z.t == RECTANGULAR)
		return z.a;
	else
		return z.a * cos(z.b);
}

double imag_part(struct complex_struct z)
{
	if (z.t == RECTANGULAR)
		return z.b;
	else
		return z.a * sin(z.b);
}

double magnitude(struct complex_struct z)
{
	if (z.t == RECTANGULAR)
		return sqrt(z.a * z.a + z.b * z.b);
	else
		return z.a;
}

double angle(struct complex_struct z)
{
	if (z.t == RECTANGULAR)
		return atan2(z.b, z.a);
	else
		return z.b;
}

int main() {
	struct complex_struct z1, z2;
	z1 = make_from_real_img(1.0, 1.0);
	z2 = make_from_mag_ang(2.0, 3.14159265358979323846 / 4.0);
	printf("z1 = %.2f + %.2fi\n", real_part(z1), imag_part(z1));
	printf("z2 = %.2f + %.2fi\n", real_part(z2), imag_part(z2));
	return 0;
}
