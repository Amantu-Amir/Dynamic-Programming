#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define prln(a) cout<<a<<"\n"
#define nl cout<<"\n"
#define P(a) cout<<a
#define PP(a,b) cout<<a<<" "<<b
#define PPP(a,b,c) cout<<a<<" "<<b<<" "<<c
#define inf 2147483647

//---------------------------------------------------------------------------//

//knight moves
ll X[8] = {2, 1, -1, -2, -2, -1, 1, 2}; 	
ll Y[8] = {1, 2, 2, 1, -1, -2, -2, -1}; 
void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
ll toInt(string s){stringstream ss;ss<<s;int n;ss>>n;return n;}
string toString(ll n){stringstream ss;ss<<n;string s;ss>>s;return s;}
string UPPER(string s){transform(all(s),s.begin(),::toupper);return s;}
string LOWER(string s){transform(all(s),s.begin(),::tolower);return s;}
bool isDigit(char ch){if(ch>=48 && ch<=57) return true; else return false;}
vector<ll>removeDup(vector<ll>v){sort(all(v)); v.resize(distance(v.begin(),unique(all(v))));return v;}
bool isVowel(char ch){ch=toupper(ch);if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E'){return true;}return false;}
bool isCons(char ch){if(isalpha(ch) && !isVowel(ch)){return true;} return false;}

//------------------------------------------------------------------------------//
const ll N=2e5+50;
const ll mod=1e9+7;


int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	for(ll T=1; T<=t; T++){
		ll n; cin>>n;
		ll dp[n+5][2];
		dp[0][0]=1;
		dp[0][1]=1;
		for(ll i=1; i<=n; i++){
			string s; cin>>s;
			if(s=="OR"){
				dp[i][0]=dp[i-1][0];
				dp[i][1]=(dp[i-1][1]*2)+dp[i-1][0];
			}
			else{
				dp[i][0]=(dp[i-1][0]*2)+dp[i-1][1];
				dp[i][1]=dp[i-1][1];
			}
			//cout<<dp[i][0]<<"\n"<<dp[i][1]<<"\n";
		}
		cout<<dp[n][1]<<"\n";
	}
	return 0;
}
