""" Write your MySQL query statement below
 left join Person with Address, using PersonId, show FirstName, LastName from Person and City, State from Address
"""
SELECT
    Person.FirstName, Person.LastName, Address.City, Address.State
FROM
    Person 
            LEFT JOIN
    Address ON Person.PersonId = Address.PersonId;