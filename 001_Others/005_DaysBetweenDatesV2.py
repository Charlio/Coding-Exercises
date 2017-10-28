# Credit goes to Websten from forums
#
# Use Dave's suggestions to finish your daysBetweenDates
# procedure. It will need to take into account leap years
# in addition to the correct number of days in each month.

daysOfMonths = [ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

def isLeapYear(year):
    ##
    # Your code here. Return True or False
    # Pseudo code for this algorithm is found at
    # http://en.wikipedia.org/wiki/Leap_year#Algorithm
    ##
    if year % 4 != 0:
        return False
    elif year % 100 != 0:
        return True
    elif year % 400 != 0:
        return False
    else:
        return True

def daysBetweenDates(y1, m1, d1, y2, m2, d2):
    ##
    # Your code here.
    ##
    days = 0
    if y1 == y2:
        if m1 == m2:
            days = d2 - d1
        else:
            # days in remaining of m1
            if isLeapYear(y1) and m1 == 2:
                days += 29 - d1
            else:
                days += daysOfMonths[m1-1] - d1
            # days from m1+1 to m2-1
            for mon in range(m1+1, m2):
                if isLeapYear(y1) and mon == 2:
                    days += 29
                else:
                    days += daysOfMonths[mon-1]
            # days in m2
            days += d2
    else:
        # days in remaining of y1
        days += daysBetweenDates(y1, m1, d1, y1, 12, 31)
        # days from y1+1 to y2-1
        for yr in range(y1+1, y2):
            if isLeapYear(yr):
                days += 366
            else:
                days += 365
        # days in y2
        days += daysBetweenDates(y2, 1, 0, y2, m2, d2)
    return days

def test():
    test_cases = [((2012,1,1,2012,2,28), 58), 
                  ((2012,1,1,2012,3,1), 60),
                  ((2011,6,30,2012,6,30), 366),
                  ((2011,1,1,2012,8,8), 585 ),
                  ((1900,1,1,1999,12,31), 36523)]
    
    for (args, answer) in test_cases:
        result = daysBetweenDates(*args)
        if result != answer:
            print "Test with data:", args, "failed"
        else:
            print "Test case passed!"

test()