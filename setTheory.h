struct Myset {
  int count;
  int* myList;
};

Myset* get_union(int* arr, int len1, int* arr2, int len2);
Myset* get_inter(int* arr, int len1, int* arr2, int len2);
