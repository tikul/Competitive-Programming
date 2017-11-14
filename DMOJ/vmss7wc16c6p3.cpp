#include <stdio.h>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M, dfn[100005], low[100005], cur=0, ap=0;
vector<int> adj[100005];
bool art[100005], vis[100005];

int dfs(int u){
    low[u] = dfn[u] = cur++;
    vis[u] = true;
    int dcnt = 0;
    for(int v : adj[u]){
        if(!vis[v]){
            dcnt++;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u] && u != 1){
                art[u] = true;
            }
        }else{
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(u == 1 && dcnt > 1){
        art[u] = true;
    }
    if(art[u]) ap++;
}

int main(){
    memset(art, 0, sizeof(art));
    memset(vis, 0, sizeof(vis));
    scanf("%i%i", &N, &M);
    int a, b;
    for(int i = 0; i < M; i++){
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    printf("%i\n", ap);
    for(int i = 1; i <= N; i++){
        if(art[i]) printf("%i\n", i);
    }
}