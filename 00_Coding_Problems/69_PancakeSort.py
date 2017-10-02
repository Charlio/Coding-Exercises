from math import floor

def flip(arr, k):
  for i in range (int(floor( k / 2))):
    tmp = arr[i]
    arr[i] = arr[k-1-i]
    arr[k-1-i] = tmp
  
def argmax(arr):
  max_idx = 0
  for i in range(1, len(arr)):
    if arr[i] > arr[max_idx]:
      max_idx = i
  return max_idx
  
def pancake_sort(arr):
  for i in range(len(arr), 1, -1):
    print(i)
    cur_max_idx = argmax(arr[:i])
    flip(arr, cur_max_idx + 1)
    flip(arr, i)
  return arr