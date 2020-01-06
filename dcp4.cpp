/*Given an array of integers, find the first missing positive integer in linear time and constant space. 
In other words, find the lowest positive integer that does not exist in the array. The array can 
contain duplicates and negative numbers as well. For example, the input [3, 4, -1, 1] should give 2. 
The input [1, 2, 0] should give 3. This is daily coding problem #4 asked by dailycodingproblem.com */

#include <iostream>
using namespace std;

int findNum(int* arr, int len);

bool arrcontains(int* arr, int len, int k){
  for(int a = 0; a<len; a++){
    if(arr[a] == k){
      return true;
    }
  }
  return false;
}

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
 int answer = findNum(arr, len);
 cout<<"The first positive integer of linear time and constant space in this array is "<<answer<<endl;
}

int findNum(int* arr, int len){
  int min = arr[0];
  for(int i = 1; i<len; i++){
    if(arr[i] < min){
      min = arr[i];
    }
  }
  int max = arr[0];
  for(int i = 1; i<len; i++){
    if(arr[i] > max){
      max = arr[i];
    }
  }
  int answer = 0;
  for(int k = min+1; k<max+2; k++){
     if(arrcontains(arr, len, k) == false && k>0){
       answer = k;
       break;
     } 
  }
  return answer;
}
