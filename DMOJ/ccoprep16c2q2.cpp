#include <iostream>
#include <set>
#include <utility>

#define pii pair<int, int>
#define mp make_pair
using namespace std;

int N, a,b;
set<pii> seen;

int main(){
    scanf("%i", &N);
    int ans = 1;
    for(int i = 0; i < N; i++){
        scanf("%i", &a);
        b = 1;
        for(auto it = seen.begin(); it != seen.end(); it++){
            if((*it).second & a){
                b = -(*it).first+1;
                break;
            }
        }
        ans = b>ans?b:ans;
        seen.insert(mp(-b, a));
    }
    printf("%i", ans);
}