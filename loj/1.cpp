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
#define SIZE           10000000

typedef long long ll;
typedef unsigned long long ull;
typedef priority_queue< int,vector<int>, greater<int> > pq_increasing;


ull calculate ( int n, int k ) {
    ull ans = 1;
    for ( int i = 1; i <= k; i++ ) {
        ans *= (n-i+1);
        if ( ans % i == 0 )
            ans /= i;
    }
    for ( int i = 1; i <= k; i++ )
        ans *= (n-i+1);

    return ans;
}


int main () {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    sf(t);
    for ( int q = 1; q <= t; q++ ) {
        int n,k;
        sf(n);
        sf(k);
        if ( k > n ) {
            printf("Case %d: 0\n",q);
        }
        else {
            printf("Case %d: %llu\n",q,calculate(n,k));
        }
    }
    return 0;
}
