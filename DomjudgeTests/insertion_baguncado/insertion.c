#include <stdio.h>
#include <stdlib.h>

void sort(double arr[], int n) {
  int i, j;
  double current;
  for (i = 1; i <= n; i++) {
    current = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > current) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = current;
  }
}

void sort_rest(double arr[], int n, int k) {
  int i, j;
  double current;
  for (i = k; i < n; i++) {
    current = arr[i];
    j = i - 1;
    while (j > k && arr[j] < current) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = current;
  }
}

void print_arr(double arr[], int n) {
  for (int i = 0; i < n; i++)
    printf("%.3lf ", arr[i]);
  puts("\n");
}

int main() {
  int n, k;
  double *arr;
  scanf("%d %d", &n, &k);
  arr = malloc(n * sizeof(double));
  for (int i = 0; i < n; i++)
    scanf("%lf", &arr[i]);

  if(k){
    sort(arr, k);  
    sort_rest(arr, n, k);
  }
  else
  {
    sort_rest(arr, n, -1);
  }
  print_arr(arr, n);
  free(arr);
  return 0;
}