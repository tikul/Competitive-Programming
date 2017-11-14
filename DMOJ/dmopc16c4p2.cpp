#include <set>
#include <stdio.h>
using namespace std;

int N, F;
set<int> failed;
struct Batch{
    int st, ed, pts;
} cases[100005];

int main(){
    scanf("%i", &N);
    int tot = 0;
    for(int i = 0; i < N; i++){
        scanf("%i %i %i", &cases[i].st, &cases[i].ed, &cases[i].pts);
        tot += cases[i].pts;
    }
    scanf("%i", &F);
    int x;
    for(int i = 0; i < F; i++){
        scanf("%i", &x);
        failed.insert(x);
    }
    for(int i = 0; i < N; i++){
        int st = cases[i].st, ed = cases[i].ed;
        auto it = failed.lower_bound(st);
        if(*it <= ed && *it >= st){
            tot -= cases[i].pts;
        }
    }
    printf("%i", tot);
}