#include <cstdio>
#include <cstdlib>
#include <windows.h>

void test_function (int test)
{
    do {
        printf("wrong!");
    } while(test < 50);
}


int main()
{
    for(int i = 1; i <= 100; i++) {
        if(i < 50) {
            continue;
        } else {
            printf("%d",i);
            switch(i)
            {
            case 51: 
            printf(" ciallo \n");
            break;
            default:
            printf("\n");
            break;        
            }
        test_function(i);
        }
    }










    return 0;
}