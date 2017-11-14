#include <stdio.h>
#include <vector>
#include <utility>
#define pii pair<int, int>
using namespace std;

int n, c, k, tot=0, cherry[10005];
vector<pii> adj[10005];

pii dfs(int u, int p){
    int f = 0, s = 0;
    for(pii v : adj[u]){
        if(v.first==p) continue;
        pii t = dfs(v.first, u);
        if(v.second+t.first <= k && t.second >= c){
            tot++;
        }
        f += t.first+v.second;
        s += t.second;
    }
    return {f,s+cherry[u]};
}

int main(){
    scanf("%i %i %i", &n, &c, &k);
    for(int i = 1; i <= n; i++){
        scanf("%i", &cherry[i]);
    }
    int a, b, c;
    for(int i = 0; i < n-1; i++){
        scanf("%i %i %i", &a, &b, &c);
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    dfs(1, -1);
    printf("%i", tot);
}