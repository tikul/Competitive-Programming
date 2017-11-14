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

int n, a[3];
vector<pii> adj[3];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int x;
    for(int i = 0; i < 3; i++) cin >> a[i];
    adj[0].pb({1, a[0]});
    adj[0].pb({2, a[1]});
    adj[1].pb({2, a[2]});
    adj[1].pb({0, a[0]});
    adj[2].pb({0, a[1]});
    adj[2].pb({1, a[2]});
    int at = 0;
    int res = 0;
    --n;
    while(n--){
        if(adj[at][0].second < adj[at][1].second){
            res += adj[at][0].second;
            at = adj[at][0].first;
        }else{
            res += adj[at][1].second;
            at = adj[at][1].first;
        }
    }
    cout << res;
}