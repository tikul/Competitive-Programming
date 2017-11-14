#include <stdio.h>

int n;
int tree[65000];

void po(int l, int i){
    if(l >= n) return;
    printf("%i ", tree[i]);
    po(l+1, i<<1);
    po(l+1, i<<1|1);
}

int main(){
    scanf("%i", &n);
    int T = 1, t = 1;
    for(int L = n-1; L >= 1; L--){
        t = T;
        int nodes = 1<<L;
        for(int n = nodes; n < 1<<L+1; n+=2){
            tree[n] = t;
            tree[n+1] = t+nodes/2;
            t++;
        }
        T += nodes;
    }
    tree[1] = (1<<n)-1;
    po(0,1);
}