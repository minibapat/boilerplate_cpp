//Given a list of numbers and a number k, this program finds
//whether any two numbers from the list add up to k.
#include <iostream>
using namespace std;

bool sumExists(int* arr, int len, int k);

int main(int argc, char* argv[]){
  if(argc != 6){
		cerr<<"Usage: "<<argv[0]<<" A list of 4 numbers separated by spaces followed by a number k"<<endl;
		exit(1);
  }
	int arr[4];
  for(int i = 0; i<4; i++){
		arr[i] = atoi(argv[i+1]);
	}
  int k = atoi(argv[5]);
  int len = sizeof(arr)/sizeof(arr[0]);
  bool answer = sumExists(arr, len, k);
  if(answer == 0) cout<<"False"<<endl;
  else cout<<"True"<<endl;
}

bool sumExists(int* arr, int len, int k){
  for(int i = 0; i<len-1;i++){
  	for(int j = 1; j<len; j++){
			if(arr[i] + arr[j] == k){
 				return true;
 			}
		}
	}	
	return false;
}
