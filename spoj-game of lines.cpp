
#include<bits/stdc++.h>

using namespace std;

#define precision(n)   cout << setprecision(n) << fixed
#define sf(a)          scanf("%d",&a)
#define pi             3.1415926535
#define eps            0.0000000001
#define gl(a)          scanf("%lld",&a)
#define mp             make_pair

typedef unsigned long long ull;
typedef long long int ll;
typedef priority_queue< int,vector<int>, greater<int> > pq_increasing;

struct point {
    int x;
    int y;
};

int main ( ) {

    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);

    int n;
    while ( cin >> n , n ) {
        set < pair < int,int > > slopes;
        char c;
        point arr[n];
        for ( int i = 0; i < n; i++ ) {
            cin >> arr[i].x >> arr[i].y;
        }
        for ( int i = 0; i < n-1; i++ ) {
            for ( int j = i+1; j < n; j++ ) {
                int slopey = arr[i].x - arr[j].x;
                int slopex = arr[i].y - arr[j].y;
                int g = __gcd(slopex,slopey);
                slopex /= g;
                slopey /= g;
                slopes.insert(mp(slopex,slopey));
            }
        }
        cout << slopes.size() << endl;
    }
    return 0;
}
