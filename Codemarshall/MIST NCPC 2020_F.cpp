#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define precision(n)   cout << setprecision(n) << fixed
#define sf(a)          scanf("%d",&a)
#define sf2(a,b)       scanf("%d %d",&a,&b)
#define sf3(a,b,c)     scanf("%d%d%d",&a,&b,&c)
#define pi             acos(-1.0)
#define eps            0.0000000001
#define gl(a)          scanf("%llu",&a)
#define mod            1000000007
#define pf             printf
#define loop(ds,itr)   for ( auto itr = ds.begin(); itr != ds.end(); itr++ )
#define fr(i,n)        for ( int i = 0; i < n; i++ )
#define fr1(i,n)       for ( int i = 1; i <= n; i++ )
#define check(x)       cout << x << endl;
#define bug            cout << 'x' << endl;
#define srt(n)         (int)(sqrt(double(n))+eps)

#define mp             make_pair
#define min4(a,b,c,d)  min(a,min(b,min(c,d)));
#define power(n,i)     (int)(pow(n,i)+eps)
#define inf            0x3f3f3f3f
#define MAX            100005
#define ff             first
#define ss             second
#define all(v)         v.begin(),v.end()
#define mem(x,v)       memset(x,v,sizeof(x))

#ifdef FACT
     #include <ctime>
     clock_t tStart = clock();
     #define debug(args...) {dbg,args; cerr<<endl;}
     #define timeStamp debug ("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)
     #define bug printf("%d\n",__LINE__);

#else
    #define debug(args...)
    #define timeStamp

#endif

struct debugger{
    template<typename T> debugger & operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;


typedef long long ll;
typedef unsigned long long ull;
typedef pair < int,int > ii;
typedef pair < int, ii > iii;
typedef priority_queue< int,vector<int>, greater<int> > pq_increasing;
///typedef tree< int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
template < class T > inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}


int main () {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    sf(t);

    for ( int T = 1; T <= t; T++ ) {
        int n,m;
        sf2(n,m);
        vector<int> v(n);
        priority_queue <iii> pq;
        int prev = 0,len;

        fr(i,n) sf(v[i]);


        sort(all(v));

        fr(i,n) {
            len = v[i]-prev;
            pq.push({len,{len,0}});
            prev = v[i];
        }
        len = m-prev;
        pq.push({len,{len,0}});



        vector<int>ans(m+1,1);
        ans[0] = pq.top().ff;


        for ( int i = 1; i <= m-1-n; i++ ) {

            iii top = pq.top();
            pq.pop();
            top.ss.ss++; /// increase stones
            int len = ceil(top.ss.ff/double(top.ss.ss+1)); /// find new max
            pq.push({len,{top.ss.ff,top.ss.ss}});
            ans[i] = pq.top().ff;
        }


        /// PROCESS QUERIES

        int q,tmp;
        sf(q);
        printf("Case %d:\n",T);
        while ( q-- ) {
            sf(tmp);
            printf("%d\n",ans[tmp]);
        }


    }


    return 0;
}
