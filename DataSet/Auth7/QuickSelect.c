function partition(list, left, right, pivotIndex)
     pivotValue := list[pivotIndex]
     swap list[pivotIndex] and list[right]  // Move pivot to end
     storeIndex := left
     for i from left to right-1
         if list[i] <= pivotValue
             swap list[storeIndex] and list[i]
             increment storeIndex
     swap list[right] and list[storeIndex]  // Move pivot to its final place
     return storeIndex

 // Returns the n-th smallest element of list within left..right inclusive (i.e. n is zero-based).
  function recSelect(list, left, right, n)
     if left = right        // If the list contains only one element
         return list[left]  // Return that element
     pivotIndex  := ...     // select a pivotIndex between left and right, e.g. left + Math.floor(Math.random() * (right - left + 1))
     pivotIndex  := partition(list, left, right, pivotIndex)
     // The pivot is in its final sorted position
     if n = pivotIndex
         return list[n]
     else if n < pivotIndex
         return recSelect(list, left, pivotIndex - 1, n)
     else
         return recSelect(list, pivotIndex + 1, right, n)


 function nonRecSelect(list, left, right, n)
     if left = right
         return list[left]
     loop
         pivotIndex := ...     // select pivotIndex between left and right
         pivotIndex := partition(list, left, right, pivotIndex)
         if n = pivotIndex
             return list[n]
         else if n < pivotIndex
             right := pivotIndex - 1
         else
             left := pivotIndex + 1
