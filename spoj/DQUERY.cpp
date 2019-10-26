#include<stdio.h>
#include<iostream>
#include<algorithm>
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
#define s              second
#define f              first
#define min4(a,b,c,d)  min(a,min(b,min(c,d)));

typedef long long ll;
typedef unsigned long long ull;
///typedef pair< int,pair<int,int> > node;
///typedef priority_queue< int,vector<int>, greater<int> > pq_increasing;

struct node {
    int l,r,ind;
}qrs[200010];

int n;
int d = 174;
int arr[30010];
int unq[1000010];
int ans[200010];
int cnt = 0;


bool cmp ( node n1, node n2 ) {
    if ( (n1.l/d) != (n2.l/d) )
        return (n1.l/d) < (n2.l)/d;
    else
        return n1.r < n2.r;
}


void add(int index){
    unq[arr[index]]++;
    if(unq[arr[index]]==1) cnt++;
}

void remove(int index){
    unq[arr[index]]--;
    if(unq[arr[index]]==0) cnt--;
}


int main ( ) {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    scanf("%d",&n);
    for ( int i = 1; i <= n; i++ )
        scanf("%d",&arr[i]);
    int q;
    scanf("%d",&q);
    int l,r;
    for ( int i = 0; i < q; i++ )
        scanf("%d%d",&qrs[i].l,&qrs[i].r),qrs[i].ind = i;
    sort(qrs,qrs+q,cmp);
    int cl,cr;
    cl = cr = qrs[0].l;
    for ( int i = 0; i < q; i++ ) {
        int l1 = qrs[i].l;
        int r1 = qrs[i].r;
        while(cl<l1)
            remove(cl),cl++;
        while(cl>l1)
            add(cl-1),cl--;
        while(cr<=r1)
            add(cr),cr++;
        while(cr>(r1+1))
            remove(cr-1),cr--;
        ans[qrs[i].ind] = cnt;
    }
    for ( int i = 0; i < q; i++ )
        printf("%d\n",ans[i]);
}
