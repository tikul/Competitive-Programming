#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
#include <unordered_set>
#include <set>
#include <unordered_map>
using namespace std;
#define sL(i) i << 1
#define sR(i) i << 1 | 1
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>, int> ppi;

int n, cur=0;
int cnts[7];
unordered_map<string, int> conv;
unordered_set<string> seen;
string s;
int best;

int rec(int i, int j){
    if(i >= cur){
        //cout << j << " " << n-j << "\n";
        if(j== n-j){
            best = max(best, 2*j);
        }else{
            best = max(best, 2*min(j, n-j)+1);
        }
    }else{
        rec(i+1, j+cnts[i]);
        rec(i+1, j);
    }
}

int main(){
    memset(cnts, 0, sizeof(cnts));
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(seen.count(s)){
            cnts[conv[s]]++;
        }else{
            seen.insert(s);
            conv[s] = cur++;
            cnts[conv[s]]++;
        }
    }
    rec(0, 0);
    cout << best;

}