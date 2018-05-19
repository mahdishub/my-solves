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

typedef long long ll;
typedef unsigned long long ull;
typedef priority_queue< int,vector<int>, greater<int> > pq_increasing;


int main ( ) {

    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int r,c,d;
    cin >> r >> c >> d;
    int n = r*c;
    int arr[n];
    for ( int i = 0; i < n ; i++ )
        cin >> arr[i];
    sort(arr,arr+n);
    int mid = n/2;
    bool flag = true;
    int count = 0;
    for ( int i = 0; i < n; i++ ) {
        int diff = abs(arr[i] - arr[mid]);
        if ( diff % d != 0 ) {
            flag = false;
            break;
        }
        count += (diff/d);
    }
    if ( !flag )
        cout << "-1" << endl;
    else
        cout << count << endl;

}
