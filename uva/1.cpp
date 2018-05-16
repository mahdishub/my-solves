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
    int t;
    cin >> t;
    getchar();
    while ( t-- ) {
        vector < string > words;
        string s;
        while ( cin >> s, s != "*") {
            words.push_back(s);
        }
        getchar();
        string s1,s2,e;
        while ( getline(cin,e) ,e.length() ) {
            stringstream ss(e);
            ss >> s1 >> s2;
            /// bfs
            queue < string > q;
            unordered_map < string,int > level;
            unordered_map < string,bool > visited;
            q.push(s1);
            level[s1] = 0;
            visited[s1] = true;
            while ( !q.empty() ) {
                string src = q.front();
                q.pop();
                for ( size_t i = 0; i < words.size(); ++i ) {
                    string x = words[i];
                    if ( !visited[x] && x.length() == src.length() ) {
                        int count = 0;///no of diff charecters
                        for ( size_t j = 0; j < src.length(); ++j ) {///checking no of differences
                            if ( x[j] != src[j] )
                                count++;
                        }
                        if ( count == 1 ) {/// only 1 differece found,so connect
                            q.push(x);
                            level[x] = level[src] + 1;
                            visited[x] = true;
                        }
                    }
                }
            }
            cout << s1 << ' ' << s2 << ' ' << level[s2] << endl;
        }
        if ( t != 0 ) {
            cout << endl;
        }

    }


}
