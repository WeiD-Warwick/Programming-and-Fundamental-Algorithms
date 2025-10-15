#include "Class1.h"
#include <iostream>
#include <string>

// https://moodle.warwick.ac.uk/mod/page/view.php?id=2789970

/*
*
* Basic
*
*/

// 1. Write a program that displays "Hello World". 
void Class1::HelloWorld() {
	std::cout << "Hello, World!" << std::endl;
}

// 2. Write a program that inputs the year and outputs it. 
void Class1::InputYear() {
	int year;
	std::cout << "Enter the year: ";
	std::cin >> year;
	std::cout << "You entered the year: " << year << std::endl;
}

// Also write a similar program that accepts your name as an input and outputs the name with a greeting.
void Class1::GreetingUser() {
	std::string name;
	std::cout << "Enter your name: ";
	std::cin >> name;
	std::cout << "Hello, " << name << "!" << std::endl;
}

// 3. Write a program that evaluates the following things for any two integers input by the user : 
// Sum, difference, product, quotient, remainder.Do the same for floats and try a sum for two input strings.
void Class1::CalculateNums() {
	int a, b;
	char op;
	std::cout << "Please int your formula(eg:3%2):";
	std::cin >> a >> op >> b;
	switch (op) {
	case '+':
		std::cout << "Result :" << a + b << std::endl;
		break;
	case '-':
		std::cout << "Result :" << a - b << std::endl;
		break;
	case '*':
		std::cout << "Result :" << a * b << std::endl;
		break;
	case '/':
		if (b == 0) {
			std::cout << "Error: Division by zero!" << std::endl;
			break;
		}
		std::cout << "Result :" << a / b << std::endl;
		break;
	case '%':
		std::cout << "Result :" << a % b << std::endl;
		break;
	default:
		std::cout << "Error: Invalid operator!" << std::endl;
		break;
	}
}

// 4. Write a program that converts an input temperature from F to C.The formula is C = (F - 32) / 1.8.
// Output the result by showing both the F and C.
void Class1::TemperatureCovertor() {
	float f;
	std::cout << "Enter the temperature in Fahrenheit:";
	std::cin >> f;
	float c = (f - 32) * 5.0 / 9.0;
	std::cout << "Fahrenheit: " << f << " -> " << "Celsius:" << c << std::endl;
}

// 5. Do the same for pounds to kgs. 
void Class1::WeightCovertor() {
	float pounds;
	std::cout << "Enter the weight in pounds:";
	std::cin >> pounds;
	float kgs = pounds * 0.454;
	std::cout << "Pounds: " << pounds << " -> " << "kgs:" << kgs << std::endl;
}

// 6. Dice Roll: write a program to output the roll of a six sided dice. Use rand() % 6 to achieve this. 
void Class1::DiceRoll() {
	int roll = rand() % 6 + 1;
	std::cout << "Result: " << roll << std::endl;
}

// 7. Modify Dice Roll to output the result of a dice for which the number of sides is input by the user. 
void Class1::CustomDiceRoll() {
	int sides;
	std::cout << "Enter the number of sides of the dice:";
	std::cin >> sides;
	if (sides <= 0) {
		std::cout << "Error: Invalid number of sides!" << std::endl;
		return;
	}
	int roll = rand() % sides + 1;
	std::cout << "Result: " << roll << std::endl;
}

// 8. A user is allowed to roll a pair of six sided dice 10 times. Check for how many rolls they achieve a total of 7. 
void Class1::CalculateRollsFor2D6ToGet7() {

	// randomlize
	//std::srand(std::time(nullptr));

	int count = 0;
	for (int i = 0; i < 10; i++) {
		int die1 = rand() % 6 + 1;
		int die2 = rand() % 6 + 1;
		int total = die1 + die2;
		std::cout << "Roll " << i + 1 << ": " << die1 << " + " << die2 << " = " << total << std::endl;
		if (total == 7) {
			count++;
		}
	}

	std::cout << "There are " << count << " rolls for user to achieve 7" << std::endl;
}

/*
*
* Control Structures
*
*/

// 1. Input name and age and output both.However, first check for range, 
// make sure it is sensible, between 2 and 150 would be a reasonable range.When running test for different inputs.
// What are the basic ones you should test for ?
// 0, 2, 100, 150, 200
void Class1::InputNameAndAge() {
	std::string name;
	int age;
	std::cout << "Enter your name: ";
	std::cin >> name;
	std::cout << "Enter your age: ";
	std::cin >> age;
	if (age < 2 || age > 150) {
		std::cout << "Error: Invalid age!" << std::endl;
		return;
	}
	std::cout << "Hello, " << name << "! You are " << age << " years old." << std::endl;
}

// 2. Input 3 integers from 0 to 9 from the console.
// Make sure the values are between 0 and 9. Do not permit the user to repeat the input values.
// Let the user know if they are trying to repeat or inputting something that is out of bounds.
void Class1::Check3InputIntegers() {

	int num1, num2, num3;
	std::cin >> num1 >> num2 >> num3;
	if (num1 < 0 || num1 > 9 || num2 < 0 || num2 > 9 || num3 < 0 || num3 > 9) {
		std::cout << "Error: Invalid input! Numbers must be between 0 and 9." << std::endl;
		return;
	}

	if (num1 == num2 || num1 == num3 || num2 == num3) {
		std::cout << "Error: Duplicate input! " << std::endl;
		return;
	}

	std::cout << "You entered: " << num1 << ", " << num2 << ", " << num3 << std::endl;
}

