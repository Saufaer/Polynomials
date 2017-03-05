#ifndef __LIST_H__
#define __LIST_H__

#include <iostream>
#include "Link.h"

using namespace std;

template <class Type>
class List//шаблонный класс-список
{	
	int length;// Длина списка
	Link<Type>* temp;// Указатель на временное звено
public:
	Link<Type>* first;// Указатель на первое звено в списке
	Link<Type>* early;// Указатель на предыдущее звено относительно текущего	
	Link<Type>* current;// Указатель на текущее звено

	List();// Конструктор

	void Push (Type data);// Добавление звеньев в список по-убыванию (ради строительства полиномов)

	bool IsEmpty();//проверка на пустоту

	int GetLength();//вернуть длину списка

	Type GetData(int pos);//вернуть значение в заданной позиции

	void Forward();// Передвинуть указатели вперед

	void Return();// Вернуть указатели на начало

	void DeleteLink();//удалить текущее звено

	void DeleteList();//удалить список 

};

template <class Type>
List<Type>::List()// Конструктор
{   
	first=NULL;
	temp=NULL;
	current=NULL;
	early=NULL;
	length = 0;

	first = new Link<Type>();
	first->SetNext(first);//записываю указатель на первое звено

}

template <class Type>
void List<Type>::Push (Type data)// Добавление элементов
{

	temp = new Link<Type>();   //создаю новое звено
	temp->SetVal(data);//Записать значение звена из параметра 

	current = first->GetNext();     // указатель на текущее звено станет на первое звено в списке (так как идём от начала)
	early = first;    // а указатель на предыдущий станет на первый

	while (data < current->GetVal())  //пока введенное значение остается меньше ,чем в текущем звене
	{
		early = current;//указатель на предыдущий(который стоял на первом) станет на текущий                   
		current = current->GetNext(); //передвигаем текущий вперёд  
	};

	temp->SetNext(current);  //Связываем указатель на следующий нового звена с указателем на текущий элемент,
	early->SetNext(temp); //указатель на следующий от предыдущего с указателем на новый,

	early = early->GetNext();//передвигаем указатель на предыдущий на новый, чтобы указатели на предыдущий и текущий указывали на соседние звенья списка

	length++;
}

template <class Type>
bool List<Type>::IsEmpty()//проверка на пустоту
{
	if (length == 0) return true;
	return false;
}

template <class Type>
int List<Type>::GetLength()//вернуть длину списка
{
	return length;
}

template <class Type>
Type List<Type>::GetData(int pos)//вернуть значение в заданной позиции
{
	current = first->GetNext();// указатель на текущее звено станет на первое звено в списке (так как идём от начала)
	early = current; //указатель на предыдущий станет на текущий   

	for (int i = 0; i < pos; i++) 
	{
		early = current;              //указатель на предыдущий(который стоял на первом) станет на текущий            
		current = current->GetNext(); //передвигаем текущий вперёд    
	};

	return current->GetVal();//вернём то на чем остановились
}

template <class T>
void List<T>:: Forward()// Передвинуть указатели вперед
{
	early = current;
	current = current->GetNext();
};

template <class T>
void List<T>:: Return()// Вернуть указатели на начало
{
	early= first;
	current = first->GetNext();
};


template <class T>
void List<T>::DeleteLink ()//удалить текущее звено
{
	if (!IsEmpty())
	{
		early->SetNext(current->GetNext());
		delete current;

		current = early->GetNext();

		length--;
	};
}


template <class Type>
void List<Type>::DeleteList()//удалить список 
{
	current = first->GetNext();//указатель на текущее звено станет на первое звено в списке (так как идём от начала)

	while (current != first)//пока не дойдём до начала 
	{
		early = current;             //указатель на предыдущий(который стоял на первом) станет на текущий 
		current = current->GetNext();//передвигаем текущий вперёд       
		delete early;//удалим предыдущий
	};

	delete current;//удалим последний оставшийся
	length = 0;
}
#endif

