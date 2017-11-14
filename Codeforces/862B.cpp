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

int n;
vector<int> adj[100005];
int cnt[2]; //0 = black, 1 = white
int col[100005];

void dfs1(int u, int p, int c){
    col[u] = c;
    ++cnt[c];
    for(int v : adj[u]){
        if(v==p) continue;
        dfs1(v, u, !c);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int a, b;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    memset(cnt, 0, sizeof(cnt));
    dfs1(1, -1, 0);
    ll ways = 0;
    for(int i = 1; i <= n; i++){
        int sz = adj[i].size();
        ways += cnt[!col[i]]-sz;
    }
    cout << ways/2;
}