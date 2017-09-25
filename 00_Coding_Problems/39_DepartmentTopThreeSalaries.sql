# Write your MySQL query statement below
SELECT Department.Name AS Department, em1.Name AS Employee, em1.Salary
FROM Employee em1
        JOIN Department ON Department.Id = em1.DepartmentId
WHERE 3 > (SELECT COUNT(DISTINCT em2.Salary) 
           FROM Employee em2
           WHERE em2.DepartmentId = em1.DepartmentId
                 AND em2.Salary > em1.Salary
           )