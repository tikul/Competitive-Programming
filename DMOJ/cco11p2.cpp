#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
#include <cstring>
#include <functional>

#define pii pair<int, int>
#define ppi pair<int, pii>
#define mp make_pair

using namespace std;

int S, N, E;
vector<ppi> adj[1605];
int dist[1605][3605];

int main(){
    scanf("%i%i%i", &S, &N, &E);
    int s, t, d, u;
    for(int i = 0; i < E; i++){
        scanf("%i%i%i%i", &s, &t, &d, &u);
        adj[s].push_back(mp(d, mp(t,u)));
        adj[t].push_back(mp(d, mp(s,u)));
    }
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<ppi, vector<ppi>, greater<ppi>> q;
    q.push(mp(0, mp(0, 0)));
    while(!q.empty()){
        int d = q.top().first;
        int u = q.top().second.first;
        int e = q.top().second.second;
        q.pop();
        if(u == N-1){
            printf("%i", d);
            return 0;
        }
        for(ppi n : adj[u]){
            int d1 = n.first;
            int v = n.second.first;
            bool b = n.second.second;
            if(b){
                if(d1+e <= S && d+d1 < dist[v][d1+e]){
                    dist[v][d1+e] = d+d1;
                    q.push(mp(d+d1, mp(v, d1+e)));
                }
            }else{
                if(d+d1 < dist[v][e]){
                    dist[v][e] = d+d1;
                    q.push(mp(d+d1, mp(v, e)));
                }
            }
        }
    }
    printf("-1");
}