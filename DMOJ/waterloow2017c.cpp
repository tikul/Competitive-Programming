#include <stdio.h>
using namespace std;
int n, k, a[105];
int main(){
    scanf("%i %i", &n, &k);
    if(2*k < n){
        printf("0");
        return 0;
    }
    int cur = 0;
    for(int i = 1; i<= k; i++){
        int x = 1 + (n-i)/k;
        int jump = x + cur;
        cur += x;
        for(int j = i; j <= n; j+=k){
            a[j] = jump--;
        }
    }
    for(int i = 1; i <= n; i++){
        printf("%i ", a[i]);
    }
}