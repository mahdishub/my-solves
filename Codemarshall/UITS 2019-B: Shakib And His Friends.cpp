#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define precision(n)   cout << setprecision(n) << fixed
#define sf(a)          scanf("%d",&a)
#define sf2(a,b)       scanf("%d%d",&a,&b)
#define sf3(a,b,c)     scanf("%d%d%d",&a,&b,&c)
#define pi             3.1415926535
#define eps            0.000000001
#define gl(a)          scanf("%llu",&a)
#define mod            100000007
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
#define ss              second
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
typedef pair < int,int > ii;
typedef priority_queue< int,vector<int>, greater<int> > pq_increasing;
typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int n,m;
vector<int>graph[1005];
int dp[1005][3];
int parent[1005];
bool visit[1005];

int solve ( int src, int state ) {
    visit[src] = 1;
    if ( graph[src].size() == 0 ) return 0;
    if ( dp[src][state] != -1 ) return dp[src][state];
    int ans = 0;
    ///cout << src << ' ' << state << endl;
    for ( int i = 0; i < graph[src].size(); i++ ) {
        int to = graph[src][i];
        if ( to != parent[src] )  {
            parent[to] = src;
            if ( state == 0 ) ans += solve(to,1);
            else ans += min(solve(to,1),solve(to,0));
        }
    }
    ///cout << ans << endl;
    return dp[src][state] = state+ans;
}

int main () {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    ///cin.tie(0);
    int t;
    cin >> t;
    for ( int T = 1; T <= t; T++ ) {
        cin >> n >> m;
        fr(i,1005) graph[i].clear();
        memset(dp,-1,sizeof(dp));
        memset(visit,0,sizeof(visit));
        int u,v;
        while ( m-- ) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int ans = 0;
        for ( int i = 1; i <= n; i++ ) {
            if ( !visit[i] ) {
                ans += min(solve(i,0),solve(i,1));
                ///cout << ans << endl;
            }
        }
        cout << "Case " << T << ": " << n-ans << endl;
    }

}



