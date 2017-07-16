#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define pii pair<long long, short>
#define mp make_pair
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

std::vector<short> adj[5001];
short edge[5001][5001];
bool visited[5001];

int N, T, K, D;

int main(){
    scan(N);
    scan(T);
    int x, y, c;
    for(int i = 0; i < T; i++){
        scan(x);
        scan(y);
        scan(c);
        edge[x][y] = c;
        edge[y][x] = c;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    std::priority_queue<std::pii> q;
    scanf("%i", &K);
    for(int i= 0; i < K; i++){
        scan(y);
        scan(c);
        q.push(std::mp(-c, y));
    }
    bool found = false;
    scanf("%i", &D);
    while(!q.empty()){
        long long dist = q.top().first;
        short u = q.top().second;
        q.pop();
        if (!visited[u]){
            if (u == D){
                printf("%lli", -dist);
                break;
            }
            visited[u] = 1;
            for(short v : adj[u]){
                q.push(std::mp(dist-edge[u][v], v));
            }
        }
    }
}