#include<bits/stdc++.h>

using namespace std;

#define precision(n)   cout << setprecision(n) << fixed
#define sf(a)          scanf("%d",&a)
#define sf2(a,b)       scanf("%d %d",&a,&b);
#define pi             3.1415926535
#define eps            0.0000000001
#define gl(a)          scanf("%llu",&a)
#define mod            1000000007
#define pf             printf
#define loop(ds,itr)   for ( auto itr = ds.begin(); itr != ds.end(); itr++ )
#define bug            cout << 'x' << endl;
#define check(x)       cout << x << endl;

typedef long long ll;
typedef unsigned long long ull;
typedef priority_queue< int,vector<int>, greater<int> > pq_increasing;

int main() {
    ///freopen("input.txt","r",stdin);

    int t;
    cin >> t;
    getchar();
    getchar();
    for ( int itr = 1 ; itr <= t; itr++ ) {
        vector < string > s;
        int n,d,c;
        string k;
        while ( getline( cin,k ) ) { ///input
            if( k.length() == 0 ) {
                break;
            }
            s.push_back(k);
        }
        int r = s.size();
        c = r;
        int ar[r][c],ar1[r][c],ar2[r][c];
        for ( int i=0;i<r;i++) { /// making ar
            for (int j=0;j<c;j++){
                ar[i][j] = s[i][j]-'0';
            }
        }

        vector < pair < int,int > > v;
        pair < int,int > p;
        for ( int i = 0; i < r; i++ ) { /// generating all pos
            for ( int j = 0; j < r; j++ ) {
                p.first = i;
                p.second = j;
                v.push_back(p);
            }
        }
        pair < int,int > p1;
        pair <  pair < int,int > , pair < int,int> > dgs;
        vector < pair< pair<int,int>, pair<int,int> > > rect;
        for ( int i = 0; i < v.size(); i++ ) {///generating all rect
            for ( int j = i; j < v.size(); j++ ) {
                if ( v[i].first <= v[j].first && v[i].second <= v[j].second ) {
                    dgs.first = v[i];
                    dgs.second = v[j];
                    rect.push_back(dgs);
                }
            }
        }
        int max = 0;
        for ( int i = 0; i < rect.size(); i++ ) {///finding max area

            int r1 = rect[i].first.first;
            int c1 = rect[i].first.second;
            int r2 = rect[i].second.first;
            int c2 = rect[i].second.second;


            bool flag = true;
            for ( int j = r1; j <= r2; j++ ) {///checking 1's
                if (!flag)
                    break;
                for (int k = c1; k <= c2 ; k++) {
                    if ( ar[j][k] != 1) {
                        flag = false;
                        break;
                    }
                }
            }

            if ( flag ) {
                int res = ((r2-r1)+1)*((c2-c1)+1);
                if ( res > max)
                    max = res;
            }
        }

        cout << max << endl;
        if ( itr != t)
            cout << endl;
    }

    }




