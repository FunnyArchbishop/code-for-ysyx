#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int countbits(unsigned int n)
{
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
 
 
    return count;
}

unsigned int multiply(unsigned int a, unsigned int b)
{
    unsigned int result = 0;
    for(int i = 0; i < 32; i++) {
        if(b & (1 << i)) {
            result += (a << i);
        }
    }
    return result;
}

unsigned int rotate_right(unsigned int x, int n)
{
    n %= 32; //make n smaller than 32
    return (x >> n) | (x << (32 - n));
}



int swap(unsigned int &x, unsigned int &y)
{
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    return 1;
}
int main()
{
    unsigned int a;
    scanf("%u", &a);
    unsigned int b;
    scanf("%u", &b);
    printf("%d\n", countbits(a));
    printf("%u\n", multiply(a, b));
    printf("%u\n", rotate_right(a, 3));
    swap(a, b);
    printf("%u %u\n", a, b);
    return 0;
}