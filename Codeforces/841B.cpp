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

int n, a[1000005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll tot=0;
    bool isOdd = false;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] % 2 == 1){
            isOdd = true;
        }
        tot += a[i];
    }
    if(tot%2==1){
        cout << "First";
    }else{
        if(isOdd){
            cout << "First";
        }else{
            cout << "Second";
        }
    }
}