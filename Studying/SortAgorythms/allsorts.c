#include <stdio.h>
#include <stdlib.h>

void selection_sort(int arr[], int n)
{
  int maior;

  for (int i = 0; i < n; i++)
  {
    maior = i;
    for (int j = i; j < n; j++)
    {
      if (arr[j] < arr[maior])
        maior = j;
    }
    int aux = arr[maior];
    arr[maior] = arr[i];
    arr[i] = aux;
  }
}
void insertion_sort(int arr[], int n)
{
  int i, current, j;
  for (i = 1; i < n; i++)
  {
    current = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > current)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = current;
  }
}

void shell_sort(int arr[], int n)
{
  int j, k = 1, current;
  while (k <= n / 2)
    k = k * 3 + 1;

  while (k > 0)
  {
    for (int i = k; i < n; i++)
    {
      current = arr[i];
      j = i;
      while (j >= k && arr[j - k] > current)
      {
        arr[j] = arr[j - k];
        j -= k;
      }
      arr[j] = current;
    }
    k = (k - 1) / 3;
  }
}

void swap(int *a, int *b)
{
  int aux = *a;
  *a = *b;
  *b = aux;
}

int partition(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j < high; j++)
  {
    if (arr[j] <= pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return i + 1;
}
void quick_sort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pivot_index = partition(arr, low, high);
    quick_sort(arr, pivot_index + 1, high);
    quick_sort(arr, low, pivot_index - 1);
  }
}

void merge(int arr[], int low, int high, int mid)
{
  int i, j, k;
  int n1, n2;
  n1 = mid - low + 1;
  n2 = high - mid;
  int L[n1], R[n2];

  for (i = 0; i < n1; i++)
    L[i] = arr[low + i];

  for (j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];

  i = 0;
  j = 0;
  k = low;

  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
      arr[k++] = L[i++];
    else
      arr[k++] = R[j++];
  }

  while (i < n1)
    arr[k++] = L[i++];
  while (j < n2)
    arr[k++] = R[j++];
}

void merge_sort(int arr[], int low, int high)
{
  if (low < high)
  {
    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, high, mid);
  }
}

int binary_search(int arr[], int key, int low, int high)
{
  int mid = (low + high) / 2;
  if (low > high)
  {
    return -1;
  }
  if (arr[mid] == key)
    return mid;
  if (arr[mid] < key)
    return binary_search(arr, key, mid + 1, high);
  return binary_search(arr, key, low, mid - 1);
}
void print_arr(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main()
{
  int op = -1;

  int n = 10;
  int arr[10] = {0, 5, 10, 4, 12, 63, 1, 2, 9, 64};
  while (op)
  {
    scanf("%d", &op);
    switch (op)
    {

    case 1:
      selection_sort(arr, n);
      print_arr(arr, n);
      break;

    case 2:
      insertion_sort(arr, n);
      print_arr(arr, n);
      break;
    case 3:
      shell_sort(arr, n);
      print_arr(arr, n);
      break;
    case 4:
      quick_sort(arr, 0, n - 1);
      print_arr(arr, n);
      break;
    case 5:
      merge_sort(arr, 0, n - 1);
      print_arr(arr, n);
    }
  }
  int key;
  scanf("%d", &key);
  printf("%d", binary_search(arr, key, 0, n));

  return 0;
}
