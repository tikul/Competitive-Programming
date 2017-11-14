#include <stdio.h>
#include <cstring>
#include <set>
#include <utility>
using namespace std;
int n, m;
char A[1001][1001];
bool vis[1001][1001];

int main(){
	scanf("%i %i", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf(" %c", &A[i][j]);
		}
	}
	memset(vis, 0, sizeof(vis));
	int groups = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!vis[i][j]){
				int r = i, c = j;
				set<pair<int, int>> seen;
				while(!vis[r][c]){
					seen.insert({r, c});
					vis[r][c] = 1;
					if(A[r][c]=='N') --r;
					else if(A[r][c]=='S') ++r;
					else if(A[r][c]=='E') ++c;
					else --c;
				}
				if(seen.count({r, c})){
					++groups;
				}
			}
		}
	}
	printf("%i", groups);
}