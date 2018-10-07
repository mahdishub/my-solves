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
#define MAX            200005

typedef long long ll;
typedef unsigned long long ull;
typedef pair < int,int > ii;
typedef priority_queue< int,vector<int>, greater<int> > pq_increasing;

/// Kruskal Algo for mst.

struct node{
    int x,y,z;
};

bool cmp ( node a, node b ) {
    return a.z < b.z;
}

node arr[MAX];
int parent[MAX];
int cost,total;

inline int findp( int n ) {
    return ( parent[n] == n ) ? n : parent[n] = findp(parent[n]);
}
inline void Union ( int a, int b, int  c ) {
    int u = findp(a),v = findp(b);
    if ( u != v ) {
        parent[u] = v;
        cost += c;
    }
}

int main () {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m,n;
    while ( scanf("%d%d",&m,&n), n|m ) {
        for ( int i = 0; i <= m; i++ ) parent[i] = i;
        total = cost = 0;
        for ( int i = 0 ; i < n; i++ ) scanf("%d%d%d",&arr[i].x,&arr[i].y,&arr[i].z),total += arr[i].z;
        sort(arr,arr+n,cmp);
        int u,v,c,x,y;
        for ( int i = 0; i < n; i++ ) {
            u = arr[i].x, v = arr[i].y, c = arr[i].z;
            if ( findp(u) != findp(v) ) Union(u,v,c);
        }
        printf("%d\n",total-cost);
    }

}
