from cs50 import get_int, get_string

number = get_string("Number: ")


def check_validity(number):
    """
    Check if the card is valid.
    """

    # Creating a list of numbers
    def from_str_to_list(number):
        numbers = []
        for i in number:
            numbers.append(int(i))
        return numbers

    numbers = from_str_to_list(number)

    interm_list = []
    modulo_2 = []
    for i in range(len(numbers)):

        if len(numbers) % 2 != 0:
            if i % 2 != 0:
                interm_list.append(str(int(numbers[i])*2))
            else:
                modulo_2.append(int(numbers[i]))

        elif len(numbers) % 2 == 0:
            if i % 2 == 0:
                interm_list.append(str(int(numbers[i])*2))
            else:
                modulo_2.append(int(numbers[i]))

    interm_str = str(''.join(interm_list))
    sum_of_digits_modulo_2 = sum(from_str_to_list(interm_str))

    if (sum(modulo_2)+sum_of_digits_modulo_2) % 10 == 0:
        return ("Valid")
    else:
        return ("INVALID")


def which_card(number):
    """
    Check the type of card it is, if valid.
    """

    valid = check_validity(number)

    if valid != "INVALID":

        if len(number) == 15 and int(number[:2]) in [34, 37]:
            return "AMEX\n"

        elif len(number) == 16:
            if int(number[:2]) in [51, 52, 53, 54, 55]:
                return "MASTERCARD\n"
            elif int(number[:1]) == 4:
                return "VISA\n"

        elif len(number) == 13 and int(number[:1]) == 4:
            return "VISA\n"

    return "INVALID"


print(which_card(number))
