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

int r, d, n;

double dist(int u, int v){
    return sqrt(u*u + v*v);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> d >> n;
    int a, b, c;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        double d1 = dist(a,b);
        //cout << a << " " << b << "\n";
        //cout << "FAM " << d1 << " " << d1-c << " " << d1+c << "\n";
        if(d1+c <= r && d1-c >= r-d){
            cnt++;
        }
    }
    cout << cnt;

}