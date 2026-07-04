#include<bits/stdc++.h>
int floor(int x, int n) {
    if(n == 0) exit(0);
    if(x*n > 0 || x%n == 0) return x/n;
    return x/n + 1;
}

int ceiling(int x, int n) {
    if(n == 0) exit(0);
    if(x*n < 0 || x%n == 0) return x/n;
    return x/n + 1;
}

int main() {
    int x,n;
    scanf("%d %d",&x,&n);
//    printf("%d %d",x,n);
    printf("floor:%d\nceiling:%d",floor(x,n),ceiling(x,n));
    return 0;
}
