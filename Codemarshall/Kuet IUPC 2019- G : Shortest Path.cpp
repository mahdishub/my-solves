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
#define check(x)       cout << x << endl;
#define bug            cout << 'x' << endl;
#define srt(n)         (int)(sqrt(double(n))+eps)
///#define e              2.71828182845
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
typedef pair < int,int > ii;
typedef priority_queue< int,vector<int>, greater<int> > pq_increasing;
typedef tree< ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;


int mark;
vector<ii> edges[30005];
ll dist[30005];
ll dist2[30005];
int belongs[30005];
ii mtype[30005];
bool type;
int start;

void dfs( int cur, int prev ) {
    if ( edges[start].size() == 0 ) {
        belongs[start] = mark;
        mtype[mark] = {0,start};
        return;
    }
    if ( cur == start && prev != 0 ) {
        belongs[start] = mark;
        mtype[mark] = {1,start};
        return;
    }
    if ( edges[cur].size() == 1 && prev != 0 ) {
        mtype[mark] = {0,cur};
        belongs[start] = mark;
        return;
    }
    for ( int i = 0; i < edges[cur].size(); i++ ) {
        if ( edges[cur][i].ff != prev ) {
            dfs(edges[cur][i].ff,cur);
            belongs[edges[cur][i].ff] = mark;
        }
    }
}


void fdfs ( int cur, int prev,ll cost, ll *arr ) {

    if ( edges[cur].size() == 0 ) {
        return;
    }
    if ( edges[cur].size() == 1 && prev != 0  ) {
        return;
    }
    if ( cur == start && prev != 0  ) {
        return;
    }

    for ( int i = 0; i < edges[cur].size(); i++ ) {
        int v = edges[cur][i].ff;
        ll c =  (ll)edges[cur][i].ss;
        if ( v != prev ) {
            arr[v] = cost+c;
            fdfs(v,cur,cost+c,arr);
        }
    }
}


int main () {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    scanf("%d",&t);
    for ( int T = 1; T <= t; T++ ) {
        memset(belongs,-1,sizeof(belongs));
        memset(dist,0,sizeof(dist));
        memset(dist2,0,sizeof(dist2));
        memset(mtype,0,sizeof(mtype));
        fr(i,30005) edges[i].clear();
        mark = 0;
        int n,e;
        scanf("%d%d",&n,&e);
        int u,v,w;
        while ( e-- ) {
            scanf("%d%d%d",&u,&v,&w);
            edges[u].push_back({v,w});
            edges[v].push_back({u,w});
        }
        for ( int i = 1; i <= n; i++ ) {
            if ( belongs[i] != -1 ) continue;
            type = 0;
            start = i;
            dfs(i,0);
            mark++;
        }
        for ( int i = 0; i < mark; i++ ) {
            start = mtype[i].ss;
            if ( mtype[i].ff  ) {
                ii tmp = edges[start][0];
                dist[tmp.ff] = tmp.ss;
                fdfs(tmp.ff,start,tmp.ss,dist);
                tmp = edges[start][1];
                dist2[tmp.ff] = tmp.ss;
                fdfs(tmp.ff,start,tmp.ss,dist2);
            }
            else fdfs(start,0,0,dist);
        }
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",T);
        while ( q-- ) {
            scanf("%d%d",&u,&v);
            if ( belongs[u] != belongs[v] ) printf("-1\n");
            else if ( mtype[belongs[v]].ff == 0 ) printf("%lld\n",(ll)abs(dist[v]-dist[u]));
            else {
                ll mnm;
                mnm = (ll)min(abs(dist[v]-dist[u]),abs(dist2[v]-dist2[u]));
                mnm = min(dist[u]+dist2[v],mnm);
                mnm = min(dist[v]+dist2[u],mnm);
                printf("%lld\n",mnm);
            }
        }
    }

    return 0;
}


