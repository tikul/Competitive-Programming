#include <stdio.h>
#include <cstring>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define ppi pair<pii, int>
using namespace std;

int n, ds[500005], rnk[500005], sz[500005];
vector<ppi> edges;

int find(int x){
    if(ds[x]==x) return x;
    return find(ds[x]);
}

void Init(int N){
    n = N;
    for(int i = 1; i <= n; i++){
        ds[i] = i;
        rnk[i] = 0;
        sz[i] = 1;
    }
}

void AddEdge(int U, int V){
    int a = find(U);
    int b = find(V);
    if(a==b){
        edges.push_back({{0, 0}, 0});
    }else if(rnk[a] > rnk[b]){
        ds[b] = a;
        sz[a] += sz[b];
        edges.push_back({{a,b}, 0});
    }else{
        int t = 0;
        if(rnk[a]==rnk[b]){
            rnk[b]++;
            t = 1;
        }
        ds[a] = b;
        sz[b] += sz[a];
        edges.push_back({{b,a}, t});
    }
}

void RemoveLastEdge(){
    ppi e = *(edges.rbegin());
    edges.pop_back();
    int u = e.first.first; //big
    int v = e.first.second; //small
    int t = e.second;
    if(u != 0){
       sz[u] -= sz[v];
       ds[v] = v;
       if(t) rnk[u]--;
    }
}

int GetSize(int U){
    int a = find(U);
    return sz[a];
}