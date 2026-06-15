# Write your MySQL query statement below
SELECT p.product_id, 
       IFNULL(round(sum(p.price * us.units) / sum(us.units), 2), 0) as average_price
FROM prices p
LEFT JOIN UnitsSold us
ON p.product_id = us.product_id
AND p.start_date <= us.purchase_date AND p.end_date >= us.purchase_date
GROUP BY product_id;