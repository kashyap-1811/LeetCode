# Write your MySQL query statement below
SELECT s.student_id, s.student_name, ss.subject_name, COUNT(e.student_id) AS attended_exams 
FROM students AS s
CROSS JOIN subjects AS ss
LEFT JOIN examinations e
ON s.student_id = e.student_id AND ss.subject_name = e.subject_name
GROUP BY s.student_id, s.student_name, ss.subject_name 
ORDER BY s.student_id ASC, ss.subject_name ASC;