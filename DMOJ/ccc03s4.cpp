#include <iostream>
#include <string>
#include <utility>
#include <cstring>
#include <algorithm>
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define ppi pair<pii, int>
#define mp make_pair
#define first first
#define second second 
using namespace std;

int main(){
    int n, rank[15][5005], suftab[5005], lcp[5005];
    ppi split[5005];
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    string s;
    while(n--){
        memset(rank, 0, sizeof(rank));
        cin >> s;
        int sz = s.length();
        int lg = 0, x = sz, pop=0;
        while(x){
            lg++;
            if(x&1) pop++;
            x = x >> 1;
        }
        if(pop > 1) lg++;
        for(int i = 0; i < sz; i++){
            rank[1][i] = s[i]-'a';
        }
        for(int i = 2; i <= lg; i++){
            int len = 1<<(i-1);
            for(int j = 0; j < sz; j++){
                split[j] = mp( mp(rank[i-1][j], j+len/2<sz ? rank[i-1][j+len/2] : -inf), j);
            }
            sort(split, split+sz);
            for(int j = 0; j < sz; j++){
                if(i > 0 && split[j].first.first == split[j-1].first.first && split[j].first.second == split[j-1].first.second){
                    rank[i][split[j].second] = rank[i][split[j-1].second];
                }else{
                    rank[i][split[j].second] = j;
                }
            }
        }
        for(int i = 0; i < sz; i++){
            suftab[rank[lg][i]] = i;
        }
        int h = 0;
        for(int i = 0; i < sz; i++){
            if(rank[lg][i] == 0) continue;
            int k = suftab[rank[lg][i] - 1];
            while(i+h < sz && k + h < sz && s[i+h] == s[k+h]){
                h++;
            }
            lcp[rank[lg][i]] = h;
            if(h > 0) h--;
        }
        int ans = sz-suftab[0]+1;
        for(int i = 1; i < sz; i++){
            ans += sz - suftab[i] - lcp[i];
        }
        cout << ans << "\n";
    }
}