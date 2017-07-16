#include <iostream>
#include <algorithm>

int H, B, set[201];
unsigned char dp[201][200005];

int min(int a, int b){
    return a<b?a:b;
}

int main(){
    scanf("%i", &H);
    int low = 0;
    int high = 0;
    for(int i = 0; i < H; i++){
        scanf("%i", &set[i]);
        high += set[i];
    }
    scanf("%i", &B);
    int t;
    for(int i = H; i < H+B; i++){
        scanf("%i", &t);
        set[i] = -t;
        low += set[i];
    }
    int N = H+B;
    if(!N){
        printf("impossible");
        return 0;
    }
    std::sort(set, set+N);
    dp[0][set[0]-low] = 1;
    for(int i = 1; i < N; i++){
        for(int sum = low; sum <= high; sum++){
            int j = sum-low;
            if (set[i] == sum)
                dp[i][j] = 1;
            else{
                dp[i][j] = dp[i-1][j];
                if (dp[i][j] && dp[i-1][j-set[i]])
                    dp[i][j] = min(dp[i][j], 1+dp[i-1][j-set[i]]);
                else if(dp[i-1][j-set[i]])
                    dp[i][j] = 1+dp[i-1][j-set[i]];
            }
        }
    }
    if(dp[N-1][-low])
        printf("%i", dp[N-1][-low]);
    else
        printf("impossible");
}