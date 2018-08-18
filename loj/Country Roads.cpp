#include <bits/stdc++.h>

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
typedef pair< int,pair<int,int> > node;
typedef priority_queue< int,vector<int>, greater<int> > pq_increasing;

int cost[510][510];
int dist[510];
vector < int > graph[510];

int main ( ) {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    sf(t);
    for ( int T = 1; T <= t; T++ ) {
        int n,m,p,q,w;
        sf(n);
        sf(m);
        for ( int i = 0; i < 510; i++ )
            for ( int j = 0; j < 510; j++ )
                cost[i][j] = INT_MAX;
        for ( int i = 0; i < 510; i++ )
            dist[i] = INT_MAX;
        while ( m-- ) {
            scanf("%d%d%d",&p,&q,&w);
            if ( cost[p][q] == INT_MAX ) {
                graph[p].push_back(q);
                graph[q].push_back(p);
            }
            cost[p][q] = min(w,cost[p][q]);
            cost[q][p] = min(w,cost[q][p]);
        }
        int src;
        sf(src);
        queue < int > bfs;
        bfs.push(src);
        dist[src]= 0;
        while ( !bfs.empty() ){
            int u = bfs.front();
            bfs.pop();
            for ( int i = 0; i < graph[u].size(); i++ ) {
                int v = graph[u][i];
                int rdist = max (dist[u],cost[u][v]);
                if ( rdist < dist[v] ) {
                    dist[v] = rdist;
                    bfs.push(v);
                }
            }
        }
        printf("Case %d:\n",T);
        for ( int i = 0; i < n; i++ ) {
            if ( dist[i] == INT_MAX )
                printf("Impossible\n");
            else
                printf("%d\n",dist[i]);
        }
    }
    return 0;
}
