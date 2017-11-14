#include <stdio.h>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>

#define pii pair<int, int>
#define ppi pair<int, pii>
#define inf 0x3f3f3f3f

using namespace std;

int N, M, best, bridges, seen;
vector<int> adj[20];
ppi edges[25];
int dfn[20], low[20], vis[20], cnt=0;

void dfs(int u, int p){
    dfn[u] = low[u] = cnt++;
    vis[u] = true;
    seen++;
    for(int v : adj[u]){
        if(!vis[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u]){
                bridges++;
            }
        }else if(v != p){
            low[u] = min(low[u], dfn[v]);
        }
    }
}

bool isbiconnected(int u){
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(vis, 0, sizeof(vis));
    cnt = 0;
    bridges = 0;
    seen = 0;
    dfs(u, -1);
    return bridges == 0 && seen == N;
}

void solve(int x, int cost){
    if(x >= M) return;
    int w = edges[x].first;
    int u = edges[x].second.first;
    int v = edges[x].second.second;
    int ret = 0;
    adj[u].push_back(v);
    adj[v].push_back(u);
    if(cost + w < best){
        if(isbiconnected(u))
            best = min(best, cost+w);
        else
            solve(x+1, cost+w);
    }
    adj[u].pop_back();
    adj[v].pop_back();
    solve(x+1, cost);
}

int main(){
    scanf("%i%i", &N, &M);
    int a, b, c, tt=1;
    while(N != 0 && M != 0){
        best = inf;
        for(int i = 0; i < M; i++){
            scanf("%i%i%i", &a, &b, &c);
            edges[i] = {c, {a,b}};
        }
        solve(0, 0);
        if(best==inf) printf("There is no reliable net possible for test case %i.\n", tt);
        else printf("The minimal cost for test case %i is %i.\n", tt, best);
        scanf("%i%i", &N, &M);
        tt++;
    }
}