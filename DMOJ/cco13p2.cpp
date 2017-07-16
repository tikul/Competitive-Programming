#include <iostream>

int A[(1<<20)+1], N, M, a, b;
char q;

struct node{
    int skill;
    int ind;
    int wins;
} S[1<<22];

void build(int i, int l, int r){
    if (l==r){
        S[i].skill = A[l];
        S[i].ind = l;
        S[i].wins = 0;
    }else{
        int mid = (l+r)/2;
        build(2*i, l, mid);
        build(2*i+1, mid+1, r);
        if (S[2*i].skill>S[2*i+1].skill){
            S[i].skill = S[2*i].skill;
            S[i].ind = S[2*i].ind;
            S[i].wins = S[2*i].wins+1;
        }else{
            S[i].skill = S[2*i+1].skill;
            S[i].ind = S[2*i+1].ind;
            S[i].wins = S[2*i+1].wins+1;
        }
    }
}

void update(int i, int l, int r, int x, int s){
    if (l == r){
        S[i].skill = s;
        S[i].ind = x;
        S[i].wins = 0;
    }else{
        int mid = (l+r)/2;
        if (x <= mid){
            update(2*i, l, mid, x, s);
        }else{
            update(2*i+1, mid+1, r, x, s);
        }
        if (S[2*i].skill>S[2*i+1].skill){
            S[i].skill = S[2*i].skill;
            S[i].ind = S[2*i].ind;
            S[i].wins = S[2*i].wins+1;
        }else{
            S[i].skill = S[2*i+1].skill;
            S[i].ind = S[2*i+1].ind;
            S[i].wins = S[2*i+1].wins+1;
        }
    }
}

int query(int i, int l, int r, int x){
    if (S[i].ind == x){
        return S[i].wins;
    }else{
        int mid = (l+r)/2;
        if (x <= mid)
            return query(2*i, l, mid, x);
        else
            return query(2*i+1, mid+1, r, x);
    }
}

int main(){
    scanf("%i %i", &N, &M);
    for(int i =1 ; i<= (1<<N); i++){
        scanf("%i", &A[i]);
    }
    build(1, 1, (1<<N));
    int ans;
    for(int i = 0; i < M; i++){
        scanf(" %c", &q);
        if (q == 'R'){
            scanf("%i %i", &a, &b);
            update(1, 1, (1<<N), a, b);
        }else if(q == 'W'){
            printf("%i\n", S[1].ind);
        }else{
            scanf("%i", &a);
            ans = query(1, 1, (1<<N), a);
            printf("%i\n", ans);
        }
    }
}