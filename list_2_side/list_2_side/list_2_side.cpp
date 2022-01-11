#include <iostream>
struct Node				//Структура, являющаяся звеном списка
{
	int value;			// Значение x будет передаваться в список                
	Node* next;			//Указатели на адреса следующего и предыдущего элементов списка
	Node* prev;
};
class List
{
	Node* head;				//Указатели на адреса начала списка и его конца
	Node* tail;
public:
	List()
	{
		this->head = NULL;			// Инициализируем адреса как пустые
		this->tail = NULL;
	}
	void Add(int value)
	{
		Node* tmp = new Node;				//Выделение памяти под новый элемент структуры
		tmp->next = NULL;					//Указываем, что изначально по следующему адресу пусто
		tmp->value = value;					//Записываем значение в структуру
		if (head != NULL)                   //Если список не пуст
		{
			tmp->prev = tail;               //Указываем адрес на предыдущий элемент в соотв. поле
			tail->next = tmp;               //Указываем адрес следующего за хвостом элемента
			tail = tmp;                     //Меняем адрес хвоста
		}
		else								//Если список пустой
		{
			tmp->prev = NULL;               //Предыдущий элемент указывает в пустоту
			head = tail = tmp;              //Голова=Хвост=тот элемент, что сейчас добавили
		}
	}
	void Show()
	{
		Node* tmp = tail;                   //Временный указатель на адрес последнего элемента
		tmp = head;                       //Временно указываем на адрес первого элемента
		while (tmp != NULL)              //Пока не встретим пустое значение
		{
			std::cout << tmp->value << " ";        //Выводим каждое считанное значение на экран
			tmp = tmp->next;             //Смена адреса на адрес следующего элемента
		}
		std::cout << "\n";
	}
	bool isInList(int value)
	{
		bool isIn = false;
		Node* tmp = head;
		while (tmp != NULL)
		{
			if (tmp->value == value)
			{
				isIn = true;
				break;
			}
			tmp = tmp->next;
		}
		return isIn;
	}
	void removeFromList(int value)
	{
		Node* tmp = head;
		Node* fordelete;
		if (isInList(value) == true)
		{
			fordelete = tmp;
			tmp = tmp->next;
		}
		else
		{
			Show();
		}
	}
};
int main()
{
	List lst; //Объявляем переменную, тип которой есть список
	lst.Add(100); //Добавляем в список элементы
	lst.Add(200);
	lst.Add(900);
	lst.Add(888);
	lst.Show(); //Отображаем список на экране
	std::cout<<lst.isInList(900);
	std::cout << "\n";
	lst.removeFromList(888);
	lst.Show();
}
