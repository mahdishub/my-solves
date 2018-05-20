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

unordered_map < char,vector < int > > m;
string s;

int main ( ) {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin >> s;
    for ( size_t i = 0; s[i] != '\0'; i++  ) {
        m[s[i]].push_back(i);
    }
    int q;
    cin >> q;
    while ( q-- ) {
        string ss;
        cin >> ss;
        bool flag = true,flag2 = true;
        int start,fin = -1;
        for ( size_t i = 0; ss[i] != '\0'; i++ ) {
            char c = ss[i];
            auto itr = upper_bound(m[c].begin(),m[c].end(),fin);
            if ( itr == m[c].end() ) {
                flag = false;
                break;
            }
            fin = *itr;
            if ( flag2 ) {
                start = fin;
                flag2 = false;
            }
        }

        if ( flag ) {
            cout << "Matched " << start << ' ' << fin<< endl;
        }
        else
            cout << "Not matched" << endl;
    }

}
