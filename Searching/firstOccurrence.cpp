// iterative
int firstOccurence(int arr[], int x, int l, int h){
	int mid;
	while(l<=h){
		mid = (l+h)/2;
		if(x < arr[mid]){
			h = mid - 1;
		}else if( x > arr[mid]){
			l = mid + 1;
		}else{
			if(mid == 0 || arr[mid-1] != arr[mid]){
				return mid;
			}else{
				h = mid -1;
			}
		}
	}
	return -1;
}

// recursive

int firstOccurence(int arr[], int x, int l, int h){
	if(l>h){
		return -1;
	}
	int mid = (l+h)/2;
	if(x < arr[mid]){
		return firstOccurence(arr,x,l,mid-1);
	}else if(x > arr[mid]){
		return firstOccurence(arr,x,mid+1,h);
	}else{
		if(mid == 0 || arr[mid-1]!=arr[mid]){
			return mid;
		}else{
			return firstOccurence(arr,x,l,mid-1);
		}
	}
}

// similarly follow for last occurrence
