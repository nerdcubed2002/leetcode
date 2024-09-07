# Write your MySQL query statement below
with tot as
(
    select user_id,count(action) as total from Confirmations group by user_id
),

co as
(
    select user_id,count(action) as confirmed from Confirmations where action="confirmed" group by user_id
),

t3 as
(
    select tot.user_id,round(confirmed/total,2) as confirmation_rate from tot inner join co on tot.user_id=co.user_id
)

select s.user_id,coalesce(confirmation_rate,0.00) as confirmation_rate from Signups s left join t3 on s.user_id=t3.user_id