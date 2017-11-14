#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
vector<int> adj[1000002];
double prob[1000002];

int main(){
    memset(prob, 0, sizeof(prob));
    scanf("%i%i", &n, &m);
    int a, b;
    for(int i = 0; i < m; i++){
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
    }
    prob[1] = 1;
    for(int i = 1; i <= n; i++){
        if(adj[i].size()==0) printf("%.10lf\n", prob[i]);
        for(int j : adj[i]){
            prob[j] += prob[i]/adj[i].size();
        }
    }
}