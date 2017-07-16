#include <stdio.h>
#include <cmath>
#include <algorithm>

int w, h, n;
int hold[252][252];
int arr[252][252];

int main(){
    scanf("%i%i%i", &w, &h, &n);
    int t;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            scanf("%i", &t);
            hold[i][j] = t+hold[i][j-1];
            arr[i][j] = arr[i-1][j] + hold[i][j];
        }
    }
    int best = 0, cur;
    for(int len = 0; len < std::min(n, h); len++){
        int width = std::min(w, n/(len+1)) - 1;
        for(int i = 1; i <= h-len; i++){
            for(int j =1; j <= w-width; j++){
                cur = arr[i+len][j+width] + arr[i-1][j-1] - arr[i+len][j-1] - arr[i-1][j+width];
                best = std::max(best, cur);
            }
        }
    }
    printf("%i", best);
}