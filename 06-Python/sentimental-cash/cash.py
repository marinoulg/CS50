from cs50 import get_float

# do-while loop
while True:
    money = get_float("Change: ")
    if money > 0:
        break

money_in_cents = money * 100

pieces = [25, 10, 5, 1]

nb_of_25 = money_in_cents // 25
nb_of_10 = (money_in_cents - nb_of_25*25) // 10
nb_of_5 = (money_in_cents - nb_of_25*25 - nb_of_10*10) // 5
nb_of_1 = (money_in_cents - nb_of_25*25 - nb_of_10*10 - nb_of_5 * 5)

print(int(nb_of_25+nb_of_10+nb_of_5+nb_of_1))
