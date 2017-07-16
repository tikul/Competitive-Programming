#include <iostream>

int ds[1501];
int out[1501];
int ranking[1501];

int find(int x){
    if (ds[x] == x)
        return x;
    else{
        return ds[x] = find(ds[x]);
    }
}

void initialize(int n){
    for(int i = 0; i < n; i++){
        ds[i] = i;
        out[i] = n-1;
        ranking[i] = 0;
    }
}

int hasEdge(int u, int v){
    int a = find(u);
    int b = find(v);
    if(a == b) return 1; //subtract out?
    if (out[a] > 1 && out[b] > 1){
        out[a]--;
        out[b]--;
        return 0;
    }
    if (ranking[a] > ranking[b]){
        ds[b] = a;
        out[a] += out[b]-2;
    }else{
        if (ranking[a] == ranking[b])
            ranking[b]++;
        ds[a] = b;
        out[b] += out[a]-2;
    }
    return 1;
}