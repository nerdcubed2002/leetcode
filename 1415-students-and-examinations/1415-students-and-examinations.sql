# Write your MySQL query statement below
with cte1 as
( select student_id,student_name,subject_name from Students cross join Subjects),

cte2 as
( select student_id,subject_name,count(*) as cnt  from Examinations group by student_id,subject_name)

select cte1.student_id,cte1.student_name,cte1.subject_name,coalesce(cte2.cnt,0) as attended_exams from cte1 left join cte2 on cte1.student_id=cte2.student_id and cte1.subject_name=cte2.subject_name order by student_id,subject_name