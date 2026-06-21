# Write your MySQL query statement below
WITH first_time AS (
    SELECT s.product_id, MIN(year) as first_year
    FROM sales s
    GROUP BY s.product_id
)
SELECT s.product_id, 
       s.year as first_year,
       s.quantity as quantity,
       s.price as price
FROM sales s
JOIN first_time f
    ON s.product_id = f.product_id
    AND s.year = f.first_year;