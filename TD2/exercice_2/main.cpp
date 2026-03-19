#include <iostream>
#include <vector>
#include <random>

typedef std::vector<int> IntegerList;

void fillNumbers(IntegerList& numbers, size_t quantity);
int generateRandomInteger();

int computeSum(const IntegerList& numbers);
int computeMin(const IntegerList& numbers);

void displayAllNumbers(const IntegerList& numbers);
void displaySum(int sum);
void displayMin(int min);
void displayEvenNumbers(const IntegerList& numbers);

int main()
{
	IntegerList numbers;

	fillNumbers(numbers, 10);

	displayAllNumbers(numbers);
	displaySum(computeSum(numbers));
	displayMin(computeMin(numbers));
	displayEvenNumbers(numbers);

	return 0;
}

void fillNumbers(IntegerList& numbers, size_t quantity)
{
	for (size_t i = 0; i <= quantity; ++i)
	{
		numbers.push_back(generateRandomInteger());
	}
}

int generateRandomInteger()
{
	std::random_device device;
	std::mt19937 randomGenerator(device());
	std::uniform_int_distribution<std::mt19937::result_type> distribution(0, 100);

	return distribution(randomGenerator);
}

int computeSum(const IntegerList& numbers)
{
	int sum = 0;
	size_t index = 0;

	for (index = 0; index < numbers.size(); ++index)
	{
		sum += numbers.at(index);
	}
	return sum;
}

int computeMin(const IntegerList& numbers)
{
	int min = numbers.at(0);

	for (size_t i = 1; i < numbers.size(); ++i)
	{
		const int& value = numbers.at(i);

		if (value < min)
		{
			min = value;
		}
	}

	return min;
}

void displayAllNumbers(const IntegerList& numbers)
{
	std::cout << "Liste des 10 nombres generes :" << std::endl;

	for (size_t i = 0; i < numbers.size(); ++i)
	{
		if (i != 0)
			std::cout << ", ";

		std::cout << numbers.at(i);
	}

	std::cout << std::endl << std::endl;
}

void displaySum(int sum)
{
	std::cout << "Somme des nombres : " << sum << std::endl << std::endl;
}

void displayMin(int min)
{
	std::cout << "Valeur minimale : " << min << std::endl << std::endl;
}

void displayEvenNumbers(const IntegerList& numbers)
{
	std::cout << "Liste des nombres pairs :" << std::endl;

	for (size_t i = 0; i < numbers.size(); ++i)
	{
		const int& value = numbers.at(i);

		if(value % 2 == 0)
			std::cout << value << ", ";
	}

	std::cout << std::endl << std::endl;
}