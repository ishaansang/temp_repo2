#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) int((x).size())
#define FOR(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
#define rep(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define fe(i,a) for (int (i) = 0; (i) < int((a).size()); ++(i))
#define C(a) memset((a),0,sizeof(a))
#define inf 1000000000
#define pb push_back
#define ppb pop_back
#define all(c) (c).begin(), (c).end()
#define pi 2*acos(0.0)
#define sqr(a) (a)*(a)
#define mp(a,b) make_pair((a), (b))
#define fpresent(c,x) ((c).find(x) != (c).end()) 
#define X first
#define Y second
#define rz resize
#define endl '\n'
#define TCASE int __t; cin >> __t; while (__t--)

typedef vector<int> ivi;
typedef vector < ivi > ivvi;
typedef unsigned long long ull;
typedef long long int ll;
typedef vector< ll > vi;
typedef vector < vi > vvi;
typedef pair<int, int> pii;


vector<bool> vis(105);
vector<bool> vis1(105);
vi sorted ;
vi ans[101];
vvi g1(101);
vvi g2(101);

void dfs1( int u ) {
    vis[ u ] = true;
    int i;
    for ( i = 0; i < g1[u].size(); ++i ) {
        if ( !vis[ g1[u][i] ] ) {
            dfs1( g1[u][i] );
        }
    }
    sorted.pb(u);
}

void dfs2( int u, int c ) {
	cout<<u<<endl;
    vis1[ u ] =true;
    ans[c].pb(u);
    int i;
    for ( i = 0; i < g2[ u ].size(); ++i ) {
        if ( !vis1[ g2[ u ][ i ] ] ) {
            dfs2(g2[u][i],c);
        }
    }
}


int main ()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	cin>>n>>m;
	rep(i,m)
	{
		int x,y;
		cin>>x>>y;
		g1[x].pb(y);
		//g1[y].pb(x);
		g2[y].pb(x);
		//g2[x].pb(y);
	}
	for ( int i = 1; i <= n; ++i ) {
	    if ( !vis[ i ] ) {
                dfs1( i );
        }
    }
    //fe(i,sorted)cout<<sorted[i]<<" ";cout<<endl;
    int compon = 0;
    for (int i = sorted.size() - 1; i >= 0; --i ) {
        if ( !vis1[ sorted[ i ] ] ) {
            dfs2( sorted[i], compon++ );
        }
    }
    FOR(j,0,compon)
    {
    	fe(i,ans[j])
    	{
    		cout<<ans[j][i]<<" ";
    	}
    	cout<<endl;
	}


	return 0;
} 