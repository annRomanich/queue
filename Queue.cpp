// Тренировочный файл С++. Создание класса - очереди символов (некольцевой).
// Романова Анна, 15.12.2022.


#include <iostream>

using namespace std;

const int maxQsize = 100;	// максимальное число элементов в массиве очереди

class Queue
{
	char q[maxQsize];	// массив для хранения очереди
    int size; 		  	// фактическое число элементов, которое может находиться в очереди
    int putloc, getloc;	// индексы "положить" (последнего сохранённого элемента) и "взять"


public:
	// скопируем очередь заданной длины
	Queue(int len)
	{
		// размер очереди должен быть меньше maxQsize и больше 0
		if(len > maxQsize)
			len = maxQsize;
		else if (len <= 0)
			len = 1;

		size = len;
		putloc = getloc = 0;
	}
	
	~Queue(){};

	// поместим символ в очередь
	void put(char ch)
	{
		// проверка, не заполнена ли очередь
		if(putloc == size)	
		{
			cout << "-- Queue is full.\n";
			return; 
		}
		putloc++;		// добавляем ячейку
		q[putloc] = ch;	// заносим новый элемент в ячейку
	}

	// извлечём символ из очереди
	char get()
	{
		// проверка, не пуста ли очередь
		if(getloc == putloc)
		{
			cout<< "-- Queue is empty.\n";
			return 0;
		}
		getloc++;			// извлекаем ячейцу из очереди
		return q[getloc];	// индекс ячейки с последним извлечённым элементом
	}
};

int main(int argc, char const *argv[])
{

	Queue bigQ(100);
	Queue smallQ(4);
	char ch;
	int i;

	cout<< "Using bigQ for storage Latin Alphabet. \n";

	// поместим в bigQ буквы алфавита
	for(i = 0; i < 26; i++)
		bigQ.put('A' + i);

	// извлечём и выведем на экран элементы из bigQ
	cout<< "Content bigQ:";
	for(i = 0; i < 26; i++)
	{
		ch = bigQ.get();
		if(ch != 0) 
			cout<< ch;
	}

	cout<< "\n\n";

	cout<< "Using smallQ for demonstrations errors.\n";

	for(i = 0; i < 5; i++)
	{
		cout<< "Trying to write "<< (char) ('Z' - i);
		smallQ.put('Z' - i);
		cout<< "\n";
	}
	
	cout<< "\n";

	// другая ошибка в smallQ
	cout<< "Content smallQ: ";
	for(int i = 0; i < 5; i++)
	{
		ch = smallQ.get();

		if(ch != 0) cout << ch;
	}

	cout<< "\n";

	return 0;
}

