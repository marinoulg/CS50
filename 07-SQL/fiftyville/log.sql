-- Keep a log of any SQL queries you execute as you solve the mystery.

select *
from crime_scene_reports
where year = 2024 and day = 28 and month = 07 and street like "%humphrey%";

-- 295|2024|7|28|Humphrey Street|Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.
-- 297|2024|7|28|Humphrey Street|Littering took place at 16:36. No known witnesses.

-- interesting facts: The robbery, of id 295, took place at 10:15am, 3 witnesses.

select *
from interviews
where year = 2024 and day = 28 and month = 07;

-- 158|Jose|2024|7|28|“Ah,” said he, “I forgot that I had not seen you for some weeks. It is a little souvenir from the King of Bohemia in return for my assistance in the case of the Irene Adler papers.”
-- 159|Eugene|2024|7|28|“I suppose,” said Holmes, “that when Mr. Windibank came back from France he was very annoyed at your having gone to the ball.”
-- 160|Barbara|2024|7|28|“You had my note?” he asked with a deep harsh voice and a strongly marked German accent. “I told you that I would call.” He looked from one to the other of us, as if uncertain which to address.
-- 161|Ruth|2024|7|28|Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
-- 162|Eugene|2024|7|28|I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
-- 163|Raymond|2024|7|28|As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.
-- 191|Lily|2024|7|28|Our neighboring courthouse has a very annoying rooster that crows loudly at 6am every day. My sons Robert and Patrick took the rooster to a city far, far away, so it may never bother us again. My sons have successfully arrived in Paris.

-- interesting witnesses: Ruth (id, 161); Eugene (id, 162); Raymond (id, 163)
-- we know that, according to Ruth, the thief left 10 minutes-ish after the theft, so at around 10:25am
-- we know, according to Eugene, that the thief withdrew money by the ATM on Leggett Street before 10:15am on the 28th of July 2024.
-- we know, according to Raymond, that the thief called their partner for less than a minute to buy the earliest flight out of Fiftyville departing on the 29th of July 2024.

select *
from people
where name like "%ruth%";
-- 430845|Ruth|(772) 555-5770||HZB4129

select *
from people
where name like "%eugene%";
-- 280744|Eugene|(666) 555-5774|9584465633|47592FJ

select *
from people
where name like "%raymond%";
-- 937274|Raymond|(125) 555-8030||Y18DLY3

select id
from people
where name like "%ruth%" or name like "%eugene%" or name like "%raymond%";
-- 280744
-- 430845
-- 937274

select account_number
from bank_accounts
where person_id in (
                    select id
                    from people
                    where name like "%ruth%" or name like "%eugene%" or name like "%raymond%"
                    );
-- 24064261
-- 49406050
-- 28579039

select *
from atm_transactions
where account_number in (select account_number
                        from bank_accounts
                        where person_id in (
                                            select id
                                            from people
                                            where name like "%ruth%" or name like "%eugene%" or name like "%raymond%"
                                            )
                        );
-- 37|24064261|2024|7|26|Carvalho Road|withdraw|100
-- 91|49406050|2024|7|26|Daboin Sanchez Drive|deposit|95
-- 143|28579039|2024|7|27|Carvalho Road|withdraw|90
-- 170|49406050|2024|7|27|Daboin Sanchez Drive|withdraw|40
-- 307|24064261|2024|7|28|Daboin Sanchez Drive|deposit|25
-- 363|24064261|2024|7|29|Carvalho Road|deposit|60
-- 372|24064261|2024|7|29|Humphrey Lane|deposit|10
-- 373|49406050|2024|7|29|Leggett Street|deposit|25
-- 384|24064261|2024|7|29|Leggett Street|deposit|75
-- 443|28579039|2024|7|29|Daboin Sanchez Drive|deposit|55
-- 490|28579039|2024|7|29|Leggett Street|deposit|35
-- 492|49406050|2024|7|29|Humphrey Lane|deposit|30
-- 567|49406050|2024|7|29|Humphrey Lane|deposit|30
-- 609|49406050|2024|7|30|Humphrey Lane|withdraw|90
-- 611|24064261|2024|7|30|Humphrey Lane|withdraw|75
-- 647|24064261|2024|7|30|Blumberg Boulevard|deposit|75
-- 655|49406050|2024|7|30|Blumberg Boulevard|withdraw|35
-- 794|28579039|2024|7|30|Humphrey Lane|deposit|5
-- 821|28579039|2024|7|31|Carvalho Road|deposit|95
-- 825|28579039|2024|7|31|Leggett Street|deposit|50
-- 933|24064261|2024|7|31|Humphrey Lane|withdraw|40
-- 944|28579039|2024|7|31|Humphrey Lane|deposit|95
-- 1009|24064261|2024|7|31|Leggett Street|deposit|100
-- 1037|49406050|2024|7|31|Leggett Street|deposit|100
-- 1087|24064261|2024|8|1|Carvalho Road|deposit|65
-- 1092|28579039|2024|8|1|Humphrey Lane|deposit|10
-- 1102|49406050|2024|8|1|Leggett Street|withdraw|5
-- 1147|24064261|2024|8|1|Humphrey Lane|deposit|35
-- 1151|28579039|2024|8|1|Carvalho Road|withdraw|30
-- 1160|28579039|2024|8|1|Humphrey Lane|withdraw|70
-- 1190|24064261|2024|8|1|Blumberg Boulevard|deposit|15
-- 1276|49406050|2024|8|1|Blumberg Boulevard|withdraw|95
-- 1328|49406050|2024|8|1|Daboin Sanchez Drive|deposit|50

select *
from bakery_security_logs
where year = 2024 and day = 28 and month = 07;

