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

const int sz = 2*1e5;
int arr[sz+5],trr[sz+5];
unordered_map <int,int> M;

struct node {
    int cnt = 0;
    node *left = NULL,*right = NULL;
    node( int cnt, node *left, node *right ) : cnt(cnt),left(left),right(right) {}
    node* update(int l,int r,int id)  {
        if ( id < l | id > r ) {
            return this;
        }
        if ( l == r ) return new node(1,NULL,NULL);
        int m = (l+r)>>1;
        node* ln = left->update(l,m,id);
        node* rn = right->update(m+1,r,id);
        return new node(cnt+1,ln,rn);
    }
};

node* null =  new node(0,NULL,NULL);

node* build  ( int l,int r ) {
    if ( l == r ) return new node(0,NULL,NULL);
    int m = (l+r)>>1;
    node *ln = build(l,m);
    node *rn = build(m+1,r);
    return new node(0,ln,rn);
}

int K;

int query ( node *a,node *b, int l, int r ) {
    int c = a->cnt-b->cnt;
    if ( K == 0 ) return -1;
    if ( K > c ) {
        K -= c;
        return -1;
    }
    if ( l == r ) {
      if ( K == c ) { K = 0; return l; }
      else return -1;
    }
    int m = (l+r)>>1;
    int a1 = query(a->left,b->left,l,m);
    int a2 = query(a->right,b->right,m+1,r);
    return max(a1,a2);

}

node* roots[sz+5];
node  *init,*temp;

int main () {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    sf2(n,m);
    fr(i,n) {sf(arr[i]); trr[i] = arr[i];}
    sort(arr,arr+n);
    fr(i,n) M[arr[i]] = i;
    init = build(0,n-1);
    fr (i,n) {
        temp = ( i == 0 ) ? init : roots[i-1];
        roots[i] = temp->update(0,n-1,M[trr[i]]);
    }
    int L,R;

    while ( m-- ) {
        sf3(L,R,K);
        L--,R--;
        temp = ( L == 0 ) ? init:roots[L-1];
        printf("%d\n",arr[query(roots[R],temp,0,n-1)]);
    }


}
