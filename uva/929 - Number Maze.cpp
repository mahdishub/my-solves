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
#define mp             make_pair
#define f              first
#define s              second


typedef long long ll;
typedef unsigned long long ull;
typedef pair < int,int > p;
typedef pair < int,p > node;
typedef priority_queue< node,vector<node>, greater<node> > pq_increasing;

int arr[1005][1005];
int d[1005][1005];
int n,m;
pq_increasing pq;
node k;

void  push ( int r, int c, int x, int y ) {
    if ( r <= 0 || c <= 0 || r > n || c > m )
        return;
    if ( d[r][c] + arr[x][y] < d[x][y] ){
        d[x][y] = d[r][c] + arr[x][y];
        k.f = d[x][y];
        k.s = mp(x,y);
        pq.push(k);
    }
}

int main ( ) {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while ( t-- ) {
        for ( int i = 0; i < 1005; i++ ) {
            for ( int j = 0; j < 1005; j++ )
                d[i][j] = INT_MAX;
        }
        cin >> n >> m;
        for ( int i = 1; i <= n; i++ ) {
            for ( int j = 1; j <= m; j++ ) {
                cin >> arr[i][j];
            }
        }

        /// dijktras algo
        k.f = arr[1][1];
        k.s = mp(1,1);
        pq.push(k);
        d[1][1] = arr[1][1];
        while ( !pq.empty() ) {
            node src = pq.top();
            pq.pop();
            int r = src.s.f;
            int c = src.s.s;
            push(r,c,r+1,c);
            push(r,c,r-1,c);
            push(r,c,r,c+1);
            push(r,c,r,c-1);
        }
        /// dijkstra end
        cout << d[n][m] << endl;
    }
    return 0;
}


