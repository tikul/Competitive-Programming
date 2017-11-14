#include <stdio.h>
#include <unordered_set>

#define twelve 1000000000000LL
#define six 1000000LL

using namespace std;
int N;

int main(){
  scanf("%i", &N);
  unordered_set<long long> prev, cur;
  prev.insert(0);
  char x;
  long long a, b, c;
  for(int i = 1; i <= N; i++){
    scanf(" %c", &x);
    if(x == '~'){
      for(long long i : prev){
        a = i / twelve;
        b = (i / six) % six;
        c = i % six;
        if(a <= b && a <= c){
          cur.insert((a+1)*twelve+b*six+c);
        }
        if(b <= a && b <= c){
          cur.insert(a*twelve+(b+1)*six+c);
        }
        if(c <= a && c <= b){
          cur.insert(a*twelve+b*six+(c+1));
        }
      }
    }else{
      x -= '0';
      for(long long i : prev){
        a = i / twelve;
        b = (i / six) % six;
        c = i % six;
        if(x==1){
          cur.insert((a+1)*twelve+b*six+c);
        }else if(x==2){
          cur.insert(a*twelve+(b+1)*six+c);
        }else{
          cur.insert(a*twelve+b*six+(c+1));
        }
      }
    }
    prev = cur;
    cur.clear();
  }
  int can[3] = {0, 0, 0};
  for(long long i : prev){
    if(can[0] && can[1] && can[2]) break;
    a = i / twelve;
    b = (i / six) % six;
    c = i % six;
    if(a <= b && a <= c){
      can[0] = 1;
    }
    if(b <= a && b <= c){
      can[1] = 1;
    }
    if(c <= a && c <= b){
      can[2] = 1;
    }
  }
  for(int i = 1; i <= 3; i++){
    if(can[i-1]) printf("%i\n", i);
  }
}