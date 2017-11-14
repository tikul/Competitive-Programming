#include <stdio.h>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>
#include <stdio.h>
#define pii pair<int, int>
#define inf 0x3f3f3f3f
#define maxn 100005
using namespace std;
int numTrees=0, diameter=0;
int down1[maxn], down2[maxn], downind[maxn]; //each node
int radius[maxn]; //each tree
bool vis[maxn];
vector<pii> adj[maxn];

int downdfs(int u, int p){
    vis[u] = true;
    for(pii v : adj[u]){
        if(v.first==p) continue;
        int len = downdfs(v.first, u);
        if(len+v.second > down1[u]){
            down2[u] = down1[u];
            down1[u] = len+v.second;
            downind[u] = v.first;
        }else if(len+v.second > down2[u]){
            down2[u] = len+v.second;
        }
    }
    return down1[u];
}

int updfs(int u, int p, int up){
    int alt = max(up, down2[u]);
    int best = max(up, down1[u]);
    diameter = max(down1[u]+alt, diameter);
    radius[numTrees] = min(best, radius[numTrees]);
    for(pii v : adj[u]){
        if(v.first==p) continue;
        if(v.first==downind[u]){
            updfs(v.first, u, v.second+alt);
        }else{
            updfs(v.first, u, v.second+best);
        }
    }
}

void init(){
    memset(vis, 0, sizeof(vis));
    memset(down1, 0, sizeof(down1));
    memset(down2, 0, sizeof(down2));
    memset(radius, 0x3f, sizeof(radius));
}

int travelTime(int N, int M, int L, int A[], int B[], int T[]){
    init();
    for(int i = 0; i < M; i++){
        int a = A[i], b = B[i], c = T[i];
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    for(int i = 0; i < N; i++){
        if(!vis[i]){
            downdfs(i, -1);
            updfs(i, -1, 0);
            numTrees++;
        }
    }
    if(numTrees==1){
        return diameter;
    }
    if(numTrees ==2){
        return max(diameter, L+radius[0]+radius[1]);
    }
    sort(radius, radius+numTrees);
    int onebridge = L+radius[numTrees-2]+radius[numTrees-1];
    int twobridge = 2*L+radius[numTrees-3]+radius[numTrees-2];
    int best = max(onebridge, twobridge);
    best = max(best, diameter);
    return best;
}