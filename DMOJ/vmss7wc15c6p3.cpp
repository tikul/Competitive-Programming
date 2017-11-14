#include <stdio.h>
#include <vector>
#include <algorithm>
#define inf 0x3f3f3f3f

using namespace std;

int n, ans=-inf;
vector<int> adj[400005];
int w[400005];

int dfs(int u, int p){
    int best=w[u];
    for(int v : adj[u]){
        if(v == p) continue;
        best += dfs(v, u);
    }
    ans = max(best, ans);
    return best;
}

int main(){
    scanf("%i", &n);
    int a, b;
    for(int i = 0; i < n-1; i++){
        scanf("%i%i", &a, &b);
        adj[a-1].push_back(b-1);
    }
    for(int i = 0; i < n; i++){
        scanf("%i", w+i);
    }
    dfs(0, -1);
    printf("%i", ans);
}