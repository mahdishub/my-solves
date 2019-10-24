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
#define mp             make_pair
#define min4(a,b,c,d)  min(a,min(b,min(c,d)));
#define power(n,i)     (int)(pow(n,i)+eps)
#define inf            0x3f3f3f3f
#define MAX            100005
#define ff             first
#define ss             second
#define all(v)         v.begin(),v.end()

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

const int sz = 5*1e4+50;
int graph[sz];
int d[sz], low[sz], scc[sz],belongs[sz],reaches[sz];
stack<int>s;
bool onStack[sz];
int tick;



void tarjan ( int src ) {
    d[src] = low[src] = tick++;
    s.push(src);
    onStack[src] = true;
    int to = graph[src];
    if ( d[to] == -1 ) {
        tarjan(to);
        low[src] = min(low[src],low[to]);
    }
    else if ( onStack[to] ) {
        low[src] = min(low[src],low[to]);
    }
    if ( d[src] == low[src] ) {
        int cnt = 0;
        int v;
        do {
            v = s.top();
            onStack[v] = false;
            s.pop();
            cnt++;
            belongs[v] = low[src];
        } while ( src != v );
        scc[low[src]] = cnt;
    }
}


void init() {
    memset(graph,0,sizeof(graph));
    tick = 0;
    memset(d,-1,sizeof(d));
    memset(low,0,sizeof(low));
    memset(scc,0,sizeof(scc));
    memset(belongs,0,sizeof(belongs));
    memset(reaches,-1,sizeof(reaches));
}


int dfs ( int src ) {
    if ( scc[belongs[src]] > 1 ) return reaches[src] = scc[belongs[src]];
    if ( reaches[src] != -1 ) return reaches[src];
    return dfs(graph[src])+1;
}


int main () {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    ///cin.tie(0);
    int t;
    cin >> t;
    for ( int T = 1; T <= t; T++ ) {
        init();
        int n,u,v;
        cin >> n;
        fr(i,n) cin >> u >> v, graph[u] = v;
        memset(d,-1,sizeof(d));
        for ( int i = 1; i <= n; i++ ) {
            if ( d[i] == -1 ) tarjan(i);
        }
        int mxm = 0;
        int ans = 1;
        for ( int i = 1; i <= n; i++ ) {
            int t = dfs(i);
            ///cout << t << endl;
            if ( t > mxm ) {
                mxm = t, ans = i;
            }
            else if ( t == mxm ) ans = min(i,ans);
        }
        cout << "Case " << T << ": " << ans << endl;
    }
    return 0;
}
