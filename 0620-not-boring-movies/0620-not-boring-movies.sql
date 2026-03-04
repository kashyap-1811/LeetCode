# Write your MySQL query statement below
SELECT * FROM Cinema c
WHERE c.description NOT IN ("boring") 
AND c.id % 2 = 1
ORDER BY c.rating DESC;