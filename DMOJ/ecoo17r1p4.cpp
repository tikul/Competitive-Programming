#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    string sorted[1005], arr[1005];
    for(int i = 0; i < 10; i++){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            sorted[i] = arr[i];
        }
        sort(sorted, sorted+n);
        int best = 99999;
        unordered_map<string, string> ht;
        unordered_set<string> visited;
        for(int rmv = 0; rmv < n; rmv++){
            string guy = arr[rmv];
            int ans=0,j=0,k=0;
            while(j < n && k < n){
                if(sorted[j]==guy) j++;
                if(k==rmv) k++;
                ht[arr[k]] = sorted[j];
                // cout << arr[k] << " " << sorted[j] << "\n";
                j++; k++;
            }
            for(int x = 0; x < n; x++){
                if(x==rmv || visited.find(arr[x]) != visited.end()) continue;
                string cur = arr[x];
                while(visited.find(cur) == visited.end()){
                    visited.insert(cur);
                    ans++;
                    cur = ht[cur];
                }   
                ans--;
                //cout << ans << " ";
            }
            best = min(best, ans);
            // cout << "\n" << best << " rmv:" << rmv << "\n";
            ht.clear();
            visited.clear();
        }
        cout << best << "\n";
    }
}