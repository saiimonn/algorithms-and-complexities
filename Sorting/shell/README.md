# Shell Sort Notes

An improved version of insertion sort. It works by sorting elements at specific gaps, gradually reducing the gap size until it becomes one.

**Origin**
- Created by Donald Shell in 1959
- He created this to overcome the inefficiency of insertion sort when dealing with large datasets, especially when elements are located far from their correct positions.

**Stable?** - It is not

**Time & Space Complexity**

| Case | Time Complexity | Space Complexity |
| :--- | :---: | :---: |
| **Best Case** | $O(n log n)$ | $O(1)$ |
| **Average Case** | $O(n^1.25) to O(n^2)$ | $O(1)$ |
| **Worst Case** | $O(n^2)$ | $O(1)$ |