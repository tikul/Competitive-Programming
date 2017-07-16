#include <iostream>
#include <vector>
int N, M, ds[100001], rank[100001] = {0};

int find(int c){
    if (ds[c] == c){
        return c;
    }else{
        return ds[c] = find(ds[c]);
    }
}

int main(){
    scanf("%i %i", &N, &M);
    std::vector<int> v;
    for(int i = 1; i < N+1; i++){
        ds[i] = i;
    }
    int a, b, fa, fb;
    for(int i = 0; i < M; i++){
        scanf("%i %i", &a, &b);
        fa = find(a);
        fb = find(b);
        if (fa != fb){
            if (rank[fa] > rank[fb]){
                ds[fb] = fa;
            }else{
                if (rank[fa] == rank[fb]){
                    rank[fb]++;
                }
                ds[fa] = fb;
            }
            v.push_back(i+1);
        }
    }
    if (v.size() != N-1){
        printf("Disconnected Graph");
    }
    else{
        for(auto it = v.begin(); it != v.end(); it++){
            printf("%i\n", *it);
        }
    }
}