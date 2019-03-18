#include<bits/stdc++.h>

using namespace std;

#define precision(n)   cout << setprecision(n) << fixed
#define sf(a)          scanf("%d",&a)
#define pi             3.1415926535
#define eps            0.0000000001
#define gl(a)          scanf("%llu",&a)
#define mp             make_pair
#define mod            1000000007
#define pf             printf

typedef long long ull;

typedef priority_queue< int,vector<int>, greater<int> > pq_increasing;


pair<ull,int> sparse[33][30005];
ull arr[30005];

void generatesparse( int n ) {
    int maxlevel = ceil(log2(n));
    for ( int i = 1; i <= maxlevel; i++ ) {
        int len = 1 << (i-1);
        for ( int j = 0; j <= n; j++ ) {
            if ( sparse[i-1][j] <= sparse[i-1][j+len]) {
                sparse[i][j].first = sparse[i-1][j].first;
                sparse[i][j].second = sparse[i-1][j].second;
            }
            else{
                sparse[i][j].first = sparse[i-1][j+len].first;
                sparse[i][j].second = sparse[i-1][j+len].second;
            }
        }
    }
}

pair <ull,int> rmq( int left,int right ) {
    int len = right - left + 1;
    int level = floor(log2(len));
    int levellen = 1 << level;
    return min(sparse[level][left],sparse[level][right+1-levellen]);
}

ull divncon( int left,int right ) {
    ull maxa = 0,area_m,area_l,area_r;
    if ( left > right )
        return 0;

    if ( left == right )
        return arr[left];
    else {
        pair < int,int > p = rmq(left,right);
        int min_index = p.second;
        area_l = max(divncon(left,min_index-1),divncon(min_index+1,right));
        return max(area_l,(ull)arr[min_index]*(right-left+1));
    }
}

int main ( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    int t;
    sf(t);
    for ( int q = 1; q<= t; q++ ) {
        int n;
        sf(n);
        for ( int i = 0; i < n; i++ ){
            sf(sparse[0][i].first);
            arr[i] = sparse[0][i].first;
            sparse[0][i].second = i;
        }
        generatesparse(n);
        printf("Case %d: %llu\n",q,divncon(0,n-1));
    }
}
