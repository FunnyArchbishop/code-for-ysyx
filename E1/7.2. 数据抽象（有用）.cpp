#include<math.h>
#include<stdio.h>

//////////////////////////////////////////////////////////////////

struct SComplex {
	double Re, Im;
};
/*概念调用/IO层*/
double GetRe(struct SComplex z) {	return z.Re;}
double GetIm(struct SComplex z) {	return z.Im;}
double GetMag(struct SComplex z) {
	return sqrt(z.Re * z.Re + z.Im * z.Im);
}
double GetAng(struct SComplex z) {
	if(z.Im == 0 and z.Re == 0) {
		printf("Wrong angle!");
		exit(-1);
	}
	return atan2(z.Im,z.Re);
}
SComplex WriteX(double Re,double Im) {
	struct SComplex z = {.Re = Re,.Im = Im};
	return z;
}
SComplex WriteA(double Mag,double Ang) {
	struct SComplex z = {.Re = Mag * cos(Ang),.Im = Mag * sin(Ang)};
	return z;
}
int scancX(struct SComplex *z) {
	scanf("%lf %lf",&z->Re,&z->Im);
	return 1;
}
int printcX(struct SComplex z) {
	if(z.Im == 0.0) 		printf("%lf", z.Re);
	else if(z.Re == 0.0)	printf("%lfi",z.Im);
	else if(z.Im < 0.0)		printf("%lf - %lfi",z.Re,-z.Im);
	else					printf("%lf + %lfi",z.Re,z.Im);
	return 1;
}
int printcA(struct SComplex z) {
	if(GetMag(z) == 0.0 || GetAng(z) == 0.0) printf("%lf",GetMag(z));
	else printf("%lf * e^(i%lf)",GetMag(z),GetAng(z));
	return 1;
}
/*基础运算层*/
SComplex Add(struct SComplex z1,struct SComplex z2) {
//	struct SComplex z = {.Re=z1.Re + z2.Re,.Im = z1.Im + z2.Im};
	return WriteX(z1.Re + z2.Re,z1.Im + z2.Im);
}
SComplex Sub(struct SComplex z1,struct SComplex z2) {
//	struct SComplex z = {.Re=z1.Re - z2.Re,.Im = z1.Im - z2.Im};
	return WriteX(z1.Re - z2.Re,z1.Im - z2.Im);
}

SComplex Mul(struct SComplex z1,struct SComplex z2) {
/*	
	struct SComplex z = {
		.Re = z1.Re * z2.Re - z1.Im * z2.Im,
		.Im = z1.Re * z2.Im - z2.Re * z1.Im
	};
	return z;
*/
	return WriteA(GetMag(z1) * GetMag(z2),GetAng(z1) + GetAng(z2));
}
SComplex Div(struct SComplex z1,struct SComplex z2) {
	return WriteA(GetMag(z1) / GetMag(z2),GetAng(z1) - GetAng(z2));
}

/////////////////////////////////////////////////////////////////////

void __swap(int &a,int &b) {
	int a1 = a,b1 = b;
	b = a1;
	a = b1;
}
int GCDbyEuclid(int a, int b) {
	if(a == 0 or b == 0) return 1;
	a = abs(a);
	b = abs(b);
	if(a < b) __swap(a,b);
	int ans = a % b;
	if(ans == 0) return b;
	return GCDbyEuclid(b,ans);
}

struct Qnumber {
	int zi;
	int mu;
};

/*概念调用/IO层*/
Qnumber writeq(int zi,int mu) {
	int divnum = GCDbyEuclid(mu,zi);
	struct Qnumber x = {.zi = zi/divnum, .mu = mu/divnum};
	return x;
}
int scanq(struct Qnumber *x) {
	scanf("%d/%d",&x->zi,&x->mu);
	return 1;
}
int printq(struct Qnumber x) {
	if(x.mu == 0)				exit(-1);
	if(x.zi == 0)				printf("%d",x.zi);
	else if(abs(x.mu) == 1)		printf("%d",x.zi * x.mu);
	else if(x.mu * x.zi < 0)	printf("-%d/%d",abs(x.zi),abs(x.mu));
	else 						printf("%d/%d",abs(x.zi),abs(x.mu));
	return 1;
}

/*基础运算层*/
Qnumber add(struct Qnumber a,struct Qnumber b) {
	return writeq(a.zi * b.mu + a.mu * b.zi,a.mu * b.mu);
}
Qnumber sub(struct Qnumber a,struct Qnumber b) {
	return writeq(a.zi * b.mu - a.mu * b.zi,a.mu * b.mu);
}
Qnumber mul(struct Qnumber a,struct Qnumber b) {
	return writeq(a.zi * b.zi,a.mu * b.mu);
}
Qnumber div(struct Qnumber a,struct Qnumber b) {
	return writeq(a.zi * b.mu,a.mu * b.zi);
}

int main() {
	SComplex z1;
	scancX(&z1);
	SComplex z2;
	scancX(&z2);
	printf("add:");
	printcX(Add(z1,z2));
	printf("\nSub:");
	printcX(Sub(z1,z2));
	printf("\nMul:");
	printcX(Mul(z1,z2));
	printf("\nDiv:");
	printcX(Div(z1,z2));
	printf("\n\n");
	
	Qnumber r1;
	scanq(&r1);
	Qnumber r2;
	scanq(&r2);
	printf("add:");
	printq(add(r1,r2));
	printf("\nSub:");
	printq(sub(r1,r2));
	printf("\nMul:");
	printq(mul(r1,r2));
	printf("\nDiv:");
	printq(div(r1,r2));
	printf("\n\n");
	return 0;
}
