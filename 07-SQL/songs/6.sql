select songs.name from songs
join artists on artists.id = songs.artist_id
where artists.name == 'Post Malone';
