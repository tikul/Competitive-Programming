#include <stdio.h>

int main(){
    int n, m;
    scanf("%i %i", &n, &m);
    if(n==1 || m == 1) printf("First");
    else if((n&1)^(m&1)) printf("First");
    else printf("Second");
}