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

int n;
set<string> seen;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(seen.count(s)) cout << "YES\n";
        else{
            cout << "NO\n";
            seen.insert(s);
        }
    }
}