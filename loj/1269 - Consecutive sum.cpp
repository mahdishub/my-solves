#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define precision(n)   cout << setprecision(n) << fixed
#define sf(a)          scanf("%d",&a)
#define sf2(a,b)       scanf("%d %d",&a,&b)
#define sf3(a,b,c)     scanf("%d%d%d",&a,&b,&c)
#define pi             3.1415926535
#define eps            0.000000001
#define gl(a)          scanf("%llu",&a)
#define mod            100000007
#define pf             printf
#define loop(ds,itr)   for ( auto itr = ds.begin(); itr != ds.end(); itr++ )
#define fr(i,n)        for ( int i = 0; i < n; i++ )
#define check(x)       cout << x << endl
#define bug            cout << 'x' << endl;
#define srt(n)         (int)(sqrt(double(n))+eps)
///#define e              2.71828182845
#define mp             make_pair
#define min4(a,b,c,d)  min(a,min(b,min(c,d)));
#define power(n,i)     (int)(pow(n,i)+eps)
#define inf            0x3f3f3f3f
#define MAX            100005
#define ff             first
#define ss              second
#define sqr(a)         a*a
#define all(v)         v.begin(),v.end()
/*
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
*/

typedef long long ll;
typedef unsigned long long ull;
typedef pair < int,int > ii;
typedef priority_queue< int,vector<int>, greater<int> > pq_increasing;
typedef tree< ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int last;
const int sz = (50000*32)+50000;
int n;
struct node {
    int child[2];
}Trie[sz];

void new_node ( int idx ) {
    Trie[idx].child[0] = Trie[idx].child[1] = -1;
}

void add ( int num ) {
    int itr = 0;
    int bit;
    for ( int i = 31; i >= 0; i-- ) {
        bit = (num>>i) & 1;
        if ( Trie[itr].child[bit] == -1 ) {
            new_node(++last);
            Trie[itr].child[bit] = last;
        }
        itr = Trie[itr].child[bit];
    }
}

int get_min ( int num ) {
    int itr = 0;
    int bit;
    int ans = 0;
    for ( int i = 31; i >= 0; i-- ) {
        bit = (num>>i) & 1;
        ans <<= 1;
        if ( bit == 0 ) {
            if ( Trie[itr].child[0] != -1 ) itr = Trie[itr].child[0], bit ^= 0, ans |= bit;
            else itr = Trie[itr].child[1], bit ^= 1, ans |= bit;
        }
        else {
            if ( Trie[itr].child[1] != -1 ) itr = Trie[itr].child[1], bit ^= 1, ans |= bit;
            else itr = Trie[itr].child[0], bit ^= 0, ans |= bit;
        }
    }
    return ans;
}

int get_max ( int num ) {
    int itr = 0;
    int bit;
    int ans = 0;
    for ( int i = 31; i >= 0; i-- ) {
        bit = (num>>i) & 1;
        ans <<= 1;
        if ( bit == 1 ) {
            if ( Trie[itr].child[0] != -1 ) itr = Trie[itr].child[0], bit ^= 0, ans |= bit;
            else itr = Trie[itr].child[1], bit ^= 1, ans |= bit;
        }
        else {
            if ( Trie[itr].child[1] != -1 ) itr = Trie[itr].child[1],bit ^= 1, ans |= bit;
            else itr = Trie[itr].child[0], bit ^= 0, ans |= bit;
        }
    }
    return ans;
}

int main () {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    ///cin.tie(0);
    int t;
    sf(t);
    for ( int T = 1; T <= t; T++ ) {
        last = 0;
        new_node(last);
        sf(n);
        int tmp;
        int cur = 0;
        add(0);
        int mnm,mxm;
        fr(i,n) {
            sf(tmp);
            cur ^= tmp;
            if ( i == 0 ) mnm = mxm = cur;
            mnm = min(mnm,get_min(cur));
            mxm = max(mxm,get_max(cur));
            add(cur);
        }
        printf("Case %d: %d %d\n",T,mxm,mnm);
    }
    return 0;
}
