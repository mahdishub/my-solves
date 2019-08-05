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

char s[65];
ll dp[65][65];
ll solve ( int l, int r ) {
    if ( l == r ) return dp[l][r] = 1;
    if ( l > r ) return 0;
    if ( dp[l][r] != -1 ) return dp[l][r];
    if ( s[l] == s[r] ) {
        dp[l][l] = 1, dp[r][r] = 1;
        return dp[l][r] = 1+solve(l+1,r)+solve(l,r-1);
    }
    return dp[l][r] = solve(l+1,r)+solve(l,r-1)-solve(l+1,r-1);
}

int main () {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    sf(t);
    for ( int T = 1; T <= t; T++ ) {
        memset(dp,-1,sizeof(dp));
        scanf("%s",s);
        printf("Case %d: %lld\n",T,solve(0,strlen(s)-1));
        ///fr(i,strlen(s))fr(j,strlen(s))printf("%d %d %lld\n",i,j,dp[i][j]);
    }

    return 0;
}
