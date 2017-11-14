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

int n, a[2005], b[2005];
unordered_set<int> nums;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        nums.insert(x);
        a[i] = x;
    }
    for(int i = 0; i < n; i++){
        cin >> x;
        nums.insert(x);
        b[i] = x;
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            x = a[i] ^ b[j];
            if(nums.count(x)) ++cnt;
        }
    }
    if(cnt%2==0) cout << "Karen";
    else cout << "Koyomi";
}