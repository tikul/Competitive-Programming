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
pii b[100005];
vector<int> groups[100005];
bool vis[100005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = mp(a[i], i);
    }
    sort(b, b+n);
    int tg = 0;
    for(int i = 0; i < n; i++){
        int j = b[i].second;
        if(!vis[j]){
            while(!vis[j]){
                vis[j] = 1;
                groups[tg].push_back(j+1);
                j = b[j].second;
            }
            tg++;
        }
    }
    cout << tg << "\n";
    for(int i = 0; i < tg; i++){
        cout << groups[i].size() << " ";
        sort(groups[i].begin(), groups[i].end());
        for(int j : groups[i]){
            cout << j << " ";
        }
        cout << "\n";
    }
}