-- 219|2024|7|28|8|2|entrance|1M92998
-- 220|2024|7|28|8|2|entrance|N507616
-- 221|2024|7|28|8|2|exit|1M92998
-- 222|2024|7|28|8|2|exit|N507616
-- 223|2024|7|28|8|7|entrance|7Z8B130
-- 224|2024|7|28|8|7|exit|7Z8B130
-- 225|2024|7|28|8|13|entrance|47MEFVA
-- 226|2024|7|28|8|13|exit|47MEFVA
-- 227|2024|7|28|8|15|entrance|D965M59
-- 228|2024|7|28|8|15|entrance|HW0488P
-- 229|2024|7|28|8|15|exit|D965M59
-- 230|2024|7|28|8|15|exit|HW0488P
-- 231|2024|7|28|8|18|entrance|L93JTIZ
-- 232|2024|7|28|8|23|entrance|94KL13X
-- 233|2024|7|28|8|25|entrance|L68E5I0
-- 234|2024|7|28|8|25|entrance|HOD8639
-- 235|2024|7|28|8|25|exit|HOD8639
-- 236|2024|7|28|8|34|exit|L68E5I0
-- 237|2024|7|28|8|34|entrance|1106N58
-- 238|2024|7|28|8|34|entrance|W2CT78U
-- 239|2024|7|28|8|34|exit|W2CT78U
-- 240|2024|7|28|8|36|entrance|322W7JE
-- 241|2024|7|28|8|38|entrance|3933NUH
-- 242|2024|7|28|8|38|exit|3933NUH
-- 243|2024|7|28|8|42|entrance|0NTHK55
-- 244|2024|7|28|8|44|entrance|1FBL6TH
-- 245|2024|7|28|8|44|exit|1FBL6TH
-- 246|2024|7|28|8|49|entrance|P14PE2Q
-- 247|2024|7|28|8|49|exit|P14PE2Q
-- 248|2024|7|28|8|50|entrance|4V16VO0
-- 249|2024|7|28|8|50|exit|4V16VO0
-- 250|2024|7|28|8|57|entrance|8LLB02B
-- 251|2024|7|28|8|57|exit|8LLB02B
-- 252|2024|7|28|8|59|entrance|O784M2U
-- 253|2024|7|28|8|59|exit|O784M2U
-- 254|2024|7|28|9|14|entrance|4328GD8
-- 255|2024|7|28|9|15|entrance|5P2BI95
-- 256|2024|7|28|9|20|entrance|6P58WS2
-- 257|2024|7|28|9|28|entrance|G412CB7
-- 258|2024|7|28|10|8|entrance|R3G7486
-- 259|2024|7|28|10|14|entrance|13FNH73
-- 260|2024|7|28|10|16|exit|5P2BI95
-- 261|2024|7|28|10|18|exit|94KL13X
-- 262|2024|7|28|10|18|exit|6P58WS2
-- 263|2024|7|28|10|19|exit|4328GD8
-- 264|2024|7|28|10|20|exit|G412CB7
-- 265|2024|7|28|10|21|exit|L93JTIZ
-- 266|2024|7|28|10|23|exit|322W7JE
-- 267|2024|7|28|10|23|exit|0NTHK55
-- 268|2024|7|28|10|35|exit|1106N58
-- 269|2024|7|28|10|42|entrance|NRYN856
-- 270|2024|7|28|10|44|entrance|WD5M8I6
-- 271|2024|7|28|10|55|entrance|V47T75I
-- 272|2024|7|28|11|6|entrance|4963D92
-- 273|2024|7|28|11|13|entrance|C194752
-- 274|2024|7|28|11|52|entrance|94MV71O
-- 275|2024|7|28|12|20|entrance|FLFN3W0
-- 276|2024|7|28|12|49|entrance|207W38T
-- 277|2024|7|28|13|8|entrance|RS7I6A0
-- 278|2024|7|28|13|30|entrance|4468KVT
-- 279|2024|7|28|13|42|entrance|NAW9653
-- 280|2024|7|28|14|18|exit|NAW9653
-- 281|2024|7|28|15|6|exit|RS7I6A0
-- 282|2024|7|28|15|16|exit|94MV71O
-- 283|2024|7|28|16|6|exit|WD5M8I6
-- 284|2024|7|28|16|38|exit|4468KVT
-- 285|2024|7|28|16|42|exit|207W38T
-- 286|2024|7|28|16|47|exit|C194752
-- 287|2024|7|28|17|11|exit|NRYN856
-- 288|2024|7|28|17|15|exit|13FNH73
-- 289|2024|7|28|17|16|exit|V47T75I
-- 290|2024|7|28|17|18|exit|R3G7486
-- 291|2024|7|28|17|36|exit|FLFN3W0
-- 292|2024|7|28|17|47|exit|4963D92

-- plate number "13FNH73" entered at 10:14am and left at 5:15pm the same day


select *
from bakery_security_logs
where year = 2024 and day = 28 and month = 07 and activity = "entrance" and hour < 11;

-- 219|2024|7|28|8|2|entrance|1M92998
-- 220|2024|7|28|8|2|entrance|N507616
-- 223|2024|7|28|8|7|entrance|7Z8B130
-- 225|2024|7|28|8|13|entrance|47MEFVA
-- 227|2024|7|28|8|15|entrance|D965M59
-- 228|2024|7|28|8|15|entrance|HW0488P
-- 231|2024|7|28|8|18|entrance|L93JTIZ
-- 232|2024|7|28|8|23|entrance|94KL13X
-- 233|2024|7|28|8|25|entrance|L68E5I0
-- 234|2024|7|28|8|25|entrance|HOD8639
-- 237|2024|7|28|8|34|entrance|1106N58
-- 238|2024|7|28|8|34|entrance|W2CT78U
-- 240|2024|7|28|8|36|entrance|322W7JE
-- 241|2024|7|28|8|38|entrance|3933NUH
-- 243|2024|7|28|8|42|entrance|0NTHK55
-- 244|2024|7|28|8|44|entrance|1FBL6TH
-- 246|2024|7|28|8|49|entrance|P14PE2Q
-- 248|2024|7|28|8|50|entrance|4V16VO0
-- 250|2024|7|28|8|57|entrance|8LLB02B
-- 252|2024|7|28|8|59|entrance|O784M2U
-- 254|2024|7|28|9|14|entrance|4328GD8
-- 255|2024|7|28|9|15|entrance|5P2BI95
-- 256|2024|7|28|9|20|entrance|6P58WS2
-- 257|2024|7|28|9|28|entrance|G412CB7
-- 258|2024|7|28|10|8|entrance|R3G7486
-- 259|2024|7|28|10|14|entrance|13FNH73
-- 269|2024|7|28|10|42|entrance|NRYN856
-- 270|2024|7|28|10|44|entrance|WD5M8I6
-- 271|2024|7|28|10|55|entrance|V47T75I

-- license plates that entered the bakery on the day of the theft before 11am.
select license_plate
from bakery_security_logs
where year = 2024 and day = 28 and month = 07 and activity = "entrance" and hour < 11;

-- license plates that entered the bakery on the day of the theft before 11am and that also left the bakery the same day.
select license_plate
from bakery_security_logs
where year = 2024 and day = 28 and month = 07 and activity = "exit"
and license_plate in (
                      select license_plate
                      from bakery_security_logs
                      where year = 2024 and day = 28 and month = 07 and activity = "entrance" and hour < 11
                      )


-- REMAINDER:
-- we know that, according to Ruth, the thief left 10 minutes-ish after the theft, so at around 10:25am

select license_plate
from bakery_security_logs
where year = 2024 and day = 28 and month = 07 and activity = "exit" and hour = 10 and hour < 11 and minute > 23

-- the license_plate on the car used after the theft is 1106N58
-- whose person does this license plate belong to?
select phone_number
from people
where license_plate = (
                      select license_plate
                      from bakery_security_logs
                      where year = 2024
                      and day = 28
                      and month = 07
                      and activity = "exit"
                      and hour = 10
                      and hour < 11
                      and minute > 23);
