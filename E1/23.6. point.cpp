#include<stdio.h>
int main()
{
    char c = 'A';
    char *pc = &c;
    const char **p = &pc; // pointer to pointer to const char
    char *const *q = &pc; // pointer to const pointer to char
    char **const r = &pc; // const pointer to pointer to char
    
    return 0;
}