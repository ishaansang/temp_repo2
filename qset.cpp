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
    #define N (int)1e5+6
     
    struct dabba
    {
    	ll a[3];
    	ll b[3];
    	int sum;
    	ll ans;
    	dabba()
    	{
    		sum=ans=0;
    		a[0]=a[1]=a[2]=b[0]=b[2]=b[1]=0;
    	}
    };
     
    dabba nil;
    vector < dabba > tree(4*N);
    int v[N];
  
     
    dabba merge(dabba i,dabba j)
    {
    	dabba x;
    	x.ans=i.ans+j.ans;
    	rep(z,3)
    	{
    		x.a[(z+i.sum)%3]+=j.a[z];
    		x.b[(z+j.sum)%3]+=i.b[z];
    		x.a[z]+=i.a[z];
    		x.b[z]+=j.b[z];
    	}
    	x.ans+=i.b[0]*j.a[0]+i.b[1]*j.a[2]+i.b[2]*j.a[1];
    	x.sum=i.sum+j.sum;
    	x.sum%=3;
    	return x;
    }
     
    void build_tree(int node,int a,int b)
    {
    	if(a>b)return;
    	if(a==b)
    	{
    		tree[node].a[v[a]%3]=1;
    		tree[node].b[v[a]%3]=1;
    		tree[node].sum=v[a]%3;
    		if(v[a]%3==0)tree[node].ans++;
    	}
    	else 
    	{
    	    build_tree(node*2, a, (a+b)/2); // Init left child
    	    build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
    	    tree[node]=merge(tree[node*2],tree[node*2+1]);
    	}
    	return;
    }
     
    dabba query_tree(int node,int a,int b,int i,int j)
    {
    	if(a>b || a>j || b < i)return nil;//empty dabba with everything nil
    	if(a>=i && b<=j)return tree[node];
    	else 
    	{
    	    return merge( query_tree(2*node,a,(a+b)/2,i,j) , query_tree(2*node+ 1,(a+b)/2+1,b,i,j));
    	}
    }
	 void update(int node,int i,int j,int x,int z)
	 {
	 	if(i >j || i >x || j < x )return ;
		if(i==j)
		{
			tree[node]=dabba();
			tree[node].a[z]=1;
			tree[node].b[z]=1;
			tree[node].sum=z;
			if(z==0)tree[node].ans=1;
			return;
		}

		update(2*node,i,(i+j)/2,x,z);
		update(2*node+ 1,(i+j)/2+1,j,x,z);
		tree[node]=merge(tree[node*2],tree[node*2+1]);
		
	 }
    int main ()
    {
    	ios_base::sync_with_stdio(0);
    	cin.tie(0);
    	int n,m;
 
    	string s;
    	cin>>n>>m;
    	cin>>s;
    	rep(i,n)
    	{
    		v[i]=s[i]-'0';
    	}
        build_tree(1,0,n-1);
        rep(j,m)
        {
        	int x,y,z;
        	cin>>x>>y>>z;
         	if(x==1)
        	{
        		--y;
	       		update(1,0,n-1,y,z%3);
        	}
        	else
        	{
        		--y;--z;
             	cout<<query_tree(1,0,n-1,y,z).ans<<endl;
        	}
        }
    	return 0;
    }     