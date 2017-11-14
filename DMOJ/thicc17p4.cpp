#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#define inf 0x3f3f3f3f
using namespace std;

int n, t, dp[101][101];
string s;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    memset(dp, 0, sizeof(dp));
    cin >> s >> n;
    int len = s.length();
    double best = inf;
    string nn;
    for(int _ = 0; _ < n; _++){
        double acc=0;
        cin >> t;
        for(int __ = 0; __ < t; __++){
            //memset(dp, 0, sizeof(dp));
            cin >> nn;
            for(int i = 0; i <= len; i++) dp[i][0] = i;
            for(int i = 0; i <= nn.length(); i++) dp[0][i] = i;
            for(int i = 1; i <= len; i++){
                for(int j = 1; j <= nn.length(); j++){
                    if(nn[j-1]==s[i-1]){
                        dp[i][j] = dp[i-1][j-1];
                    }else{
                        dp[i][j] = 1+dp[i-1][j-1];
                        dp[i][j] = min(dp[i][j], 1+dp[i][j-1]);
                        dp[i][j] = min(dp[i][j], 1+dp[i-1][j]);
                    }
                }
            }
            //if(__==0) printf("sd%i\n", dp[len][nn.length()]);
            acc += dp[len][nn.length()];
        }
        best = min(acc/t, best);
        //printf("acc: %lf\n", acc);
    }
    cout << fixed << best;
}