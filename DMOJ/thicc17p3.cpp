#include <stdio.h>
#include <set>
#include <utility>
#include <vector>

#define mp make_pair
#define pii pair<int, int>
#define pb push_back

using namespace std;

int n, q, day=0;
vector<pii> loc[1000005];

int main(){
    int x;
    scanf("%i", &n);
    for(int i = 1; i <= n; i++){
        scanf("%i", &x);
        loc[i].pb(mp(x, 0));
    }
    scanf("%i", &q);
    char op;
    int a, b;
    while(q--){
        scanf(" %c %i %i", &op, &a, &b);
        if(op == 'C'){
            day++;
            loc[a].push_back(mp(b, day));
        }else{
            int lo = 0;
            int hi = loc[a].size()-1;
            int m = 0;
            while(lo <= hi){
                m = (lo+hi)/2;
                if(loc[a][m].second < b){
                    lo = m+1;
                }else if(loc[a][m].second > b){
                    hi = m-1;
                }else{
                    break;
                }
            }
            if(m < loc[a].size() && loc[a][m].second <= b){
                printf("%i\n", loc[a][m].first);
            }else{
                printf("%i\n", loc[a][m-1].first);
            }
        }
    }
    // for(int i =1; i <= n; i++){
    //     printf("%i: ", i);
    //     for(pii v: loc[i]){
    //         printf("{%i, %i} ", v.first, v.second);
    //     }
    //     printf("\n");
    // }

}