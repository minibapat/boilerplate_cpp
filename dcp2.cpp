//Given an array of integers, return a new array such that each element 
//at index i of the new array is the product of all the numbers in the 
//original array except the one at i
//Daily Coding Problem #2 from dailycodingproblem.com 

#include <iostream>
using namespace std;

int* findprod(int* arr, int len);

int main(int argc, char* argv[]){
	if(argc < 3){
		cerr<<"Usage: "<<argv[0]<<" Enter a list of numbers separated by spaces"<<endl;
		exit(1);
	}
	int arr[argc-1];
	for(int i = 0; i<argc-1; i++){
		arr[i] = atoi(argv[i+1]);
	}
	int len = sizeof(arr)/sizeof(arr[0]);
	int* newarr = findprod(arr, len);
	for(int k = 0; k<len; k++){
		cout<<newarr[k]<<" ";
	}
 	cout<<endl;
}

int* findprod(int* arr, int len){
	int* ptr = new int[len];
	for(int i = 0; i<len; i++){
		int product = 1;
  	for(int j = 0; j<len; j++){
			if(j != i){
			 product = product * arr[j];
			}
		}	
		ptr[i] = product;
  }
	return ptr;
}
