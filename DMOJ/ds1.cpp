#include <iostream>
#define ll long long
int N, M, a, b, A[100001];
ll BIT[100001];
int freq[100001];
char q;

void updater(int i, int x){
    for(; i <= N; i += i&-i)
        BIT[i] += x;
}

void updatef(int i, int x){
    for(; i <= 100000; i += i&-i)
        freq[i] += x;
}

ll queryr(int l, int r){
    ll ans = 0;
    for(; r>0; r -= r&-r)
        ans += BIT[r];
    for(; l>0; l -= l&-l)
        ans -= BIT[l];
    return ans;
}

int queryf(int i){
    int ans = 0;
    for(; i>0; i -= i&-i)
        ans += freq[i];
    return ans;
}

int main(){
    scanf("%i %i", &N, &M);
    for(int i = 1; i <= N; i++){
        scanf("%i", &A[i]);
        updater(i, A[i]);
        updatef(A[i], 1);
    }
    ll ans;
    for(int i = 0; i < M; i++){
        scanf(" %c", &q);
        if (q=='C'){
            scanf("%i %i", &a, &b);
            updater(a, b-A[a]);
            updatef(A[a], -1);
            updatef(b, 1);
            A[a] = b;
        }else if (q=='S'){
            scanf("%i %i", &a, &b);
            ans = queryr(a-1, b);
            printf("%lli\n", ans);
        }else{
            scanf("%i", &a);
            ans = queryf(a);
            printf("%i\n", ans);
        }
    }
}