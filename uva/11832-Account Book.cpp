#include<bits/stdc++.h>

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
#define min4(a,b,c,d)  min(a,min(b,min(c,d)));

typedef long long ll;
typedef unsigned long long ull;
typedef pair < ull,int > ii;
typedef priority_queue< ii,vector<ii>, greater<ii> > pq_increasing;

vector < string > subsets;
vector < int > arr1,arr2;
vector < long long > sum2;
unordered_map < long long,vector < int >  > pos;
string ans;
unordered_map < long long,bool > mark;
bool exist;

void gen() {
    int n = (1 << 20);
    for ( int i = 0; i < n; i++ ) {
        bitset<20>bs(i);
        subsets.push_back(bs.to_string());
    }
}

void calculate (  ) {

    long long sum;
    int n = arr2.size();
    int sz = (1 << n);
    for ( int i = 0; i < sz; i++ ) {
        sum = 0;
        for ( int j = 0; j < n; j++ ) {
            (subsets[i][20-n+j] == '1')? sum -= arr2[j] : sum += arr2[j];
        }
        sum2.push_back(sum);
        pos[sum].push_back(i);
    }
    for ( int i = (sz/2)-1,j=sz/2; i >= 0,j < sz; i--,j++ ) {
        sum = (-1)*sum2[i];
        sum2.push_back(sum);
        pos[sum].push_back(j);
    }
}

string convert ( int n, int sz ) {
    string s,s1="";
    while ( n ) {
        ( n & 1 ) ? s.push_back('1') : s.push_back('0');
        n = n >> 1;
    }
    reverse(s.begin(),s.end());
    s1.append(sz-s.length(),'0');
    s1 += s;
    return s1;
}

int main ( ) {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    gen();
    int n,f;
    while ( scanf("%d%d",&n,&f) , n|f )  {
        int temp;
        arr1.clear(),arr2.clear(),sum2.clear(),pos.clear(),ans.clear();
        mark.clear();
        for ( int i = 0; i < n; i++ ) {
            scanf("%d",&temp);
            ( i < ceil(n/2) ) ? arr1.push_back(temp) : arr2.push_back(temp);
        }
        calculate();
        sort(sum2.begin(),sum2.end());
        long long rem;
        string s,s1,s2;
        exist = false;
        int n1 = arr1.size();
        int sz = (1<<n1);
        long long sum;
        for ( int i = 0; i < sz; i++ ) {
            sum = 0;
            for ( int j = 0; j < n1; j++ ) {
                ( subsets[i][20-n1+j] == '1')? sum-=arr1[j] : sum+= arr1[j];
            }
            rem = f - sum;
            if ( binary_search(sum2.begin(),sum2.end(),rem) ) {
                if ( !exist ) {
                    s1 = convert(i,arr1.size());
                    s2 = convert(pos[rem][0],arr2.size());
                    s = s1 + s2;
                    for ( int i = 0; i < s.length(); i++ ) ans.push_back(s[i]);
                    exist = true;
                }

                if ( exist ) {
                    int temp = i;
                    for ( int j = arr1.size()-1; j >= 0; j-- ) {
                        if ( temp & 1 ) {
                            if ( ans[j] != '1') ans[j] = '?';
                        }
                        else {
                            if ( ans[j] != '0') ans[j] = '?';
                        }
                        temp = temp >> 1;
                    }
                    if ( mark[rem] ) continue;
                    for ( int j = 0; j < pos[rem].size(); j++ ){
                        int temp = pos[rem][j];
                        for ( int k = n-1; k >= arr1.size(); k-- ) {
                            if ( temp & 1 ) {
                                if ( ans[k] != '1' ) ans[k] ='?';
                            }
                            else {
                                if ( ans[k] != '0') ans[k] = '?';
                            }
                            temp = temp >>  1;
                        }
                    }
                    mark[rem] = true;
                }
            }
        }
        if ( !exist ) printf("*");
        else {
            for ( int i = 0; i < n; i++ ) {
                if ( ans[i] == '0') printf("+");
                else if ( ans[i] == '1') printf("-");
                else printf("?");
            }
        }
        printf("\n");
    }
}
