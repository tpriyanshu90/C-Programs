#include<iostream>
using namespace std;

int linearSearch(int arr[],int n, int key);
int binarySearch(int arr[], int low, int high, int key);

int main(){
	int n,key;
	cout<<"Enter the array size: ";
	cin>>n;
	int* arr = new int[n];
	cout<<"Enter the array in ascending order: "<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"The array is: "<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl<<"Enter the element to be found: ";
	cin>>key;
	int pos = binarySearch(arr,0,n,key);
	if(pos!=-1)
		cout<<"The element found at position: "<<pos<<endl;
	else
		cout<<"The element is not in the list."<<endl; 
	return 0;
}

int binarySearch(int arr[], int low, int high, int key){
	while(low<high){
		int mid = (low+high)/2;
		if(arr[mid]<key)
			low = mid+1;
		else if(arr[mid]>key)
			high = mid-1;
		else if(arr[mid]==key)
			return mid+1;
	}
	return -1;
}

int linearSearch(int arr[], int n, int key){
	for(int i=0;i<n;i++){
		if(arr[i]==key)
			return i+1;
	}
	return -1;
}

