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
	void OfString(string &st);
	double Calculate(int x, int y, int z);//вычисление в точке
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
	Return();//вернуть указатели в стартовое положение
	current = first->GetNext();//вернем указатели в исходную позцию

	while (current != first)//пока не дойдем до конца циклического списка
	{

		if (current->GetVal().coef==0)//если есть нулевой коэффициент
		{
			DeleteLink(); //удаляем старый-текущий
		}
		current = current->GetNext();//двигаем указатель на текущий
	}
}

void Polinom::OfString(string &st)//преобразование из строки в список
{	

	string s=st;//копирую входящую строку

	string num="";//строка для коэффициента
	int coef=0;//коэффициент
	int a=0;//степень
	int b=0;
	int c=0;

	int len=st.length();//вернуть длину строки
	int i=0;
	while (i!=len)//пока не дойдём до конца строки
	{
		if((s[i]=='-')&&(i==0)&&((s[i+1]=='x')||(s[i+1]=='y')||(s[i+1]=='z')))//если это первый моном с единичным отрицательным коэффициентом
		{
			num="-1";
			i++;
		}

		if((s[i]=='-')&&(i==0)&&((s[i+1] >= '0' && s[i+1] <= '9')))//если это первый моном с не единичным отрицательным коэффициентом
		{
			num+=s[i];
			i++;
		}

		if ((s[i] >= '0' && s[i] <= '9')&&(i==0))//если положительный коэффициент в первом
		{
			num+=s[i];
			i++;
		}

		if ((s[i] >= '0' && s[i] <= '9')&&(i!=0)&&(s[i-1]!='x')&&(s[i-1]!='y')&&(s[i-1]!='z'))//если коэффициент является числом
		{
			num+=s[i];
			i++;
		}

		if((s[i]=='x')&&((s[i+1] >= '0' && s[i+1] <= '9')))//если переменная х
		{	
			if ((i==0)&&(num==""))//если это первый моном с положительным единичным коэффициентом
			{
				num="1";//он станет таковым
			}

			a=atoi(&s[i+1]);//записываем степень,взятую из строки		
			if (i!=len-2)//если это не предпоследняя позиция
			{
				i+=2;//перешагиваем на следующую переменную
			}
			else//если дальше конец строки
			{
				i++;//шаг вперёд и выходим из цикла
			}
		}
		if((s[i]=='y')&&((s[i+1] >= '0' && s[i+1] <= '9')))//если переменная у
		{			
			if ((i==0)&&(num==""))
			{
				num="1";
			}
			b=atoi(&s[i+1]);
			if (i!=len-2)
			{
				i+=2;
			}
			else
			{
				i++;
			}
		}
		if((s[i]=='z')&&((s[i+1] >= '0' && s[i+1] <= '9')))//если переменная z
		{			
			if ((i==0)&&(num==""))
			{
				num="1";
			}
			c=atoi(&s[i+1]);
			if (i!=len-2)
			{
				i+=2;
			}
			else
			{
				i++;
			}
		}
		if((s[i]=='+')&&(i!=0))//если дошли до следующего монома c положительным коэффициентом
		{			
			coef=stoi(num);		//записываем числовой коэффициент из получившейся строки	
			Create(coef,a,b,c);//добавляем получившийся моном
			coef=0;
			a=b=c=0;
			if((s[i+1]=='x')||(s[i+1]=='y')||(s[i+1]=='z'))
			{
				num="1";
			}
			else
			{
				num="";
			}
			i++;
		}		
		if((s[i]=='-')&&(i!=0))//если дошли до следующего монома c отрицательным коэффициентом
		{

			coef=stoi(num);			
			Create(coef,a,b,c);
			coef=0;
			a=b=c=0;
			if((s[i+1]=='x')||(s[i+1]=='y')||(s[i+1]=='z'))
			{
				num="-1";
			}
			else
			{
				num="-";
			}			
			i++;
		}
		if(i==len-1)//если это последний моном 
		{

			coef=stoi(num);			
			Create(coef,a,b,c);
			coef=0;
			a=b=c=0;
			num="";
			i++;
		}
	}
}

string Polinom:: ToString()//преобразование из списка в строку
{
	string res;
	long double k,a,b,c;//для использования стандартной функции to_string надо использовать именно такой тип(VS2010)
	int size=GetLength();//получим текущую длину полинома
	for (int i=0; i<size;i++)
	{
		if (i!=0 && GetData(i).coef>0)//условие , когда вписать +
		{
			res +="+";
		}
		k=GetData(i).coef;//запомнить коэффициент
		if((k!=1)&&(k!=-1))
		{
			res +=(to_string(k));//добавить коэффициент ко строке
		}
		if(k==-1)
		{
			res +="-";//добавить коэффициент ко строке
		}
		a=GetData(i).degree/100;//запомнить степень
		if(a!=0)
		{
			res += "x";
			res+=(to_string(a));//добавить степень ко строке
		}

		b=GetData(i).degree/10 % 10;
		if(b!=0)
		{
			res += "y";
			res+=(to_string(b));
		}

		c=GetData(i).degree%10;
		if(c!=0)
		{
			res += "z";
			res+=(to_string(c));
		}

	}
	return res;//вернём строку
}

Polinom& Polinom::operator*(double num)//перегрузка умножения на константу
{
	current = first->GetNext();//вернем указатели в исходную позцию
	if (num == 0)//если умножаем полином на ноль
	{
		DeleteList();//удалим его весь
	}
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

double Polinom::Calculate(int x, int y, int z) 
{
	double res = 0;
	int v;
	int a, b, c, coef;

	Return();//вернуть указатели в стартовое положение
	while (current != first)//пока не дойдем до конца циклического списка
	{
		coef=current->GetVal().coef;//запишем коэффициент
		v=current->GetVal().degree;//запишем свернутую степень
		a = (int)(v / 100);
		b = (int)((v - a * 100) / 10);
		c = v - a * 100 - b * 10;
		current = current->GetNext();//перейдем в следующий моном
		res += coef*(powl(x, a)*powl(y, b)*powl(z, c));//найдем результат
	}
	return res;
};


#endif
