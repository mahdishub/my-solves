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
#define min4(a,b,c,d)  min(a,min(b,min(c,d)));
#define MAX            2005

typedef long long ll;
typedef unsigned long long ull;
typedef pair < int,int > ii;
typedef priority_queue< int,vector<int>, greater<int> > pq_increasing;

vector < int > graph[MAX];
short color[MAX];
vector < pair<int,int> > pointlist;
bool bicolor;
short dp[1005][1005];
ll sum;

pair<int,int> bfs ( int src ) {
    queue < int > q;
    color[src] = 1;
    q.push(src);
    int c1=0,c2=0;
    while ( !q.empty() && bicolor ) {
        int u = q.front();
        q.pop();
        ( color[u] == 1 ) ? c1++: c2++;
        for ( int i = 0; i < graph[u].size(); i++ ) {
            int v = graph[u][i];
            if ( color[v] == color[u] ) { bicolor = false; break;}
            else if ( color[v] == 0 ) {
                (color[u] == 1 ) ? color[v] = 2: color[v] = 1;
                q.push(v);
            }
        }
    }
    sum += c1 + c2;
    return {c1,c2};
}
bool coloring(int p, int target) {
    if(target == 0 && p == pointlist.size() ) return true;
    if(target < 0 || p == pointlist.size() ) return false;
    if ( dp[p][target] != -1 ) return dp[p][target];
    dp[p][target] = coloring(p+1, target - pointlist[p].first) || coloring(p+1, target - pointlist[p].second);
    return dp[p][target];
}
int main ( ) {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    sf(t);
    while( t-- ){
        bicolor = true;
        for ( int i = 0; i < MAX; i++ ) graph[i].clear();
        sum = 0;
        memset(dp,-1,sizeof(dp));
        memset(color,0,sizeof(color));
        pointlist.clear();
        int c,b,con;
        scanf("%d%d%d",&c,&b,&con);
        int p,q;
        for ( int i = 0; i < con; i++ ) {
            scanf("%d%d",&p,&q);
            graph[p].push_back(q);
            graph[q].push_back(p);
        }
        for ( int i = 1; i <= b+c; i++ ) {
            if ( color[i] > 0 ) continue;
            pointlist.push_back(bfs(i));
            if ( !bicolor ) break;
        }
        if ( !bicolor || (sum - b) != c ) printf("no\n");
        else ( coloring(0,b) ) ? printf("yes\n") : printf("no\n");
    }
}