-- 449774|Taylor|(286) 555-6063|1988161715|1106N58

-- who is Taylor, our suspect, in contact with?
select * from phone_calls limit 5;

select *
from phone_calls
where caller = (
                select phone_number
                from people
                where license_plate = (
                                      select license_plate
                                      from bakery_security_logs
                                      where year = 2024
                                      and day = 28
                                      and month = 07
                                      and activity = "exit"
                                      and hour = 10
                                      and hour < 11
                                      and minute > 23)
                                        )
    or receiver =  (
                select phone_number
                from people
                where license_plate = (
                                      select license_plate
                                      from bakery_security_logs
                                      where year = 2024
                                      and day = 28
                                      and month = 07
                                      and activity = "exit"
                                      and hour = 10
                                      and hour < 11
                                      and minute > 23)
                                        );

-- 31|(771) 555-7880|(286) 555-6063|2024|7|25|119
-- 32|(487) 555-5865|(286) 555-6063|2024|7|25|199
-- 46|(286) 555-6063|(789) 555-8833|2024|7|25|125
-- 97|(060) 555-2489|(286) 555-6063|2024|7|26|371
-- 254|(286) 555-6063|(676) 555-6554|2024|7|28|43
-- 284|(286) 555-6063|(310) 555-8568|2024|7|28|235
-- 451|(286) 555-6063|(344) 555-9601|2024|7|30|154


select distinct caller, count(*)
from phone_calls
where caller = (
                select phone_number
                from people
                where license_plate = (
                                      select license_plate
                                      from bakery_security_logs
                                      where year = 2024
                                      and day = 28
                                      and month = 07
                                      and activity = "exit"
                                      and hour = 10
                                      and hour < 11
                                      and minute > 23)
                                        )
    or receiver =  (
                select phone_number
                from people
                where license_plate = (
                                      select license_plate
                                      from bakery_security_logs
                                      where year = 2024
                                      and day = 28
                                      and month = 07
                                      and activity = "exit"
                                      and hour = 10
                                      and hour < 11
                                      and minute > 23)
                                        )
group by caller;

-- (060) 555-2489|1
-- (286) 555-6063|4
-- (487) 555-5865|1
-- (771) 555-7880|1

select distinct caller, count(*)
from phone_calls
where caller = (
                select phone_number
                from people
                where license_plate = (
                                      select license_plate
                                      from bakery_security_logs
                                      where year = 2024
                                      and day = 28
                                      and month = 07
                                      and activity = "exit"
                                      and hour = 10
                                      and hour < 11
                                      and minute > 23)
                                        )
    or receiver =  (
                select phone_number
                from people
                where license_plate = (
                                      select license_plate
                                      from bakery_security_logs
                                      where year = 2024
                                      and day = 28
                                      and month = 07
                                      and activity = "exit"
                                      and hour = 10
                                      and hour < 11
                                      and minute > 23)
                                        )
group by receiver;

-- (771) 555-7880|3
-- (286) 555-6063|1

-- we know, according to Raymond, that the thief called their partner for less than a minute to buy the earliest flight out of Fiftyville departing on the 29th of July 2024.
select receiver from phone_calls
where caller = (
                select phone_number
                from people
                where license_plate = (
                                      select license_plate
                                      from bakery_security_logs
                                      where year = 2024
                                      and day = 28
                                      and month = 07
                                      and activity = "exit"
                                      and hour = 10
                                      and hour < 11
                                      and minute > 23)
                )
and duration < 60
and year = 2024 and day = 28 and month = 07;

-- (676) 555-6554

-- whose person does this number belong to?

select * from people
where phone_number = (
                      select receiver from phone_calls
                      where caller = (
                                      select phone_number
                                      from people
                                      where license_plate = (
                                                            select license_plate
                                                            from bakery_security_logs
                                                            where year = 2024
                                                            and day = 28
                                                            and month = 07
                                                            and activity = "exit"
                                                            and hour = 10
                                                            and hour < 11
                                                            and minute > 23)
                                      )
                      and duration < 60
                      and year = 2024 and day = 28 and month = 07);

-- 250277|James|(676) 555-6554|2438825627|Q13SVG6


-- which flight are they taking?
select * from flights
where year = 2024 and day = 29 and month = 07
order by hour
limit 1;

-- 36|8|4|2024|7|29|8|20
-- this means they are taking the flight whose id is 36, departing from airport_id 8 and arriving to airport_id 4
-- where from?

select * from airports
where id = (select origin_airport_id from flights
where year = 2024 and day = 29 and month = 07
order by hour
limit 1);

-- 8|CSF|Fiftyville Regional Airport|Fiftyville

-- where to?
select * from airports
where id = (select destination_airport_id from flights
where year = 2024 and day = 29 and month = 07
order by hour
limit 1);

-- 4|LGA|LaGuardia Airport|New York City


-- we know, according to Eugene, that the thief withdrew money by the ATM on Leggett Street before 10:15am on the 28th of July 2024.
-- to confirm the thief is indeed Taylor, let's check their bank withdrawals

select * from atm_transactions
where year = 2024 and day = 28 and month = 07
and transaction_type LIKE "%withdraw%"
and atm_location = 'Leggett Street';

-- 246|28500762|2024|7|28|Leggett Street|withdraw|48
-- 264|28296815|2024|7|28|Leggett Street|withdraw|20
-- 266|76054385|2024|7|28|Leggett Street|withdraw|60
-- 267|49610011|2024|7|28|Leggett Street|withdraw|50
-- 269|16153065|2024|7|28|Leggett Street|withdraw|80
-- 288|25506511|2024|7|28|Leggett Street|withdraw|20
-- 313|81061156|2024|7|28|Leggett Street|withdraw|30
-- 336|26013199|2024|7|28|Leggett Street|withdraw|35

select distinct account_number from atm_transactions
where year = 2024 and day = 28 and month = 07
and transaction_type LIKE "%withdraw%"
and atm_location = 'Leggett Street';

-- 28500762
-- 28296815
-- 76054385
-- 49610011
-- 16153065
-- 25506511
-- 81061156
-- 26013199

-- does one of these accounts belong to Taylor?
select person_id
from bank_accounts
where account_number in (select distinct account_number from atm_transactions
                        where year = 2024 and day = 28 and month = 07
                        and transaction_type LIKE "%withdraw%"
                        and atm_location = 'Leggett Street');

-- 686048
-- 514354
-- 458378
-- 395717
-- 396669
-- 467400
-- 449774
-- 438727

-- who are all these people? is one of them Taylor?
select name
from people
where id in (select person_id
            from bank_accounts
            where account_number in (select distinct account_number from atm_transactions
                                    where year = 2024 and day = 28 and month = 07
                                    and transaction_type LIKE "%withdraw%"
                                    and atm_location = 'Leggett Street'));
