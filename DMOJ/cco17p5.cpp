#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

#define pii pair<int, int>
#define mp make_pair

using namespace std;

int N;
pii A[200001];

int main(){
    scanf("%i", &N);
    int a,b;
    for(int i = 1; i <= N; i++){
        scanf("%i %i", &a, &b);
        A[i] = mp(-a, b);
    }
    sort(A+1, A+1+N);
    int ai, bi;
    int bought = 0;
    int ans = 0;
    priority_queue<int> q;
    for(int i = 1; i <= N; i++){
        ai = -A[i].first;
        bi = A[i].second;
        q.push(-bi);
        if(N-i + bought < ai){
            for(int j = 0; j < ai-(N-i+bought); j++){
                ans -= q.top();
                q.pop();
                bought++;
            }
        }
    }
    printf("%i", ans);
}