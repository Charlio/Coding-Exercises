# Write your MySQL query statement below
delete p from Person p, Person q where p.Id > q.Id and p.Email = q.Email;