-- indeed, one of them IS Taylor.
-- So, if we come full circle:

select id from people where name = 'Taylor'
-- 449774

select account_number
from bank_accounts
where account_number in (select distinct account_number from atm_transactions
                        where year = 2024 and day = 28 and month = 07
                        and transaction_type LIKE "%withdraw%"
                        and atm_location = 'Leggett Street')
and person_id = (select id from people where name = 'Taylor')

-- 76054385

select amount
from atm_transactions
where account_number = (select account_number
                        from bank_accounts
                        where account_number in (select distinct account_number from atm_transactions
                                                where year = 2024 and day = 28 and month = 07
                                                and transaction_type LIKE "%withdraw%"
                                                and atm_location = 'Leggett Street')
                        and person_id = (select id from people where name = 'Taylor'))
and year = 2024 and day = 28 and month = 07;

-- 60

-- RECAP:
-- We now know that Taylor, the thief of the CS50 Duck, withdrew $60 on Leggett Street,
-- before he went to the bakery to steal the duck.
-- Right after the theft, he called his friend and accomplice James, via his own phone number
-- (Taylor's) (286) 555-6063, whose phone number is (676) 555-6554, so that James would book
-- a plane ticket for July 29th 2024 departing from airport_id 8, aka Fiftyville Regional Airport,
-- and arriving to airport_id 4, aka LaGuardia Airport (New York City), at 8:20am.
-- He then left the parking lot of the bakery at 10:35am with his car, license plate number 1106N58.

-- Still to answer:
-- Where on the flight will he be seated?
-- Is James with him?
-- Did he and James exchange money?

-- get flight_id
select id from flights
where year = 2024 and day = 29 and month = 07
order by hour
limit 1;

-- get passport number of Taylor
select passport_number from people where name = 'Taylor';
-- 1988161715

-- get passport number of James
select passport_number from people where name = 'James';
-- 2438825627

select *
from passengers
where flight_id = (select id from flights
   where year = 2024 and day = 29 and month = 07
   order by hour
   limit 1)
and (passport_number = (select passport_number from people where name = 'Taylor')
or passport_number = (select passport_number from people where name = 'James'));
-- 36|1988161715|6D

select *
from passengers
where flight_id = (select id from flights
   where year = 2024 and day = 29 and month = 07
   order by hour
   limit 1)
and passport_number = (select passport_number from people where name = 'Taylor')
or passport_number = (select passport_number from people where name = 'James');

-- 10|2438825627|7C
-- 21|2438825627|6A
-- 36|1988161715|6D
-- 47|2438825627|9B

-- Interestingly enough, we now know that Taylor will be flying alone on seat 6D, aka without James,
-- to NYC, but we don't know where James might flight to.

select *
from passengers
where passport_number = (select passport_number from people where name = 'James');

-- 10|2438825627|7C
-- 21|2438825627|6A
-- 47|2438825627|9B


select * from flights
where id in (
            select flight_id
            from passengers
            where passport_number = (select passport_number from people where name = 'James')
            );

-- 10|8|4|2024|7|30|13|55
-- 21|3|8|2024|7|26|17|58
-- 47|4|8|2024|7|30|9|46


-- So James is departing:
--        - from airport id 8 to airport id 4 on the 2024/7/30 at 1:55pm, flight id 10, seat 7C or
--        - from airport id 3 to airport id 8 on the 2024/7/26 at 5:58pm, flight id 21, seat 6A, or
--        - from airport id 4 to airport id 8 on the 2024/7/30 at 9:46am, flight id 47, seat 9B


select distinct origin_airport_id from flights
where id in (
            select flight_id
            from passengers
            where passport_number = (select passport_number from people where name = 'James')
            )
-- 8
-- 3
-- 4

-- he is either departing or arriving from either 3 of them.

select *
from airports
where id in (
  select distinct origin_airport_id from flights
where id in (
            select flight_id
            from passengers
            where passport_number = (select passport_number from people where name = 'James')
            )
)

-- 3|LAX|Los Angeles International Airport|Los Angeles
-- 4|LGA|LaGuardia Airport|New York City
-- 8|CSF|Fiftyville Regional Airport|Fiftyville

-- So James is departing:
--        - from airport CSF|Fiftyville Regional Airport|Fiftyville to airport LGA|LaGuardia Airport|New York City on the 2024/7/30 at 1:55pm, flight id 10, seat 7C, or
--        - from airport LAX|Los Angeles International Airport|Los Angeles to airport CSF|Fiftyville Regional Airport|Fiftyville on the 2024/7/26 at 5:58pm, flight id 21, seat 6A, or
--        - from airport LGA|LaGuardia Airport|New York City to airport CSF|Fiftyville Regional Airport|Fiftyville on the 2024/7/30 at 9:46am, flight id 47, seat 9B


-- To answer this question, we need to know if James is (or not) in Fiftyville. Let's check that by taking a look at his bank account and atm transactions.

select id from people where name like '%james%';

select account_number
from bank_accounts
where person_id = (
                  select id
                  from people
                  where name like '%james%');

-- it seems James has no bank account.

-- looking for a motive
select * from interviews where name like '%taylor%';

select * from interviews where name like '%james%';
-- 26|James|2024|2|5|“The circumstances are of great delicacy, and every precaution has to be taken to quench what might grow to be an immense scandal and seriously compromise one of the reigning families of Europe. To speak plainly, the matter implicates the great House of Ormstein, hereditary kings of Bohemia.”

select * from interviews where transcript like '%ormstein%';

-- 19|Katherine|2024|1|28|“Why, indeed?” murmured Holmes. “Your Majesty had not spoken before I was aware that I was addressing Wilhelm Gottsreich Sigismond von Ormstein, Grand Duke of Cassel-Felstein, and hereditary King of Bohemia.”
-- 26|James|2024|2|5|“The circumstances are of great delicacy, and every precaution has to be taken to quench what might grow to be an immense scandal and seriously compromise one of the reigning families of Europe. To speak plainly, the matter implicates the great House of Ormstein, hereditary kings of Bohemia.”

-- According to an interview given by James on February 5th 2024, James may have planned the robbery of the duck because of a very delicate situation, for which "every precaution has to be taken" so that "the great House of Ormstein, hereditary kings of Bohemia" would not be implicated in a scandal.


select * from interviews where transcript like '%bohemia%';
-- 19|Katherine|2024|1|28|“Why, indeed?” murmured Holmes. “Your Majesty had not spoken before I was aware that I was addressing Wilhelm Gottsreich Sigismond von Ormstein, Grand Duke of Cassel-Felstein, and hereditary King of Bohemia.”
-- 22|Harold|2024|2|2|“You may address me as the Count Von Kramm, a Bohemian nobleman. I understand that this gentleman, your friend, is a man of honour and discretion, whom I may trust with a matter of the most extreme importance. If not, I should much prefer to communicate with you alone.”
-- 26|James|2024|2|5|“The circumstances are of great delicacy, and every precaution has to be taken to quench what might grow to be an immense scandal and seriously compromise one of the reigning families of Europe. To speak plainly, the matter implicates the great House of Ormstein, hereditary kings of Bohemia.”
-- 89|Albert|2024|4|19|I had had so many reasons to believe in my friend’s subtle powers of reasoning and extraordinary energy in action that I felt that he must have some solid grounds for the assured and easy demeanour with which he treated the singular mystery which he had been called upon to fathom. Once only had I known him to fail, in the case of the King of Bohemia and of the Irene Adler photograph; but when I looked back to the weird business of the Sign of Four, and the extraordinary circumstances connected with the Study in Scarlet, I felt that it would be a strange tangle indeed which he could not unravel.
-- 158|Jose|2024|7|28|“Ah,” said he, “I forgot that I had not seen you for some weeks. It is a little souvenir from the King of Bohemia in return for my assistance in the case of the Irene Adler papers.”

-- in the case of the Irene Adler papers, Jose received help from the King of Bohemia, Wilhelm Gottsreich Sigismond von Ormstein, Grand Duke of Cassel-Felstein, and hereditary King of Bohemia,
-- who gifed him something in return, "a little souvenir", on July 28th 2024. Was it the Duck? Who is Jose?


select * from interviews where year = 2024 and month = 2;
-- 20|Doris|2024|2|1|“Who was he, then, and what was his object in deserting Miss Sutherland?”

-- 21|Joan|2024|2|2|“Had there been women in the house, I should have suspected a mere vulgar intrigue. That, however, was out of the question. The man’s business was a small one, and there was nothing in his house which could account for such elaborate preparations, and such an expenditure as they were at. It must, then, be something out of the house. What could it be? I thought of the assistant’s fondness for photography, and his trick of vanishing into the cellar. The cellar! There was the end of this tangled clue. Then I made inquiries as to this mysterious assistant and found that I had to deal with one of the coolest and most daring criminals in London. He was doing something in the cellar—something which took many hours a day for months on end. What could it be, once more? I could think of nothing save that he was running a tunnel to some other building.
-- 22|Harold|2024|2|2|“You may address me as the Count Von Kramm, a Bohemian nobleman. I understand that this gentleman, your friend, is a man of honour and discretion, whom I may trust with a matter of the most extreme importance. If not, I should much prefer to communicate with you alone.”

-- 23|Carol|2024|2|4|“And the ring?” I asked, glancing at a remarkable brilliant which sparkled upon his finger.
-- 24|Tyler|2024|2|4|“Some cold beef and a glass of beer,” he answered, ringing the bell. “I have been too busy to think of food, and I am likely to be busier still this evening. By the way, Doctor, I shall want your co-operation.”
-- 25|Evelyn|2024|2|4|“You see, Watson,” he explained in the early hours of the morning as we sat over a glass of whisky and soda in Baker Street, “it was perfectly obvious from the first that the only possible object of this rather fantastic business of the advertisement of the League, and the copying of the Encyclopædia, must be to get this not over-bright pawnbroker out of the way for a number of hours every day. It was a curious way of managing it, but, really, it would be difficult to suggest a better. The method was no doubt suggested to Clay’s ingenious mind by the colour of his accomplice’s hair. The £ 4 a week was a lure which must draw him, and what was it to them, who were playing for thousands? They put in the advertisement, one rogue has the temporary office, the other rogue incites the man to apply for it, and together they manage to secure his absence every morning in the week. From the time that I heard of the assistant having come for half wages, it was obvious to me that he had some strong motive for securing the situation.”

-- 26|James|2024|2|5|“The circumstances are of great delicacy, and every precaution has to be taken to quench what might grow to be an immense scandal and seriously compromise one of the reigning families of Europe. To speak plainly, the matter implicates the great House of Ormstein, hereditary kings of Bohemia.”

-- 27|Raymond|2024|2|6|“Good-night, Mister Sherlock Holmes.”
-- 28|Jeremy|2024|2|6|“It is our French gold,” whispered the director. “We have had several warnings that an attempt might be made upon it.”

-- 29|Ralph|2024|2|7|“You appeared to read a good deal upon her which was quite invisible to me,” I remarked.
-- 30|Patrick|2024|2|7|Its disappearance, however, was but momentary. With a rending, tearing sound, one of the broad, white stones turned over upon its side and left a square, gaping hole, through which streamed the light of a lantern. Over the edge there peeped a clean-cut, boyish face, which looked keenly about it, and then, with a hand on either side of the aperture, drew itself shoulder-high and waist-high, until one knee rested upon the edge. In another instant he stood at the side of the hole and was hauling after him a companion, lithe and small like himself, with a pale face and a shock of very red hair.

-- 31|Bobby|2024|2|8|“I was aware of it,” said Holmes dryly.
-- 32|Sandra|2024|2|8|“No, that was not the point. However, I shall write two letters, which should settle the matter. One is to a firm in the City, the other is to the young lady’s stepfather, Mr. Windibank, asking him whether he could meet us here at six o’clock to-morrow evening. It is just as well that we should do business with the male relatives. And now, Doctor, we can do nothing until the answers to those letters come, so we may put our little problem upon the shelf for the interim.”

-- 33|Joshua|2024|2|9|“I then lounged down the street and found, as I expected, that there was a mews in a lane which runs down by one wall of the garden. I lent the ostlers a hand in rubbing down their horses, and received in exchange twopence, a glass of half-and-half, two fills of shag tobacco, and as much information as I could desire about Miss Adler, to say nothing of half a dozen other people in the neighbourhood in whom I was not in the least interested, but whose biographies I was compelled to listen to.”

-- 34|Kathryn|2024|2|10|I placed my revolver, cocked, upon the top of the wooden case behind which I crouched. Holmes shot the slide across the front of his lantern and left us in pitch darkness—such an absolute darkness as I have never before experienced. The smell of hot metal remained to assure us that the light was still there, ready to flash out at a moment’s notice. To me, with my nerves worked up to a pitch of expectancy, there was something depressing and subduing in the sudden gloom, and in the cold dank air of the vault.

-- 35|Catherine|2024|2|11|“I have an inspector and two officers waiting at the front door.”
-- 36|Willie|2024|2|11|I work at the courthouse, and I saw the hit-and-run on my way into work this morning.

-- 37|Janice|2024|2|12|“Some ten or twelve, but none which present any feature of interest. They are important, you understand, without being interesting. Indeed, I have found that it is usually in unimportant matters that there is a field for the observation, and for the quick analysis of cause and effect which gives the charm to an investigation. The larger crimes are apt to be the simpler, for the bigger the crime the more obvious, as a rule, is the motive. In these cases, save for one rather intricate matter which has been referred to me from Marseilles, there is nothing which presents any features of interest. It is possible, however, that I may have something better before very many minutes are over, for this is one of my clients, or I am much mistaken.”
-- 38|Joseph|2024|2|12|“You will excuse this mask,” continued our strange visitor. “The august person who employs me wishes his agent to be unknown to you, and I may confess at once that the title by which I have just called myself is not exactly my own.”
-- 39|Dennis|2024|2|12|A man entered who could hardly have been less than six feet six inches in height, with the chest and limbs of a Hercules. His dress was rich with a richness which would, in England, be looked upon as akin to bad taste. Heavy bands of astrakhan were slashed across the sleeves and fronts of his double-breasted coat, while the deep blue cloak which was thrown over his shoulders was lined with flame-coloured silk and secured at the neck with a brooch which consisted of a single flaming beryl. Boots which extended halfway up his calves, and which were trimmed at the tops with rich brown fur, completed the impression of barbaric opulence which was suggested by his whole appearance. He carried a broad-brimmed hat in his hand, while he wore across the upper part of his face, extending down past the cheekbones, a black vizard mask, which he had apparently adjusted that very moment, for his hand was still raised to it as he entered. From the lower part of the face he appeared to be a man of strong character, with a thick, hanging lip, and a long, straight chin suggestive of resolution pushed to the length of obstinacy.

-- 40|Michael|2024|2|14|The man sat huddled up in his chair, with his head sunk upon his breast, like one who is utterly crushed. Holmes stuck his feet up on the corner of the mantelpiece and, leaning back with his hands in his pockets, began talking, rather to himself, as it seemed, than to us.

-- 41|Isabella|2024|2|15|“It is most unlikely that she carries it about with her. It is cabinet size. Too large for easy concealment about a woman’s dress. She knows that the King is capable of having her waylaid and searched. Two attempts of the sort have already been made. We may take it, then, that she does not carry it about with her.”
-- 42|Arthur|2024|2|15|“Well, I found my plans very seriously menaced. It looked as if the pair might take an immediate departure, and so necessitate very prompt and energetic measures on my part. At the church door, however, they separated, he driving back to the Temple, and she to her own house. ‘I shall drive out in the park at five as usual,’ she said as she left him. I heard no more. They drove away in different directions, and I went off to make my own arrangements.”

-- 43|Nicholas|2024|2|20|“You did it very nicely, Doctor,” he remarked. “Nothing could have been better. It is all right.”
-- 44|Justin|2024|2|20|The question was hardly out of my mouth, and Holmes had not yet opened his lips to reply, when we heard a heavy footfall in the passage and a tap at the door.

-- 45|Kayla|2024|2|21|“You have the photograph?”

-- 46|Scott|2024|2|23|“Well, when they closed their League offices that was a sign that they cared no longer about Mr. Jabez Wilson’s presence—in other words, that they had completed their tunnel. But it was essential that they should use it soon, as it might be discovered, or the bullion might be removed. Saturday would suit them better than any other day, as it would give them two days for their escape. For all these reasons I expected them to come to-night.”
-- 47|Emily|2024|2|23|“I am very much afraid that it is not. But between ourselves, Windibank, it was as cruel and selfish and heartless a trick in a petty way as ever came before me. Now, let me just run over the course of events, and you will contradict me if I go wrong.”

-- 48|Dylan|2024|2|24|“No, no, the mystery!” I cried.
-- 49|Peter|2024|2|24|“They have but one retreat,” whispered Holmes. “That is back through the house into Saxe-Coburg Square. I hope that you have done what I asked you, Jones?”

-- 50|Jennifer|2024|2|25|I left him then, still puffing at his black clay pipe, with the conviction that when I came again on the next evening I would find that he held in his hands all the clues which would lead up to the identity of the disappearing bridegroom of Miss Mary Sutherland.
-- 51|Kimberly|2024|2|27|“Oh, yes, mother is alive and well. I wasn’t best pleased, Mr. Holmes, when she married again so soon after father’s death, and a man who was nearly fifteen years younger than herself. Father was a plumber in the Tottenham Court Road, and he left a tidy business behind him, which mother carried on with Mr. Hardy, the foreman; but when Mr. Windibank came he made her sell the business, for he was very superior, being a traveller in wines. They got £ 4700 for the goodwill and interest, which wasn’t near as much as father could have got if he had been alive.”

select * from interviews where transcript like '%king of bohemia%';
-- 19|Katherine|2024|1|28|“Why, indeed?” murmured Holmes. “Your Majesty had not spoken before I was aware that I was addressing Wilhelm Gottsreich Sigismond von Ormstein, Grand Duke of Cassel-Felstein, and hereditary King of Bohemia.”
-- 89|Albert|2024|4|19|I had had so many reasons to believe in my friend’s subtle powers of reasoning and extraordinary energy in action that I felt that he must have some solid grounds for the assured and easy demeanour with which he treated the singular mystery which he had been called upon to fathom. Once only had I known him to fail, in the case of the King of Bohemia and of the Irene Adler photograph; but when I looked back to the weird business of the Sign of Four, and the extraordinary circumstances connected with the Study in Scarlet, I felt that it would be a strange tangle indeed which he could not unravel.
-- 158|Jose|2024|7|28|“Ah,” said he, “I forgot that I had not seen you for some weeks. It is a little souvenir from the King of Bohemia in return for my assistance in the case of the Irene Adler papers.”

select * from interviews where transcript like '%irene adler%';
-- 86|Christina|2024|4|14|“I was half-dragged up to the altar, and before I knew where I was I found myself mumbling responses which were whispered in my ear, and vouching for things of which I knew nothing, and generally assisting in the secure tying up of Irene Adler, spinster, to Godfrey Norton, bachelor. It was all done in an instant, and there was the gentleman thanking me on the one side and the lady on the other, while the clergyman beamed on me in front. It was the most preposterous position in which I ever found myself in my life, and it was the thought of it that started me laughing just now. It seems that there had been some informality about their license, that the clergyman absolutely refused to marry them without a witness of some sort, and that my lucky appearance saved the bridegroom from having to sally out into the streets in search of a best man. The bride gave me a sovereign, and I mean to wear it on my watch chain in memory of the occasion.”
-- 89|Albert|2024|4|19|I had had so many reasons to believe in my friend’s subtle powers of reasoning and extraordinary energy in action that I felt that he must have some solid grounds for the assured and easy demeanour with which he treated the singular mystery which he had been called upon to fathom. Once only had I known him to fail, in the case of the King of Bohemia and of the Irene Adler photograph; but when I looked back to the weird business of the Sign of Four, and the extraordinary circumstances connected with the Study in Scarlet, I felt that it would be a strange tangle indeed which he could not unravel.
-- 117|Juan|2024|5|27|“I can’t imagine. I suppose that you have been watching the habits, and perhaps the house, of Miss Irene Adler.”
-- 152|George|2024|7|19|“The facts are briefly these: Some five years ago, during a lengthy visit to Warsaw, I made the acquaintance of the well-known adventuress, Irene Adler. The name is no doubt familiar to you.”
-- 158|Jose|2024|7|28|“Ah,” said he, “I forgot that I had not seen you for some weeks. It is a little souvenir from the King of Bohemia in return for my assistance in the case of the Irene Adler papers.”
-- 186|Daniel|2024|8|23|As he spoke the gleam of the sidelights of a carriage came round the curve of the avenue. It was a smart little landau which rattled up to the door of Briony Lodge. As it pulled up, one of the loafing men at the corner dashed forward to open the door in the hope of earning a copper, but was elbowed away by another loafer, who had rushed up with the same intention. A fierce quarrel broke out, which was increased by the two guardsmen, who took sides with one of the loungers, and by the scissors-grinder, who was equally hot upon the other side. A blow was struck, and in an instant the lady, who had stepped from her carriage, was the centre of a little knot of flushed and struggling men, who struck savagely at each other with their fists and sticks. Holmes dashed into the crowd to protect the lady; but, just as he reached her, he gave a cry and dropped to the ground, with the blood running freely down his face. At his fall the guardsmen took to their heels in one direction and the loungers in the other, while a number of better dressed people, who had watched the scuffle without taking part in it, crowded in to help the lady and to attend to the injured man. Irene Adler, as I will still call her, had hurried up the steps; but she stood at the top with her superb figure outlined against the lights of the hall, looking back into the street.

select * from interviews where transcript like '%duck%';
select * from interviews where transcript like '%cs50%';
-- return nothing

-- no motive found (yet)

--  Does James have a car?
select license_plate from people where name like '%james%';
-- 250277|James|(676) 555-6554|2438825627|Q13SVG6


select count(*) from phone_calls
where (caller = (select phone_number from people where name like '%james%')
      and receiver = (select phone_number from people where name like '%taylor%'));
-- 0

select * from phone_calls
where (receiver = (select phone_number from people where name like '%james%')
      and caller = (select phone_number from people where name like '%taylor%'));
-- 1

-- James has never called Taylor, and Taylor has only called James once.

select *
from bakery_security_logs
where license_plate = (select license_plate from people where name like '%james%');

-- 11|2024|7|25|8|39|entrance|Q13SVG6
-- 56|2024|7|25|16|21|exit|Q13SVG6
-- 316|2024|7|29|12|19|entrance|Q13SVG6
-- 341|2024|7|29|17|43|exit|Q13SVG6

select *
from bakery_security_logs
where license_plate = (select license_plate from people where name like '%taylor%');

-- According to the logs of the bakery, James's car was at the parking lot of the bakery on the 25th
-- of July 2024, and also on the 29th of July 2024, which means he had not yet left Fiftyville, but also
-- it means that he had to depart from Fiftyville. Worth noting: both times, he entered and left the parking
-- lot after over 5 hours and on the same day.
-- Taylor, on the other hand, had never been to the bakery before according to the logs of the bakery (of his car).


--------- GOING BACK FROM THE START --------------

-- All you know is that the theft took place on July 28, 2024 and that it took place on
-- Humphrey Street.
-- You may find it helpful to start with the crime_scene_reports table. Start by looking
-- for a crime scene report that matches the date and the location of the crime.

select *
from crime_scene_reports
where year = 2024 and day = 28 and month = 07 and street like "%humphrey%";

-- 295|2024|7|28|Humphrey Street|Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.
-- 297|2024|7|28|Humphrey Street|Littering took place at 16:36. No known witnesses.

-- interesting facts: The robbery, of id 295, took place at 10:15am, 3 witnesses.

select *
from interviews
where year = 2024 and day = 28 and month = 07 and transcript like "%bakery%";

-- 161|Ruth|2024|7|28|Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
-- 162|Eugene|2024|7|28|I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
-- 163|Raymond|2024|7|28|As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.


-- "within ten minutes of the theft"
select *
from bakery_security_logs
where (year = 2024 and day = 28 and month = 07) and
(hour = 10 and minute > 15 minute < 25);

-- 260|2024|7|28|10|16|exit|5P2BI95
-- 261|2024|7|28|10|18|exit|94KL13X
-- 262|2024|7|28|10|18|exit|6P58WS2
-- 263|2024|7|28|10|19|exit|4328GD8
-- 264|2024|7|28|10|20|exit|G412CB7
-- 265|2024|7|28|10|21|exit|L93JTIZ
-- 266|2024|7|28|10|23|exit|322W7JE
-- 267|2024|7|28|10|23|exit|0NTHK55

-- who are these people, and did they withdraw some money before the theft by the ATM on Leggett Street?

-- get name and id of people
select *
from people
where license_plate in (select license_plate
                        from bakery_security_logs
                        where (year = 2024 and day = 28 and month = 07) and
                        (hour = 10 and minute > 15 and minute < 25))

-- 221103|Vanessa|(725) 555-4692|2963008352|5P2BI95
-- 243696|Barry|(301) 555-4174|7526138472|6P58WS2
-- 396669|Iman|(829) 555-5269|7049073643|L93JTIZ
-- 398010|Sofia|(130) 555-0289|1695452385|G412CB7
-- 467400|Luca|(389) 555-5198|8496433585|4328GD8
-- 514354|Diana|(770) 555-1861|3592750733|322W7JE
-- 560886|Kelsey|(499) 555-9472|8294398571|0NTHK55
-- 686048|Bruce|(367) 555-5533|5773159633|94KL13X

select account_number
from bank_accounts
where person_id in (select id
                    from people
                    where license_plate in (select license_plate
                                            from bakery_security_logs
                                            where (year = 2024 and day = 28 and month = 07) and
                                            (hour = 10 and minute > 15 and minute < 25)))
-- 49610011
-- 26013199
-- 25506511
-- 28500762
-- 56171033

select *
from atm_transactions
where account_number in (
  select account_number
from bank_accounts
where person_id in (select id
                    from people
                    where license_plate in (select license_plate
                                            from bakery_security_logs
                                            where (year = 2024 and day = 28 and month = 07) and
                                            (hour = 10 and minute > 15 and minute < 25)))
                    and year = 2024 and day = 28 and month = 07 and atm_location like "%Leggett%"
)

-- 246|28500762|2024|7|28|Leggett Street|withdraw|48
-- 267|49610011|2024|7|28|Leggett Street|withdraw|50
-- 288|25506511|2024|7|28|Leggett Street|withdraw|20
-- 336|26013199|2024|7|28|Leggett Street|withdraw|35

-- We now have 4 suspects, being:

select person_id
from bank_accounts
where account_number in
(select account_number
from atm_transactions
where account_number in (
  select account_number
from bank_accounts
where person_id in (select id
                    from people
                    where license_plate in (select license_plate
                                            from bakery_security_logs
                                            where (year = 2024 and day = 28 and month = 07) and
                                            (hour = 10 and minute > 15 and minute < 25)))
                    and year = 2024 and day = 28 and month = 07 and atm_location like "%Leggett%"
))

-- 686048
-- 514354
-- 396669
-- 467400

select *
from people
where id in
(select person_id
from bank_accounts
where account_number in
(select account_number
from atm_transactions
where account_number in (
  select account_number
from bank_accounts
where person_id in (select id
                    from people
                    where license_plate in (select license_plate
                                            from bakery_security_logs
                                            where (year = 2024 and day = 28 and month = 07) and
                                            (hour = 10 and minute > 15 and minute < 25)))
                    and year = 2024 and day = 28 and month = 07 and atm_location like "%Leggett%"
)))

-- 396669|Iman|(829) 555-5269|7049073643|L93JTIZ
-- 467400|Luca|(389) 555-5198|8496433585|4328GD8
-- 514354|Diana|(770) 555-1861|3592750733|322W7JE
-- 686048|Bruce|(367) 555-5533|5773159633|94KL13X

with withdrawals_suspects as
    (select *
    from atm_transactions
    where account_number in (
      select account_number
    from bank_accounts
    where person_id in (select id
                        from people
                        where license_plate in (select license_plate
                                                from bakery_security_logs
                                                where (year = 2024 and day = 28 and month = 07) and
                                                (hour = 10 and minute > 15 and minute < 25)))
                        and year = 2024 and day = 28 and month = 07 and atm_location like "%Leggett%"
    ))

select withdrawals_suspects.*, people.* from withdrawals_suspects
join bank_accounts on withdrawals_suspects.account_number = bank_accounts.account_number
join people on bank_accounts.person_id = people.id;

-- 267|49610011|2024|7|28|Leggett Street|withdraw|50|686048|Bruce|(367) 555-5533|5773159633|94KL13X
-- 336|26013199|2024|7|28|Leggett Street|withdraw|35|514354|Diana|(770) 555-1861|3592750733|322W7JE
-- 288|25506511|2024|7|28|Leggett Street|withdraw|20|396669|Iman|(829) 555-5269|7049073643|L93JTIZ
-- 246|28500762|2024|7|28|Leggett Street|withdraw|48|467400|Luca|(389) 555-5198|8496433585|4328GD8

with suspects as
(with withdrawals_suspects as
    (select *
    from atm_transactions
    where account_number in (
      select account_number
    from bank_accounts
    where person_id in (select id
                        from people
                        where license_plate in (select license_plate
                                                from bakery_security_logs
                                                where (year = 2024 and day = 28 and month = 07) and
                                                (hour = 10 and minute > 15 and minute < 25)))
                        and year = 2024 and day = 28 and month = 07 and atm_location like "%Leggett%"
    ))

select withdrawals_suspects.*, people.* from withdrawals_suspects
join bank_accounts on withdrawals_suspects.account_number = bank_accounts.account_number
join people on bank_accounts.person_id = people.id)

select * from suspects
join phone_calls on phone_calls.caller = suspects.phone_number
where phone_calls.year = 2024 and phone_calls.day = 28 and phone_calls.month = 07 and duration < 60;

-- 267|49610011|2024|7|28|Leggett Street|withdraw|50|686048|Bruce|(367) 555-5533|5773159633|94KL13X|233|(367) 555-5533|(375) 555-8161|2024|7|28|45
-- 336|26013199|2024|7|28|Leggett Street|withdraw|35|514354|Diana|(770) 555-1861|3592750733|322W7JE|255|(770) 555-1861|(725) 555-3243|2024|7|28|49


with accomplices as
(
  with suspects as
(with withdrawals_suspects as
    (select *
    from atm_transactions
    where account_number in (
      select account_number
    from bank_accounts
    where person_id in (select id
                        from people
                        where license_plate in (select license_plate
                                                from bakery_security_logs
                                                where (year = 2024 and day = 28 and month = 07) and
                                                (hour = 10 and minute > 15 and minute < 25)))
                        and year = 2024 and day = 28 and month = 07 and atm_location like "%Leggett%"
    ))

select withdrawals_suspects.*, people.* from withdrawals_suspects
join bank_accounts on withdrawals_suspects.account_number = bank_accounts.account_number
join people on bank_accounts.person_id = people.id)

select * from suspects
join phone_calls on phone_calls.caller = suspects.phone_number
where phone_calls.year = 2024 and phone_calls.day = 28 and phone_calls.month = 07 and duration < 60

)

select accomplices.name as suspect, people.*
from accomplices
join people on people.phone_number = accomplices.receiver;

-- Bruce|864400|Robin|(375) 555-8161||4V16VO0
-- Diana|847116|Philip|(725) 555-3243|3391710505|GW362R6

with accomplices as
(
  with suspects as
(with withdrawals_suspects as
    (select *
    from atm_transactions
    where account_number in (
      select account_number
    from bank_accounts
    where person_id in (select id
                        from people
                        where license_plate in (select license_plate
                                                from bakery_security_logs
                                                where (year = 2024 and day = 28 and month = 07) and
                                                (hour = 10 and minute > 15 and minute < 25)))
                        and year = 2024 and day = 28 and month = 07 and atm_location like "%Leggett%"
    ))

select withdrawals_suspects.*, people.* from withdrawals_suspects
join bank_accounts on withdrawals_suspects.account_number = bank_accounts.account_number
join people on bank_accounts.person_id = people.id)

select * from suspects
join phone_calls on phone_calls.caller = suspects.phone_number
where phone_calls.year = 2024 and phone_calls.day = 28 and phone_calls.month = 07 and duration < 60

)

select passengers.*, accomplices.name as suspect
from accomplices
join people on people.phone_number = accomplices.receiver
join passengers on passengers.passport_number = accomplices.passport_number
where passengers.flight_id = (
                              select id from flights
                              where year = 2024 and day = 29 and month = 07
                              order by hour
                              limit 1
                              );
-- 36|5773159633|4A|Bruce


-- Understanding motive?

select * from interviews where name like '%bruce%';
-- 139|Bruce|2024|7|2|“We are close there now,” my friend remarked. “This fellow Merryweather is a bank director, and personally interested in the matter. I thought it as well to have Jones with us also. He is not a bad fellow, though an absolute imbecile in his profession. He has one positive virtue. He is as brave as a bulldog and as tenacious as a lobster if he gets his claws upon anyone. Here we are, and they are waiting for us.”

select * from interviews where name like '%robin%';
-- Nothing
