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
const int N = 1e6+5;

ll v[N], w[N], dp[N];

int main(){
    ll n, L;
    scanf("%lld%lld", &n, &L);
    for(int i = 1; i < N; i++) dp[i] = LINF;
    for(int i = 0; i < n; i++){
        scanf("%lld%lld", &w[i], &v[i]);
    }

    for (int i = 0; i < n; i++) // Adding item by item to our dp
        for (int j = N-1; j >= 0; j--){
            dp[j + v[i]] = min(dp[j] + w[i], dp[j + v[i]]);
        }
    ll ans = 0;
    for(int i = 0; i < N; i++){
        // db(dp[i]);
        if(dp[i] <= L) ans = i;
    }
    printf("%lld\n", ans);
    return 0;
}