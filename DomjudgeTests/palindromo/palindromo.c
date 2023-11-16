#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 2001

int isPalindrome(const char *k, int start, int end) {
  while (start < end) {
    if (k[start] != k[end]) {
      return 0;
    }
    start++;
    end--;
  }
  return 1;
}

int largestPalindrome(const char *k, int start, int end) {
  if (start >= end) {
    return 1;
  }

  if (isPalindrome(k, start, end)) {
    return end - start + 1;
  }

  int leftSize = largestPalindrome(k, start, end - 1);
  int rightSize = largestPalindrome(k, start + 1, end);

  return (leftSize > rightSize) ? leftSize : rightSize;
}

int main() {
  char k[max];
  scanf("%s", k);

  int length = strlen(k);
  int largestPalindromeSize = largestPalindrome(k, 0, length);

  printf("%d\n", largestPalindromeSize);

  return 0;
}