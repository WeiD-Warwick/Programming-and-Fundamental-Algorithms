#include <iostream>

// https://moodle.warwick.ac.uk/mod/page/view.php?id=2789970

// 1. Write a program that displays "Hello World". 
void HelloWorld() {
	std::cout << "Hello, World!" << std::endl;
}

// 2. Write a program that inputs the year and outputs it. 
void InputYear() {
	int year;
	std::cout << "Enter the year: ";
	std::cin >> year;
	std::cout << "You entered the year: " << year << std::endl;
}

// Also write a similar program that accepts your name as an input and outputs the name with a greeting.
void GreetingUser() {
	std::string name;
	std::cout << "Enter your name: ";
	std::cin >> name;
	std::cout << "Hello, " << name << "!" << std::endl;
}

// 3. Write a program that evaluates the following things for any two integers input by the user : 
// Sum, difference, product, quotient, remainder.Do the same for floats and try a sum for two input strings.
void CalculateNums() {
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
void TemperatureCovertor() {
	float f;
	std::cout << "Enter the temperature in Fahrenheit:";
	std::cin >> f;
	float c = (f - 32) * 5.0 / 9.0;
	std::cout << "Fahrenheit: " << f << " -> " << "Celsius:" << c << std::endl;
}

// 5. Do the same for pounds to kgs. 
void WeightCovertor() {
	float pounds;
	std::cout << "Enter the weight in pounds:";
	std::cin >> pounds;
	float kgs = pounds * 0.454;
	std::cout << "Pounds: " << pounds << " -> " << "kgs:" << kgs << std::endl;
}

// 6. Dice Roll: write a program to output the roll of a six sided dice. Use rand() % 6 to achieve this. 
void DiceRoll() {
	int roll = rand() % 6 + 1;
	std::cout << "Result: " << roll << std::endl;
}
 
// 7. Modify Dice Roll to output the result of a dice for which the number of sides is input by the user. 
void CustomDiceRoll() {
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
void CalculateRollsFor2D6ToGet7() {

	// randomlize
	std::srand(std::time(nullptr));

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

int main() {
	//HelloWorld();
	//InputYear();
	//GreetingUser();
	//CalculateNums();
	//TemperatureCovertor();
	//DiceRoll();
	//CustomDiceRoll();
	CalculateRollsFor2D6ToGet7();
;	return 0;
}