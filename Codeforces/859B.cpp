#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
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

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int l = sqrt(n);
    int w;
    for(int i = l; i <= n; i++){
        if(i*l >= n){
            w = i;
            break;
        }
    }
    cout << 2*w + 2*l;
}