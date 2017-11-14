#include <stdio.h>
#include <deque>
#include <utility>
#include <cstring>
#define pii pair<int, int>
#define ppi pair<pii, int>
#define mp make_pair
#define F first
#define S second

using namespace std;

char grid[1002][1002];
bool vis[1002][1002];
int R, C, t, sr, sc, fr, fc;

int main(){
    memset(vis, 0, sizeof(vis));
    scanf("%i %i %i %i %i %i", &R, &C, &sr, &sc, &fr, &fc);
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            scanf(" %c", &grid[i][j]);
            //printf("%i %i received\n", i, j);
        }
    }
    scanf("%i", &t);
    int a, b;
    for(int i = 0; i < t; i++){
        scanf("%i %i", &a, &b);
        grid[a][b] = 'T';
    }
    deque<ppi> q;
    q.push_back(mp(mp(sr, sc), 0));
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    int tele = -1;
    int reg = -1;
    while(!q.empty()){
        ppi x = q.front();
        q.pop_front();
        int cr = x.F.F;
        int cc = x.F.S;
        int d = x.S;
        if(cc < 0 || cc >= C || cr < 0 || cr >= R) continue;
        if(vis[cr][cc] || grid[cr][cc]=='X') continue;
        vis[cr][cc] = true;
        if(cr == fr && cc == fc){
            reg = d;
            break;
        }
        if(grid[cr][cc] == 'T' && tele == -1){
            tele = d;
        }
        for(int i = 0; i < 4; i++){
            q.push_back(mp(mp(cr+dr[i], cc+dc[i]), d+1));
        }
    }
    if(tele==-1){
        printf("0");
    }else{
        printf("%i", reg-tele);
    }
}