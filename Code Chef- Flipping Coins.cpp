#include<bits/stdc++.h>

using namespace std;

#define precision(n)   cout << setprecision(n) << fixed
#define sf(a)          scanf("%d",&a)
#define sf2(a,b)       scanf("%d %d",&a,&b)
#define sf3(a,b,c)     scanf("%d%d%d",&a,&b,&c)
#define pi             3.1415926535
#define eps            0.000001
#define gl(a)          scanf("%llu",&a)
#define mod            1000000007
#define pf             printf
#define loop(ds,itr)   for ( auto itr = ds.begin(); itr != ds.end(); itr++ )
#define fr(i,n)        for ( int i = 0; i < n; i++ )
#define check(x)       cout << x << endl;
#define bug            cout << 'x' << endl;
#define srt(n)         (int)(sqrt(double(n))+eps)
#define e              2.71828182845
#define mp             make_pair
#define min4(a,b,c,d)  min(a,min(b,min(c,d)));
#define power(n,i)     (int)(pow(n,i)+eps)
#define inf            0x3f3f3f3f
///#define MAX            100005
#define f              first
///#define s              second
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
typedef priority_queue< int,vector<int>, greater<int> > pq_increasing;

const int MAX = int(3*1e5);
int tree[MAX];
bool lazy[MAX];
int Left,Right,c;

void marklazy ( int n ) {/// marking the children lazy
    n = n << 1;
    lazy[n] = lazy[n+1] = true;
}

void update_tree ( int idx,int l,int r ) {
    int nc = r-l+1,mid = int((l+r)>>1);
    ///cout << l << ' ' << r << endl;
    if ( lazy[idx] ) { /// if node needs to be updated
        tree[idx] = nc - tree[idx];
        if ( l != r ) marklazy(idx); /// if not leaf node
        lazy[idx] = false;
    }
    if ( l >= Left && r <= Right ) { ///fully in segment
        tree[idx] = nc - tree[idx];
        if ( l != r ) marklazy(idx);
        return;
    }
    if ( l == r | l > Right | r < Left ) return; /// out of segment or leaf
    update_tree(idx<<1,l,mid);
    update_tree((idx<<1)+1,mid+1,r);
    tree[idx] = tree[idx<<1] + tree[(idx<<1)+1];
}

int query ( int idx, int l, int r ) {
    ///cout << l << ' ' << r << endl;
    int nc = r-l+1,mid = int((l+r)>>1);
    int ans;
    if ( lazy[idx] ) {
        tree[idx] = nc - tree[idx];
        if ( l != r ) marklazy(idx);
        lazy[idx] = false;
    }
    if ( l >= Left && r <= Right ) {
        return tree[idx];
    }
    if ( l == r | l > Right | r < Left ) return 0;
    return query(idx<<1,l,mid) + query((idx<<1)+1,mid+1,r);
}


int main () {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(tree,0,sizeof(tree));
    memset(lazy,false,sizeof(lazy));
    int n,q;
    sf2(n,q);
    while ( q-- ) {
        sf3(c,Left,Right);
        Left++,Right++;
        if ( !c )  update_tree(1,1,n);
        else printf("%d\n",query(1,1,n));
    }
    return 0;
}
