#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
#include <unordered_set>
#include <set>
#include <unordered_map>
using namespace std;
#define sL(i) i << 1
#define sR(i) i << 1 | 1
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>, int> ppi;

int n, a[52];
int dp[53][2][2]; //pie, who, tomove
int pf[53];
//0 = bob, 1 = alice

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    memset(dp, 0, sizeof(dp));
    memset(pf, 0, sizeof(pf));
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pf[i+1] = pf[i] + a[i];
    }
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < 2; j++){ //who's moving
            if(i == 0 && j == 1) continue;
            dp[i][j][j] = max(dp[i+1][j][1-j]+a[i], dp[i+1][j][j]);
            dp[i][1-j][j] = (pf[n] - pf[i]) - dp[i][j][j];
        } 
    }
    cout << dp[0][1][0] << " " << dp[0][0][0];
}