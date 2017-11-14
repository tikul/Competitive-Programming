#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#define mod 1000000007
#define seed 7349
using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    int sl=s.length(), tl=t.length();
    int len=min(sl, tl);
    long long prevt=0,prevs=0,prevexp=1;
    int best = -1;
    for(int i = 0; i < len; i++){
        prevt = ((prevt*seed) + t[i])%mod;
        if(i != 0){
            prevexp = (seed*prevexp)%mod;
        }
        prevs = (prevs + s[sl-i-1]*prevexp)%mod;
        if(prevt==prevs){
            best = i;
        }
    }
    cout << s+t.substr(best+1);
}