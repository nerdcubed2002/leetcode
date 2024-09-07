# Write your MySQL query statement below
with t1 as (select id,name from Employee),
t2 as(select managerId from Employee group by managerId having count(*)>=5)

select t1.name from t1 join t2 ON t1.id=t2.managerId