#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>, int> ppi;

int n;
bool tosort[300011];
set<int> stack;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    bool sorted = true;
    string cmd;
    int val, pl=-1, ans=0;
    for(int i = 0; i < 2*n; i++){
        cin >> cmd;
        if(cmd == "add"){
            cin >> val;
            pl++;
            if(pl==0){
                tosort[pl] =0;
                sorted = true;
            }else{
                int fst = *stack.begin();
                if(val > fst){
                    sorted = false;
                    tosort[pl] = 1;
                }else{
                    tosort[pl] = 0;
                }
            }
            stack.insert(val);
        }else{
            if(tosort[pl] && !sorted){
                //printf("%i %i\n", pl, i);
                ans++;
                sorted = true;
            }
            pl--;
            stack.erase(stack.begin());
        }
    }
    cout << ans;

}