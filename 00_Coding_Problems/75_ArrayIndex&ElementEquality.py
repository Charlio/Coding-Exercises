def index_equals_value_search(arr):
  lowest = None
  low = 0
  high = len(arr) 
  while low <= high: 
    mid = (low+high)/2 
    if arr[mid] == mid: 
      lowest = mid
      high = mid - 1
    elif arr[mid] < mid:
      low = mid + 1   
    else:
      high = mid - 1 
  if lowest == None:
    return -1
  else:
    return lowest
  
  
arr =[-5, 0, 2, 3, 10, 29]
arr = [0, 1, 2, 3, 4, 5]
print(index_equals_value_search(arr))