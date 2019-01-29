#include<bits/stdc++.h>

using namespace std;

#define precision(n)   cout << setprecision(n) << fixed
#define sf(a)          scanf("%d",&a)
#define sf2(a,b)       scanf("%d %d",&a,&b)
#define pi             3.1415926535
#define eps            0.000001
#define gl(a)          scanf("%llu",&a)
#define mod            1000000007
#define pf             printf
#define loop(ds,itr)   for ( auto itr = ds.begin(); itr != ds.end(); itr++ )
#define fr(i,n)        for ( int i = 0; i < n; i++ )
///#define check(x)       cout << x << endl;
#define bug            cout << 'x' << endl;
#define srt(n)         (int)(sqrt(double(n))+eps)
#define e              2.71828182845
#define mp             make_pair
#define min4(a,b,c,d)  min(a,min(b,min(c,d)));
#define power(n,i)     (int)(pow(n,i)+eps)
#define inf            0x3f3f3f3f
///#define MAX            100005
#define f              first
#define s              second
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


/// d ----- 0-> N, 1 -> E, 2 -> S, 3 -> W;

bool arr[51][51];
int level[51][51][4];
int n,m;
struct node {
    short x,y,d;
};

bool check ( short x, short y ) {
   if ( x <= 0 | y <= 0 | x >= n | y >= m ) return false;
   else if ( arr[x][y] | arr[x][y-1] | arr[x-1][y] | arr[x-1][y-1]  ) return false;
   else return true;
}
node moves[4][5] = { {{-1,0,0},{-2,0,0}, {-3,0,0},{0,0,1},{0,0,3}},
                     {{0,1,1} ,{0,2,1} , {0,3,1},{0,0,0},{0,0,2}},
                     {{1,0,2} ,{2,0,2} , {3,0,2},{0,0,3},{0,0,1}},
                     {{0,-1,3},{0,-2,3}, {0,-3,3},{0,0,2},{0,0,0}}
                 };
void bfs ( node src ) {
    queue <node> q;
    q.push(src);
    short x,y,d,nx,ny,nd;
    int l;
    level[src.x][src.y][src.d] = 0;
    while ( !q.empty() ) {
        x = q.front().x, y = q.front().y, d = q.front().d;
        l = level[x][y][d];
        q.pop();
        for ( int i = 0; i < 5; i++ ) {
            node t = moves[d][i];
            nx = x+t.x, ny = y+t.y;
            if ( !check(nx,ny) ) { i = 2; continue;}
            if ( level[nx][ny][t.d] == inf ) {
                level[nx][ny][t.d] = l + 1;
                q.push({nx,ny,t.d});
            }
        }
    }
}


int main () {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while ( cin >> n >> m, n,m ) {
        memset(level,inf,sizeof(level));
        fr(i,n) fr(j,m) cin >> arr[i][j];
        node s,target;
        string str;
        cin >> s.x >> s.y >> target.x >> target.y >> str;
        if ( str[0] == 'n' ) s.d = 0;
        else if ( str[0] == 'e' ) s.d = 1;
        else if ( str[0] == 's' ) s.d = 2;
        else s.d = 3;
        bfs(s);
        int ans = inf;
        for ( int i = 0; i < 4; i++ ) ans = min(ans,level[target.x][target.y][i]);
        if ( ans == inf ) ans = -1;
        cout << ans << endl;
    }
    return 0;
}
