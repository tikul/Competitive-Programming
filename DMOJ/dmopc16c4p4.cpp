#include <stdio.h>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>

#define mp make_pair
#define pii pair<int, int>
#define ppi pair<pair<int,int>, int>

using namespace std;
int n, q, manga[100005], ans[100005], freq[100005], block, res=0;
ppi queries[100005];

bool comp(const ppi &lhs, const ppi &rhs){
    if(lhs.first.first/block != rhs.first.first/block)
        return lhs.first.first/block < rhs.first.first/block;
    else
        return lhs.first.second < rhs.first.second;
}

void add(int pos){
    int x = ++freq[manga[pos]];
    if(x % 2 == 0) res++;
    else if(x > 1 && x % 2 == 1) res--;
}

void sub(int pos){
    int x = --freq[manga[pos]];
    if(x > 0 && x % 2 ==0) res++;
    else if(x > 0 && x % 2 ==1) res--;
}

int main(){
    memset(freq, 0, sizeof(freq));
    scanf("%i", &n);
    for(int i = 1; i <= n; i++)
        scanf("%i", &manga[i]);
    manga[0] = 0;
    block = sqrt(n);
    int a, b;
    scanf("%i", &q);
    for(int i = 0; i < q; i++){
        scanf("%i%i", &a, &b);
        queries[i] = mp(mp(a,b), i);
    }
    sort(queries, queries+q, &comp);
    int l, r, ind, L=0, R=0;
    for(int i = 0; i < q; i++){
        l = queries[i].first.first;
        r = queries[i].first.second;
        ind = queries[i].second;
        while(R < r){
            R++;
            add(R);
        }
        while(L > l){
            L--;
            add(L);
        }
        while(R > r){
            sub(R);
            R--;
        }
        while(L < l){
            sub(L);
            L++;
        }
        ans[ind] = res;
    }
    for(int i = 0; i < q; i++)
        printf("%i\n", ans[i]);
}