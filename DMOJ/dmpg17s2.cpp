#include <iostream>
#include <algorithm>

int N, Q;

int ds[200001];
int rank[200001];

int find(int x){
    if (ds[x] == x)
        return x;
    else{
        return ds[x] = find(ds[x]);
    }
}

int main(){
    scanf("%i %i", &N, &Q);
    for(int i = 1; i <= N; i++)
        ds[i] = i;
    char a;
    int b, c, u, v;
    for(int i = 0; i < Q; i++){
        scanf(" %c %i %i", &a, &b, &c);
        u = find(b);
        v = find(c);
        if(a == 'A'){
            if (u != v){
                if (rank[u] > rank[v]){
                    ds[v] = u;
                }else{
                    if(rank[u] == rank[v]){
                        rank[v]++;
                    }
                    ds[u] = v;
                }
            }
        }else{
            printf(u==v?"Y\n":"N\n");
        }
    }
}