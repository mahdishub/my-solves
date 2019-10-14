#include<iostream>
using namespace std;

typedef long long ll;


const int  sz = 2*1e5+10;
const int add = 1e5;
ll dp[sz];
int s[105],f[105];
#define fr(i,n) for ( int i = 0; i < n; i++ )

int main () {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    fr(i,n) cin >> s[i] >> f[i];
    fr(i,sz) dp[i] = INT_MIN;
    dp[add] = 0;
    dp[s[0]+add] = f[0];
    for ( int i = 1; i < n; i++ ) {
        if ( s[i] >= 0 ) {
            for ( int j = sz-1; j-s[i] >= 0 ; j-- ) {
                dp[j] = max(dp[j],dp[j-s[i]]+f[i]);
            }
        }
        else {
            for ( int j = 0; j-s[i] < sz; j++ ) {
                dp[j] = max(dp[j],dp[j-s[i]]+f[i]);
            }
        }
    }
    ll mxm = 0;
    for ( int i = add; i < sz; i++ ) {
        int ai = i-add;
        if ( dp[i] >= 0 ) mxm = max(mxm,ai+dp[i]);
    }
    cout << mxm << endl;
 }
