#include <iostream>
#include "setTheory.h"

using namespace std;

struct CProduct{
  int x;
  int y;
};

Myset* get_union(int* arr, int len1, int* arr2, int len2){
  bool state = true;
  int count = 0;
  int counter = 0;
  int localarr[len1 + len2];

  Myset *myset_data = new Myset;
  count = len1;
  int i = 0, j = 0;
  while((i<len1 && j<len2) && counter<len1+len2){   
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
  while(i<len1){
     localarr[count] = arr[i];
     count++; i++;
  }
  while(j<len2){
    localarr[count] = arr2[j];
    count++; j++;
  }
  myset_data->myList = new int[count];
  for(int k = 0; k<count; k++){
    myset_data->myList[k] = localarr[k];
  }
  
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
  mydata->myList = new int[counter];
  for(int k = 0; k<counter; k++){
     mydata->myList[k] = localarr[k];
  }
  mydata->count = counter;
 
  return mydata; 
}

CProduct* get_cartesian(int* arr, int len1, int* arr2, int len2) {
  CProduct* myprod = new CProduct[sizeof(CProduct) * sizeof(arr) * sizeof(arr2)];
  int index = 0;
  for(int i = 0; i<len1; i++){
  	for(int j = 0; j<len2; j++){
      myprod[index].x = arr[i];
      myprod[index].y = arr2[j];
      index++;
    }
	}
  return myprod;
}

int main(){
  int arr[] = { 4,5,6, 9};
  int arr2[] = {6,9,12};
  //expected union: 4,5,6,9,12
  //expected intersection: 6,9
  CProduct* prod = get_cartesian(arr, sizeof(arr)/sizeof(arr[0]), arr2, sizeof(arr2)/sizeof(arr2[0]));
	for(int a = 0; a<12; a++){
    cout<<"("<<prod[a].x<<","<<prod[a].y<<")";
  }
  cout<<endl;  
  Myset* answer = get_union(arr, sizeof(arr)/sizeof(arr[0]), arr2, sizeof(arr2)/sizeof(arr2[0]));
  cout<<"Union: "<<endl;
  for(int i = 0; i<answer->count; i++){ 
     cout<<answer->myList[i]<<" ";
  }
  cout<<endl;
  cout<<"Intersection: "<<endl;
  Myset* intersection = get_inter(arr,sizeof(arr)/sizeof(arr[0]), arr2, sizeof(arr2)/sizeof(arr2[0]));
  for(int j = 0; j<intersection->count; j++){
    cout<<intersection->myList[j]<<" ";
  } 
} 
