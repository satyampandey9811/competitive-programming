// link to question - https://www.hackerrank.com/challenges/almost-sorted/problem

#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> &arr, int n) {
  for (int i = 1; i < n; i++) {
    if (arr[i] < arr[i - 1])
      return false;
  }
  return true;
}

void solve(vector<int> &arr) {
  int n = arr.size();

  // case 1
  if (isSorted(arr, n)) {
    cout << "yes";
    return;
  }

  // case 2 : a
  int pos = -1;
  for (int i = 1; i < n; i++) {
    if (arr[i] < arr[i - 1]) {
      pos = i - 1;
      break;
    }
  }
  for (int i = pos + 1; i < n; i++) {
    if (arr[i] < arr[pos]) {
      if (i + 1 == n) {
        swap(arr[i], arr[pos]);
        if (isSorted(arr, n)) {
          cout << "yes\n";
          cout << "swap " << pos + 1 << ' ' << i + 1;
          return;
        }
        swap(arr[i], arr[pos]);
      } else if (arr[i + 1] > arr[pos]) {
        swap(arr[i], arr[pos]);
        if (isSorted(arr, n)) {
          cout << "yes\n";
          cout << "swap " << pos + 1 << ' ' << i + 1;
          return;
        }
        swap(arr[i], arr[pos]);
        break;
      }
    }
  }
  // case 2 : b

  int startingIndex = -1;
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      startingIndex = i;
      break;
    }
  }
  int lastIndex = startingIndex + 1;
  while (lastIndex < n and arr[lastIndex] < arr[lastIndex - 1]) {
    lastIndex++;
  }

  reverse(arr.begin() + startingIndex, arr.begin() + lastIndex);

  if (isSorted(arr, n)) {
    cout << "yes\n";
    cout << "reverse " << startingIndex + 1 << ' ' << lastIndex;
    return;
  }

  // case 3
  cout << "no";
}

int main() {
  int n;
  cin >> n;

  vector<int> input(n);
  for (int i = 0; i < n; i++) {
    cin >> input[i];
  }
  solve(input);

  return 0;
}
