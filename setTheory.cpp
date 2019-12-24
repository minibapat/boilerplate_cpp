#include <iostream>
using namespace std;

struct Myset {
  int count;
  int* myList;
};


Myset* get_union(int* arr, int len1, int* arr2, int len2){
  bool state = true;
  int count = 0;
  int counter = 0;
  int localarr[len1 + len2];

  Myset *myset_data = new Myset;
  count = len1;
  int i = 0, j = 0;
  while((i<len1 || j<len2) && counter<len1+len2){   
      if(arr2[j] == arr[i]) {
          localarr[counter] = arr[i];
          i++; j++;
          counter++;
      } 
      else if(arr[i] < arr2[j]){
        localarr[counter] = arr[i];
        counter++; i++;
      } 
      else if(arr[i] > arr2[j]){
        localarr[counter] = arr2[j];
        counter++; j++;
        state = false;
      }
    if(state == false){
       count++; 
    }
    state = true;
  }
  cout<<count<<endl; 
  int* heaparr = new int[count];
  for(int k = 0; k<count; k++){
    heaparr[k] = localarr[k];
  }
  
  myset_data->myList = heaparr;
  myset_data->count = count;

  return myset_data;
 
}

int main(){
  int arr[] = {1,2,3,4, 5};
  int arr2[] = {2,3,5,7};
  //expected union: 1, 2, 3, 4, 5, 7
  //expected intersection: 2, 3, 5
  Myset* answer = get_union(arr, 5, arr2, 4);
  for(int i = 0; i<answer->count; i++){ 
     cout<<answer->myList[i]<<" ";
  }
  //int* unionarr = gen_union(arr, 5, arr2, 4);
} 
