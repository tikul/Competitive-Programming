#include <stdio.h>
#include <cmath>
#include <algorithm>

int m, n, k;
int diff[30002][1002];

int main(){
    scanf("%i %i %i", &m, &n, &k);
    int x, y, r, b, start, end;
    for(int _ = 0; _ < k; _++){
        scanf("%i %i %i %i", &x, &y, &r, &b);
        start = std::max(y-r, 1);
        end = std::min(y+r, m);
        int width, left, right;
        for(int height = start; height <= end; height++){
            width = sqrt(r*r - (height-y)*(height-y));
            left = std::max(1, x-width);
            right = std::min(n, x+width);
            diff[height][left] += b;
            diff[height][right+1] -= b;
        }
    }
    int best = 0, bestcount = 0;
    for(int i = 1; i <= m; i++){
        int t = 0;
        for(int j = 1; j <= n+1; j++){
            t += diff[i][j];
            if(t > best){
                best = t;
                bestcount = 1;
            }else if (t==best){
                bestcount++;
            }
        }
    }
    printf("%i\n%i", best, bestcount);
}