#include <stdio.h>
#include <algorithm>
#include <cstring>

long long bit[252][252][252];
int ar[252][252][252];
int n, q;

void update(int a, int b, int c, int x){
    for(int i = a; i <= n; i += i&-i){
        for(int j = b; j <= n; j += j&-j){
            for(int k = c; k <= n; k += k&-k){
                bit[i][j][k] += x;
            }
        }
    }
}

long long query(int a, int b, int c){
    long long ret = 0;
    for(int i = a; i; i -= i&-i){
        for(int j = b; j; j -= j&-j){
            for(int k = c; k; k -= k&-k){
                ret += bit[i][j][k];
            }
        }
    }
    return ret;
}

int main(){
    memset(ar, 0, sizeof(ar));
    memset(bit, 0, sizeof(bit));
    scanf("%i%i", &n, &q);
    char op;
    int x1, x2, y1, y2, z1, z2, w;
    long long res = 0;
    while(q--){
        scanf(" %c", &op);
        if(op=='C'){
            scanf("%i %i %i %i", &x1, &y1, &z1, &w);
            update(x1, y1, z1, w-ar[x1][y1][z1]);
            ar[x1][y1][z1] = w;
        }else{
            scanf("%i %i %i %i %i %i", &x1, &y1, &z1, &x2, &y2, &z2);
            x1--; y1--; z1--;
            res += query(x2, y2, z2);
            res += query(x1, y1, z2);
            res -= query(x1, y2, z2);
            res -= query(x2, y1, z2);
            res += query(x2, y1, z1);
            res -= query(x1, y1, z1);
            res -= query(x2, y2, z1);
            res += query(x1, y2, z1);
        }
    }
    printf("%lli\n", res);
}