#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define precision(n)   cout << setprecision(n) << fixed
#define sf(a)          scanf("%d",&a)
#define sf2(a,b)       scanf("%d %d",&a,&b)
#define sf3(a,b,c)     scanf("%d%d%d",&a,&b,&c)
#define pi             acos(-1.0)
#define eps            0.000001
#define gl(a)          scanf("%llu",&a)
#define pf             printf
#define loop(ds,itr)   for ( auto itr = ds.begin(); itr != ds.end(); itr++ )
#define fr(i,n)        for ( int i = 0; i < n; i++ )
#define check(x)       cout << x << endl
#define bug            cout << 'x' << endl;
#define srt(n)         (int)(sqrt(double(n))+eps)
#define e              2.71828182845
#define mp             make_pair
#define min4(a,b,c,d)  min(a,min(b,min(c,d)));
#define power(n,i)     (int)(pow(n,i)+eps)
#define inf            0x3f3f3f3f
#define MAX            100005
#define ff             first
#define ss             second
#ifdef FACT
     #include <ctime>
     clock_t tStart = clock();
     #define debug(args...) {dbg,args; cerr<<endl;}
     #define timeStamp debug ("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)
     #define bug printf("%d\n",__LINE__);

#else
    #define debug(args...)
    #define timeStamp

#endif

struct debugger{
    template<typename T> debugger & operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;


typedef long long ll;
typedef unsigned long long ull;
typedef pair < int,int > ii;
typedef priority_queue< int,vector<int>, greater<int> > pq_increasing;
typedef tree< ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

const int sz = (5*1e5)+30;
ll arr[sz][3];
ll mod = 1e9+7;


ll mpow(ll x, ll y) {
	ll res = 1;
    x = x % mod;
    while (y > 0) {
        if (y & 1) res = (res*x) % mod;
        y = y>>1;
        x = (x*x) % mod;
    }
	return res;
}

int main () {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    ///cin.tie(0);
    int t;
    int mn = 5*1e5+7;
    arr[3][0] = 2LL, arr[3][1] = 1LL;
    for ( int i = 4; i <= mn; i++ ) {
        arr[i][0] = (arr[i-1][1]*2LL)%mod;
        arr[i][1] = arr[i-1][0]+arr[i-1][1];
        arr[i][1] %= mod;
    }
    ///for ( int i = 3; i <= 8; i++ ) cout << arr[i][0] << ' ' << arr[i][1] << endl;
    cin >> t;
    for ( int T = 1; T <= t; T++ ) {
        string s;
        cin >> s;
        char prev = 'x';
        ll cnt = 0;
        ll ans = 1;
        bool flag = false, flagw = false;
    for ( int i = 0; i < s.length(); i++ ) {
           if ( s[i] == 'W' ) cnt++,flagw = true;
           else if ( flag && cnt == 0 && s[i] != 'W' ) {
                prev = s[i];
                continue;
           }
           else {
                flag = true;
                if ( prev == 'x' ) {ans *= mpow(2LL,cnt);}
                else if ( prev == s[i] ) ans *= arr[cnt+2][0];
                else if ( prev != s[i] ) ans *= arr[cnt+2][1];
                ans %= mod;
                prev = s[i];
                cnt = 0;
           }
        }
        if ( cnt != 0 && flag  ) {///BWWWW
            ans *= mpow(2LL,cnt);
            ans %= mod;
        }
        if ( !flag && flagw ) {/// WWWW
            ans = (3LL*arr[s.length()][0])%mod;
            ans += (6LL*arr[s.length()][1])%mod;
            ans %= mod;
            if ( s.length() == 1 ) ans = 3LL;
            if ( s.length() == 2 ) ans = 6LL;
        }
        if ( !flagw ) ans = 0; ///RRRR
        cout << "Case " << T << ": " << ans << endl;
    }
    return 0;
}
