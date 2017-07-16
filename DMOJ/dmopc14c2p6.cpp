#include <iostream>
#include <utility>
#include <vector>
#include <cstring>
#include <tuple>

using namespace std;

#define pii pair<int, int>
#define mp make_pair
#define mt make_tuple
#define ti tuple<int, int, int>


int S[400005], N, Q, a, b, c;
int order[100001];
vector<ti> queries[20001];
vector<int> masses[20001];

void update(int i, int l, int r, int ni, int x){
    if (l==r){
        S[i] = x;
    }else{
        int mid = (l+r)/2;
        if (ni <= mid)
            update(2*i, l, mid, ni, x);
        else
            update(2*i+1, mid+1, r, ni, x);
        S[i] = S[2*i]+S[2*i+1];
    }
}

int getsum(int i, int l, int r, int nl, int nr){
    if(l >= nl && r <= nr){
        return S[i];
    }else{
        int ans = 0;
        int mid = (l+r)/2;
        if (l <= nr && mid >= nl)
            ans += getsum(2*i, l, mid, nl, nr);
        if(mid+1 <= nr && r >= nl)
            ans += getsum(2*i+1, mid+1, r, nl, nr);
        return ans;
    }
}

int main(){
    scanf("%i", &N);
    memset(S, 0, sizeof(S));
    for(int i = 1; i <= N; i++){
        scanf("%i", &a);
        masses[a].push_back(i);
    }
    scanf("%i", &Q);
    for(int i = 0; i < Q; i++){
        scanf("%i %i %i", &a, &b, &c);
        queries[c].push_back(mt(i,a+1,b+1));
    }
    int x, y, z;
    for(int i = 20000; i >= 1; i--){
        for(int j : masses[i]){
            update(1, 1, N, j, i);
        }
        for(auto query: queries[i]){
            tie(x, y, z) = query;
            order[x] = getsum(1, 1, N, y, z);
        }
    }
    for(int i = 0; i < Q; i++){
        printf("%i\n", order[i]);
    }
}