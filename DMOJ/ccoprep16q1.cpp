#include <iostream>
#include <stack>
#include <cstring>

bool grid[1001][1001];
int line[1001];
int widths[1001];

int K, N, M;

int main(){
    scanf("%i", &K);
    char t;
    for(int _ = 0; _ < K; _++){
        memset(line, 0, sizeof(line));
        scanf("%i %i", &M, &N);
        for(int r = 0; r < M; r++){
            for(int c = 0; c < N; c++){
                scanf(" %c", &t);
                grid[r][c] = t=='F';
            }
        }
        int best = -1;
        for(int row = 0; row < M; row++){
            std::stack<int> st;
            std::stack<int> st2;
            for(int j = 0; j < N; j++){
                line[j] = grid[row][j]*line[j] + grid[row][j];
            }
            for(int j = 0; j < N; j++){ //find left
                while(!st.empty() && line[st.top()] >= line[j])
                    st.pop();
                if (st.empty())
                    widths[j] = j;
                else
                    widths[j] = j - st.top() - 1;
                st.push(j);
            }
            for(int j = N-1; j >= 0; j--){ //find right
                while(!st2.empty() && line[st2.top()] >= line[j])
                    st2.pop();
                if (st2.empty())
                    widths[j] += N-j-1;
                else
                    widths[j] += st2.top() - j-1;
                st2.push(j);
            }
            for(int j = 0; j < N; j++){
                if (line[j]*(widths[j]+1) > best)
                    best = line[j]*(widths[j]+1);
            }
        }
        printf("%i\n", 3*best);
    }
}