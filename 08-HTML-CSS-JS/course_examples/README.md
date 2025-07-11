# Implementation details

Design a webpage using ```HTML```, ```CSS```, and ```JavaScript``` to let users answer ```trivia``` questions.

- In ```index.html```, add beneath “Part 1” a multiple-choice trivia question of your choosing with ```HTML```.

  - You should use an ```h3 heading``` for the text of your question.
  - You should have one ```button``` for each of the possible answer choices. There should be at least three answer choices, of which exactly one should be correct.

- Using ```JavaScript```, add logic so that the buttons change colors when a user clicks on them.

  - If a user clicks on a button with an incorrect answer, the button should turn red and text should appear beneath the question that says “Incorrect”.

  - If a user clicks on a button with the correct answer, the button should turn green and text should appear beneath the question that says “Correct!”.
- In ```index.html```, add beneath “Part 2” a text-based free response question of your choosing with ```HTML```.
  - You should use an h3 heading for the text of your question.
  - You should use an input field to let the user type a response.
  - You should use a button to let the user confirm their answer.

- Using ```JavaScript```, add logic so that the text field changes color when a user confirms their answer.
  - If the user types an incorrect answer and presses the confirmation button, the text field should turn red and text should appear beneath the question that says “Incorrect”.
  - If the user types the correct answer and presses the confirmation button, the input field should turn green and text should appear beneath the question that says “Correct!”.

Optionally, you may also:

  - Edit ```styles.css``` to change the CSS of your webpage!
  - Add additional trivia questions to your trivia quiz if you would like!

# Walkthrough
This video was recorded when the course was still using CS50 IDE for writing code. Though the interface may look different from your codespace, the behavior of the two environments should be largely similar!


# Hints
Use document.querySelector to query for a single HTML element.
Use document.querySelectorAll to query for multiple HTML elements that match a query. The function returns an array of all matching elements.
Not sure how to solve?

# Testing
No check50 for this one, as implementations will vary based on your questions! But be sure to test both incorrect and correct responses for each of your questions to ensure that your webpage responds appropriately.

Run ```http-server``` in your terminal while in your ```trivia``` directory to start a web server that serves your webpage.

# How to Submit
```
submit50 cs50/problems/2025/x/trivia
```
Want to see the staff’s solution?
You can find two ways of solving the problem here!

1) Creating event listeners with ```JavaScript```
2) Creating event listeners with ```HTML```
