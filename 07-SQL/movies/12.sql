with BC_and_co as -- ids of people having played with bradley cooper in films
(
  -- list of all movies with bradley cooper
  with BC as
      (
        select id, title from movies
        where id in (
                    select movie_id from stars
                    where person_id = (select id from people where name like "%bradley cooper%")
                    )
      )

  select stars.movie_id as movie_id, stars.person_id as person_id, title from stars
  join BC on stars.movie_id = BC.id
)

select title from BC_and_co
where person_id == (select id from people where name like "%jennifer lawrence%")
;
