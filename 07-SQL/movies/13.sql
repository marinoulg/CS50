
with KB_and_co as -- ids of people having played with bradley cooper in films
(
  -- list of all movies with bradley cooper
  with KB as
      (
        select id, title from movies
        where id in (
                    select movie_id from stars
                    where person_id = (select id from people where name like "%kevin bacon%" and  birth = 1958)
                    )
      )

  select stars.movie_id as movie_id, stars.person_id as person_id, title from stars
  join KB on stars.movie_id = KB.id
)

-- select * from KB_and_co;

select distinct name from people
join KB_and_co on KB_and_co.person_id = people.id
where person_id != (select id from people where name like "%kevin bacon%" and  birth = 1958)
