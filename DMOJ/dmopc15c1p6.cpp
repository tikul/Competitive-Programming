#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cassert>

#define inf 1<<30
#define left(i) i << 1
#define right(i) i << 1 | 1

int n, m, q, arr[200005];

struct node{
    int tot;
    int lazy;
} seg[800011];

void push_down(int i, int l, int r){
    if(seg[i].lazy){
        seg[i].tot = (seg[i].tot + ((r-l+1)%m)*(seg[i].lazy))%m;
        if(l != r){
            seg[left(i)].lazy = (seg[left(i)].lazy+seg[i].lazy)%m;
            seg[right(i)].lazy = (seg[right(i)].lazy+seg[i].lazy)%m;
        }
        seg[i].lazy = 0;
    }
}

void push_up(int i, int l, int r){
    if(l != r){
        int mid = (l+r)/2;
        push_down(left(i), l, mid);
        push_down(right(i), mid+1, r);
    }
    seg[i].tot = (seg[left(i)].tot + seg[right(i)].tot)%m;
}

void build(int i, int l, int r){
    if(l==r){
        seg[i].tot = arr[l]%m;
        seg[i].lazy = 0;
    }else{
        int mid = (l+r)/2;
        build(left(i), l, mid);
        build(right(i), mid+1, r);
        seg[i].tot = (seg[left(i)].tot + seg[right(i)].tot)%m;
        seg[i].lazy = 0;
    }
}

void update(int i, int l, int r, int ql, int qr, int val){
    push_down(i, l, r);
    if(l >= ql && r <= qr){
        seg[i].lazy = (seg[i].lazy + val)%m;
        push_down(i, l, r);
    }else{
        int mid = (l+r)/2;
        if(ql <= mid && qr >= l)
            update(left(i), l, mid, ql, qr, val);
        if(ql <= r && qr >= mid+1)
            update(right(i), mid+1, r, ql, qr, val);
        push_up(i, l, r);
    }
}

int query(int i, int l, int r, int ql, int qr){
    push_down(i, l, r);
    if(l >= ql && r <= qr){
        return seg[i].tot;
    }else{
        int mid = (l+r)/2;
        int res = 0;
        if(ql <= mid && qr >= l)
            res = (res + query(left(i), l, mid, ql, qr))%m;
        if(ql <= r && qr >= mid+1)
            res = (res + query(right(i), mid+1, r, ql, qr))%m;
        return res;
    }
}

int main(){
    scanf("%i%i%i", &m, &n, &q);
    for(int i = 1; i <= n; i++)
        scanf("%i", &arr[i]);
    build(1, 1, n);
    int op, a, b, c, ans;
    for(int i = 0; i < q; i++){
        scanf("%i", &op);
        if(op == 1){
            scanf("%i %i %i", &a, &b, &c);
            update(1, 1, n, a, b, c);
        }else{
            scanf("%i %i", &a, &b);
            ans = query(1, 1, n, a, b);
            printf("%i\n", ans);
        }
    }
}