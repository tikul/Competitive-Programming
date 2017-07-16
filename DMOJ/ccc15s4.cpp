#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <deque>

#define mp make_pair
#define pii pair<int, int>
#define ppi pair<pair<int, int>, int>
#define ppp pair<pair<int, int>, pair<int, int>>
#define inf 1<<30

using namespace std;

int k, n, m;

vector<int> wear[2001][2001];
vector<pii> info[2001][2001];
int bw[2001];
vector<int> adj[2001];
bool visited[2001];

int main(){
    scanf("%i%i%i", &k, &n, &m);
    int a, b, t, h, A, B;
    for(int i = 0; i < m; i++){
        scanf("%i%i%i%i", &a, &b, &t, &h);
        adj[a].push_back(b);
        adj[b].push_back(a);
        wear[a][b].push_back(h);
        wear[b][a].push_back(h);
        info[a][b].push_back(mp(t,h));
        info[b][a].push_back(mp(t,h));
    }
    for(int i = 1; i < n; i++)
        bw[i] = -1;
    scanf("%i%i", &A, &B);
    bw[B] = k-1;
    deque<int> dq;
    dq.push_back(B);
    while(!dq.empty()){
        int node = dq.front();
        dq.pop_front();
        for(int v : adj[node]){
            for(int e : wear[node][v]){
                if (bw[node]-e > bw[v]){
                    bw[v] = bw[node]-e;
                    dq.push_back(v);
                }
            }
        }
    }
    if (bw[A] < 0){
        printf("-1");
        return 0;
    }
    priority_queue<ppi> q;
    q.push(mp(mp(0, 0), A));
    int count = 0;
    while(!q.empty()){
        int node = q.top().second;
        int dist = -q.top().first.first;
        int check = -q.top().first.second;
        q.pop();
        if (visited[node] || check > bw[node]) continue;
        visited[node] = true;
        if(node == B){
            printf("%i", dist);
            break;
        }
        for(int v : adj[node]){
            for(pii e : info[node][v]){
                q.push(mp(mp(-dist-e.first, -check-e.second), v));
            }
        }
    }
}