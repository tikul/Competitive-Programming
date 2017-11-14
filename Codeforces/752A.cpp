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
#include <cmath>
using namespace std;
#define sL(i) i << 1
#define sR(i) i << 1 | 1
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>, int> ppi;

int n, m, k;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    int lane = (k-1)/(2*m);
    int desk = k - 2*m*lane;
    cout << lane+1 << " " << (desk+1)/2 << (desk%2==1?" L":" R");
}