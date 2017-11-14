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

int a[6];

bool good(int s){
    if(s%2 != 0) return 0;
    for(int i = 0; i < 6; i++){
        for(int j = i+1; j < 6; j++){
            for(int k = j+1; k < 6; k++){
                if(a[i]+a[j]+a[k] == s/2) return true;
            }
        }
    }
    return false;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int s = 0;
    for(int i = 0; i < 6; i++){
        cin >> a[i];
        s += a[i];
    }
    cout << (good(s)?"yes":"no");
}