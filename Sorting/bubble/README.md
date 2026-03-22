# Bubble Sort Notes

An elementary sorting algorithm that compares two adjacent elements and swap what's out of place. After each pass, one section is already gone (after every iteration there is an element towards/at the end of the array that is already in its rightful place (clean section), it expands after every iteration).

**Origin**

- First described by Edward Harry Friend in his paper "Sorting on Electronig Computer Systems"
- It was conceptualized with the need to
  - Minimize computer time
  - Manual intervention
  - Storage usage

**Stable??** - YES IT IS

**Time & Space Complexity**

| Case | Time Complexity | Space Complexity |
| :--- | :---: | :---: |
| **Best Case** | $O(n)$ | $O(1)$ |
| **Average Case** | $O(n^2)$ | $O(1)$ |
| **Worst Case** | $O(n^2)$ | $O(1)$ |