select name from people
where id in (
            (select person_id from stars where movie_id =
            (select id from movies where title like "toy story"))
            )
