APS_assignment2
==

SUFFIX ARRAY
---
It is the question on the suffix Array(built from scratch) in O(nlogn) using the radix sort(if you use the STL sort then time
complexity becomes O(nlognlogn).

Also built the LCP(longest common prefix array) to solve 2nd part and the 3rd part.



Nth_nofaUnsortedArray.cpp
---

It is implementation of nth_element() STL function which finds nth element in O(n) in unsorted array.

Run with exe file and then enter the no. of elements and then nth element you want to find. At last this file will compare with STL function.

Assumption: all the elements are distinct.

Time complexity: O(n)


String Builder
---

In this I built the String Builder for c++ class and its basic operations like append O(1),initialisation O(1) and findSubtring O(n) for this I used KMP algo.

In this I used tree dataStructure and each substring add as a node , When we just want to print the string then just do  Inorder traversal on tree.

Unordered_Map
---

In this ,I implemented the basic STL unordered_Map and its basic functionalities like remove,find,insert. 

In this internally we used the HASH Table and you can change the Table Size. For string I used hashing method DJB2 and for int I used Mid square method. 

This Unordered_Map is generic means , It can work for any datatype but you just need to define its hash function inside Hash class.
