# Write your MySQL query statement below
select distinct(log1.Num) ConsecutiveNums
from Logs log1, Logs log2, Logs log3
where
    log1.Id + 1 = log2.Id and Log2.Id + 1 = log3.Id
    and log1.Num = log2.Num and log2.Num = log3.Num