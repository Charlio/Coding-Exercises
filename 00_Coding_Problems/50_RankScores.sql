# Write your MySQL query statement below
select Score, (select count(distinct score) from scores where score >= s.score) Rank from scores s order by score desc