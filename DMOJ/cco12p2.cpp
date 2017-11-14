#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>
#include <functional>
#include <utility>

#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define ppi pair<int, pii>
#define mp make_pair

using namespace std;

int N, M;
int dist1[20005], dist2[20005];
vector<pii> adj[20005];

int main(){
    scanf("%i%i", &N, &M);  
    int a, b, c;
    for(int i = 0; i < M; i++){
        scanf("%i%i%i", &a, &b, &c);
        adj[a].push_back(mp(b,c));
    }
    memset(dist1, 0x3f, sizeof(dist1));
    memset(dist2, 0x3f, sizeof(dist2));
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push(mp(0,1));
    dist1[1] = 0;
    while(!q.empty()){
        int d = q.top().first;
        int u = q.top().second;
        q.pop();
        for(pii out : adj[u]){
            int v = out.first;
            int w = out.second;
            if(d+w < dist1[v]){
                dist2[v] = dist1[v];
                dist1[v] = d+w;
                q.push(mp(d+w, v));
            }else if(d+w < dist2[v] && d+w != dist1[v]){
                dist2[v] = d+w;
                q.push(mp(d+w, v));
            }
        }
    }
    if(dist2[N]==inf) printf("-1");
    else printf("%i", dist2[N]);
}