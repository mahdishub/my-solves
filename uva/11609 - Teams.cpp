#include<bits/stdc++.h>

using namespace std;

#define precision(n)   cout << setprecision(n) << fixed
#define sf(a)          scanf("%d",&a)
#define pi             3.1415926535
#define eps            0.0000000001
#define gl(a)          scanf("%lld",&a)
#define mp             make_pair
#define mod            1000000007

typedef unsigned long long ull;
typedef long long int ll;
typedef priority_queue< int,vector<int>, greater<int> > pq_increasing;


ull modpow ( ull a , ull b ) {/// a^b
    ull res;
    if ( b == 0 )
        return 1;
    else if ( b & 1 ) {
        res = ( a % mod) * ( modpow(a,b-1) % mod ) % mod;
        return res;
    }
    else {
        res = ( modpow(a,b>>1) ) % mod;
        return (res*res)%mod;
    }

}


int main ( ) {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    for ( int q = 1; q<= t; q++ ) {
        ull n,a;
        cin >> n;
        n %= mod;
        printf("Case #%d: ",q);
        cout << ( modpow(2,n-1) * n ) % mod << endl;

    }
}
