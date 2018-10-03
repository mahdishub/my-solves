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

int sr,sc,dr,dc;

ll solve ( ) {
    bool se = false,de = false;
    if ( (sr & 1) == (sc & 1) ) se = true;
    if ( (dr & 1) != (dc & 1) ) de = true;
    if ( sr == dr ) return abs(sc-dc);
    else if ( abs(sr-dr) <= abs(sc-dc) ) return abs(sr-dr)+abs(sc-dc);
    else {
        int ans = max(abs(sr-dr),abs(sc-dc));
        if ( se && de ) return ans*2-1;
        else if ( !se && !de ) return ans*2+1;
        else return ans*2;
    }
}

int main () {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while ( scanf("%d%d%d%d",&sr,&sc,&dr,&dc),sr|sc|dr|dc) {
        if ( sr > dr ) {swap(sr,dr),swap(sc,dc);}
        if ( sc > dc ) sc = 2*dc-sc;
        printf("%lld\n",solve());
    }

}
