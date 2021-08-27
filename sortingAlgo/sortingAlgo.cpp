#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void selectionSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        int minIdx = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }
        if(minIdx != i){
            swap(arr[i], arr[minIdx]);
        }
    }
}

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 and arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; 
    }
}

void merge(int arr[], int l, int m, int r){
    int n1 = m - l + 1, n2 = r - m;
    int a[n1], b[n2];
    for(int i = 0; i < n1; i++){
        a[i] = arr[l + i];
    }
    for(int i = 0; i < n2; i++){
        b[i] = arr[m + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while(i < n1 and j < n2){
        if(a[i] <= b[j]){
            arr[k] = a[i];
            i++;
        }else{
            arr[k] = b[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        arr[k] = a[i];
        i++, k++;
    }
    while(j < n2){
        arr[k] = b[j];
        j++, k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if(r > l){
        int mid = l + (r - l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int partition(int arr[], int l, int h){
    int pivot = arr[h];
    int i = l - 1;
    for(int j = l; j < h; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return i + 1;
}

void quickSort(int arr[], int l, int r){
    if(l < r){
        int p = partition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}

int main(){
    int arr[] = {2, 3, 4, 2, 1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}