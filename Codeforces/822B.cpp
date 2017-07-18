#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
//#include <unordered_set>
#include <set>
#include <unordered_map>

using namespace std;

#define left(i) i << 1
#define right(i) i << 1 | 1
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>, int> ppi;

int n, m;
string s, t;
vector<int> pos[1005];

int main(){
    // cin.sync_with_stdio(0);
    // cin.tie(0);
    cin >> n >> m >> s >> t;
    int best = 1005, bp=-1;
    for(int i = 0; i+n <= m; i++){
        // cout << i << "here\n";
        int j = 0, k = i;
        while(j < n){
            if(s[j] != t[k]){
                pos[i].push_back(j+1);
            }
            j++;
            k++;
        }
        if(pos[i].size() < best){
            best = pos[i].size();
            bp = i;
        }
    }
    cout << best << "\n";
    for(int i = 0; i < best; i++){
        if(i != 0) cout << " ";
        cout << pos[bp][i];
    }

}