#include <stdio.h>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>
#define mp make_pair
#define pii pair<int, int>
#define mod 1000000007

using namespace std;

int n, m;
unordered_map<long long, int> edges;
vector<int> adj[100005];

int indeg[100005];
bool vis[100005];
pii dp[100005];

pii dfs(int u){
    if(vis[u])
        return dp[u];
    vis[u] = true;
    int x=0,y=0;
    pii h;
    for(int v : adj[u]){
        h = dfs(v);
        x += (1LL * edges[1LL*u*1000000+v]*h.first)%mod;
        x %= mod;
        y += (1LL * edges[1LL*u*1000000+v]*(h.first+h.second))%mod;
        y %= mod;
    }
    //printf("%i %i %i\n", u, x, y);
    return dp[u] = mp(max(x,1), y);
}

int main(){
    scanf("%i%i", &n, &m);
    memset(vis, 0, sizeof(vis));
    int a, b;
    for(int i = 0; i < m; i++){
        scanf("%i%i", &a, &b);
        indeg[b]++;
        if(edges.find(1LL * a * 1000000 + b) != edges.end()){
            edges[1LL * a * 1000000 + b] += 1;
        }else{
            adj[a].push_back(b);
            edges[1LL * a * 1000000 + b] = 1;
        }
    }
    int ans = 0;
    pii res;
    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0){
            res = dfs(i);
            ans += res.second;
            ans %= mod;
        }
    }
    printf("%i\n", ans);
}