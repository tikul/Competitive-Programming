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
    int s, v1, v2, t1, t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    if(2*t1+s*v1 < 2*t2 +s*v2){
        cout << "First";
    }else if(2*t2+s*v2 < 2*t1+s*v1){
        cout << "Second";
    }else{
        cout << "Friendship";
    }
}