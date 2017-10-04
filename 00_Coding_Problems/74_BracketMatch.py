def bracket_match(text):
  count_left = 0
  count_diff = 0
  for br in text: #O(n)
    if br == '(':
      count_left += 1
    else: # br == ')'
      if count_left > 0:
        count_left -= 1    
      else:
        count_diff += 1
  return count_diff + count_left
  
text = "())(" 
print(bracket_match(text))






