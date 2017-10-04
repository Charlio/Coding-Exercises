def find_duplicates(arr1, arr2):
  # [1, 2, 3, 5, 6, 7]
  # [3, 6, 7, 8, 20]
  # [3, 6, 7]
  
  # pt1, pt2
  # iterate over arr1, arr2
  # find common numbers
  
  pt1 = 0
  pt2 = 0
  n1 = len(arr1)
  n2 = len(arr2)
  ans = []
  while pt1 < n1 and pt2 < n2:
    if arr1[pt1] == arr2[pt2]:
      ans.append(arr1[pt1])
      pt1 += 1
      pt2 += 1
    elif arr1[pt1] < arr2[pt2]:
      pt1 += 1
    else:
      pt2 += 1
  return ans

arr1 = [1, 2, 3, 5, 6, 7]
arr2 = [3, 6, 7, 8, 20]
print(find_duplicates(arr1, arr2))

# Time: O(n1 + n2)
#[1, 3, 5, 7, 9]
#[2, 4, 6, 8, 10]

# Space: O(min(n1, n2))