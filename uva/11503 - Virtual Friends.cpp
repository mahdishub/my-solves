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
#define MAX            100005

typedef long long ll;
typedef unsigned long long ull;
typedef pair < int,int > ii;
typedef priority_queue< int,vector<int>, greater<int> > pq_increasing;


unordered_map < string,int > id;
int parent[MAX],r[MAX];
int idn;

inline void setid ( string s ) {
    if ( id[s] == 0 ) {
        idn++;
        id[s] = idn;
    }
}

inline int findp ( int a ) {
    return ( parent[a] == a ) ? a : parent[a] = findp(parent[a]);
}

inline void Union( int a, int b ) {
    int u,v;
    u = findp(a);
    v = findp(b);
    if ( u != v ) {
        r[v] += r[u];
        parent[u] = v;
    }
}

int main ( ) {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t,f;
    cin >> t;
    while ( t-- ) {
        cin >> f;
        for ( int i = 1; i < MAX; i++ ) r[i] = 1,parent[i] = i;
        idn = 0;
        id.clear();
        while ( f-- ) {
            string s1,s2;
            cin >> s1 >> s2;
            setid(s1),setid(s2);
            Union(id[s1],id[s2]);
            cout << r[findp(id[s2])] << endl;
        }
    }
}
