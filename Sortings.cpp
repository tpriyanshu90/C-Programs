#include <iostream>
using namespace std;
 
void selectionSort(int* arr,int n);
void bubbleSort(int *arr,int n);
void insertionSort(int * arr,int n);

int main() {
	int n;
	int ch;
	char flag='y';
	while(flag=='y'||flag=='Y'){
		cout<<"Enter the array size: ";
		cin>>n;
		int* arr = new int[n];
		cout<<endl<<"Enter array elements: "<<endl;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cout<<endl<<"Initial Array : ";
		for(int i=0;i<n;i++)
			cout<<arr[i]<<" ";
		cout<<endl<<"Which Sorting do you want to use?\n1. Selection\n2. Bubble\n3. Insertion\n";
		cout<<endl<<"your Choice : ";
		cin>>ch;
		switch(ch){
			case 1: 
				cout<<endl<<"Selection Sorted Array : ";
				selectionSort(arr,n);
				for(int i=0;i<n;i++)
					cout<<arr[i]<<" ";
				break;
			case 2: 
				cout<<endl<<"Bubble Sorted Array : ";
				bubbleSort(arr,n);
				for(int i=0;i<n;i++)
					cout<<arr[i]<<" ";
				break;
			case 3:
				cout<<endl<<"Insertion Sorted Array : ";
				insertionSort(arr,n);
				for(int i=0;i<n;i++)
					cout<<arr[i]<<" ";	
				break;
			default:
				cout<<endl<<"Please Select Correct option!";
		}
		cout<<endl<<"Do you want to continue? (y/n) : ";
		cin>>flag;
	}
	cout<<endl;
	return 0;
}

void selectionSort(int *arr,int n){
	for(int i=0;i<n-1;i++){
		int min_index = i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[min_index])
				min_index=j;
		}
		if(i!=min_index){
			int temp=arr[i];
			arr[i]=arr[min_index];
			arr[min_index] = temp;
		}
	}
}

void bubbleSort(int *arr, int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(arr[j]>arr[j+1])
			{
				int temp = arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

void insertionSort(int* arr, int n){
	for(int i=1;i<n;i++){
		int j=i-1;
		int key = arr[i];
		while(j>=0 && arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}