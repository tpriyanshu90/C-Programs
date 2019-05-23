#include <iostream>
using namespace std;

void mergeSort(int* arr,int p,int r);
void merge(int* arr, int p, int q, int r);
void quickSort(int *arr, int p, int r);
int partition(int * arr, int p, int r);

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
		cout<<endl<<"Which Sorting do you want to use?\n1. Quick Sort\n2. Merge Sort\n";
		cout<<endl<<"your Choice : ";
		cin>>ch;
		switch(ch){
			case 1: 
				cout<<endl<<"Quick Sorted Array : ";
				quickSort(arr,0,n-1);
				for(int i=0;i<n;i++)
					cout<<arr[i]<<" ";
				break;
			case 2: 
				cout<<endl<<"Merge Sorted Array : ";
				mergeSort(arr,0,n-1);
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

void mergeSort(int* arr, int p, int r){
	if(p<r){
		int q=(p+r)/2;
		mergeSort(arr,p,q);
		mergeSort(arr,q+1,r);
		merge(arr,p,q,r);
	}
}

void merge(int *arr, int p, int q, int r){
	int n1 = q-p+1;
	int n2 = r-q;
	int L[n1];
	int R[n2];
	for(int i=0;i<n1;i++)
		L[i]=arr[p+i];
	for(int j=0;j<n1;j++)
		R[j]=arr[q+j+1];
	int i=0;
	int j=0;
	int k=p;
	while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    }
}

void quickSort(int* arr, int p, int r){
	if(p<r){
		int q = partition(arr,p,r);
		quickSort(arr,p,q-1);
		quickSort(arr,q+1,r);	
	}
}

int partition(int* arr, int p, int r){
	int pivot=arr[r],temp;
	int i=p-1;
	for(int j=p;j<r;j++){
		if(arr[j]<=pivot){
			i++;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	temp=arr[i+1];
	arr[i+1]=arr[r];
	arr[r]=temp;
	return i+1;
}