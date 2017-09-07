"""Implement quick sort in Python.
Input a list.
Output a sorted list."""
def quicksort(array):
    return quicksort_aux(array, 0, len(array)-1)
    
def quicksort_aux(array, start, end):
    if start < end:
        pivot_idx = end
        pivot = array[pivot_idx]
        i = start
        while i < pivot_idx:
            if array[i] > pivot:
                array[pivot_idx] = array[i]
                array[i] = array[pivot_idx-1]
                array[pivot_idx-1] = pivot
                pivot_idx -= 1
            else:
                i +=1
        quicksort_aux(array, start, pivot_idx-1)
        quicksort_aux(array, pivot_idx+1, end)
    return array

test = [21, 4, 1, 3, 9, 20, 25, 6, 21, 14]
print quicksort(test)