#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

int memo[5000001];

using namespace std;

int solve(int x){
    if (memo[x] != -1){
        return memo[x];
    }
    if (x % 2 == 0){
        return memo[x] = 1+solve(x/2);
    }
    else{
        int best = solve(x-1)+x-1;
        int a;
        for(int i = 2; i < floor(sqrt(x))+1; i++){
            if (x % i == 0){
                a = min( solve(x-i) + (x/i)-1, solve((i-1)*(x/i)) + i-1);
                best = min(best, a);
            }
        }
        return memo[x] = best;
    }
}

int main(){
    memset(memo, -1, sizeof(memo));
    memo[1] = 0;
    int n;
    scanf("%i", &n);
    printf("%i", solve(n));
}