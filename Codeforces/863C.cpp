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
typedef pair<long long, long long> pll;
typedef pair<pair<int,int>, int> ppi;

ll k;
int a, b, A[4][4], B[4][4];
bool seen[4][4];
vector<pii> hist;
vector<pii> wins;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> a >> b;
    for(int i = 1; i <= 3; i++){
        cin >> A[i][1] >> A[i][2] >> A[i][3];
    }
    for(int i = 1; i <= 3; i++){
        cin >> B[i][1] >> B[i][2] >> B[i][3];
    }
    memset(seen, 0, sizeof seen);
    int mv=0;
    int aw=0, bw=0;
    while(!seen[a][b] && mv < k){
        mv++;
        hist.push_back({a,b});
        seen[a][b] = 1;
        if(a == 3 && b == 2 || a == 2 && b == 1|| a == 1 && b==3){
            aw++;
        }else if(b == 3 && a == 2 || b == 2 && a == 1|| b == 1 && a==3){
            bw++;
        }
        // cout << "Score: " << aw << " - " << bw << "\n"; 
        wins.pb({aw,bw});
        int s = A[a][b];
        int t = B[a][b];
        a = s; b = t;
    }
    if(mv == k){
        cout << wins.back().first << " " << wins.back().second;
        return 0;
    }
    int x = 0;
    for(; x < hist.size(); x++){
        if(hist[x].first == a && hist[x].second == b) break;
    }
    k -= mv;
    int cyc = mv-x;
    ll rounds = (k-1)/cyc;
    ll cur = (k-1)%cyc;
    pll res = wins.back();
    pll lol = x>0? wins[x-1] : mp(0,0);
    for(int i = x; i < mv; i++){
        wins[i].first -= lol.first;
        wins[i].second -= lol.second;
    }
    pll newwins = wins.back();
    // cout << "moves: " << mv << "\n";
    // cout << "rounds: " << rounds << "\n";
    // cout << "cur: " << cur << "\n";
    res.first += rounds*newwins.first + wins[cur+x].first;
    res.second += rounds*newwins.second + wins[cur+x].second;
    cout << res.first << " " << res.second;
}