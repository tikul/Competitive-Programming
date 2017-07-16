#include <string>
#include <iostream>

using namespace std;

int n, k;
string s;

int pre[26][2005];
int diff[26][2005];

int main(){
    cin >> n >> k;
    cin >> s;
    if(k > n){
        cout << "WRONGANSWER";
        return 0;
    }else if(k==n){
        cout << s;
        return 0;
    }
    for(int i = 1; i <= n; i++)
        diff[s[i-1]-'a'][i]++;
    bool pos = false;
    for(int i = 0; i < 26; i++){
        for(int j = 1; j <= n; j++){
            pre[i][j] = pre[i][j-1]+diff[i][j];
        }
        if(pre[i][n]==0){
            string qq = s.substr(0, k);
            for(int _ = 0; _ < n-k; _++)
                qq += 'a'+i;
            cout << qq;
            return 0;
        }
        pos |= (pre[i][n]<=k);
    }
    if(!pos){
        cout << "WRONGANSWER";
        return 0;
    }
    for(int i = 0; i+k <= n; i++){
        char x = s[i];
        if(pre[x-'a'][n] == pre[x-'a'][i+k]){
            string qq = s.substr(i, k);
            for(int _ = 0; _ < n-k; _++)
                qq += x;
            cout << qq;
            return 0;
        }
    }
    cout << "help me\n";
}