# Comb Sort Notes

An improved version of bubble sort. It uses a shrinking gap sequence until the algorithm finishes with a final pass similar to bubble sort(comparing adjacent elements).

$gap = floor(gap/shrink factor)$

*note*: shrink_factor = 1.3

**Origin**
- Created by Arthur Barowy & Wlodzimierz Dobosiewicz in 1991.
- Later popularized by Stephen Lacy and Richard Box

**Stable??** - It is not stable

**Time & Space Complexity**

| Case | Time Complexity | Space Complexity |
| :--- | :---: | :---: |
| **Best Case** | $O(n log n)$ | $O(1)$ |
| **Average Case** | $O(n^2)$ | $O(1)$ |
| **Worst Case** | $O(n^2)$ | $O(1)$ |