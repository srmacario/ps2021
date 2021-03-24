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
const int N = 15;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vi a;
    while(n){
        a.pb(n%10);
        n /= 10;
    }
    reverse(a.begin(), a.end());
    vector <string> ans;
    for(int i = 0; i < a.size(); i++){
        while(a[i]){
            ans.pb("1");
            a[i]--;
            for(int j = i+1; j < a.size(); j++){
                if(a[j]){
                    ans[ans.size()-1] += "1";
                    a[j]--;
                }
                else ans[ans.size()-1] += "0";
            }
        }
    }
    cout << ans.size() << "\n";
    for(auto s : ans) cout << s << " ";
    cout << "\n";
    return 0;
}