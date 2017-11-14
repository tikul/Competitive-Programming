#include <stdio.h>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
#include <cmath>
#define pfi pair<float, int>
#define ppi pair<pfi, int>
#define mp make_pair
#define F first
#define S second

using namespace std;

int v, e, passed[1002];
float d[1002];
vector<pfi> adj[1002];
bool vis[1002];

int main(){
    memset(vis, 0, sizeof(vis));
    scanf("%i %i", &v, &e);
    int n, m, dd, s;
    for(int i = 0; i < e; i++){
        scanf("%i %i %i %i", &n, &m, &dd, &s);
        float t = (float) 60*dd/s;
        adj[n].push_back(mp(t, m));
        adj[m].push_back(mp(t, n));
    }
    for(int i = 1; i <= v; i++) d[i] = 1e9;
    priority_queue<ppi, vector<ppi>, greater<ppi>> q;
    d[1] = 0;
    q.push(mp(mp(0, 1), 0));
    while(!q.empty()){
        ppi val = q.top();
        q.pop();
        int u = val.F.S;
        int cnt = val.S;
        if(vis[u]) continue;
        vis[u] = true;
        passed[u] = cnt;
        for(pfi n : adj[u]){
            if(d[u]+n.F < d[n.S]){
                d[n.S] = d[u]+n.F;
                q.push(mp(mp(d[n.S], n.S), cnt+1));
            }
        }
    }
    int x = round(d[v]/3);
    printf("%i\n%i", passed[v], x);
}