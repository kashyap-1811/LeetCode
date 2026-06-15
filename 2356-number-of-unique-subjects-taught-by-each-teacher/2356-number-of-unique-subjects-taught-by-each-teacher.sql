# Write your MySQL query statement below
SELECT teacher_id, COUNT(*) AS cnt
FROM (
    SELECT DISTINCT teacher_id, subject_id
    FROM teacher 
    GROUP BY teacher_id, subject_id
) as derived
GROUP BY teacher_id;