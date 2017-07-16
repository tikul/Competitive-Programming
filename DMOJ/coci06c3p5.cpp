#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#define ll long long
#define mod 1000000000
using namespace std;
int N, M, a, b;
bool visited[10005];
bool cycle[10005];
bool big, bad;
ll dp[10005];
vector<vector<int>> graph(10005,vector<int>());

ll dfs(int node){
    if (visited[node] || bad){
        cycle[node] = true;
        return 0;
    }
    if (dp[node] != -1){
        return dp[node];
    }
    if (node == 2){
        return 1;
    }
    else{
        ll best = 0;
        visited[node] = true;
        for(int i = 0; i < graph[node].size(); i++){
            best += dfs(graph[node][i]);
            if (best >= mod){
                big = true;
                best = best %mod;
            }
        }
        if (cycle[node] && best > 0)
            bad = true;
        visited[node] = false;
        return dp[node] = best;
    }
}

int main(){
    memset(dp, -1, sizeof(dp));
    memset(visited, 0, sizeof(visited));
    memset(cycle, 0, sizeof(cycle));
    big = false;
    bad = false;
    scanf("%i %i", &N, &M);
    for(int i = 0; i < M; i++){
        scanf("%i %i", &a, &b);
        graph[a].push_back(b);
    }
    ll ans = dfs(1);
    if (bad)
        printf("inf");
    else if (!big)
        printf("%lli", ans);
    else{
        string s = to_string(ans);
        for(int i = 0; i < 9 - s.length(); i++){
            printf("%i", 0);
        }
        cout << s;
    }
}