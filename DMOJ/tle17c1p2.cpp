#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
int N, F, cnt=0;
unordered_map<string, int> cv;
int en[1005];
pii food[1005];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> F;
    int x;
    string s;
    for(int i = 0; i < F; i++){
        cin >> s >> x;
        cv[s] = cnt;
        en[cnt++] = x;
    }
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s >> x;
        food[i] = {x, en[cv[s]]};
    }
    sort(food, food+N);
    int i = 0, e = 0, p = 0;
    for(i = 0; i < N; i++){
        int pos = food[i].first;
        int val = food[i].second;
        if(pos==p){
            e += val;
        }else{
            if(pos-p > e){
                break;
            }else{
                e -= pos-p;
                e += val;
                p = pos;
            }
        }
    }
    cout << i;
}