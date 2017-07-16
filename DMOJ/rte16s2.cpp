#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <unordered_set>

typedef long long lli;

using namespace std;

string evac, dirs[4];
int lens[4];
unordered_set<short> nums[2503];
short mult[4] = {2500, -2500, 1, -1};

int main(){
    for(int i = 0; i < 4; i++){
        cin >> dirs[i];
        lens[i] = dirs[i].length();
    }
    cin >> evac;
    int n = evac.length();
    nums[0].insert(0);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 4; j++){
            if (lens[j] <= i && evac.substr(i-lens[j], lens[j]) == dirs[j]){
                for(auto num : nums[i-lens[j]]){
                    nums[i].insert(num+mult[j]);
                }
            }
        }
    }
    cout << nums[n].size();
}