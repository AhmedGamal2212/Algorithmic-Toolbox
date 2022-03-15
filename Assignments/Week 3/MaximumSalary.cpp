#include<bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define ll long long
#define ull unsigned long long
#define MOD 1000000007ll
#define PI 3.14159265
#define ceil(a, b) ((a / b) + (a % b ? 1 : 0))
#define imin INT_MIN
#define imax INT_MAX
#define nl '\n'
#define modulo(a, b, mod) ((((a) % mod) * ((b) % mod)) % mod)

// making the two string-numbers equal in sizes circularly to compare them easy

void complete(string& s, int& size){
	string tmp(s);
	for(int i = 0; i < size / tmp.size(); i++)
		s += tmp;
	s += tmp.substr(0, size % tmp.size());
}

// sorting the numbers according to the first index that has two unequal digits 

bool by(string& a, string& b){
	int mustBe = max(a.size(), b.size());
	
	string A(a), B(b);
	
	complete(A, mustBe), complete(B, mustBe);
	
	for(int i = 0; i < mustBe; i++){
		if(A[i] != B[i]){
			return A[i] > B[i];
		}
	}
	return A > B;
}

void solve(){
	int n; cin >> n;
	vector<string> v(n);
	for(auto& i : v) cin >> i;
	
	
	sort(all(v), by);
	
	// the array is ready to combine its numbers forming the answer
	
	for(auto& i : v){
		cout << i;
	}
}

int main(){
	solve();
	cout << nl;
}
