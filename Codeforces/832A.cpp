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

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long n, k;
    cin >> n >> k;
    long long x = n-k;
    long long res = x/k;
    if(res % 2 == 0){
        cout << "YES";
    }else{
        cout << "NO";
    }
}