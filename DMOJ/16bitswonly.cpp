#include <iostream>
int N;
long long a, b, p;

int main(){
    scanf("%i", &N);
    while(N--){
        scanf("%lli %lli %lli", &a, &b, &p);
        if (a*b == p)
            printf("POSSIBLE DOUBLE SIGMA\n");
        else
            printf("16 BIT S/W ONLY\n");
    }
}