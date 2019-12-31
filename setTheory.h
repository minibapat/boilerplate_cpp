struct Myset {
  int count;
  int* myList;
};

struct CProduct{
  int x;
  int y;
};

Myset* get_union(int* arr, int len1, int* arr2, int len2);
Myset* get_inter(int* arr, int len1, int* arr2, int len2);
CProduct* get_cartesian(int* arr, int len1, int* arr2, int len2);
Myset* diff_of_sets(int* arr, int len1, int* arr2, int len2);
