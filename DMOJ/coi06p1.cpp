#include <stdio.h>
#include <stack>
#include <utility>
#include <unordered_map>
#define pii pair<int, int>
using namespace std;
stack<pii> st;
int N, a[500005], ans[500005];
int main(){
    scanf("%i", &N);
    for(int i = 1; i <= N; i++){
        scanf("%i", a+i);
    }
    long long res = 0;
    for(int i = 1; i <= N; i++){      
        int max = 0;
        int temp = 0;
        while(!st.empty() && st.top().first < a[i]){
            if(st.top().first >= max){
                ++temp;
                max = st.top().first;
            }
            st.pop();
        }
        if(!st.empty()){
            if(st.top().first > a[i]){
                ans[i] = 1;
                ++temp;
            }else{
                temp += ans[i] = 1+ans[st.top().second];
            }
        }
        res += temp;
        st.push({a[i], i});
    }
    printf("%lli", res);
}