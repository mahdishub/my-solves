
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
#define eps            0.0000000001
#define gl(a)          scanf("%llu",&a)
#define mod            1000000007
#define pf             printf
#define loop(ds,itr)   for ( auto itr = ds.begin(); itr != ds.end(); itr++ )
#define fr(i,n)        for ( int i = 0; i < n; i++ )
#define fr1(i,n)       for ( int i = 1; i <= n; i++ )
#define check(x)       cout << x << endl;
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
#define all(v)         v.begin(),v.end()
#define mem(x,v)       memset(x,v,sizeof(x))

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
typedef tree< int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
template < class T > inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}


const int sz = 5*1e4+5;
int n,k;
bool val[sz];
vector < int > graph[sz];
bool visit[sz];
int sub[sz];
ll tmp[105];
ll dp[sz][105];

inline void Clear() {
    fr(i,sz) graph[i].clear();
    mem(visit,0);
    mem(dp,0);
    mem(sub,0);
}


void fnd ( int src ) {
    sub[src] = 1;
    dp[src][val[src]] = 1;
    visit[src] = 1;
    for ( int v: graph[src] ) {
        if ( visit[v] ) continue;
        fnd(v);
        fill(tmp,tmp+105,0);
        for ( int i = val[sz]; i <= min(sub[src],k); i++ ) {
            for ( int  j = 0; j <= min(sub[v],k-i); j++ ) {
                tmp[i+j] += dp[src][i]*dp[v][j];
                tmp[i+j] %= mod;
            }
        }
        ///cout << src << ' ' << v << endl;

        sub[src] += sub[v];
        for ( int i = 0; i <= min(sub[src],k); i++ ) {
            dp[src][i] = (dp[src][i]+tmp[i]) % mod;
            ///cout << dp[src][i] << ' ';
        }
        ///cout << endl;

    }

}


int main () {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);

    int t;
    sf(t);

    fr1(T,t) {
        Clear();
        sf2(n,k);
        fr1(i,n) sf(val[i]);
        int u,v;
        fr(i,n-1) {
            sf2(u,v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        fnd(1);
        ll ans = 0;
        fr1(i,n) ans = (ans+dp[i][k])%mod;
        printf("%lld\n",ans);

    }

    return 0;
}
