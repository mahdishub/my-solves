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
#define MAX            100005
#define f              first
#define s              second
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

const int sz = 1e5;

struct node {
    int sum,psum,ssum,val;
};

node tree[2*sz];
int arr[sz];

void init ( int idx, int l, int r ) {
    if ( l == r ) {
        tree[idx] = (node){arr[l],arr[l],arr[l],arr[l]};
        return;
    }
    int m = (l+r)>>1, L = (idx<<1)+1 , R = L+1;
    init(L,l,m);
    init(R,m+1,r);
    tree[idx].sum = tree[L].sum + tree[R].sum;
    tree[idx].psum = max(tree[L].psum,tree[L].sum + tree[R].psum);
    tree[idx].ssum = max(tree[R].ssum, tree[R].sum + tree[L].ssum);
    tree[idx].val = max(tree[L].ssum+tree[R].psum, max(tree[L].val,tree[R].val));
}



node query ( int idx, int l, int r, int ql, int qr ) {
    if ( ql == l && qr == r ) return tree[idx];
    int m = (l+r)>>1, L = (idx<<1)+1, R = L+1;
    if ( ql > m ) return query(R,m+1,r,ql,qr);
    if ( qr <= m ) return query(L,l,m,ql,qr);
    node nl = query(L,l,m,ql,m);
    node nr = query(R,m+1,r,m+1,qr);
    return (node)   {
            (nl.sum+nr.sum),
            max(nl.psum, nl.sum + nr.psum ),
            max(nr.ssum, nr.sum + nl.ssum ),
            max(nl.ssum+nr.psum,max(nl.val,nr.val))
        };
}

void update ( int idx, int l, int r, int id, int val ) {
    if ( l > id | r < id ) return;
    if ( l == r ) {
        tree[idx] = (node){val,val,val,val};
        return;
    }
    int m = (l+r)>>1, L = (idx<<1)+1, R = L+1;
    update(L,l,m,id,val);
    update(R,m+1,r,id,val);
    tree[idx].sum = tree[L].sum + tree[R].sum;
    tree[idx].psum = max(tree[L].psum,tree[L].sum + tree[R].psum);
    tree[idx].ssum = max(tree[R].ssum, tree[R].sum + tree[L].ssum);
    tree[idx].val = max(tree[L].ssum+tree[R].psum, max(tree[L].val,tree[R].val));
}

int main () {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    sf(n);
    fr(i,n) sf(arr[i]);
    init(0,0,n-1);
    int q,l,r,a;
    sf(q);
    while ( q-- ) {
        sf3(a,l,r);
        if ( a ) printf("%d\n",query(0,0,n-1,l-1,r-1).val);
        else update(0,0,n-1,l-1,r);
    }
    return 0;
}
