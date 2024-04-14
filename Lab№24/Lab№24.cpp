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
	Plenty()
	{// Конструктор без параметров
		size = 0;
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

	~Plenty()
	{// Деструктор 
		std::cout << "\nPlenty\n";
	}

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
		int index = 0;
		if (size == other.Get_size())
		{
			for (int i = 0; i < size; i++)
			{
				int count = 0;
				for (int j = 0; j < size; j++)
				{
					if (plenty[i] != other[j])
						count++;
				}
				if (count == size)
					std::cout << plenty[i] << ' ';
			}
		}
		else 
		{
			std::cout << "\nРазмеры не совпадают\n";
			return -1;
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

//template<typename T>
//class Money : public Plenty
//{
//private:
//	long rubles;
//	int pennies;
//public:
//	Money()
//	{
//		rubles = 1 + rand() % 1000;
//		pennies = rand() % 100;
//	}
//
//	~Money()
//	{
//		std::cout << "\nMoney\n";
//	}
//
//	void print()
//	{
//		std::cout << rubles << "," << pennies;
//	}
//};

int main()
{
	/*srand(time(NULL));*/
	setlocale(LC_ALL, "rus");
	// 1. Создаем первый объект типа Plenty, инициализируем и выводим на экран
	Plenty <int> plenty_first;
	std::cout << "Первое множество: ";
	for (int i = 0; i < 3/*2 + rand() % 8*/; i++)
	{
		plenty_first.insert(rand() % 20);
	}
	plenty_first.print();
	std::cout << "\nSize: " << plenty_first.Get_size() << std::endl << std::endl; // Debug
	
	// 2. Создаем второй объект типа Plenty, инициализируем и выводим на экран
	Plenty <int> plenty_second;
	std::cout << "Второе множество: ";
	for (int i = 0; i < 3/*2 + rand() % 8*/; i++)
	{
		plenty_second.insert(rand() % 20);
	}
	plenty_second.print();
	std::cout << "\nSize: " << plenty_second.Get_size() << std::endl;

	// 3. Демонстрация перегрузки операции []
	int n = rand() % plenty_first.Get_size();
	std::cout << "\nplenty_first[n]: " << plenty_first[n] << std::endl;

	// 4. Демонстрация работоспособности операции "-"(разности множеств)
	std::cout << "\nРазность множества plenty_first к plenty_second: ";
	plenty_first - plenty_second;
	std::cout << std::endl;

	return 0;
}