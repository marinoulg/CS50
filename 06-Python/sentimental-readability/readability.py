from cs50 import get_string
from string import ascii_letters

# print(ascii_letters)
text = get_string("Text: ")

nb_letters = 0
count_punctuation = 0

for letter in text:
    if letter in ascii_letters:
        nb_letters += 1
    elif letter in ["?", ".", "!"]:
        count_punctuation += 1

nb_words = len(text.split())

L = (nb_letters/nb_words) * 100
S = (count_punctuation/nb_words) * 100

Coleman_Liau = 0.0588 * L - 0.296 * S - 15.8

if Coleman_Liau > 15:
    print("Grade 16+")
elif Coleman_Liau < 1:
    print("Before Grade 1")
else:
    print(f"Grade: {round(Coleman_Liau)}")
