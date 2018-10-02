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
#define e              2.71828182845
#define mp             make_pair
#define min4(a,b,c,d)  min(a,min(b,min(c,d)));
#define inf            0x3f3f3f3f

typedef long long ll;
typedef unsigned long long ull;
typedef pair < int,int > ii;
typedef priority_queue< int,vector<int>, greater<int> > pq_increasing;



int len = 5;
int arr[]={1,5,10,25,50};
ull dp[6][30005];

ull cc ( int index, int toMake ) {
    ull ans1 = 0,ans2 = 0;
    if ( dp[index][toMake] != -1 ) return dp[index][toMake];
    if ( index == len ) return ( toMake == 0 );
    ans1 =  cc(index+1,toMake);
    if ( toMake-arr[index] >= 0 )
        ans2 = cc( index,toMake-arr[index] );
    return dp[index][toMake] =  ans1+ans2;
}


int main () {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int toMake;
    memset(dp,-1,sizeof(dp));
    while(scanf("%d",&toMake) == 1){
        ull ways = cc(0,toMake);
        ( ways == 1 ) ? printf("There is only 1 way "):printf("There are %llu ways ",ways);
        printf("to produce %d cents change.\n",toMake);

    }


    return 0;
}