// 3. We will make a simple quiz, keep the score for the quiz and display it at the end.
// The following questions should be answered(Note : assume inputs are correct at this time - so no need for error checking) :
// Input any one of the following which is a capital city of a country(1. London, 2. Paris, 3. New York, 4. Coventry).
// In this case user has one input.Present the individual solutions on different lines.Note: user only needs to input a number.
// Name two countries which are in the EU(1. Norway, 2. Sweden, 3. Denmark, 4. France).In this case user has two inputs.
void Class1::Quiz() {
	int score = 0;
	int answer1, answer2_1, answer2_2;
	std::cout << "Question 1: Which of the following is a capital city of a country?" << std::endl;
	std::cout << "1. London" << std::endl;
	std::cout << "2. Paris" << std::endl;
	std::cout << "3. New York" << std::endl;
	std::cout << "4. Coventry" << std::endl;
	std::cout << "Your answer (input the number): ";
	std::cin >> answer1;
	if (answer1 == 2) {
		score++;
	}

	std::cout << "Question 2: Name two countries which are in the EU." << std::endl;
	std::cout << "1. Norway" << std::endl;
	std::cout << "2. Sweden" << std::endl;
	std::cout << "3. Denmark" << std::endl;
	std::cout << "4. France" << std::endl;
	std::cout << "Your answers (input two numbers separated by space): ";
	std::cin >> answer2_1 >> answer2_2;

	if ((answer2_1 == 2 || answer2_1 == 3 || answer2_1 == 4) && (answer2_2 == 2 || answer2_2 == 3 || answer2_2 == 4) && (answer2_1 != answer2_2)) {
		score += 2;
	}
	else if ((answer2_1 == 2 || answer2_1 == 3 || answer2_1 == 4) || (answer2_2 == 2 || answer2_2 == 3 || answer2_2 == 4)) {
		score++;
	}
	std::cout << "Your total score is: " << score << std::endl;
}

// 4. Output the squares and 4th power of every integer from 0 to 25. Display them on individual lines for each integer.
void Class1::SquaresFrom0to25() {
	int num = 0;
	for (int i = 0; i <= 25; i++) {
		int square = i * i;
		std::cout << i << ": Square is " << square << "; 4th power is " << square * square << std::endl;
	}
	return;
}

// 6. You will ask the user to input their birthday as a number between 0 and 31 and a month also as an integer. 
// Convert these into the format DD/M for example 14 and 2 as input becomes 14th February. 
// Note: at this stage please ignore that not all months have 31 days. 
// Use a switch statement to make the assignment from month as a number to text. 
// Note: this is not the best way to do this. We will revisit this when we do arrays. 
// If the input for the month or date is out of range just print an error and ask the user to try again. 
void Class1::BirthdayCovertor() {
	int day, month;
	std::string new_day;
	std::string new_month;
	std::cout << "Enter your birthday (eg: 12 2 mean 12th February): ";
	std::cin >> day >> month;
	if (day < 1 || day > 31 || month < 1 || month > 12) {
		std::cout << "Error: Invalid input! Day must be between 1 and 31, month must be between 1 and 12." << std::endl;
		return;
	}

	switch (day) {
	case 1: case 21: case 31:
		new_day = std::to_string(day) + "st";
		break;
	case 2: case 22:
		new_day = std::to_string(day) + "nd";
		break;
	case 3: case 23:
		new_day = std::to_string(day) + "rd";
		break;
	default:
		new_day = std::to_string(day) + "th";
	}

	switch (month) {
	case 1:
		new_month = "January";
		break;
	case 2:
		new_month = "February";
		break;
	case 3:
		new_month = "March";
		break;
	case 4:
		new_month = "April";
		break;
	case 5:
		new_month = "May";
		break;
	case 6:
		new_month = "June";
		break;
	case 7:
		new_month = "July";
		break;
	case 8:
		new_month = "August";
		break;
	case 9:
		new_month = "September";
		break;
	case 10:
		new_month = "October";
		break;
	case 11:
		new_month = "November";
		break;
	case 12:
		new_month = "December";
		break;
	}

	std::cout << "Your birthday is: " << new_day << " " << new_month << std::endl;
	return;
}


// 1. The computer generates a random number automatically between 0 and 9. Use rand() % 10 to achieve this. Ask the user to guess the number. Let the user know whether they guessed correctly or not.
// 2. Extend to keep on going until the number is guessed.Store the number of tries and output it at the end.
// 3. Extend the guess a number game to any number between 0 ... 999, but now the computer suggests whether to go up or down after each input.
void Class1::GuessNumber() {
	// randomlize
	//std::srand(std::time(nullptr));

	int number = rand() % 1000;
	int guess = -1;
	while (number != guess) {
		std::cout << "Guess the Number(0-999)!" << std::endl;
		std::cin >> guess;
		if (guess < number) {
			std::cout << "Too Low!" << std::endl;
		}
		else if (guess > number) {
			std::cout << "Too High!" << std::endl;
		}
		else {
			std::cout << "You Got It!" << std::endl;
		}
	}
	return;
}

// Modify Guess Number Game to have the computer play against itself. What is a good set of choices to get the computer (guessing part) to choose? 
void Class1::GuessNumberByPC() {
	auto generateAnswer = [](int bottom, int top) { return bottom + (top - bottom) / 2; };

	int top = 999;
	int bottom = 0;
	int number = rand() % 1000;
	int guessNum = generateAnswer(bottom, top);
	do {
		std::cout << "Guess the Number(0-999)!" << std::endl;
		int guessNum = generateAnswer(bottom, top);
		if (guessNum < number) {
			bottom = guessNum + 1;
			std::cout << "PC guess: " << guessNum << ". Too Low!" << std::endl;
		}
		else if (guessNum > number) {
			top = guessNum - 1;
			std::cout << "PC guess: " << guessNum << ". Too High!" << std::endl;
		}
		else {
			std::cout << "PC guess: " << guessNum << ". PC Got It!" << std::endl;
			break;
		}
	} while (guessNum != number);
}