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
#define loop(ds,itr)   for ( auto itr = ds.begin(); itr != ds.end(); itr++ )

typedef long long ll;
typedef unsigned long long ull;
typedef priority_queue< int,vector<int>, greater<int> > pq_increasing;

int main ( ) {

    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int e;
    cin >> e;
    vector < int > arr[e];
    for ( int i = 0; i < e; i++ ) {
        int x;
        cin >> x ;
        while ( x-- ) {
            int friends;
            cin >> friends;
            arr[i].push_back(friends);
        }
    }
    int t;
    cin >> t;
    while ( t-- ) {

        int root;
        cin >> root;
        queue < int > q;
        unordered_map < int,int > level;
        unordered_map < int,bool > visited;
        map < int,int > maxboom;
        q.push(root);
        level[root] = 0;
        visited[root] = true;
        while ( !q.empty() ) {
            int src = q.front();
            q.pop();
            for ( int i = 0; i < arr[src].size(); i++ ) {
                int f = arr[src][i];
                if ( !visited[f] ) {
                    q.push(f);
                    level[f] = level[src] + 1;
                    maxboom[level[f]]++;
                    visited[f] = true;
                }
            }

        }
        int mx = INT_MIN,mxlvl;
        loop ( maxboom,itr ) {

            if ( (itr -> second) > mx ){
                mx = itr -> second;
                mxlvl = itr -> first;
            }

        }
        if ( arr[root].size() == 0 )
            cout << 0 << endl;
        else
            cout << mx << ' ' << mxlvl << '\n';

    }



}
