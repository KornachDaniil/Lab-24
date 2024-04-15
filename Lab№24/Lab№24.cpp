#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

template<typename T> //Инстанцирования класса Plenty для работы с различными типами данных
class Plenty
{
private:
	size_t size;
	std::vector<T> plenty;

public:
	Plenty(size_t size = 0)
	{// Конструктор без параметров
		this->size = size;
	}

	void insert(T number)
	{// Функция для размещения чисел в множестве
		if (size == 0)
		{
			plenty.push_back(number);
			size++;
		}

		if (coincidence(number) != false)
		{
			plenty.push_back(number);
			size++;
			if (size > 1)
				sort(plenty.begin(), plenty.end()); // Сортировка в порядке возрастания
		}
	}

	~Plenty() {} // Деструктор

	bool coincidence(T& number)
	{// Функция для отслеживания: существует ли данное число в множестве
		for (int i = 0; i < size; i++)
		{
			if (plenty[i] == number)
				return false;
		}
	}

	T Get_size()
	{// Геттер для поля size
		return size;
	}

	const T& operator [] (int& index)
	{//  Перегрузка оператора []
		return plenty[index];
	}

	const T& operator - (Plenty& other)
	{//  Перегрузка оператора -
		size_t other_object_size = other.Get_size();
		int in = 0;
		int jn = 0;
		int _size = size;

		if (size > other_object_size)
			jn = size - other_object_size;

		else if (size < other.Get_size())
		{
			in = other_object_size - size;
			_size = other_object_size;
		}

		for (int i = 0; i < _size - in; i++)
		{
			int count = 0;
			for (int j = 0; j < _size - jn; j++)
			{
				if (plenty[i] != other[j])
					count++;
			}
			if (count == _size - jn)
				std::cout << plenty[i] << ' ';
		}
		
		return 0;
	}

	void print()
	{// Вывод 
		for (auto x : plenty)
		{
			std::cout << x << ' ';
		}
	}
};

template<typename T>
class Money : public Plenty <T>
{
private:
	long rubles;
	int pennies;
public:
	Money()
	{// Конструктор без параметров
		rubles = 1 + rand() % 1000;
		pennies = rand() % 100;
	}

	~Money() {} // Деструктор

	T Get_rubles()
	{//  Геттер поля rubles
		return rubles;
	}

	void print()
	{// Функция вывода полей класса Money
		std::cout << rubles << "," << pennies;
	}
};

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	// 1. Создаем первый объект типа Plenty, инициализируем и выводим на экран
	Plenty <int> plenty_first;
	std::cout << "Первое множество: ";
	for (int i = 0; i < 2 + rand() % 8; i++)
	{
		plenty_first.insert(rand() % 20);
	}
	plenty_first.print();
	std::cout << "\nSize: " << plenty_first.Get_size() << std::endl << std::endl; // Debug
	
	// 2. Создаем второй объект типа Plenty, инициализируем и выводим на экран
	Plenty <int> plenty_second;
	std::cout << "Второе множество: ";
	for (int i = 0; i < 2 + rand() % 8; i++)
	{
		plenty_second.insert(rand() % 20);
	}
	plenty_second.print();
	std::cout << "\nSize: " << plenty_second.Get_size() << std::endl;

	// 3. Демонстрация работоспособности операции "-"(разности множеств)
	std::cout << "\nРазность множества plenty_first к plenty_second: ";
	plenty_first - plenty_second;
	std::cout << std::endl;

	// 4. Демонстрация перегрузки операции []
	int n = rand() % plenty_first.Get_size();
	std::cout << "\nplenty_first[" << n << "]: " << plenty_first[n] << std::endl << std::endl;

	// 5.Демонстрация выполнения операция для контейнера, содержащий элементы пользовательского класса
	std::cout << "Демонстрация выполнения операция для контейнера, содержащий элементы пользовательского класса: \n";
	//5.1 Cоздаем 4 объекта типа Money и инициализируем
	Money <int> money_1;
	Money <int> money__1;
	Money <int> money_2;
	Money <int> money__2;
	
	//5.2 Создаем объект plenty_third типа Plenty и инициализируем его
	Plenty <int> plenty_third;
	plenty_third.insert(money_1.Get_rubles());
	plenty_third.insert(money__1.Get_rubles());
	std::cout << "plenty_third: ";
	plenty_third.print();
	//5.3 Создаем объект plenty_four типа Plenty и инициализируем его
	Plenty <int> plenty_four;
	plenty_four.insert(money_2.Get_rubles());
	plenty_four.insert(money__2.Get_rubles());
	std::cout << "\nplenty_four: ";
	plenty_four.print();

	//5.4 Демонстриурем операцию "-"
	std::cout << "\nРазность: ";
	plenty_third - plenty_four;
	std::cout << std::endl << "Демонстрация корректного вывода через запятую: ";
	money_1.print();
	std::cout << std::endl;

	return 0;
}