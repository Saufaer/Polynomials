#include "Polinom.h"
int main()
{
	int count,count1,count2;
	cout<< "1)Work of two polinoms "<<endl<<"2)Work of one polinom"<<endl<<"3)Exit"<<endl;
	cin >> count;
	while (count!=3)
	{
		switch (count) 
		{

		case 1: 
			{   
				system("cls");
				cout<<"first polinom:"<<endl;
				string s;
				cin>>s;	
				Polinom p;
				p.OfString(s);

				cout<<"Second polinom:"<<endl;
				string d;
				cin>>d;
				Polinom q;
				q.OfString(d);


				cout << "1)First+Second"<<endl<<"2)First-Second"<<endl<<"3)Back"<<endl;
				cin >> count1;

				switch (count1)
				{
				case 1:
					{
						system("cls");			
						p+=q;
						string res=p.ToString();
						if (p.GetLength()==0){res="0";}	
						system("cls");
						cout<<"("<<s<<") + ("<<d<<")"<<" = "<<res<<endl<<endl;					
						break;

					}

				case 2: 
					{				
						system("cls");		
						p-=q;
						string res=p.ToString();
						if (p.GetLength()==0){res="0";}	
						system("cls");
						cout<<"("<<s<<") - ("<<d<<")"<<" = "<<res<<endl<<endl;								
						break;
					}

				case 3:
					system("cls");

				}

				cout<< "1)Work of two polinoms "<<endl<<"2)Work of one polinom"<<endl<<"3)Exit"<<endl;
				cin >> count;
				break;	
			}

		case 2:
			{
				system("cls");
				cout << "1)Multiply by the number"<<endl<<"2)Calculate in point"<<endl<<"3)Back"<<endl;
				cin >> count2;
				switch (count2)
				{
				case 1:
					{
						system("cls");
						cout<<"polinom: "<<endl;
						string s;
						cin>>s;	
						Polinom p;
						p.OfString(s);
						cout<<"coefficient: "<<endl;
						double c;
						cin>>c;
						p*c;
						string res=p.ToString();
						if (p.GetLength()==0){res="0";}
						system("cls");
						cout<<"("<<s<<") * ("<<c<<")"<<" = "<<res<<endl<<endl;
						break;	
					}
				case 2:
					{
						system("cls");
						cout<<"polinom:"<<endl;
						string s;
						cin>>s;	
						Polinom p;
						p.OfString(s);

						int x,y,z;
						cout<<"x=";
						cin>>x;
						cout<<"y=";
						cin>>y;
						cout<<"z=";
						cin>>z;
						double res=p.Calculate(x,y,z);
						system("cls");
						cout<<"value of polinom:   "<<s<<"  in point["<<x<<","<<y<<","<<z<<"]"<<" = "<<res<<endl<<endl;			
						break;	
					}
				case 3:
					system("cls");
				}
				cout<< "1)Work of two polinoms "<<endl<<"2)Work of one polinom"<<endl<<"3)Exit"<<endl;
				cin >> count;
			}
		}
	}
	return 0;
}
