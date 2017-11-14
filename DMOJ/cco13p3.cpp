#include <stdio.h>
#include <vector>
#include <cstring>
#include <utility>
#include <unordered_map>
#define pii pair<int, int>
#define mp make_pair
using namespace std;
int n,longest=0;
long long cnt=0;
bool vis[400007];
vector<int> adj[400007];

pii dfs(int u, int p){
    vis[u] = 1;
    pii res;
    int x, y, lseen=0, lcnt=1;
    for(int v : adj[u]){
        if(v == p) continue;
        res = dfs(v, u);
        x = res.first;
        y = res.second;
        if(lseen+x+1 > longest){
            longest = lseen+x+1;
            cnt = (long long) lcnt * y;
        }else if(lseen+x+1 == longest){
            cnt += (long long) lcnt * y;
        }
        if(x > lseen){
            lseen = x;
            lcnt = y;
        }else if(x == lseen){
            lcnt += y;
        }
    }
    return mp(1+lseen, lcnt);
}
int main(){
    scanf("%i", &n);
    int a, b;
    for(int i = 0; i < n-1; i++){
        scanf("%i %i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1);
    printf("%i %lli", longest, cnt);
}