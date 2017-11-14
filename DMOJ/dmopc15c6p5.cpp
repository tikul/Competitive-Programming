#include <stdio.h>
#include <set>
using namespace std;
int n, k, a[3000005];
multiset<int> seen;
int main(){
    scanf("%i%i", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%i", a+i);
    }
    int L = 0, R = 0;
    long long cnt = 0;
    while(L < n){
        bool bad = false;
        while(R < n && !bad){
            int x = a[R];
            if(seen.size() == 0){
                seen.insert(x);
                R++;
                continue;
            }
            int lo = *seen.begin();
            int hi = *seen.rbegin();
            if(x < lo && hi-x > k){
                bad = true;
            }else if(x > hi && x-lo > k){
                bad = true;
            }else{
                seen.insert(x);
                R++;
            }
        }
        auto it = seen.find(a[L]);
        seen.erase(it);
        cnt += R-L;
        L++;
    }
    printf("%lli", cnt);
}