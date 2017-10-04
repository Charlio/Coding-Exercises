def meeting_planner(slotsA, slotsB, dur):
  ptA = 0
  ptB = 0
  inter = intersection(slotsA, ptA, slotsB, ptB)
  while inter[1] - inter[0] < dur:
    if slotsA[ptA][1] < slotsB[ptB][1]:
      ptA += 1
      if ptA == len(slotsA):
        return []
    else:
      ptB += 1
      if ptB == len(slotsB):
        return []
    inter = intersection(slotsA, ptA, slotsB, ptB)
  if ptA == len(slotsA) or ptB == len(slotsB) or inter[1] <= inter[0]:
    return []
  else:
    return [inter[0], inter[0]+dur]
       
def intersection(slotsA, ptA, slotsB, ptB):
  if ptA == len(slotsA) or ptB == len(slotsB):
    return [0, 0]
  else:
    lower = max(slotsA[ptA][0], slotsB[ptB][0])
    upper = min(slotsA[ptA][1], slotsB[ptB][1])
    return [lower, upper]
  
slotsA = [[10, 50], [60, 120], [140, 210]]
slotsB = [[0, 15], [60, 70]]
dur = 8

slotsA = [[10, 50], [60, 120], [140, 210]]
slotsB = [[0, 15], [60, 70]]
dur = 12
print(meeting_planner(slotsA, slotsB, dur))