#include <iostream>
#include <ctime>
#include <vector>

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
		while (size == 0) {
			plenty.push_back(number);
			size++;
		}

		if (coincidence(number) != false) 
		{
			plenty.push_back(number);
			size++;
			if (size > 1)
				sort(plenty, size);
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

	void sort(std::vector<T>& plenty, size_t& size)
	{
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (plenty[j] > plenty[j + 1]) {
					T temp = plenty[j];
					plenty[j] = plenty[j + 1];
					plenty[j + 1] = temp;
				}
			}
		}
	}

	T Get_size()
	{
		return size;
	}

	//const int& operator [] (int& index)
	//{//  Перегрузка оператора []
	//	return array[index];
	//}

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
	Plenty <int> plenty;
	
	plenty.insert(10);
	plenty.insert(11);
	plenty.insert(0);
	plenty.insert(11);
	plenty.insert(10);
	plenty.insert(0);

	std::cout << plenty.Get_size() << std::endl; // Debug

	plenty.print();

	return 0;
}