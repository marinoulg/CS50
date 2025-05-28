import csv
import sys


def main():

    # TODO: Check for command-line usage
    try:
        if len(sys.argv) == 3:
            pass
    except IndexError:
        print("Error message.")

    # TODO: Read database file into a variable
    csv = sys.argv[1]  # databases/small.csv
    sequence = sys.argv[2]  # sequences/1.txt

    lines = []
    with open(csv) as file:
        lines += file.readlines()

    persons = []
    for i in range(1, len(lines)):
        my_dict = {}

        for key, value in zip(lines[0].split(","), lines[i].split(",")):
            if "\n" in key and value:
                my_dict[key.replace("\n", "")] = value.replace("\n", "")
            else:
                my_dict[key] = value
        persons.append(my_dict)

    # TODO: Read DNA sequence file into a variable
    with open(sequence) as seq:
        sequence = seq.readline()

    # TODO: Find longest match of each STR in DNA sequence
    dict_sequences = {}
    for subsequence in (list(persons[0].keys())[1:]):
        longest_run = longest_match(sequence, subsequence)
        dict_sequences[subsequence] = longest_run

    # TODO: Check database for matching profiles
    for person in persons:
        count = 0

        for subsequence in (list(persons[0].keys())[1:]):
            if int(person[subsequence]) == int(dict_sequences[subsequence]):
                count += 1

        if count == len((list(persons[0].keys())[1:])):
            print(person["name"])
            break
    else:
        print("No match.")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
