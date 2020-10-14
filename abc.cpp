/*
	bhoktāraṁ yajña-tapasāṁ sarva-loka-maheśvaram
    suhṛdaṁ sarva-bhūtānāṁ jñātvā māṁ śantim ṛcchati 
    									   --BG 5.29
*/

#include <bits/stdc++.h>

using namespace std;
#pragma region DEBUG
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#pragma endregion DEBUG

#define lli long long  
#define pii pair <lli,lli> 
#define mii map <lli,lli>   
#define vi vector <lli> 

#define M (lli)(1e9+7)
#define N (lli)(1e6)
#define inf (lli)1e18

#define sz(s) (lli)((s).size())
#define all(v) (v).begin() + 1, (v).end()
#define ff first
#define ss second
#define pb push_back

#define forn(i,a,b)  for(lli i = a; i <= b; ++i)
#define ford(i,a,b)  for(lli i = a; i >= b; --i)
lli n, m, k, cnt = 0, L, R, u, v,s;

vi a, fact,sp,b;
lli powD(lli a,lli b){
	a%=M;
	lli res=1;
	while(b){
		if(b&1){res*=a;res%=M;}
		a*=a;a%=M;
		b>>=1;
	}
	return res;
}
void preSieve(){
	sp.resize(N+1);
	forn(i,1,N)sp[i]=i;
	for(lli i=2;i<=N;i++){
		if(sp[i]==i){
			for(lli j=2*i;j<=N;j+=i){
				if(sp[j]==j)sp[j]=i;
			}
		}
	}

}
vi primeF(lli n){
	vi ans;
	while(n>1){
		ans.push_back(sp[n]);
		n/=sp[n];
	}
	return ans;
}
lli _add(lli a, lli b){
	a%=M;
	b%=M;
	lli ans = ((a+b)%M + M)%M;
	return ans;
}
lli _mul(lli a, lli b){
	a%=M;
	b%=M;
	lli ans = ((a*b)%M + M)%M;
	return ans;
}
void solve(){
	cin>>n;
	mii mp;
	forn(i,1,n){
		cin>>m;
		if(i==1){
			while(m--){
				lli x;cin>>x;
				vi v = primeF(x);
				for(auto p:v)mp[p]++;
			}
		}
		else{
			mii nmp;
			while(m--){
				lli x;cin>>x;
				vi v = primeF(x);
				for(auto p:v)
					nmp[p]++;
			}

			vi zero;
			for(auto p:mp){
				lli num = p.ff;
				if(nmp.find(num)!=nmp.end()){
					mp[num] = min(mp[num],nmp[num]);
				}
				else{
					zero.push_back(num);
				}
			}
			for(auto num:zero)
				mp.erase(mp.find(num));
		}
	}
	lli ans = 1;
	for(auto p:mp){
		ans = _mul(ans,powD(p.ff,p.ss));
	}
	cout<<ans;


}

signed main(){

	ios_base::sync_with_stdio(false);cin.tie(0);	 
	preSieve(); 
	lli _t = 1;//cin>>_t;
	while(_t--){
		solve();cout<<"\n";
	}
}