# Write your MySQL query statement below
SELECT Employee.name ,Bonus.bonus from Employee
LEFT JOIN Bonus ON Employee.empID = Bonus.empID
where bonus < 1000 OR Bonus IS NULL;