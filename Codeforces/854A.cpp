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

bool coprime(int a, int b){
    if(a < b) swap(a, b);
    for(int i = 2; i <= b; i++){
        if(a % i == 0 && b %i == 0) return true;
    }
    return false;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int big;
    for(int i = 1; i <= (n-1)/2; i++){
        if(!coprime(i, n-i)){
            big = i;
        }
    }
    cout << big << " " << n-big;
}