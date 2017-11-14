#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <functional>
using namespace std;
#define sL(i) i << 1
#define sR(i) i << 1 | 1
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>, int> ppi;

int n, m;
vector<pii> adj[100005];
int dist[100005];
int dang[100005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int a, b, t;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> t;
        adj[a].push_back({b, t});
        adj[b].push_back({a, t});
    }
    memset(dist, 0x3f, sizeof dist);
    memset(dang, 0, sizeof dang);
    dist[1] = 0;
    dang[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, 1});
    while(!q.empty()){
        int d = q.top().first;
        int u = q.top().second;
        q.pop();
        for(auto x : adj[u]){
            int v = x.first;
            bool y = x.second;
            if(dist[v] == 0x3f3f3f3f){
                q.push({d+1, v});
                dist[v] = dist[u]+1;
                dang[v] = dang[u]+y;
            }else if(!y){
                if(dang[u] < dang[v]){
                    q.push({d+1, v});
                    dist[v] = dist[u]+1;
                    dang[v] = dang[u];
                }else if(dang[u] == dang[v]){
                    if(dist[u]+1 < dist[v]){
                        q.push({d+1, v});
                        dist[v] = dist[u]+1;
                    }
                }
            }else{
                if(dang[u]+1 < dang[v]){
                    q.push({d+1, v});
                    dist[v] = dist[u]+1;
                    dang[v] = dang[u]+1;
                }else if(dang[u]+1 == dang[v]){
                    if(dist[u]+1 < dist[v]){
                        q.push({d+1, v});
                        dist[v] = dist[u]+1;
                    }
                }
            }
        }
    }
    // for(int i = 1; i <= n; i++){
    //     cout << dang[i] << " " << dist[i] << "\n";
    // }
    if(dist[n]==0x3f3f3f3f){
        cout << -1;
    }else{
        cout << dang[n] << " " << dist[n];
    }
}