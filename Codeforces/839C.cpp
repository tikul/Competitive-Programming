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
#include <iomanip>
#include <unordered_map>
using namespace std;
#define left(i) i << 1
#define right(i) i << 1 | 1
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>, int> ppi;

vector<int> adj[100005];
double prob[100005];
int dist[100005];
int deg[100005];
int n;

int dfs(int u, int p){
    for(int v : adj[u]){
        if(v==p) continue;
        dist[v] = dist[u]+1;
        if(u==1){
            prob[v] = prob[u]/(adj[u].size());
        }else{
            prob[v] = prob[u]/(adj[u].size()-1);
        }
        dfs(v, u);
    }
}

int main(){
    memset(deg, 0, sizeof(deg));
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int a, b;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    dist[1] = 0;
    prob[1] = 1;
    dfs(1, -1);
    double ans = 0;
    for(int i = 1; i <= n; i++){
        if(deg[i]==1){
            ans += prob[i]*dist[i];
        }
    }
    cout << fixed;
    cout << setprecision(7);
    cout << ans;
}