#include<iostream>
#include<iomanip>


using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
#define MOD 100000000000000000
#define ff  first
#define ss  second


pll dp[1005];

inline pll add( pll a, pll b ) {
    ll low = a.ss+b.ss;
    ll high = low/MOD;
    low %= MOD;
    high += a.ff+b.ff;
    return make_pair(high,low);
}

int main () {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    ///cin.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i = 0; i < 1005; i++ ) dp[i] = make_pair(0,1);
    for ( int i = 2; i <= k; i++ ) {
        for ( int j = i; j <= n; j++ ) {
            dp[j] = add(dp[j],dp[j-i]);
        }
    }
    ///dp[n].ff = 1, dp[n].ss = 1;
    if ( dp[n].ff == 0 ) cout << dp[n].ss << endl;
    else cout << dp[n].ff << setw(17) << setfill('0') << dp[n].ss << endl;
    return 0;
 }
