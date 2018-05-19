#include<bits/stdc++.h>

using namespace std;

#define precision(n)   cout << setprecision(n) << fixed
#define sf(a)          scanf("%d",&a)
#define pi             3.1415926535
#define eps            0.0000000001
#define gl(a)          scanf("%llu",&a)
#define mod            1000000007
#define pf             printf
#define loop(ds,itr)   for ( auto itr = ds.begin(); itr != ds.end(); itr++ )
#define bug            cout << 'x' << endl;
#define check(x)       cout << x << endl;

typedef long long ll;
typedef unsigned long long ull;
typedef priority_queue< int,vector<int>, greater<int> > pq_increasing;

bool grid[1005][1005];
int level[1005][1005];

struct pos {
    int r;
    int c;
}start,loc;

pos mp(int r, int c) {
    pos x;
    x.r = r;
    x.c = c;
    return x;
}
queue < pos > q;
void push( int row,int column,int lvl ) {

    q.push(mp(row,column));
    level[row][column] = lvl+1;


}
void bfs ( pos start, pos loc,int r, int c ) {


    q.push(start);
    level[start.r][start.c] = 0;
    while ( !q.empty() ) {
        pos src = q.front();
        q.pop();
        int lvl = level[src.r][src.c] + 1;
        if ( src.c + 1 <= c && !grid[src.r][src.c+1] ) {
            push(src.r,src.c+1,level[src.r][src.c]);
            grid[src.r][src.c+1] = true;
        }
        if ( src.r + 1 <= r && !grid[src.r+1][src.c] ) {
            push(src.r+1,src.c,level[src.r][src.c]);
            grid[src.r+1][src.c] = true;
        }
        if ( src.c - 1 >= 0 && !grid[src.r][src.c-1] ) {
            push(src.r,src.c-1,level[src.r][src.c]);
            grid[src.r][src.c-1] = true;
        }
        if ( src.r - 1 >= 0 && !grid[src.r-1][src.c] ) {
            push(src.r-1,src.c,level[src.r][src.c]);
            grid[src.r-1][src.c] = true;
        }

    }


}


int main ( ) {

    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int r,c,n,row,column,no;
    while ( cin >> r >> c , r || c ) {
        cin >> n;
        for ( int i = 0; i < 1005; i++ ) {
            memset(grid[i],false,1005);
            memset(level[i],-1,1005);
        }
        while ( n-- ) {
            cin >> row >> no;
            while ( no-- ) {
                cin >> column;
                grid[row][column] = true;
            }
        }
        cin >> start.r >> start.c >> loc.r >> loc.c;
        bfs(start,loc,r,c);
        cout << level[loc.r][loc.c] << endl;
    }
}
