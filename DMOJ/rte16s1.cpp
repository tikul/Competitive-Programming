#include <stdio.h>

int n, k, t;

int main(){
    scanf("%i", &t);
    while(t--){
        scanf("%i%i", &n, &k);
        int avail = n-k;
        int i = 1;
        while(i*(i+1)/2 <= avail){
            avail -= i*(i+1)/2;
            i++;
        }
        printf("%i\n", n-k-avail);
    }
}