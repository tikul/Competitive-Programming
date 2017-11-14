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
#include <cassert>
using namespace std;
#define sL(i) i << 1
#define sR(i) i << 1 | 1
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>, int> ppi;

string s;
set<char> vowels;
vector<string> ans;
int n;
int dp[3005];
int aup[3005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    vowels.insert('a');
    vowels.insert('e');
    vowels.insert('i');
    vowels.insert('o');
    vowels.insert('u');
    cin >> s;
    n = s.length();
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        int con = 0;
        bool tt = false; //not the same
        for(int j = i-1; j >= 0; j--){
            if(vowels.count(s[j])){
                con = 0;
                tt = false;
                if(1+dp[j] < dp[i]){
                    aup[i] = j;
                    dp[i] = 1+dp[j];
                }
            }else{
                assert(s[j] != 'a');
                con++;
                if(j != i-1 && s[j] != s[j+1] && !vowels.count(s[j+1])){
                    tt = true;
                }
                if(tt && con>=3) break;
                if(1+dp[j] < dp[i]){
                    aup[i] = j;
                    dp[i] = 1+dp[j];
                }
            }
        }
    }
    while(n != 0){
        int m = aup[n];
        ans.push_back(s.substr(m, n-m));
        n = aup[n];
    }
    for(auto it = ans.rbegin(); it != ans.rend(); it++){
        cout << *it << " ";
    }
}