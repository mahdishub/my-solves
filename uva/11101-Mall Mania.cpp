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
#define inf            0x3f3f3f3f
#define MAX            2005

typedef long long ll;
typedef unsigned long long ull;
///typedef pair < int,int > ii;
typedef priority_queue< int,vector<int>, greater<int> > pq_increasing;

struct ii {
    int first,second;
};

int level[MAX][MAX];
vector < ii > sources;
vector < ii > dest;
bool m2[MAX][MAX];
queue <ii> q;
bool visited[MAX][MAX];
short moves_x[4] = {1,0,-1,0};
short moves_y[4] = {0,-1,0,1};

inline void push( ii src,int x, int y ) {
    if ( x > 2000 || x  < 0 || y < 0 || y > 2000 || visited[x][y] ) return;
    level[x][y] = level[src.first][src.second]+1;
    visited[x][y] = true;
    q.push({x,y});
}

int bfs( ) {
    int x,y;
    while ( !q.empty() ) {
        x = q.front().first, y = q.front().second;
        if ( m2[x][y] ) {
            return level[x][y];
        }
        q.pop();
        for ( int i = 0; i < 4; i++ ) push({x,y},x+moves_x[i],y+moves_y[i]);
    }
}

int main () {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int p1,p2,t1,t2;
    while ( scanf("%d",&p1) , p1 ) {
        memset(m2,0,sizeof(m2));
        for ( int i = 0; i < MAX; i++ ) fill(level[i],level[i]+MAX,inf);
        memset(visited,0,sizeof(visited));
        while (!q.empty())q.pop();
        int t1,t2;
        for ( int i = 0 ; i < p1; i++ ) {
            scanf("%d%d",&t1,&t2);
            q.push({t1,t2});
            visited[t1][t2] = true;
            level[t1][t2] = 0;
        }
        scanf("%d",&p2);
        for ( int i = 0; i < p2; i++ ) {
            scanf("%d%d",&t1,&t2);
            dest.push_back({t1,t2});
            m2[t1][t2] = true;
        }
        printf("%d\n",bfs());
    }

}

