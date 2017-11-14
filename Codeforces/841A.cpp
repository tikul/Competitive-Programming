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
#define left(i) i << 1
#define right(i) i << 1 | 1
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>, int> ppi;

int n, k, a[26];

int main(){
    memset(a, 0, sizeof(a));
    cin.sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> n >> k >> s;
    int tt = 0;
    for(int i = 0; i < s.length(); i++){
        char x = s[i];
        a[x-'a']++;
    }
    bool good = true;
    for(int i = 0; i < 26; i++){
        if(a[i] > k){
            good = false;
        }
    }
    if(!good){
        cout << "NO";
    }else{
        cout << "YES";
    }
}