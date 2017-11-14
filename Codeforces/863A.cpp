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

int x;
long long p10[15];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> x;
    p10[0] = 1;
    for(int i = 1; i < 11; i++){
        p10[i] = 10*p10[i-1];
    }
    while(x > 0 && x % 10 == 0){
        x /= 10;
    }
    int len;
    for(len = 0; len < 12; len++){
        if(x/p10[len] == 0) break;
    }
    for(int i = 0, j = len-1; i < j; i++, j--){
        if((x/p10[i]) % 10 != (x/p10[j]) % 10){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

}