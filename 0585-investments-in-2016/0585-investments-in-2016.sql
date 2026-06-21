# Write your MySQL query statement below
WITH not_same_city AS (
    SELECT 
        pid,
        tiv_2015,
        tiv_2016
    FROM insurance 
    GROUP BY lat, lon
    HAVING COUNT(*) = 1
)
SELECT round(SUM(nsc.tiv_2016), 2) as tiv_2016
FROM not_same_city as nsc
WHERE nsc.tiv_2015 IN (
    SELECT i.tiv_2015
    FROM insurance as i
    WHERE nsc.pid != i.pid
);