#include <stdio.h>
#include <cstring>

bool dp[1000005];
int n, c, x,best=0;

int main(){
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    scanf("%i %i", &c, &n);
    while(n--){
        scanf("%i", &x);
        for(int sum = c-1; sum >= x; sum--)
            dp[sum] |= dp[sum-x];
    }
    while(!dp[c] && c > 0){
        c--;
    }
    printf("%i", c);
}