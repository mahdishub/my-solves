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

int dist[505];
int cost[105];
vector <int> floors[10];
int n,d;
vector < ii > graph[505];

inline void searchcon ( int  lift, int floor ) {
    for ( int i = 0; i < n; i++ ) {
        if ( i == lift ) continue;
        if ( binary_search(floors[i].begin(),floors[i].end(),floor ) ) {
            int index = lift*100+floor;
            int edge = i*100+floor;
            int c = 60;
            if ( floor == 0 )
                c = 0;
            graph[index].push_back({c,edge});
        }
    }
}
int main ( ) {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ///ios_base::sync_with_stdio(false);
    while ( cin >> n >> d ) {
        memset(cost,0,105);
        for ( int i = 0; i < 10; i++ ) floors[i].clear();
        for ( int i = 0; i < 505; i++ ) graph[i].clear();
        for ( int i = 0; i < n; i++ ) cin >> cost[i];
        string s;
        getchar();
        for ( int i = 0; i < n; i++ ){
            getline(cin,s);
            stringstream ss(s);
            int f;
            while ( ss >> f ) floors[i].push_back(f);
        }
        int i,j;
        for ( i = 0; i < n; i++ ) {
            for ( j = 0; j < floors[i].size()-1; j++ ) {
                int index = i*100+floors[i][j];
                int edge = i*100+floors[i][j+1];
                int c = cost[i]*(floors[i][j+1]-floors[i][j]);
                graph[index].push_back({c,edge});
                graph[edge].push_back({c,index});
                searchcon(i,floors[i][j]);
            }
            searchcon(i,floors[i][j]);
        }
        pq_increasing pq;
        for ( int i = 0; i < 505; i++ ) dist[i] = INT_MAX;
        int m = INT_MAX,src;
        for ( int i = 0; i < n; i++ ) {
            dist[i*100] = 0;
            if ( m > cost[i] && floors[i][0] == 0 ) {
                src = i;
                m = cost[i];
            }
        }
        pq.push({0,src*100});
        while ( !pq.empty() ) {
            int u = pq.top().second;
            int node_cost = pq.top().first;
            pq.pop();
            for ( int i = 0; i < graph[u].size(); i++ ) {
                int v = graph[u][i].second;
                int edge_cost = graph[u][i].first;
                if ( node_cost + edge_cost < dist[v] ) {
                    dist[v] = node_cost + edge_cost;
                    pq.push({dist[v],v});
                }
            }
        }
        int minm = INT_MAX;
        for ( int i = 0; i < 5; i++ ) minm = min(minm,dist[i*100+d]);

        if ( minm == INT_MAX ) cout << "IMPOSSIBLE\n";
        else cout << minm << endl;
    }
}
