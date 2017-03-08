#ifndef __POLINOM_H__
#define __POLINOM_H__

#include "List.h"
#include "Monom.h"
#include <string>

using namespace std;

class Polinom: public List<Monom>//наследуем от класса-список
{
public:
	Polinom();// Конструктор
	void Create(int coef,int x,int y,int z);//создание монома и запись в полином
	string ToString();//преобразовать список в строку
	Polinom& operator*(double num);// перегрузка умножения на константу
	Polinom& operator+=(Polinom &d);// перегрузка сложения
	Polinom& operator-=(Polinom &d);// перегрузка вычитания
	Polinom& operator=(Polinom &d);// перегрузка присваивания

};

Polinom::Polinom()//конструктор
{
	Monom temp(0, -1);//"нулевой" моном
	first = new Link<Monom>;
	first->SetVal(temp);//установим значение
	first->SetNext(first);//установим указатель
}

void Polinom::Create(int coef,int x,int y,int z)
{
	if (coef!=0)
	{
		Monom temp(coef, 100*x+ 10*y + z);//создаём моном
		Push(temp);//кладем в полином	

		if (current->GetVal().degree == early->GetVal().degree)//сравниваем соседние степени
		{
			Monom temp(current->GetVal().coef + early->GetVal().coef, current->GetVal().degree);//если совпадают ,то складываем коэффициенты
			Push(temp);	//кладем в полином результат
			DeleteLink(); //удаляем старый-текущий
			DeleteLink(); //удалить второй-старый,который стал текущим
		}	
	}			
}

string Polinom:: ToString()
{
	string res;
	long double k,a,b,c;//для использования стандартной функции to_string надо использовать именно такой тип
	int size=GetLength();//получим текущую длину полинома
	for (int i=0; i<size;i++)
	{
		if (i!=0 && GetData(i).coef>0)//условие , когда вписать +
		{
			res +=" +";
		}
		k=GetData(i).coef;//запомнить коэффициент
		res +=(to_string(k));//добавить коэффициент ко строке
		res += " x^";
		a=GetData(i).degree/100;//запомнить степень
		res+=(to_string(a));//добавить степень ко строке
		res += " y^";
		b=GetData(i).degree/10 % 10;
		res+=(to_string(b));
		res += " z^";	
		c=GetData(i).degree%10;
		res+=(to_string(c));
		res += " ";
	}
	return res;//вернём строку
}

Polinom& Polinom::operator*(double num)//перегрузка умножения на константу
{
	current = first->GetNext();//вернем указатели в исходную позцию
	while (current != first)//пока не дойдем до конца циклического списка
	{
		Monom temp(num*current->GetVal().coef, current->GetVal().degree);//умножим коэффициент мономов на входящий
		current->SetVal(temp);//установим значение монома
		current = current->GetNext();//следующая итерация
	};
	return *this;
}

Polinom& Polinom::operator+=(Polinom &d)//перегрузка оператора сложения полиномов
{
	Return();//вернуть указатели в стартовое положение
	d.Return();//и на прибавляемом

	while (current != first || d.current != d.first)//пока не дойдём до конца циклического списка
	{
		if (current->GetVal() < d.current->GetVal()) //если нет совпадений по степени 
		{
			Push(d.current->GetVal()); //, то дабвляем моном (по убыванию)         
			d.Forward();//движемся дальше по прибавляемому

		} 
		else 
			if (current->GetVal() == d.current->GetVal())//если степени совпадают 
			{
				Monom temp(current->GetVal().coef + d.current->GetVal().coef, current->GetVal().degree);//складываем мономы

				current->SetVal(temp);//устанаваливаем значение монома

				if (current->GetVal().coef == 0)//если в результате получился нулевой коэффициент
				{
					DeleteLink();  //удаляем его
					d.Forward();
				}
				else
				{
					d.Forward();//если всё нормально, то двигаемя дальше
					Forward();
				};
			} 
			else 
			{
				Forward();
			}
	};

	return *this;//вернём p , где p = p+d 
}

Polinom& Polinom::operator-=(Polinom &d)//перегрузка вычитания
{
	return (*this) += d*(-1);//тоже самое , только противоположное дейсвтие
}

Polinom& Polinom::operator=(Polinom &d)//перегрузка присваивания
{
	this->DeleteList();//удаляем первый

	Monom temp(0, -1);//создаем его заново
	first = new Link<Monom>;
	first->SetVal (temp);
	first->SetNext(first);

	for (int i = 0; i < d.GetLength(); i++)
	{
		Push(d.GetData(i));//перезаписываем мономы из входящего полинома
	};

	return *this;
}
#endif