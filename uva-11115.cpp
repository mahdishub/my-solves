
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




unordered_map < int,vector < string > > values;

string rev ( string s ) {

    int len = s.length();
    for ( int i = 0; i < len/2; i++ )
        swap(s[i],s[len-i-1]);
    return s;
}

string calc ( string s,int p ) {
    string res = "";
    char c;
    int len = s.length(),mf,carry=0,r,ans;
    for ( int i = len-1; i >= 0; i-- ) {///249*9
        mf = s[i] - '0';///9
        ans = mf * p;///81
        ans += carry;
        r = ans % 10;
        carry = ans / 10;
        c = char ( r + '0');///1
        res += c;
    }
    if ( carry > 0) {
        c = char (carry + '0');
        res += c;
    }
    return rev(res);
}



void precalc ( ) {

    for ( int i = 1; i <= 10; i++ ) {
        values[i].push_back("1");
        if ( i == 10 )
            values[i].push_back("10");
        else {
            string init = "";
            init += char ( i + '0' );
            values[i].push_back(init);
        }
        for ( int j = 2; j <= 25; j++ ) {
            string s = values[i][j-1];
            string res = calc(s,i);
            values[i].push_back(res);
        }
    }

}

int main ( ) {

    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);

    precalc();
    int a,b;
    while ( cin >> a >> b , a||b ) {

        cout << values[a][b] <<endl;

    }
    return 0;
}
