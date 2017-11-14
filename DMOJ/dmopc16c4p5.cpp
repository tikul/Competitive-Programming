#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>

#define pii pair<int, int>
#define ppi pair<int, pii>
#define mp make_pair

using namespace std;

int n, m;
ppi edges[200005];
int ds[200005], best[200005], ranking[200005];
vector<int> group[200005];

int find(int x){
    if(ds[x]==x){
        return x;
    }else{
        return ds[x] = find(ds[x]);
    }
}

struct greaterppi{
    bool operator() (const ppi &lhs, const ppi &rhs) const{
        return lhs.first > rhs.first;
    }
} comp;

int main(){
    scanf("%i%i", &n, &m);
    for(int i = 1; i <= n; i++){
        ranking[i] = 0;
        ds[i] = i;
        group[i].push_back(i);
    }
    int a, b, c;
    for(int i = 0; i < m; i++){
        scanf("%i %i %i", &a, &b, &c);
        edges[i] = mp(c, mp(a,b));
    }
    sort(edges, edges+m, comp);
    for(int i = 0; i < m; i++){
        int w = edges[i].first;
        int x = find(edges[i].second.first);
        int y = find(edges[i].second.second);
        if(x == y) continue;
        if(y == 1) swap(x, y);
        if(x == 1){
            for(int n : group[y]){
                best[n] = w;
                group[1].push_back(n);
            }
            group[y].clear();
            ds[y] = 1;
        }else{
            if(ranking[x] > ranking[y]){
                ds[y] = x;
                for(int n : group[y]){
                    group[x].push_back(n);
                }
                group[y].clear();
            }else{
                if(ranking[x]==ranking[y]) ranking[y]++;
                ds[x] = y;
                for(int n : group[x]){
                    group[y].push_back(n);
                }
                group[x].clear();
            }
        }
    }
    best[1] = 0;
    for(int i = 1; i <= n; i++){
        printf("%i\n", best[i]);
    }
}