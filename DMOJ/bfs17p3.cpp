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
#include <functional>
using namespace std;
#define sL(i) i << 1
#define sR(i) i << 1 | 1
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,int> pdi;
typedef pair<pair<int,int>, int> ppi;

int n, m, b1, b2;
bool vis[3005];
struct Player{
    int x, y, r;
} p1[3005], p2[3005];

int ddist[3005];

bool reachable1(int i, int j){
    return (p1[i].x-p1[j].x)*(p1[i].x-p1[j].x) + (p1[i].y-p1[j].y)*(p1[i].y-p1[j].y) <= p1[i].r*p1[i].r;
}

bool reachable2(int i, int j){
    return (p2[i].x-p2[j].x)*(p2[i].x-p2[j].x) + (p2[i].y-p2[j].y)*(p2[i].y-p2[j].y) <= p2[i].r*p2[i].r;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    //int x, y, r;
    int s1;
    int lo = 0;
    for(int i = 0; i < n; i++){
        cin >> p1[i].x >> p1[i].y >> p1[i].r;
        if(p1[i].y > lo){
            s1 = i;
            lo = p1[i].y;
        }
        if(p1[i].r==9001){
            b1 = i;
        }
    }
    int s2;
    lo = 0;
    for(int i = 0; i < m; i++){
       cin >> p2[i].x >> p2[i].y >> p2[i].r; 
        if(p2[i].y > lo){
            s2 = i;
            lo = p2[i].y;
        }
        if(p2[i].r==9001){
            b2 = i;
        }
    }
    int best1=2e9;
    int best2=2e9;
    for(int i = 0; i < n; i++){
        ddist[i] = 2e9;
        vis[i] = 0;
    }
    priority_queue<pdi, vector<pdi>, greater<pdi>> q;
    ddist[s1] = 0;
    q.push({0, s1});
    while(!q.empty()){
        int d = q.top().first;
        int u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        if(u==b1){
            best1 = d;
            break;
        }
        vis[u] = 1;
        for(int i = 0; i < n; i++){
            if(i==u) continue;
            if(reachable1(u,i) && d+1 < ddist[i]){
                ddist[i] = d+1;
                q.push({d+1, i});
            }
        }
    }
    for(int i = 0; i < m; i++){
        ddist[i] = 2e9;
        vis[i] = 0;
    }
    ddist[s2] = 0;
    priority_queue<pdi, vector<pdi>, greater<pdi>> q2;
    q2.push({0, s2});
    while(!q2.empty()){
        int d = q2.top().first;
        int u = q2.top().second;
        q2.pop();
        if(vis[u]) continue;
        if(u==b2){
            best2 = d;
            break;
        }
        vis[u] = 1;
        for(int i = 0; i < m; i++){
            if(i==u) continue;
            if(reachable2(u,i) && d+1 < ddist[i]){
                ddist[i] = d+1;
                q2.push({d+1, i});
            }
        }
    }
    if(best1 < best2){
        cout << "We are the champions!";
    }else if(best2 < best1){
        cout << ":'(";
    }else{
        cout << "SUDDEN DEATH";
    }
}