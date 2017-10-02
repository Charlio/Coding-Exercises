def get_different_number(arr):
  for i in range(len(arr)):
    while i != arr[i]:
      if arr[i] >= len(arr):
        arr[i] = -1
        break
      else:
        tmp = arr[arr[i]]
        arr[arr[i]] = arr[i]
        arr[i] = tmp
  for i in range(len(arr)):
    if arr[i] == -1:
      return i
  return len(arr)
    