# Write your MySQL query statement below
select activity_date as day, count(*) as active_users 
from (
    SELECT DISTINCT a.activity_date, a.user_id 
    FROM ACTIVITY a
    where a.activity_date >= '2019-06-28' and a.activity_date <= '2019-07-27'
) as derived
group by activity_date;