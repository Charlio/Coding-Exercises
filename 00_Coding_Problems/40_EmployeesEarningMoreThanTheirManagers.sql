# Write your MySQL query statement below
SELECT em1.name AS Employee
FROM Employee AS em1, Employee AS em2
WHERE em1.ManagerId = em2.Id 
      AND em1.Salary > em2.Salary