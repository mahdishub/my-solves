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
#define SIZE           10000000

typedef long long ll;
typedef unsigned long long ull;
typedef priority_queue< int,vector<int>, greater<int> > pq_increasing;

bool sieve[SIZE];
void primeSieve ( int n ) {
    sieve[0] = sieve[1] = 1;
    for ( int i = 4; i <= n; i += 2 ) sieve[i] = true;
    int sqrtn = sqrt ( n );
    for ( int i = 3; i <= sqrtn; i += 2 ) {
        if ( sieve[i] == false ) {
            for ( int j = i * i; j <= n; j += 2 * i ) sieve[j] = true;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    primeSieve(SIZE);
    while ( n-- ) {
        long long p;
        cin >> p;
        long long sqrtn = floor(sqrt(p)+eps);
        if ( sqrtn*sqrtn == p )
            if ( !sieve[sqrtn] )
                cout << "YES\n";
            else
                cout << "NO\n";
        else
            cout << "NO\n";
    }
}
