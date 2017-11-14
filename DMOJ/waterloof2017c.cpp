#include <stdio.h>
#include <algorithm>
#include <utility>
#include <set>
#define pii pair<int, int>
using namespace std;
int N, K, A[200005];
set<pii> seen;

int main(){
    scanf("%i %i", &N, &K);
    for(int i = 0; i < N; i++){
        scanf("%i", A+i);
    }
    sort(A, A+N);
    int best = 0;
    for(int i = 0; i < N; i++){
        if(i <= N-K) seen.insert({A[i+K-1]-A[i], i});
        auto it = seen.begin();
        while(it->second < i-K+1){
            seen.erase(it);
            it = seen.begin();
        }
        best = max(best, it->first);
    }
    printf("%i", best);
}