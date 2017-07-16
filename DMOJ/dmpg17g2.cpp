#include <stdio.h>
#include <algorithm>

#define inf 1LL<<50
#define left(x) x<<1
#define right(x) x<<1|1
typedef long long ll;

using namespace std;

int n, q, arr[100003];

struct node{
    ll pre, suf, tot, best;
    node (){ pre = suf = tot = best = inf;};
    node(ll x) : pre(x), suf(x), tot(x), best(x){}
} seg[400003];

void build(int i, int l, int r){
    if(l==r){
        seg[i] = node(arr[l]);
    }else{
        int mid = (l+r)/2;
        build(left(i), l, mid);
        build(right(i), mid+1, r);
        seg[i].tot = seg[left(i)].tot + seg[right(i)].tot;
        seg[i].pre = max(seg[left(i)].pre, seg[left(i)].tot + seg[right(i)].pre);
        seg[i].suf = max(seg[right(i)].suf, seg[left(i)].suf + seg[right(i)].tot);
        seg[i].best = seg[left(i)].suf + seg[right(i)].pre;
        seg[i].best = max(seg[left(i)].best, seg[i].best);
        seg[i].best = max(seg[i].best, seg[right(i)].best);
    }
}

void update(int i, int l, int r, int val, int ind){
    if(l==r){
        arr[ind] = val;
        seg[i] = node(val);
    }else{
        int mid = (l+r)/2;
        if(ind <= mid){
            update(left(i), l, mid, val, ind);
        }else{
            update(right(i), mid+1, r, val, ind);
        }
        seg[i].tot = seg[left(i)].tot + seg[right(i)].tot;
        seg[i].pre = max(seg[left(i)].pre, seg[left(i)].tot + seg[right(i)].pre);
        seg[i].suf = max(seg[right(i)].suf, seg[left(i)].suf + seg[right(i)].tot);
        seg[i].best = seg[left(i)].suf + seg[right(i)].pre;
        seg[i].best = max(seg[left(i)].best, seg[i].best);
        seg[i].best = max(seg[i].best, seg[right(i)].best);
    }
}

node query(int i, int l, int r, int ql, int qr){
    if(l >= ql && r <= qr){
        return seg[i];
    }
    int mid = (l+r)/2;
    node resl, resr, ret;
    if(ql <= mid && qr >= l){
        resl = query(left(i), l, mid, ql, qr);
    }
    if (qr >= mid+1 && ql <= r){
        resr = query(right(i), mid+1, r, ql, qr);
    }
    if(resl.best == inf){
        return resr;
    }else if(resr.best == inf){
        return resl;
    }else{
        ret.tot = resl.tot + resr.tot;
        ret.pre = max(resl.pre, resl.tot + resr.pre);
        ret.suf = max(resr.suf, resl.suf + resr.tot);
        ret.best = resl.suf + resr.pre;
        ret.best = max(resl.best, ret.best);
        ret.best = max(resr.best, ret.best);
        return ret;
    }
}

int main(){
    scanf("%i %i", &n, &q);
    for(int i = 1; i <= n; i++){
        scanf("%i", &arr[i]);
    }
    build(1, 1, n);
    char xd;
    int a, b;
    for(int i = 0; i < q; i++){
        scanf(" %c %i %i", &xd, &a, &b);
        if(xd == 'S'){
            update(1, 1, n, b, a);
        }else{
            node ans = query(1, 1, n, a, b);
            printf("%lli\n", ans.best);
        }
    }
}