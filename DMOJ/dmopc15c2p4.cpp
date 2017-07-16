#include <iostream>
#include <map>
#include <algorithm>
#define ull unsigned long long
using namespace std;

int N;
ull starts[100005];
struct anime{
    ull s;
    ull d;
    ull val;
} animes[100005];
map<ull, ull> dp;

ull find_next(int index, ull f){
    auto it = lower_bound(starts+index, starts+N, f);
    if (dp.find(*it) != dp.end()){
        return (*it);
    }else{
        return find_next(index+1, f);
    }
}

int main(){
    scanf("%i", &N);
    dp[1ULL<<41] = 0; //random big number
    starts[N] = 1ULL<<41;
    for(int i = 0; i < N; i++){
        scanf("%llu %llu %llu", &animes[i].s, &animes[i].d, &animes[i].val);
        starts[i] = animes[i].s;
    }
    ull a, b, c;
    for(int i = N-1; i >=0; i--){
        a = animes[i].s;
        b = animes[i].d;
        c = animes[i].val;
        ull ugh = dp[find_next(i, a+b)];
        ull ooh = dp[find_next(i, a)];
        dp[a] = max(c + ugh, ooh);
    }
    printf("%llu\n", dp[starts[0]]);
}