#include<bits/stdc++.h>

using namespace std;

#define precision(n)   cout << setprecision(n) << fixed
#define sf(a)          scanf("%d",&a)
#define sf2(a,b)       scanf("%d %d",&a,&b)
#define pi             3.1415926535
#define eps            0.000001
#define gl(a)          scanf("%llu",&a)
#define mod            1000000007
#define pf             printf
#define loop(ds,itr)   for ( auto itr = ds.begin(); itr != ds.end(); itr++ )
#define fr(i,n)        for ( int i = 0; i < n; i++ )
#define bug            cout << 'x' << endl;
#define check(x)       cout << x << endl;
#define e              2.71828182845
#define mp             make_pair
#define min4(a,b,c,d)  min(a,min(b,min(c,d)));
#define inf            0x3f3f3f3f
#define MAX            100005
///#define first          f
///#define second         s

typedef long long ll;
typedef unsigned long long ull;
typedef pair < int,int > ii;
typedef priority_queue< int,vector<int>, greater<int> > pq_increasing;

int arr[505][505];

int main () {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    while ( sf2(n,m) , n|m ) {
        fr(i,n) fr(j,m) sf(arr[i][j]);
        int q,l,u;
        sf(q);
        while ( q-- ) {
            sf2(l,u);
            int maxm = 0,mt, k = min(n,m);
            for ( int i = 0; i < n; i++ ) {
                mt = 0;
                int lo = lower_bound(arr[i],arr[i]+m,l)-arr[i];
                for ( int j = 0; j < k; j++ ) {
                    if (  lo+j < m && i+j < n && arr[i][lo+j]<= u && arr[i+j][lo] <= u && arr[i+j][lo+j] <= u ) mt++;
                    else break;
                }
                maxm = max(mt,maxm);
            }
            printf("%d\n",maxm);
        }
        printf("-\n");
    }
}
