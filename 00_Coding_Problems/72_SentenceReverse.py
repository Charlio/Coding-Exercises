'''
def reverse_words(arr):
  words = []
  front = -1
  end = -1
  n = len(arr)
  for i in range(n):
    if arr[i] == ' ':
      front = end
      end = i
      words.append(''.join(arr[front+1: end]))
  front = end
  words.append(''.join(arr[front+1:]))
  
  reversed_wds = words[::-1]
  reversed_char = []
  for word in reversed_wds:
    reversed_char += [word[i] for i in range(len(word))]
    reversed_char.append(' ')
  return reversed_char[:-1]
'''
def reverse_words(arr):
  n = len(arr)
  flip(arr, 0, n)
  ptA = 0
  ptB = 0
  while ptB <= n:
    if ptB == n or arr[ptB] == ' ':
      flip(arr, ptA, ptB)
      ptA = ptB + 1
    ptB += 1
  return arr
      
def flip(arr, ptA, ptB):
  low = ptA
  high = ptB
  while low < high:
    arr[low], arr[high-1] = arr[high-1], arr[low]
    low += 1
    high -= 1

# time: O(n) 
# space: O(n)

arr = ['p', 'e', ' ', 'm', 'a', 'k', ' ', 'p', 'r']

print(reverse_words(arr))