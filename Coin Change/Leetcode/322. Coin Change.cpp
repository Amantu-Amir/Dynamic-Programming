#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define Mid(b,e) b+(e-b)/2
#define inf 2147483647

//---------------------------------------------------------------------------//
//Timus: 314795JS

//knight moves
//ll X[8] = {2, 1, -1, -2, -2, -1, 1, 2}; 	
//ll Y[8] = {1, 2, 2, 1, -1, -2, -2, -1}; 
//ll dx[]={1,-1,0,0};
//ll dy[]={0,0,1,-1};
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

const ll p=29;
const ll N=2e6+50;
const ll mod=1e9+7;


class Solution{
public:
    int coinChange(vector<int>& coins, int amount){
    	int len=coins.size();
        int dp[len+5][amount+5];
        for(int i=0; i<=len; i++){
            for(int j=0; j<=amount; j++){
                dp[i][j]=100000;
            }
        }
        for(int i=0; i<len; i++){
        	dp[i][0]=0;
        }
        for(int i=0; i<len; i++){
        	for(ll j=1; j<=amount; j++){
        		if(j>=coins[i]){
        			if(i>0){
        				dp[i][j]=min(dp[i-1][j],dp[i][j-coins[i]]+1);
        			}
        			else{
        				dp[i][j]=min(100000,dp[i][j-coins[i]]+1);
        			}
        		}
        		else{
        			if(i>0){
        				dp[i][j]=dp[i-1][j];
        			}
        		}
        	}
        }
        if(dp[len-1][amount]==100000){
        	return -1;
        }
        else{
        	return dp[len-1][amount];
        }
    }
};


int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	int t=1;
	for(int T=1; T<=t; T++){
		int n,k; cin>>n>>k;
		vector<int>coin(n);
		for(int i=0; i<n; i++){
			cin>>coin[i];
		}
		Solution obj;
		int res=obj.coinChange(coin,k);
		cout<<res<<"\n";
	}
	return 0;
}

