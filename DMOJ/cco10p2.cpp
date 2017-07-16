#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <set>
#include <unordered_set>
#include <vector>

#define inf 0x3f3f3f3f

using namespace std;

int n, d;

struct node{
    int sc;
    int child[2] = {-1, -1};
    int checked[605];
    vector<int> dp;
} tree[302];

void build(int node){
    int l = tree[node].child[0];
    int r = tree[node].child[1];
    if(l == -1 && r == -1){ 
        tree[node].dp.push_back(tree[node].sc);
        tree[node].checked[tree[node].sc+n] = 1;
    }else if((l== -1 || r == -1) && l != r){
        for(int i = 0; i < 2; i++){
            int j = tree[node].child[i];
            if(j== -1) continue;
            build(j);
            tree[node].sc += tree[j].sc;
            if(tree[node].checked[tree[node].sc+n] >= inf)
                tree[node].dp.push_back(tree[node].sc);
            tree[node].checked[tree[node].sc+n] = min(1, tree[node].checked[tree[node].sc+n]);
            for(int y : tree[j].dp){
                int z = tree[j].checked[y+n];
                if(tree[node].checked[y+n] >= inf)
                    tree[node].dp.push_back(y);   
                tree[node].checked[y+n] = min(tree[node].checked[y+n], z);
            }  
        }
    }else{
        build(l);
        build(r);
        tree[node].sc += tree[l].sc+tree[r].sc;
        if(tree[node].checked[tree[node].sc+n] >= inf)
            tree[node].dp.push_back(tree[node].sc);
        tree[node].checked[tree[node].sc+n] = min(1, tree[node].checked[tree[node].sc+n]);
        for(int y : tree[l].dp){
            for(int z : tree[r].dp){
                int h = y+z;
                if(tree[node].checked[h+n] >= inf)
                    tree[node].dp.push_back(y+z);
                tree[node].checked[h+n] = min(tree[node].checked[h+n], tree[l].checked[y+n]+tree[r].checked[z+n]);
            }
        }
    }
}

int main(){
    scanf("%i%i", &n, &d);
    int a, b, c;
    for(int i = 0; i < n; i++){
        scanf("%i %i %i", &a, &b, &c);
        memset(tree[a].checked, 0x3f, sizeof(tree[a].checked));
        tree[a].sc = b?1:-1;
        tree[a].dp.push_back(0);
        tree[a].checked[0+n] = 0;
        for(int j = 0; j < c; j++){
            scanf("%i", &tree[a].child[j]);
        }
    }
    int root = 0;
    build(root);
    int goal = tree[root].sc-d;
    if(tree[root].checked[goal+n] >= inf){
        printf("-1\n");
    }else{
        printf("%i\n", tree[root].checked[goal+n]);
    }

}