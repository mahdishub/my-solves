#include<bits/stdc++.h>

using namespace std;

#define precision(n)   cout << setprecision(n) << fixed
#define scll(a)        scanf("%lld",&a)
#define pi             3.1415926535
#define eps            0.0000000001
#define getlong(a)     scanf("%lld",&a)
#define mp             make_pair

typedef unsigned long long ull;
typedef long long int ll;
typedef priority_queue<int, vector<int>, greater<int> > pq_increasing;


int main ( ) {

    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    while ( t-- ) {
        int battles,sg,sb;
        cin >> battles >> sg >> sb;
        priority_queue < int > green_s;
        priority_queue < int > blue_s;
        vector < pair < int,int > > batlleground;

        for( int i = 0; i < sg; i++ ) {///sginp
            int a;
            cin >> a;
            green_s.push(a);
        }
        for ( int i = 0; i < sb; i++ ) {///sbinp
            int b;
            cin >> b;
            blue_s.push(b);
        }
        int g,b;
        while( true ) {///rounds
            if ( green_s.empty() || blue_s.empty())
                break;
            for ( int i = 0; i < battles; i++ ) {///battles
                if ( !green_s.empty() && !blue_s.empty() ) {
                    g = green_s.top();
                    b = blue_s.top();
                    green_s.pop();
                    blue_s.pop();
                    batlleground.push_back(mp(g,b));
                }
            }

            for ( int q = 0; q < batlleground.size(); q++ ) {
                if(batlleground[q].first > batlleground[q].second){
                    green_s.push(batlleground[q].first - batlleground[q].second);
                }
                if(batlleground[q].second > batlleground[q].first){
                    blue_s.push(batlleground[q].second - batlleground[q].first);
                }
            }
            batlleground.clear();
        }
        if ( blue_s.empty() && green_s.empty() )
            cout << "green and blue died" << endl;
        else if ( blue_s.empty() ) {
            cout << "green wins" << endl;
            while( !green_s.empty() ) {
                cout << green_s.top() << endl;
                green_s.pop();
            }
        }
        else if ( green_s.empty() ) {
            cout << "blue wins" << endl;
            while( !blue_s.empty() ) {
                cout << blue_s.top() << endl;
                blue_s.pop();
            }
        }

        if(t == 0)
            continue;
        cout << endl;

    }


    return 0;
}
