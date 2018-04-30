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


int main ( ) {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    int p,q,r,s,n,low,high;
    precision(5);
    while( cin >> p >> q >> r >> s ) {

        double ans = 1.00;
        q = min(q,p-q);
        s = min(s,r-s);
        high = max(q,s);
        for (int i = 0; i < high; i++ ) {
            if ( i < q && i < s )
                ans = ans*(double(p-i)/double(r-i));
            else if ( i < q )
                ans = ans*(double(p-i)/double(i+1));
            else if ( i < s )
                ans = ans/(double(r-i)/double(i+1));
        }
        cout  << ans << endl;
    }

}
