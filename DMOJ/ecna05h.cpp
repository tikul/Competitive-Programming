#include <iostream>
#include <cstring>
#include <algorithm>

int N, dp[1000][1000], greed[1000][1000], things[1000];
int greedy(int, int);
int strategy(int, int);

int main(){
    int f, count{0};
    scanf("%i", &f);
    while( f != 0){
        count++;
        memset(dp, -1, sizeof(dp));
        memset(greed, -1, sizeof(greed));
        for(int i = 0; i < f; i++){
            scanf("%i", &things[i]);
        }
        int ans = strategy(0, f-1);
        printf("In game %i, the greedy strategy might lose by as many as %i points.\n", count, ans);
        scanf("%i", &f);
    }
}

int greedy(int l, int r){
    if (l == r){
        return -things[l];
    }
    if (greed[l][r] != -1){
        return greed[l][r];
    }
    if (things[l] >= things[r]){
        greed[l][r] = strategy(l+1, r) - things[l];
    }else{
        greed[l][r] = strategy(l, r-1) - things[r];
    }
    return greed[l][r];
}

int strategy(int l, int r){
    if (l == r){
        return things[l];
    }
    if (dp[l][r] != -1){
        return dp[l][r];
    }
    int a = things[l] + greedy(l+1, r);
    int b = things[r] + greedy(l, r-1);
    dp[l][r] = std::max(a, b);
    return dp[l][r];
}