#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    int dp[5000][3];
    for(int i = 0; i < 5000; i++){
        for(int j = 0; j < 3; j++){
            dp[i][j] = 0;
        }
    }
    for(int j = 1; j < n; j++){
        int ni{0}, nj{j};
        for(int i = 0; i < n-j; i++){
            if (s[ni] == s[nj]){
                dp[ni][2] = dp[ni+1][0];
            }else{
                dp[ni][2] = 1 + min(dp[ni+1][1], dp[ni][1]);
            }
            ni++;
            nj++;
        }
        for(int a = 0; a < 2; a++){
            for(int b = 0; b < n-j; b++){
                dp[b][a] = dp[b][a+1];
            }
        }
    }
    cout << dp[0][2];
}