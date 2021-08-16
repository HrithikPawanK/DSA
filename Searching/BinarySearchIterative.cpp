#include<bits/stdc++.h>
using namespace std;

// timecomplexity --> O(ciel(logn))

int binarySearch(int arr[], int x, int n){
	int l = 0, r = n-1 ;
	while(l<=r){
		int mid = (l + r)/2;
		if(arr[mid]==x){
			return mid;
		}
		else if(arr[mid] > x){
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	return -1;
}

int main(){
	
	return 0;
}