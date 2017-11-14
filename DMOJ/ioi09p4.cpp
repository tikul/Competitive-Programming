#include <stdio.h>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;

int dp[52][52][52][52]; //r c w l
int pre[52][52];
int n, m;

int main(){
    int x;
    scanf("%i %i", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%i", &x);
            pre[i+1][j+1] = pre[i][j+1] + pre[i+1][j] - pre[i][j] + x;
        }
    }
    
    for(int w = 0; w < m; w++){
        for(int l = 0; l < n; l++){
            //if(w==1 && l==1) continue;
            for(int c = 0; c+w < m; c++){
                for(int r = 0; r+l < n; r++){
                    if(w==0  && l == 0){
                        dp[r][c][w][l] = 0;
                    }else{
                        int best = inf;
                        for(int cut = 1; cut <= w; cut++){
                            best = min(best, dp[r][c][cut-1][l]+dp[r][c+cut][w-cut][l]);
                        }
                        for(int cut = 1; cut <= l; cut++){
                            best = min(best, dp[r][c][w][cut-1]+dp[r+cut][c][w][l-cut]);
                        }
                        dp[r][c][w][l] = best+(pre[r+l+1][c+w+1]+pre[r][c]-pre[r][c+w+1]-pre[r+l+1][c]);
                        //printf("%i %i %i %i: %i, %i\n", r, c, w+1, l+1, dp[r][c][w][l], best);
                    }
                }
            }
        }
    }

    printf("%i", dp[0][0][m-1][n-1]);
}