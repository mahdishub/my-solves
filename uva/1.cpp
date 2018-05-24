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

typedef long long ll;
typedef unsigned long long ull;
typedef priority_queue< int,vector<int>, greater<int> > pq_increasing;


double p,q,r,s,t,u;

double findval ( double x ) {

    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

double findx ( double low,double high ) {

    double mid,ans;
    mid = (low + high)/2.00;
    ans = findval(mid);
    if ( fabs(ans) < eps )
        return mid;
    else {
        if ( findval(low)*findval(mid) > 0 )
            return findx(mid,high);
        else
            return findx(low,mid);
    }
}

int main ( ) {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    precision(4);
    while ( cin >> p >> q >> r >> s >> t >> u ) {
        if ( findval(0)*findval(1) > 0 )
            cout << "No solution\n";
        else
            cout << findx(0.00,1.00) << endl;
    }
}


