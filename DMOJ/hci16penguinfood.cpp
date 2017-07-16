#include <stdio.h>
#include <algorithm>


#define left(x) x<<1
#define right(x) x<<1|1
typedef long long ll;

using namespace std;

int n, m, arr[1000003];

struct node{
    int pre, suf, tot, best;
    node (){};
    node(int x) : pre(x), suf(x), tot(x), best(x){}
} seg[4000003];

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

int main(){
    scanf("%i", &n);
    for(int i = 1; i <= n; i++){
        scanf("%i", &arr[i]);
    }
    build(1, 1, n);
    printf("%i\n", seg[1].best);
    scanf("%i", &m);
    int a, b;
    for(int i = 0; i < m; i++){
        scanf("%i %i", &a, &b);
        a++;
        update(1, 1, n, b, a);
        printf("%i\n", seg[1].best>0?seg[1].best:0);
    }   
}