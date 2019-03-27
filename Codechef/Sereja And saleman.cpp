#include<bits/stdc++.h>

using namespace std;

#define precision(n)   cout << setprecision(n) << fixed
#define sf(a)          scanf("%d",&a)
#define sf2(a,b)       scanf("%d %d",&a,&b)
#define sf3(a,b,c)     scanf("%d%d%d",&a,&b,&c)
#define pi             3.1415926535
#define eps            0.000001
#define gl(a)          scanf("%llu",&a)
#define mod            1000000007
#define pf             printf
#define loop(ds,itr)   for ( auto itr = ds.begin(); itr != ds.end(); itr++ )
#define fr(i,n)        for ( int i = 0; i < n; i++ )
#define check(x)       cout << x << endl;
#define bug            cout << 'x' << endl;
#define srt(n)         (int)(sqrt(double(n))+eps)
#define e              2.71828182845
#define mp             make_pair
#define min4(a,b,c,d)  min(a,min(b,min(c,d)));
#define power(n,i)     (int)(pow(n,i)+eps)
#define inf            0x3f3f3f3f
///#define MAX            100005
#define f              first
#define s              second
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

int t, n, m, u, v, k;
map <ii,bool> bad_edge;
map<int,bool> exist;
vector <int> b_n;
int bn;
const ll MOD = int(1e9)+7;
const ll sz = 1e5;
ll dp[1<<15][15][15];
ll fact[sz+5];


ll ext_gcd (ll A, ll B, ll &X, ll &Y)
{
    long long x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1, y2 = 0;
    x1 = 0, y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 =
                y1, x1 = x, y1 = y )
    {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    X = x2;
    Y = y2;
    return r2;
}

inline ll modInv (ll a, ll m)
{
    long long x, y;
    ext_gcd(a, m, x, y);
    x %= m;
    if (x < 0) x += m;
    return x;
}


ll ncr(int n, int r)
{
    if(r>n) return 0;
    ll ret=fact[n];
    ll down=(fact[r]*fact[n-r])%MOD;
    ret=(ret*modInv(down,MOD))%MOD;
    return ret;
}

ll findans ( int mask, int c_n, int n_t ) {
    if ( dp[mask][c_n][n_t] != -1  ) return dp[mask][c_n][n_t];
    if ( mask == (1<<k)-1 ) {
        ll s = (ncr(n-n_t,bn))%MOD;
        s = (s * fact[n-bn])%MOD;
        return s;
    }
    ll ans = 0;
    int temp = 0;
    for ( int i = 0; i < k; i++ ) {
        if ( !(mask & ( 1 << i )) ) {
            temp = 0;
            if ( bad_edge.find({b_n[c_n],b_n[i]}) != bad_edge.end() ) temp = 1;
            if ( mask == 0 ) temp = 0;
            ans += (findans( mask | (1<<i), i, n_t+temp ))%MOD;
        }
    }
    return dp[mask][c_n][n_t] = ans % MOD;
}



int main () {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    sf(t);
    fact[0] = 1;
    for ( int i = 1; i <= int(1e5); i++ ) fact[i] = (fact[i-1]*i) % MOD;
    while ( t-- ) {
        memset(dp,-1,sizeof(dp));
        bad_edge.clear();
        exist.clear();
        b_n.clear();
        sf2(n,m);
        while ( m-- ) {
            sf2(u,v);
            bad_edge[{v,u}] = bad_edge[{u,v}] = true;
            if ( !exist[u]  ) {b_n.push_back(u);exist[u] = true;}
            if ( !exist[v] )  {b_n.push_back(v);exist[v] = true;}
        }
        ll ans = 0;
        k = b_n.size();
        bn = k;
        ans = findans(0,0,0);
        printf("%lld\n",ans);
    }
    return 0;
}
