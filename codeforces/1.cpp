#include<bits/stdc++.h>

using namespace std;

#define precision(n)   cout << setprecision(n) << fixed
#define scll(a)        scanf("%lld",&a)
#define pi             3.1415926535
#define eps            0.0000000001
#define getlong(a)     scanf("%lld",&a)
#define mp             make_pair

typedef unsigned long long ull;
typedef long long int ll;
typedef priority_queue< int,vector<int>, greater<int> > pq_increasing;
typedef pair< int,int > point;

int arr[100005];

int segment_end( int l,int n ) {
    int right;
    for ( int i = l; i <= n; i++ ) {
        if ( arr[i] < arr[i+1] ) {
            right = i;
            break;
        }
    }
    return right;
}

int main ( ) {

    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    for ( int i = 1; i <= n; i++ )
        cin >> arr[i];
    arr[0] = 0;
    arr[n+1] = (int)1e9;
    bool segmentfound = false,no = false;
    int left = 1,right;
    for ( int i = 1; i <= n; i++ ) {
        if ( arr[i] > arr[i+1] ) {/// 0 10 1 11 12 13 1e9
            if ( segmentfound ) {
                no = true;
                break;
            }
            else
                segmentfound = true;
            left = i;
            right = segment_end(left,n);
            if ( arr[left-1] > arr[right] ) {
                no = true;
                break;
            }
            if ( arr[left] > arr[right+1] ) {
                no = true;
                break;
            }
            i = right;
        }
    }
    if ( no )
        cout << "no\n";
    else {
        if ( !segmentfound )
            cout << "yes\n" << left << ' ' << left << endl;
        else
            cout << "yes\n" << left << ' ' << right  << endl;
    }
}
