#include <string>
#include <iostream>
#include <cmath>

using namespace std;

string s;

int counts[4];

int main(){
    cin >> s;
    int n = s.length();
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i]=='L') counts[0]++;
        else if(s[i] == 'R') counts[1]++;
        else if(s[i] == 'D') counts[2]++;
        else counts[3]++;
    }
    if(abs(counts[0]-counts[1]) % 2 == 0){
        if(abs(counts[2]-counts[3]) % 2 == 0){
            ans += abs(counts[0]-counts[1])/2 + abs(counts[2]-counts[3])/2;
        }else{
            ans = -1;
        }
    }else{
        if(abs(counts[2]-counts[3]) % 2 == 0){
            ans = -1;
        }else{
            ans = 1+(abs(counts[0]-counts[1]))/2 + abs(counts[2]-counts[3])/2;
        }
    }
    cout << ans;
}