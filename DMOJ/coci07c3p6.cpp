#include <stdio.h>
#include <algorithm>

using namespace std;

#define maxn 250002
#define inf 1<<30
#define left(i) i << 1
#define right(i) i << 1 | 1

struct node{
    int tot;
    int cnt[10];
    int lazy;
} seg[4*maxn];

int n, m;
char config[maxn];

int push_down(int i, int l, int r){
    if(seg[i].lazy){
        //printf("xd %i %i\n", l, r);
        if(l != r){
            seg[left(i)].lazy += seg[i].lazy;
            seg[right(i)].lazy += seg[i].lazy;
        }
        int temp[10];
        int h = seg[i].lazy;
        //printf("%i HAYCHE\n", h);
        int res = 0;
        //printf("si9 %i\n", seg[i].cnt[9]);
        for(int j = 0; j < 10; j++){
            temp[(j+h)%10] = seg[i].cnt[j];
            int x =((j+h)%10) * seg[i].cnt[j];
            //printf("%i kajfa\n", x);
            res += x;
        }
        for(int j = 0; j < 10; j++){
            seg[i].cnt[j] = temp[j];
        }
        seg[i].tot = res;
        //printf("after push down %i\n", seg[i].tot);
        seg[i].lazy = 0;
    }
}

int push_up(int i, int l, int r){
    int mid = (l+r)/2;
    push_down(left(i), l, mid);
    push_down(right(i), mid+1, r);
    int res = 0;
    for(int j = 0; j < 10; j++){
        seg[i].cnt[j] = seg[left(i)].cnt[j]+seg[right(i)].cnt[j];
        res += j*seg[i].cnt[j];
    }
    seg[i].tot = res;
}

void build(int i, int l, int r){
    if(l==r){
        seg[i].tot = config[l-1]-'0';
        seg[i].cnt[config[l-1]-'0'] = 1;
        seg[i].lazy = 0;
        // printf("L: %i R: %i TOT: %i\n", l, r, seg[i].tot);
    }else{
        int mid = (l+r)/2;
        build(left(i), l, mid);
        build(right(i), mid+1, r);
        push_up(i, l, r);
        seg[i].lazy = 0;
        // printf("L: %i R: %i TOT: %i\n", l, r, seg[i].tot);
    }
}

void update(int i, int l, int r, int ql, int qr){
    push_down(i, l, r);
    if(l==r){
        int res = 0;
        int temp[10];
        for(int j = 0; j < 10; j++){
            temp[(j+1)%10] = seg[i].cnt[j];
            res += ((j+1)%10) * seg[i].cnt[j];
        }
        for(int j = 0; j < 10; j++){
            seg[i].cnt[j] = temp[j];
        }
        seg[i].tot = res;
        seg[i].lazy = 0;
        // printf("UPDATE L: %i R: %i TOT: %i\n", l, r, seg[i].tot);
    }else if(l >= ql && r <= qr){
        seg[left(i)].lazy++;
        seg[right(i)].lazy++;
        int res = 0;
        int temp[10];
        for(int j = 0; j < 10; j++){
            temp[(j+1)%10] = seg[i].cnt[j];
            res += ((j+1)%10) * seg[i].cnt[j];
        }
        for(int j = 0; j < 10; j++){
            seg[i].cnt[j] = temp[j];
        }
        seg[i].tot = res;
        // printf("UPDATE L: %i R: %i TOT: %i\n", l, r, seg[i].tot);
    }else{
        int mid = (l+r)/2;
        if(qr >= l && ql <= mid){
            update(left(i), l, mid, ql, qr);
        }
        if(qr >= mid+1 && ql <= r){
            update(right(i), mid+1, r, ql, qr);
        }
        push_up(i, l, r);
        // printf("UPDATE L: %i R: %i TOT: %i\n", l, r, seg[i].tot);
    }
}

int query(int i, int l, int r, int ql, int qr){
    push_down(i, l, r);
    if(l >= ql && r <= qr){
        // printf("QUERY HERE: L: %i R: %i TOT: %i\n", l, r, seg[i].tot);
        return seg[i].tot;
    }else{
        int mid = (l+r)/2;
        int res = 0;
        if(qr >= l && ql <= mid){
            res += query(left(i), l, mid, ql, qr);
        }
        if(qr >= mid+1 && ql <= r){
            res += query(right(i), mid+1, r, ql, qr);
        }
        // printf("QUERY HERE: L: %i R: %i TOT: %i\n", l, r, res);
        return res;
    }
}

int main(){
    scanf("%i %i", &n, &m);
    scanf("%s", config);
    build(1, 1, n);
    // printf("%i %i\n",seg[2].tot, seg[3].tot);
    int a, b,ans;
    for(int i = 0; i < m; i++){
        scanf("%i %i", &a, &b);
        ans = query(1, 1, n, a, b);
        //printf("kms %i\n", seg[5].tot);
        printf("%i\n", ans);
        update(1, 1, n, a, b);
        // printf("-----------------\n");
    }
}