/* Write your PL/SQL query statement below */
SELECT eu.unique_id as unique_id, e.name as name
FROM employees e
LEFT JOIN employeeUNI eu ON e.id = eu.id;