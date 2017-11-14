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

int n, a[100005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll lo=0,hi=0;
    bool odd = false;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        odd |= a[i] % 2 == 1;
        lo += a[i];
        hi += a[i];
    }
    if(n%2==0 || odd){
        lo -= n/2;
        hi += n/2;
        cout << lo << "\n" << hi;
    }else{
        lo -= n/2;
        if(lo % 2 == 1) lo--;
        hi += n/2;
        if(hi % 2 == 1) hi++;
        cout << lo << "\n" << hi; 
    }

}