#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

pii p[3];


bool test(){
    for(int i = 0; i < 2; i++){
        int hipo = (p[2].st - p[i].st)*(p[2].st - p[i].st) + (p[2].nd - p[i].nd)*(p[2].nd - p[i].nd);
        int c1 = (p[2].st - p[i^1].st)*(p[2].st - p[i^1].st) + (p[2].nd - p[i^1].nd)*(p[2].nd - p[i^1].nd);
        int c2 = (p[i].st - p[i^1].st)*(p[i].st - p[i^1].st) + (p[i].nd - p[i^1].nd)*(p[i].nd - p[i^1].nd);
        db(hipo _ c1 _ c2);
        if(hipo == c1 + c2 and hipo and c1 and c2) return true;
    }
    int hipo = (p[0].st - p[1].st)*(p[0].st - p[1].st) + (p[0].nd - p[1].nd)*(p[0].nd - p[1].nd);
    int c1 = (p[0].st - p[2].st)*(p[0].st - p[2].st) + (p[0].nd - p[2].nd)*(p[0].nd - p[2].nd);
    int c2 = (p[1].st - p[2].st)*(p[1].st - p[2].st) + (p[1].nd - p[2].nd)*(p[1].nd - p[2].nd);
    db(hipo _ c1 _ c2);
    if(hipo == c1 + c2 and hipo and c1 and c2) return true;
    return false;
}

int main(){
    for(int i = 0; i < 3; i++){
        scanf("%d%d", &p[i].st, &p[i].nd);
    }
    if(test()){
        printf("RIGHT\n");
        return 0;
    }
    else{
        for(int i = 0; i < 3; i++){
            p[i].st++;
            if(test()){
                printf("ALMOST\n");
                return 0;
            }
            p[i].st-=2;
            if(test()){
                printf("ALMOST\n");
                return 0;
            }
            p[i].st++;

            p[i].nd++;
            if(test()){
                printf("ALMOST\n");
                return 0;
            }
            p[i].nd-=2;
            if(test()){
                printf("ALMOST\n");
                return 0;
            }
            p[i].nd++;
        }
    }
    printf("NEITHER\n");
    return 0;
}