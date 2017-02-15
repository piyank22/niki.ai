/*******************
AUTHOR: HUMBLE_LOSER
*******************/

#include <iostream>
#include <cstdio>
#include <math.h>
#include <ctime>
#include <bitset>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <functional>
#include <vector>

using namespace std;

#define PI acos(-1)
#define EXP 2.7182818284590452353602874713527
#define endl '\n'
#define ll long long
#define llu long long unsigned
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vvii vector<vii>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fst first
#define snd second
#define sz(v) int(v.size())
#define eps 1e-5
#define forr(i,a,b) for(int i = int(a) ; i<= int(b) ; i++ )
#define rof(i,a,b)  for(int i = int(a) ; i>= int(b) ; i-- )
#define rep(i,n) for(int i=0 ; i<int(n) ; i++ )
#define all(v) (v).begin(),(v).end()
#define inf 0x3f3f3f3f
// #define mod 1000000007
#define zero(x) memset(&x,0,sizeof(x))
#define minus(x) memset(&x,0xff,sizeof(x))
#define infinity(x) memset(&x,0x3f,sizeof(x))
#define boost cin.tie(0); ios_base::sync_with_stdio(0); 
#define trace1(x) cerr << #x <<" = "<< x <<endl;
#define trace2(x,y) cerr << #x <<" = "<< x <<" , "<< #y <<" = "<< y <<endl;
#define trace3(x,y,z) cerr << #x <<" = "<< x <<" , "<< #y <<" = "<< y <<" , "<< #z <<" = "<< z <<endl;
#define trace_arr(a,i,n) cerr << #a <<" : " ; forr(_i,i,n) cerr << a[_i] << " "; cerr << endl;
#define trace_mat(a,i,n,j,m) cerr << #a <<" :\n" ; forr(_i,i,n){forr(_j,j,m) cerr << setw(6) << a[_i][_j] << " "; cerr << endl;}cerr<<endl;
#define test_case int __T;cin >> __T; forr(tc, 1 , __T)


const ll mod = 1e9+7;
class mat
{
public:
    ll a[2][2];
    mat(int k=0)
    {
        a[0][0]=1;  a[0][1]=0;
        a[1][0]=0;  a[1][1]=1;
        if( k == 1)
        {
            a[0][0]=0;  a[0][1]=1;
            a[1][0]=1;
        }
    }
    mat operator+(const mat& m )
    {
        mat ans;
        forr(i,0,1)
            forr(j,0,1)
            {
                ans.a[i][j] = a[i][j] + m.a[i][j];
                while(ans.a[i][j] >= mod)
                    ans.a[i][j] -= mod;
            }
        return ans;
    }
    mat operator*(const mat& m )
    {
        mat ans;
        ll mod2=mod*mod;
        forr(i,0,1)
            forr(j,0,1)
            { 
                ll temp = 0;
                forr(k,0,1)
                {
                    temp += a[i][k] * m.a[k][j];
                    while( temp >= mod2 ) temp -= mod2;
                }
                ans.a[i][j]= temp%mod; 
            }
        return ans;
    }
    ll sum()
    {
        return ( a[0][0] + a[0][1] + a[1][0] + a[1][1] ) % mod;
    }
};

inline mat fast_power(ll p , mat a = mat(1) )
{
    mat res;
    while(p)
    {
        if(p&1)
            res = res*a;
        a = a*a;
        p >>=1;
    }
    return res;
}

int main()
{
    boost;
    int t;
    cin >> t;

    while(t--)
    {
        ll n;
        cin >> n;
        mat ans = fast_power(n-1);
        cout << ans.sum() << endl;
    }
    
    return 0;
}