/*
 * given an array of n numbers, print the maximum number that can be the result
 * of multiplying two numbers of that array
 * 
 */

#include<bits/stdc++.h>
using namespace std;

#define nl '\n'

int main(){
	int n; cin >> n;
	vector<int> v(n);
	
	for(auto& i : v) cin >> i;
	
	/* first of all, 
	 * we want to find the largest number in the whole array and store its index
	 */
	
	int maxi = 0;
	for(int i = 0; i < n; i++)
		if(v[i] > v[maxi]) maxi = i;
	
	/* second, we need to find the second-largest number in the array 
	 * (except the first maximum that we've already found)
	 */
	 
	int secondMaxi = not(maxi > 0);
	for(int i = 0; i < n; i++){
		if(i == maxi) continue;
		if(v[i] > v[secondMaxi]) secondMaxi = i;
	}
	
	//the product of the two numbers we've just found will be the answer of the problem
	
	cout << 1ll * v[maxi] * v[secondMaxi] << nl; // casting to long long to avoid the overflow
}
