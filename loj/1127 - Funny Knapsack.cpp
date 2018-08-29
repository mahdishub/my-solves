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
#define maxm           15

typedef long long ll;
typedef unsigned long long ull;
typedef pair < ull,int > ii;
typedef priority_queue< ii,vector<ii>, greater<ii> > pq_increasing;

string s,s1;
int n;
ll w;
vector < string > subsets;
vector < ll > arr1,arr2;
vector < ll > sum1,sum2;

void gen ( ) {
    ll sz = 1 << 15;
    for ( int i = 0; i < sz; i++ ) {
        bitset <15> str(i);
        string sa = str.to_string();
        subsets.push_back(sa);
    }
}

void calc ( ) {
    ll sum = 0;
    ll  sz = ( 1 << arr1.size() );
    for ( int i = 0; i < sz; i++ )  {
        sum = 0;
        for ( int j = 0; j < subsets[i].size(); j++ ) {
            if ( subsets[i][j] == '1' )
                sum += arr1[14-j];
        }
        if ( sum <= w ) sum1.push_back(sum);
    }

    sz = (  1 << arr2.size() );
    for ( int i = 0; i < sz; i++ ) {
        sum = 0;
        for ( int j = 0; j < subsets[i].size(); j++ ) {
            if ( subsets[i][j] == '1' )
                sum += arr2[14-j];
        }
        if ( sum <= w ) sum2.push_back(sum);
    }
}


int main ( ) {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int test;
    sf(test);
    gen();
    for( int q = 1; q <= test; q++ ) {
        arr1.clear(),arr2.clear();
        sum1.clear(),sum2.clear();
        scanf("%d%lld",&n,&w);
        int w1;
        for ( int i = 0; i < n; i++ ) {
            scanf("%d",&w1);
            ( i & 1 )? arr1.push_back(w1) : arr2.push_back(w1);
        }
        calc();
        ll rem;
        ll ans = 0;
        sort(sum2.begin(),sum2.end());
        for ( int i = 0 ; i < sum1.size(); i++ ) {
            rem = w - sum1[i];
            ans += upper_bound(sum2.begin(),sum2.end(),rem) - sum2.begin();
        }
        printf("Case %d: %lld\n",q,ans);
    }
}
