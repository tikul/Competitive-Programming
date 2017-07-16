#include <iostream>
#include <utility>
#include <queue>
#include <cstring>

#define pii pair<int, int>
#define ppi pair<pair<int,int>, int>
#define mp make_pair

int T;
char grid[50][50];
bool visited[50][50];

using namespace std;

int main(){
    scanf("%i", &T);
    int l, w, startr, startc;
    for(int i = 0; i < T; i++){
        memset(visited, 0, sizeof(visited));
        scanf("%i %i", &l, &w);
        for(int r = 0; r < w; r++){
            for(int c = 0; c < l; c++){
                scanf(" %c", &grid[r][c]);
                if (grid[r][c] == 'C'){
                    startr = r;
                    startc = c;
                }
            }
        }
        int row, col, count = 0;
        ppi temp;
        bool found = false;
        queue<ppi> q;
        q.push(mp(mp(startr,startc), 0));
        while(!q.empty()){
            temp = q.front();
            q.pop();
            row = temp.first.first;
            col = temp.first.second;
            count = temp.second;
            if (visited[row][col] || grid[row][col] == 'X')
                continue;
            if (grid[row][col] == 'W'){
                found = true;
                break;
            }
            if (row-1 >= 0)
                q.push(mp(mp(row-1, col), count+1));
            if (row+1 < w)
                q.push(mp(mp(row+1, col), count+1));
            if (col-1 >= 0)
                q.push(mp(mp(row, col-1), count+1));
            if (col+1 < l)
                q.push(mp(mp(row, col+1), count+1));
            visited[row][col] = true;
        }
        if (found && count < 60)
            printf("%i\n", count);
        else
            printf("#notworth\n");
    }
}