#include <stdio.h>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>

#define pii pair<int, int>
#define mp make_pair

using namespace std;

int n, t, down1[200005], down2[200005], downind[200005], best[200005], up[200005];
vector<pii> adj[200005];

int downdfs(int u, int p){
    for(pii n : adj[u]){
        int v = n.first;
        int w = n.second;
        if(v==p) continue;
        downdfs(v, u);
        if(down1[v] + w > down1[u]){
            down2[u] = down1[u];
            down1[u] = down1[v] + w;
            downind[u] = v;
        }else if(down1[v] + w > down2[u]){
            down2[u] = down1[v] + w;
        }
    }
}

int updfs(int u, int p){
    for(pii n : adj[u]){
        int v = n.first;
        int w = n.second;
        if(v == p) continue;
        if(v == downind[u]){
            up[v] = w + max(down2[u], up[u]);
            best[v] = max(down1[v], up[v]);
        }else{
            up[v] = best[v] = w + best[u];
        }
        updfs(v, u);
    }
}

int main(){
    memset(down1, 0, sizeof(down1));
    memset(down2, 0, sizeof(down2));
    scanf("%i%i", &n, &t);
    int a, b, c;
    long long tot = 0;
    for(int i = 0; i < n-1; i++){
        scanf("%i%i%i", &a, &b, &c);
        tot += 2*c;
        adj[a].push_back(mp(b,c));
        adj[b].push_back(mp(a,c));
    }
    downdfs(1, -1);
    up[1] = 0;
    best[1] = down1[1];
    updfs(1, -1);
    for(int i = 1; i <= n; i++){
        if(adj[i].size()==t) printf("%i %lli\n", i, tot-best[i]);
    }
}