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
#include <functional>
using namespace std;
#define sL(i) i << 1
#define sR(i) i << 1 | 1
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>, int> ppi;

int N, H;

struct Task{
    ll g, h, q, t;
    Task() {}
    Task(ll a, ll b, ll c, ll d) : g(a), h(b), q(c), t(d) {}
} npc[5005];

ll dp[5005][2]; // 1/0 vis/notvis

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> H;
    int a, b, c, d;
    for(int i = 0; i < N; i++){
        cin >> a >> b >> c >> d;
        npc[i] = Task(a, b, c, d);
    }
    ll best = 0;
    for(int i = 0; i < N; i++){
        for(int j = 1; j <= H; j++){
            dp[j][1] = dp[j][0];
            if(npc[i].h <= j){
                dp[j][0] = max(dp[j][0], dp[j-npc[i].h][1] + npc[i].g); 
            }        
            if(npc[i].t <= j){
                dp[j][1] = max(dp[j][1], dp[j-npc[i].t][1] + npc[i].q);
            }
        }
    }
    cout << dp[H][0];
}