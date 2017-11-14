#include <stdio.h>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
#define inf 0x3f3f3f3f
#define pii pair<int, ll>
#define ll long long
#define maxn 100005
using namespace std;
int N, M, Q, tree=0;
vector<pii> adj[maxn];
bool vis[maxn];
ll diameter[maxn], radius[maxn], down1[maxn], down2[maxn], downind[maxn];

ll downdfs(int u, int p){
    ll ret;
    vis[u] = 1;
    for(pii v: adj[u]){
        if(v.first==p) continue;
        ret = downdfs(v.first, u);
        if(ret+v.second > down1[u]){
            downind[u] = v.first;
            down2[u] = down1[u];
            down1[u] = ret+v.second;
        }else if(ret+v.second > down2[u]){
            down2[u] = ret+v.second;
        }
    }
    return down1[u];
}

void updfs(int u, int p, ll up){
    ll alt = max(up, down2[u]);
    ll best = max(down1[u], up);
    diameter[tree] = max(diameter[tree], down1[u]+alt);
    radius[tree] = min(radius[tree], best);
    for(pii v : adj[u]){
        if(v.first==p) continue;
        if(v.first==downind[u]) updfs(v.first, u, v.second+alt);
        else updfs(v.first, u, v.second+best);
    }
}

int main(){
    memset(vis, 0, sizeof(vis));
    memset(radius, 0x3f, sizeof(radius));
    memset(downind, 0, sizeof(downind));
    scanf("%i%i%i", &N, &M, &Q);
    int a, b, c;
    for(int i = 0; i < M; i++){
        scanf("%i%i%i", &a, &b, &c);
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    for(int i = 1; i <= N; i++){
        if(!vis[i]){
            downdfs(i, -1);
            updfs(i, -1, 0);
            tree++;
        }
    }
    ll longest= tree-1;
    ll rad=0;
    ll radcnt=0;
    //printf("tree %i\n", tree);
    for(int i = 0; i < tree; i++){
        //printf("%i %i %i\n", i, diameter[i], radius[i]);
        longest += diameter[i];
        if(radius[i] > rad){
            rad = radius[i];
            radcnt = 1;
        }else if(radius[i] == rad){
            radcnt++;
        }
    }
    if(Q==1){
        printf("%lli", longest);
    }else{
        if(radcnt==1){
            printf("%lli", rad);
        }else{
            printf("%lli", rad+1);
        }
    }
}