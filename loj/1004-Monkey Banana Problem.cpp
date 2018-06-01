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

int arr[105][105];
ll memo[105][105];


int main () {
    int t;
    sf(t);
    for ( int q = 1; q <= t; q++ ) {
        int n;
        sf(n);
        for( int i = 1; i <= n; i++ ) {
            for ( int j = 1; j <= i; j++ ) {
                sf(arr[i][j]);
                memo[i][j] = max(arr[i][j]+memo[i-1][j],arr[i][j]+memo[i-1][j-1]);
            }
        }
        int i1 = n;
        for ( int i = n-1; i >= 1; i-- ) {
            i1++;
            for ( int j = 1; j <= i; j++ ) {
                sf(arr[i1][j]);
                memo[i1][j] = max(arr[i1][j]+memo[i1-1][j],arr[i1][j] + memo[i1-1][j+1]);
            }
        }
        printf("Case %d: %lld\n",q,memo[2*n-1][1]);
    }
}
