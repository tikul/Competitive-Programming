#include <iostream>
#include <algorithm>
#include <utility>

#define pii pair<int, int>
#define mp make_pair

using namespace std;

int A[100002], N, M, a, b;
char q;
struct node{
    int mini;
    int gcd;
    int number;
} S[400009];

int getgcd(int a, int b){
    if (a == 0)
        return b;
    else if (b == 0)
        return a;
    else
        return getgcd(b, a%b);
}

void build(int ti, int l, int r){
    if (l == r){
        S[ti].mini = A[l];
        S[ti].gcd = A[l];
        S[ti].number = 1;
    }else{
        int mid = (l+r)/2;
        build(2*ti, l, mid);
        build(2*ti+1, mid+1, r);
        S[ti].mini = min(S[ti*2].mini, S[ti*2 + 1].mini);
        S[ti].gcd = getgcd(S[ti*2].gcd, S[ti*2 +1].gcd);
        int add = 0;
        if (S[ti].gcd == S[ti*2].gcd)
            add += S[ti*2].number;
        if (S[ti].gcd == S[ti*2 + 1].gcd)
            add += S[ti*2 +1].number;
        S[ti].number = add;
    }
}

void update(int ti, int l, int r, int ai, int x){
    if (l == r){
        S[ti].mini = x;
        S[ti].gcd = x;
    }else{
        int mid = (l+r)/2;
        if (ai <= mid)
            update(2*ti, l, mid, ai, x);
        else
            update(2*ti+1, mid+1, r, ai, x);
        S[ti].mini = min(S[2*ti].mini, S[2*ti+1].mini);
        S[ti].gcd = getgcd(S[2*ti].gcd, S[2*ti+1].gcd);
        int add = 0;
        if (S[ti].gcd == S[2*ti].gcd)
            add += S[2*ti].number;
        if (S[ti].gcd == S[2*ti+1].gcd)
            add += S[2*ti +1].number;
        S[ti].number = add;
    }
}

int querymin(int ti, int tl, int tr, int ql, int qr){
    if (tl >= ql && tr <= qr){
        return S[ti].mini;
    }
    int mid = (tl+tr)/2;
    int val = 1000000007;
    if (tl <= qr && mid >= ql)
        val = min(querymin(2*ti, tl, mid, ql, qr), val);
    if (mid+1 <= qr && tr >= ql)
        val = min(querymin(2*ti+1, mid+1, tr, ql, qr), val);
    return val;
}

int querygcd(int ti, int tl, int tr, int ql, int qr){
    if (tl >= ql && tr <= qr){
        return S[ti].gcd;
    }
    int mid = (tl+tr)/2;
    int val = 0;
    if (tl <= qr && mid >= ql)
        val = getgcd(querygcd(2*ti, tl, mid, ql, qr), val);
    if (mid+1 <= qr && tr >= ql)
        val = getgcd(querygcd(2*ti+1, mid+1, tr, ql, qr), val);
    return val;
}

pii querynumber(int ti, int tl, int tr, int ql, int qr){
    if (tl >= ql && tr <= qr){
        return mp(S[ti].gcd, S[ti].number);
    }
    int mid = (tl+tr)/2;
    pii val = mp(0, 0);
    pii x;
    int ouf, add = 0;
    if (tl <= qr && mid >= ql){
        x = querynumber(2*ti, tl, mid, ql, qr);
        val.first = getgcd(x.first, val.first);
        if (val.first == x.first)
            val.second += x.second;
    }
    if (mid+1 <= qr && tr >= ql){
        x = querynumber(2*ti+1, mid+1, tr, ql, qr);
        ouf = getgcd(x.first, val.first);
        if (ouf == val.first){
            add += val.second;
        }
        if (ouf == x.first){
            add += x.second;
        }
        val.first = ouf;
        val.second = add;
    }
    return val;
}

int main(){
    scanf("%i %i", &N, &M);
    for(int i = 1; i <= N; i++){
        scanf("%i", &A[i]);
    }
    build(1, 1, N);
    int ans;
    pii g;
    for(int i = 0; i < M; i++){
        scanf(" %c %i %i", &q, &a, &b);
        if (q == 'C'){
            A[a] = b;
            update(1, 1, N, a, b);
        }else if (q == 'M'){
            ans = querymin(1, 1, N, a, b);
            printf("%i\n", ans);
        }else if (q == 'G'){
            ans = querygcd(1, 1, N, a, b);
            printf("%i\n", ans);
        }else{
            g = querynumber(1, 1, N, a, b);
            printf("%i\n", g.second);
        }
    }
    return 0;
}