select avg(energy) from songs
join artists on artists.id = songs.artist_id
where artists.name == 'Drake';
