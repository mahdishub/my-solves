#include<bits/stdc++.h>

using namespace std;

#define precision(n)   cout << setprecision(n) << fixed
#define sf(a)          scanf("%d",&a)
#define pi             3.1415926535
#define eps            0.0000000001
#define gl(a)          scanf("%lld",&a)
#define mp             make_pair
#define mod            1000000007
#define pf             printf

typedef unsigned long long ull;
typedef long long int ll;
typedef priority_queue< int,vector<int>, greater<int> > pq_increasing;

ull pascal[51][51];

void precalc() {

    for ( int i = 0; i < 51 ; i++ )
        pascal[i][0] = 1;
    for ( int i = 1; i < 51; i++ ) {
        for ( int j = 1; j <= i; j++ ) {
            pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
        }
    }

}



int main ( ) {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    precalc();///generating pascal triangle
    int t;
    cin >> t;
    for(int q = 1; q <= t; q++ ){

        char a[100],b[100];
        int n;
        getchar();///taking newline
        getchar();/// taking (
        scanf("%[^+]",a);/// taking  string a upto +
        getchar();/// taking +
        scanf("%[^)]",b);///taking string b upto )
        scanf(")^%d",&n);/// taking n
        pf("Case %d: ",q);
        if ( n == 1 ) {///handling for (a+b)^1
            pf("%s+%s\n",a,b);
            continue;
        }
        ///suppose for (a+b)^3
        pf("%s^%d",a,n);/// a^3
        for ( int i = 1; i < n; i++ ) {
           pf("+%llu*",pascal[n][i]);///prints "+nci*"(here 3C1 = 3 && 3C2 = 3)
           if ( i == n-1 )///printing string a
              pf("%s*",a);///a*
           else
              pf("%s^%d*",a,n-i);///a^2*
           if ( i == 1 )///printing string b
              pf("%s",b);///b
           else
              pf("%s^%d",b,i);///b^2
        }
        pf("+%s^%d\n",b,n);///+b^3


    }
}
