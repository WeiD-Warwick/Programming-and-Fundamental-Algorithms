#include "Class2.h"
#include <iostream>

// Functions
// 1. Write a function to return the area of a rectangle.
void Class2::AreaOfRectangle() {
	float length, width;
	std::cout << "Enter the length and width of the rectangle: ";
	std::cin >> length >> width;
	if (length <= 0 || width <= 0) {
		std::cout << "Error: Length and width must be positive numbers!" << std::endl;
		return;
	}
	float area = length * width;
	std::cout << "The area of the rectangle is: " << area << std::endl;
}

// 2. Create a function which returns the BMI for an input height and weight as conducted in Worksheet 1. This is computed as  weight / height2 in metric units(kg / m2). 
// Let the user enter name, height and weight.Check that height and weight are sensible.
// Output the BMI.
void Class2::CalculateBMI() {
	std::string name;
	float height, weight;
	std::cout << "Enter your name: ";
	std::cin >> name;
	std::cout << "Enter your height(m): ";
	std::cin >> height;
	std::cout << "Enter your weight in Kgs: ";
	std::cin >> weight;
	if (height <= 0 || weight <= 0) {
		std::cout << "Error: Height and weight must be positive numbers!" << std::endl;
		return;
	}
	float bmi = weight / (height * height);
	std::cout << name << ", your BMI is: " << bmi << std::endl;
}

// 3. Write a function that tests whether a value is even or not.Use it to test whether the values of an array of random integers are even and output the result even or odd next to each element.
bool Class2::isEven(int value) {
	return value % 2 == 0;
}

// 4. Write a function that swaps two integers around.
void Class2::SwapIntNumber(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

// 5. Create a templated function max(T1, T2) that returns the maximum of two input variables.Use the templated swap as guidance.


// Maths Quiz
// Create a system whereby N questions are provided to a user and the score of correct answers is kept.This is targetted at children so use sensible numbers.
// The questions take the form of X + Y for X, Y integers in[0, 100) randomly chosen.
void Class2::MathsQuiz1(int n) {
	std::srand(time(0));
	int score = 0;

	for (int i = 0; i < n; i++) {
		int x = rand() % 100;
		int y = rand() % 100;
		int result = x + y;
		int userAnswer;

		std::cout << "Question " << i + 1 << ": " << x << " + " << y << "= ? ";
		std::cin >> userAnswer;
		if (userAnswer == result) {
			score++;
			std::cout << "Correct!" << std::endl;
		} else {
			std::cout << "Incorrect! The correct answer is " << result << "." << std::endl;
		}
	}

	std::cout << "Your total score is: " << score << " / " << n << "." << std::endl;
	
}

// 2. Extend this to include - , *, / , %, power.Use sensible variations of random numbers for each.For example, with / make sure the answer is an integer.
void Class2::MathsQuiz2(int n) {
	std::srand(time(0));
	int score = 0;
	char operators[] = {'+', '-', '*', '/', '%', '^'};
	for (int i = 0; i < n; i++) {
		int x = rand() % 100;
		int y = rand() % 100;
		char op = operators[rand() % 6];
		int result;
		switch (op) {
			case '+': result = x + y; break;
			case '-': result = x - y; break;
			case '*': result = x * y; break;
			case '/': 
				while (y == 0 || x % y != 0) y = rand() % 100;
				result = x / y; 
				break;
			case '%': 
				while (y == 0) y = rand() % 100;
				result = x % y; 
				break;
			case '^': 
				y = rand() % 5;
				result = pow(x, y); 
				break;
		}
		int userAnswer;
		std::cout << "Question " << i + 1 << ": " << x << " " << op << " " << y << "= ? ";
		std::cin >> userAnswer;
		if (userAnswer == result) {
			score++;
			std::cout << "Correct!" << std::endl;
		} else {
			std::cout << "Incorrect! The correct answer is " << result << "." << std::endl;
		}
	}
	std::cout << "Your total score is: " << score << " / " << n << "." << std::endl;
	
}

// Vector

// Create a 3 dimensional vector(x, y, z) structure / class and provide functionality for :

// 1. Vector Sum

// 2. Scalar multiplication

// 3. Dot product.

// 4. Output.

// Arrays 1D

// 1. Write a program that creates an array, length 10, and initialises the values of this array.
// Use integers as the data type for now.For now, initialise the array with the same value of the index.
// For example n[0] = 0, n[1] = 1 etc.Write a function displayArray() that displays the contents of this array.
// Note: The length of the array should be passed as a variable to this function so that the size can be changed whenever required without changing the code.
void Class2::InitArray() {
	const int size = 10;
	int arr[size];
	for (int i = 0; i < size; i++) {
		arr[i] = i;
	}
	this -> DisplayArray(arr, size);
	return;
}

void Class2::DisplayArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	return;
}


// 2. Write a function to reverse the order of the array by creating a new array and 
// placing the reversed contents in it and subsequently copying to the original array. (Note : for now use a fixed size, we will revisit this with dynamic memory later).
void Class2::ReverseArray(int arr[], int size) {
	int* newArr = new int[size];
	for (int i = 0; i < size; i++) {
		newArr[i] = arr[size - 1 - i];
	}
	return;
}


// 3. Supplement this code by adding behaviour that randomises your array element order.
// Use the Fisher - Yates algorithm to accomplish this.Create a function shuffleArray() to handle this.
void Class2::ShuffleArray(int arr[], int size) {
	for (int i = size - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		SwapIntNumber(arr[i], arr[j]);
	}
	return;
}

// 4. Add a function to create random values in the array for 0...999, 
// use rand() % 1000 as an assignment to each element to achieve this.
void Class2::RandomizeArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 1000;
	}
	return;
}

// 5. Find the maximum value of any given input array and print this to console.
// Create this as a function that takes the size of the array and the array itself as input.
// Call this findMaxArray() which returns the maximum value.
int Class2::FindMaxArray(int arr[], int size) {
	if (size <= 0) return -1;
	int maxVal = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > maxVal) {
			maxVal = arr[i];
		}
	}
	return maxVal;
}

// 6. Create a function findMaxArrayIndex() which finds the maximum array as in 4 but returns the index to it rather than the actual value itself.
// How can you accomplish both 4 and 5 with one function ?
int Class2::FindMaxArrayIndex(int arr[], int size) {
	if (size <= 0) return -1;
	int maxIndex = 0;
	for (int i = 1; i < size; i++) {
		if (arr[i] > arr[maxIndex]) {
			maxIndex = i;
		}
	}
	return maxIndex;
}

// 7. Based on the above find the index of the maximum of an array of size N, 
// swap this element with the last element in the array, then find the max of the array of size N - 1. 
// Continue doing this until only 1 element is left in the array.
// Display the contents of the array at this stage.What has happened to the array ?
void Class2::SortArray(int arr[], int size) {
	for (int i = size; i > 1; i--) {
		int maxIndex = this -> FindMaxArrayIndex(arr, i);
		SwapIntNumber(arr[maxIndex], arr[i - 1]);
	}
	this->DisplayArray(arr, size);
	return;
}

// *8. Test how the change in array size effects the time taken to find the max value(for both 4 and 6).
