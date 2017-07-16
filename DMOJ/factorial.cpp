#include <iostream>

long long factorial(long long);

int main() {
    long long arr[1000];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld", &arr[i]);
    }
    
    for(int i =0; i < n; i++){
        if ( arr[i] >= 34){
            printf("%lld \n", 0);
        }
        else{
            printf("%lld \n", factorial(arr[i]));
        }
    }
}

long long factorial(long long n){
    long long ans = 1;
    for(int i = 2; i <= n; i++)
        ans *= i;
        ans %= 4294967296;
    return ans;
}