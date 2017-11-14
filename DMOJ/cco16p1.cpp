#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, k;
int ds[1000005], sz[1000005];
bool iscycle[1000005], checked[1000005];

int find(int x){
    if(ds[x]==x) return x;
    return ds[x] = find(ds[x]);
}

int main(){
    memset(iscycle, 0, sizeof(iscycle));
    memset(checked, 0, sizeof(checked));
    scanf("%i%i%i", &n, &m, &k);
    for(int i = 1; i <= n; i++){
        sz[i] = 1;
        ds[i] = i;
    }
    int u, v;
    for(int i = 0; i < m; i++){
        scanf("%i%i", &u, &v);
        u = find(u);
        v = find(v);
        if(u==v){
            iscycle[u] = 1;
        }else{
            if(sz[v]>sz[u]) swap(u,v);
            ds[v] = u;
            sz[u] += sz[v];
        }
    }
    int kids=0, cuts=0; 
    for(int i = 1; i <= n; i++){
        int rep = find(i);
        if(!checked[rep]){
            checked[rep] = 1;
            int amt = sz[rep]/k;
            if(amt>0){
                kids += k*amt;
                if(iscycle[rep] && k==sz[rep]) continue;
                if(iscycle[rep]){
                    cuts += amt;
                    if(sz[rep] > k*amt) cuts++;
                }else{
                    cuts += amt;
                    if(sz[rep] == k*amt) cuts--;
                }
            }
        }
    }
    printf("%i %i", kids, cuts);
}