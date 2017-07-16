#include <stdio.h>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

int dist[100005];
struct compare{
    bool operator() (const int &lhs, const int &rhs){
        if(dist[lhs] < dist[rhs]){
            return true;
        }else if(dist[rhs] < dist[lhs]){
            return false;
        }else{
            return lhs < rhs;
        }
    }
};
int n, s, q;

set<int, compare> apples[101];
unordered_set<int> stalls[100005];
int main(){
    scanf("%i%i", &n, &s);
    for(int i = 1; i <= n; i++)
        scanf("%i", &dist[i]);
    int a, b;
    for(int i = 0; i < s; i++){
        scanf("%i%i", &a, &b);
        stalls[a].insert(b);
        apples[b].insert(a);
    }
    scanf("%i", &q);
    char f;
    while(q--){
        scanf(" %c", &f);
        if(f=='A'){
            scanf("%i%i", &a, &b);
            stalls[a].insert(b);
            apples[b].insert(a);
        }else if(f=='S'){
            scanf("%i%i", &a, &b);
            stalls[a].erase(b);
            apples[b].erase(a);
        }else if(f=='E'){
            scanf("%i %i", &a, &b);
            for(auto it = stalls[a].begin(); it != stalls[a].end(); it++){
                apples[*it].erase(a);
            }
            dist[a] = b;
            stalls[a].clear();
        }else{
            scanf("%i", &a);
            if(apples[a].size()){
                auto it = apples[a].begin();
                printf("%i\n", *it);
            }else{
                printf("-1\n");
            }
        }
    }
}