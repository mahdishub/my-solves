#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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
#define MAX            100005
#define ff             first
#define ss             second
#define sqr(a)         a*a
/*
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
*/

typedef long long ll;
typedef unsigned long long ull;
typedef pair < ll,int > ii;
typedef priority_queue< int,vector<int>, greater<int> > pq_increasing;
typedef tree< ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

ii arr[20];
int col[20][20];
int dp[int(1<<16)];
int n;

int solve ( int mask ) {
    if ( mask == (1<<n)-1 ) return 0;
    if ( dp[mask] != -1 ) return dp[mask];
    if ( __builtin_popcount(mask) == n-1 ) return dp[mask] = 1;
    int best = inf;
    for ( int i = 0; i < n; i++ ) {
        if ( (mask&(1<<i)) ) continue;
        for ( int j = 0; j < n; j++ ) {
            if ( i < j && !(mask & (1 << j))  ) {
                best = min(best,solve(mask|col[i][j])+1);
            }
        }
        break;
    }
    return dp[mask] = best;
}

int main () {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    sf(t);
    for ( int T = 1; T <= t; T++ ) {
        sf(n);
        int x1x2,y1y2,x2x3,y2y3;
        fr(i,n) sf2(arr[i].ff,arr[i].ss);
        memset(dp,-1,sizeof(dp));
        memset(col,0,sizeof(col));
        for ( int i = 0; i < n-1; i++ ) {
            for ( int j = i+1; j < n; j++ ) {
                if ( i == j ) continue;
                x1x2 = arr[i].ff - arr[j].ff;
                y1y2 = arr[i].ss - arr[j].ss;
                col[i][j] |= (1<<i);
                col[i][j] |= (1<<j);
                for ( int k = 0; k < n; k++ ) {
                    if ( k == i || k == j ) continue;
                    x2x3 = arr[j].ff - arr[k].ff;
                    y2y3 = arr[j].ss - arr[k].ss;
                    if ( x1x2*y2y3 == y1y2*x2x3 ) {
                       col[i][j] |= (1<<k);
                    }
                }
            }
        }

        printf("Case %d: %d\n",T,solve(0));
    }

    return 0;
}
