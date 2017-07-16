#include <stdio.h>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
#define XX first
#define YY second
#define mp make_pair

struct line{
    pii v1, v2;
};

int cross(pii a, pii b){
    return a.XX*b.YY-a.YY*b.XX;   
}

pii getv(pii a, pii b){
    return mp(a.XX-b.XX, a.YY-b.YY);
}

int n;

int main(){
    line rj;
    scanf("%i %i %i %i", &rj.v1.XX, &rj.v1.YY, &rj.v2.XX, &rj.v2.YY);
    if(rj.v2.XX < rj.v1.XX){
        swap(rj.v1.XX, rj.v2.XX);
        swap(rj.v1.YY, rj.v2.YY);
    }
    //pii vec = mp(rj.v2.XX-rj.v1.XX, rj.v2.YY-rj.v1.YY);
    pii vec = getv(rj.v2, rj.v1);
    //printf("pts: %i, %i. %i, %i\n", rj.v1.XX, rj.v1.YY, rj.v2.XX, rj.v2.YY);
    //printf("vec: %i %i\n", vec.XX, vec.YY);
    scanf("%i", &n);
    int vert,cnt=0;
    for(int i = 0; i < n; i++){
        line shape[35];
        scanf("%i", &vert);
        for(int i = 0; i < vert; i++){
            scanf("%i %i", &shape[i].v2.XX, &shape[i].v2.YY);
            shape[(i+1)%vert].v1.XX = shape[i].v2.XX;
            shape[(i+1)%vert].v1.YY = shape[i].v2.YY;
        }
        bool good = true;
        for(int i = 0; i < vert && good; i++){
            int crs1, crs2;
            pii vec2;
            //vec2 = mp(shape[i].v1.XX-rj.v1.XX, shape[i].v1.YY-rj.v1.YY);
            vec2 = getv(shape[i].v1, rj.v1);
            //printf("vec2a: %i %i\n", vec2.XX, vec2.YY);
            //crs1 = vec2.XX*vec.YY-vec2.YY*vec.XX;
            crs1 = cross(vec2, vec);
            // angle = cosx(vec2, vec);
            // good &= (abs(angle-1) > 1e-9);
            // printf("a1 %lf %i\n", angle, angle==1.0);
            //vec2 = mp(shape[i].v2.XX-rj.v1.XX, shape[i].v2.YY-rj.v1.YY);
            vec2 = getv(shape[i].v2, rj.v1);
            //printf("vec2b: %i %i\n", vec2.XX, vec2.YY);
            //crs2 = vec2.XX*vec.YY-vec2.YY*vec.XX;
            crs2 = cross(vec2, vec);
            // angle = cosx(vec2, vec);
            // good &= (abs(angle-1)>1e-9);
            // printf("a2 %lf %i\n", angle, angle==1.0);
            if(crs1==0)
                good &= (shape[i].v1.XX < rj.v1.XX) || (shape[i].v1.XX > rj.v2.XX);
            if(crs2==0)
                good &= (shape[i].v2.XX < rj.v1.XX) || (shape[i].v2.XX > rj.v2.XX);
            if((crs2 > 0 && crs1 < 0) || (crs1 > 0 && crs2 < 0)){
                pii lol = getv(shape[i].v1, shape[i].v2);
                pii f = getv(rj.v1, shape[i].v2);
                pii s = getv(rj.v2, shape[i].v2);
                int c1 = cross(f, lol);
                int c2 = cross(s, lol);
                if((c2 > 0 && c1 < 0) || (c1 > 0 && c2 < 0))
                    good = false;
            }
            //printf("%i %i %i----\n", good, crs1, crs2);
        }
        if(!good)cnt++;
        //printf("***********\n");
    }
    printf("%i", cnt);
}