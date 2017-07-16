#include <algorithm>
#include <stdio.h>
#include <cstring>

using namespace std;

#define left(i) i << 1
#define right(i) i << 1 | 1
#define inf 0x3f3f3f3f

struct node{
    int mini;
    int lazy;
} seg[120075];

int n, q, arr[30005];

void push_down(int i, int l, int r){
    if(seg[i].lazy != 0){
        seg[i].mini = max(0, seg[i].lazy+seg[i].mini);
        if(l != r){
            seg[left(i)].lazy = max(-inf, seg[i].lazy+seg[left(i)].lazy);
            seg[right(i)].lazy = max(-inf, seg[i].lazy+seg[right(i)].lazy);
        }
        seg[i].lazy = 0;
    }
}

void push_up(int i, int l, int r){
    int mid = (l+r)/2;
    push_down(left(i), l, mid);
    push_down(right(i), mid+1, r);
    seg[i].mini = min(seg[left(i)].mini, seg[right(i)].mini);
}

void build(int i, int l, int r){
    if(l==r){
        seg[i].mini = arr[l];
        seg[i].lazy = 0;
    }else{
        int mid = (l+r)/2;
        build(left(i), l, mid);
        build(right(i), mid+1, r);
        seg[i].mini = min(seg[left(i)].mini, seg[right(i)].mini);
        seg[i].lazy = 0;
    }
} 

void update(int i, int l, int r, int ql, int qr, int val){
    push_down(i, l, r);
    if(l >= ql && r <= qr){
        seg[i].lazy = max(-inf, seg[i].lazy+val);
        push_down(i, l, r);
    }else{
        int mid = (l+r)/2;
        if(ql <= mid && qr >= l){
            update(left(i), l, mid, ql, qr, val);
        }
        if(ql <= r && qr >= mid+1){
            update(right(i), mid+1, r, ql, qr, val);
        }
        push_up(i, l, r);
    }
}

int query(int i, int l, int r, int ql, int qr){
    push_down(i, l, r);
    if(l >= ql && r <= qr){
        return seg[i].mini;
    }else{
        int mid = (l+r)/2;
        int res = inf;
        if(ql <= mid && qr >= l){
            res = min(res, query(left(i), l, mid, ql, qr));
        }
        if(ql <= r && qr >= mid+1){
            res = min(res, query(right(i), mid+1, r, ql, qr));
        }
        return res;
    }
}

int main(){
    scanf("%i %i", &n, &q);
    for(int i = 1; i <= n; i++){
        scanf("%i", &arr[i]);
    }
    build(1, 1, n);
    int a, b, c, f, s;
    for(int i = 0; i < q; i++){
        scanf("%i %i %i", &a, &b, &c);
        update(1, 1, n, a, b, -c);
        f = query(1, 1, n, a, b);
        s = seg[1].mini;
        printf("%i %i\n", f, s);
    }
}