#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> adj[500005];
int down1[500005], down2[500005], downind[500005], ans[500005];
int N;

int downdfs(int u, int p){
    int hi = 0, lo = 0, i = u;
    for(int v : adj[u]){
        if(v==p) continue;
        int res = downdfs(v, u);
        if(res+1 > hi){
            lo = hi;
            hi = res+1;
            i = v;
        }else if(res+1 > lo){
            lo = res+1;
        }
    }
    down2[u] = lo;
    downind[u] = i;
    return down1[u] = hi;
}

int updfs(int u, int p, int up){
    int best = max(up, down1[u]);
    for(int v : adj[u]){
        if(v==p) continue;
        if(v == downind[u]){
            int x = max(down2[u], up);
            updfs(v, u, 1+x);
        }else{
            updfs(v, u, 1+best);
        }
    }
    ans[u] = best;
}
int main(){
    scanf("%i", &N);
    int a, b;
    for(int i = 0; i < N-1; i++){
        scanf("%i %i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    downdfs(1, -1);
    updfs(1, -1, 0);
    for(int i = 1; i <= N; i++){
        printf("%i\n", ans[i]+1);
        //printf("%i %i %i %i\n", down1[i], down2[i], downind[i], ans[i]);
    }
}