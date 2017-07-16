#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstring>
#define root 0
using namespace std;

int n, q;
vector<int> adj[6003];
unordered_map<int, int> dist;
int parent[6003], L[6003], pc[6003][14];
long long fr[6003];

void dfs(int u, int p, int level){
    L[u] = level;
    parent[u] = p;
    for(int v : adj[u]){
        if(v==p) continue;
        fr[v] = fr[u]+dist[min(u,v)*10000+max(u,v)];
        dfs(v, u, level+1);
    }
}

int main(){
    scanf("%i", &n);
    int a, b, w;
    for(int i = 0; i < n-1; i++){
        scanf("%i %i %i", &a, &b, &w);
        dist[min(a,b)*10000+max(a,b)] = w;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    fr[root] = 0;
    L[root] = 0;
    parent[root] = root;
    dfs(root, parent[root], L[root]);
    memset(pc, -1, sizeof(pc));
    for(int i = 0; i < n; i++)
        pc[i][0] = parent[i];
    for(int j = 1; 1 << j < n; j++){
        for(int i = 0; i < n; i++){
            if(pc[i][j-1] != -1){
                pc[i][j] = pc[pc[i][j-1]][j-1];
            }
        }
    }
    scanf("%i", &q);
    long long ans;
    while(q--){
        scanf("%i%i", &a, &b);
        //printf("%i %i", &a, &b);
        if(L[a] < L[b]) swap(a,b);
        ans = fr[a]+fr[b];
        int log = 0;
        for(log=1; 1 << log <= L[a]; log++);
        log--;
        for(int i = log; i >=0; i--){
            if(L[a]-(1<<i) >= L[b])
                a = pc[a][i];
        }
        if(a==b){
            ans -= 2*fr[a];
            printf("%lli\n", ans);
            //cout << fr[a] << "\n";
        }else{
            for(int i = log; i >= 0; i--){
                if(pc[a][i] != -1 && pc[a][i] != pc[b][i]){
                    a = pc[a][i];
                    b = pc[b][i];
                }
            }
            ans -= 2*fr[parent[a]];
            printf("%lli\n", ans);
            //cout << fr[parent[a]] << "\n";
        }
    }
}