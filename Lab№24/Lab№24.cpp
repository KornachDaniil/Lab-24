#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

template<typename T>
class Plenty
{
private:
	size_t size;
	std::vector<T> plenty;

public:
	Plenty()
	{
		size = 0;
	}

	void insert(T number)
	{	
		if(size == 0)
		{
			plenty.push_back(number);
			size++;
		}

		if (coincidence(number) != false) 
		{
			plenty.push_back(number);
			size++;
			if (size > 1)
				sort(plenty.begin(), plenty.end());
		}
	}

	~Plenty()
	{// Деструктор 
		std::cout << "\nPlenty\n";
	}

	bool coincidence(T& number)
	{
		for (int i = 0; i < size; i++) 
		{
			if (plenty[i] == number)
				return false;
		}
	}

	T Get_size()
	{
		return size;
	}

	const T& operator [] (int& index)
	{//  Перегрузка оператора []
		return plenty[index];
	}

	void print()
	{
		for (auto x : plenty)
		{
			std::cout << x << ' ';
		}
	}
};

class Money
{

};

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	Plenty <int> plenty_first;
	std::cout << "Первое множество: ";
	for (int i = 0; i < 2 + rand() % 8; i++)
	{
		plenty_first.insert(rand() % 20);
	}
	plenty_first.print();
	std::cout << "\nSize: " << plenty_first.Get_size() << std::endl << std::endl; // Debug
	
	Plenty <int> plenty_second;
	std::cout << "Второе множество: ";
	for (int i = 0; i < 2 + rand() % 8; i++)
	{
		plenty_second.insert(rand() % 20);
	}
	plenty_second.print();
	std::cout << "\nSize: " << plenty_second.Get_size() << std::endl;

	int n = rand() % plenty_first.Get_size();
	std::cout << "\nplenty_first[n]: " << plenty_first[n] << std::endl;

	return 0;
}