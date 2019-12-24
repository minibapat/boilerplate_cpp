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
  for(int k = 0; k<count; k++){
    cout<<"   "<<localarr[k];
  }
  cout<<"_____"<<endl;
  int* heaparr = new int[count];
  for(int k = 0; k<count; k++){
    heaparr[k] = localarr[k];
  }
  
  myset_data->myList = heaparr;
  myset_data->count = count;

  return myset_data;
 
}

Myset* get_inter(int* arr, int len1, int* arr2, int len2){
  Myset* mydata = new Myset;
  int localarr[len1+len2];
  int counter = 0;
  bool exists = false;
  int element = 0;
  for(int i = 0; i<len1; i++){
   for(int j =0; j<len2; j++){
     if(arr[i] == arr2[j]){
       exists = true;
       element = arr[i];
     }      
   }
   if(exists == true){
     localarr[counter] = element;
     counter++;
     exists = false;
   }
  }
  for(int f = 0; f<counter; f++){ 
    cout<<"__"<<localarr[f];
  }
  cout<<endl;
  mydata->myList = new int[counter];
  for(int k = 0; k<counter; k++){
     mydata->myList[k] = localarr[k];
  }
  mydata->count = counter;
 
  return mydata; 
}

int main(){
  int arr[] = { 6,7,10, 19};
  int arr2[] = {6,19};
  //expected union: 1, 2, 3, 4, 5, 7
  //expected intersection: 2, 3, 5
  Myset* answer = get_union(arr, 4, arr2, 2);
  for(int i = 0; i<answer->count; i++){ 
     cout<<answer->myList[i]<<" ";
  }
  cout<<endl;
  Myset* intersection = get_inter(arr,4, arr2, 2);
  for(int j = 0; j<intersection->count; j++){
    cout<<intersection->myList[j]<<" ";
  } 
} 
