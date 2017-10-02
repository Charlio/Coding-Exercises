def find_grants_cap(grantsArray, newBudget):
  # [2, 100, 50, 120, 1000]
  grantsArray.sort()
  # [2, 50, 100, 120, 1000]
  cap_idx = 0 
  cumsum = float(grantsArray[cap_idx])
  n = len(grantsArray) # 5
  while cumsum + grantsArray[cap_idx] * (n - cap_idx - 1) <= newBudget:
    cap_idx += 1
    cumsum += grantsArray[cap_idx]
  return (newBudget - cumsum + grantsArray[cap_idx]) / (n - cap_idx)


# cap_idx = 0, cumsum = 2
# 2 + 2 *(5-0-1) = 10 < 190:
# cap_idx = 1, cumsum = 2 + 50 = 52
# while: 52 + 50 * (5 - 1 - 1) = 202 > 190
# return (190 - 52 + 50) / (5 - 1) = 188 / 4 = 47