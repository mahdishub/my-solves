
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

string rev ( string s ) {///reversing string used in multiply

    int len = s.length();
    for ( int i = 0; i < len/2; i++ )
        swap(s[i],s[len-i-1]);
    return s;
}

string multiply ( string s,int p ) {///to multiply number as string with number as int
    string res = "";
    char c;
    int len = s.length(),mf,carry=0,r,ans;
    for ( int i = len-1; i >= 0; i-- ) {
        mf = s[i] - '0';
        ans = mf * p;
        ans += carry;
        r = ans % 10;
        carry = ans / 10;
        c = char ( r + '0');
        res += c;
    }
    if ( carry > 0) {
        c = char (carry + '0');
        res += c;
    }
    return rev(res);
}



void precalc ( ) {/// calculating all values n^d

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
            string res = multiply(s,i);///multiply called
            values[i].push_back(res);
        }
    }

}

int main ( ) {

    precalc();
    int a,b;
    while ( cin >> a >> b , a||b ) {

        cout << values[a][b] <<endl;

    }
    return 0;
}
