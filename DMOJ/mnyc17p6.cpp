#include <iostream>
#include <bitset>
#include <unordered_map>

using namespace std;

bitset<1000> distinct;
unordered_map<int, int> check;
int counts[1001];
int A[100001], N, Q, a;
bitset<1000> S[400004];

void build(int i, int l, int r){
    if (l == r){
        S[i].set(A[l]);
    }else{
        int mid = (l+r)/2;
        build(2*i, l, mid);
        build(2*i+1, mid+1, r);
        S[i] = S[2*i] | S[2*i+1];
    }
}

void update(int i, int l, int r, int n){
    if (l == r){
        S[i].reset();
        S[i].set(A[n]);
    }else{
        int mid = (l+r)/2;
        if (n <= mid)
            update(2*i, l, mid, n);
        else
            update(2*i+1, mid+1, r, n);
        S[i] = S[2*i] | S[2*i+1];
    }
}

bitset<1000> query(int i, int l, int r, int qr, int ql){
    if (l >= ql && r <= qr){
        return S[i];
    }else{
        int mid = (l+r)/2;
        bitset<1000> temp;
        if (ql <= mid && qr >= l){
            temp = temp | query(2*i, l, mid, qr, ql);
        }
        if (qr >= mid+1 && ql <= r){
            temp = temp | query(2*i+1, mid+1, r, qr, ql);
        }
        return temp;
    }
}

int main(){
    int ind = 0;
    scanf("%i %i", &N, &Q);
    for(int i = 1; i <= N; i++){
        scanf("%i", &a);
        if (check.find(a) != check.end()){
            counts[check[a]]++;
        }else{
            check[a] = ind;
            counts[ind]++;
            ind++;
        }
        A[i] = check[a];
    }
    build(1, 1, N);
    int x, y, z;
    int ans;
    for(int i = 0; i < Q; i++){
        scanf("%i %i %i", &x, &y, &z);
        if (x == 1){
            counts[A[y]]--;
            if (counts[A[y]] > 0){
                if (check.find(z) != check.end()){
                    counts[check[z]]++;
                    A[y] = check[z];
                }else{
                    A[y] = ind;
                    check[z] = ind;
                    ind++;
                }
                update(1, 1, N, y);
            }else{
                if (check.find(z) != check.end()){
                    counts[check[z]]++;
                    A[y] = check[z];
                    update(1, 1, N, y);
                }else{
                    check[z] = A[y];
                    counts[A[y]]++;
                }
            }
        }else{
            ans = query(1, 1, N, z, y).count();
            printf("%i\n", ans);
        }
    }
}