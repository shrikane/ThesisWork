// left is the index of the leftmost element of the subarray
  // right is the index of the rightmost element of the subarray (inclusive)
  // number of elements in subarray = right-left+1
  function inplace-partition(array, left, right, pivotIndex)
     pivotValue := array[pivotIndex]
     swap array[pivotIndex] and array[right]  // Move pivot to end
     storeIndex := left
     for i from left to right - 1  // left ≤ i < right
         if array[i] < pivotValue
             swap array[i] and array[storeIndex]
             storeIndex := storeIndex + 1
     swap array[storeIndex] and array[right]  // Move pivot to its final place
     return storeIndex

function inplace-quicksort(array, left, right)
     // If the list has 2 or more items
     if left < right
         // See "#Choice of pivot" section below for possible choices
         choose any pivotIndex such that left ≤ pivotIndex ≤ right
         // Get lists of bigger and smaller items and final position of pivot
         pivotNewIndex := inplace-partition(array, left, right, pivotIndex)
         // Recursively sort elements smaller than the pivot
         inplace-quicksort(array, left, pivotNewIndex - 1)
         // Recursively sort elements at least as big as the pivot
         inplace-quicksort(array, pivotNewIndex + 1, right)



void quickSort( int a[], int l, int r)
{
   int j;

   if( l < r ) 
   {
   	// divide and conquer
        j = partition( a, l, r);
       quickSort( a, l, j-1);
       quickSort( a, j+1, r);
   }
	
}

int partition( int a[], int l, int r) {
   int pivot, i, j, t;
   pivot = a[l];
   i = l; j = r+1;
		
   while( 1)
   {
   	do ++i; while( a[i] <= pivot && i <= r );
   	do --j; while( a[j] > pivot );
   	if( i >= j ) break;
   	t = a[i]; a[i] = a[j]; a[j] = t;
   }
   t = a[l]; a[l] = a[j]; a[j] = t;
   return j;
}

