#include<bits/stdc++.h>

using namespace std;

#define precision(n)   cout << setprecision(n) << fixed
#define sf(a)          scanf("%d",&a)
#define sf2(a,b)       scanf("%d %d",&a,&b);
#define pi             3.1415926535
#define eps            0.000001
#define gl(a)          scanf("%llu",&a)
#define mod            1000000007
#define pf             printf
#define loop(ds,itr)   for ( auto itr = ds.begin(); itr != ds.end(); itr++ )
#define bug            cout << 'x' << endl;
#define check(x)       cout << x << endl;
#define e              2.71828182845
#define mp             make_pair
#define s              second
#define f              first
#define min4(a,b,c,d)  min(a,min(b,min(c,d)));

typedef long long ll;
typedef unsigned long long ull;
typedef pair < int,int > ii;
typedef priority_queue< ii,vector<ii>, greater<ii> > pq_increasing;

vector < ii > graph[20005];
int dist[20005];


int main ( ) {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int cases;
    sf(cases);
    for ( int q = 1; q <= cases; q++ ) {
        for ( int i = 0; i < 20005; i++ ) graph[i].clear(),dist[i] = INT_MAX;
        int n,m,s,t,a,b,c;
        scanf("%d%d%d%d",&n,&m,&s,&t);
        while (m--) scanf("%d%d%d",&a,&b,&c),graph[a].push_back({b,c}),graph[b].push_back({a,c});
        pq_increasing pq;
        pq.push({0,s});
        dist[s] = 0;
        int u,v,node_cost,edge_cost;
        while ( !pq.empty() ) {
            u = pq.top().second;
            node_cost = pq.top().first;
            if ( u == t )
                break;
            pq.pop();
            for ( int i = 0; i < graph[u].size(); i++ ) {
                v = graph[u][i].first;
                edge_cost = graph[u][i].second;
                if ( node_cost + edge_cost < dist[v] ) {
                    dist[v] = node_cost + edge_cost;
                    pq.push({dist[v],v});
                }
            }
        }
        ( dist[t] != INT_MAX ) ? printf("Case #%d: %d\n",q,dist[t]): printf("Case #%d: unreachable\n",q);
    }
}
