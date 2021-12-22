#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <cctype>  // библиотека для преобразования регистра текста
#include <cstdlib> //библиотека для преобразования СС

using namespace std;

//caesar_ascii - шифр цезаря по таблице аски
//registr - преобразование регистра
//sdvig - побитовый сдвиг
//konvert - конверт из dec в другие СС
//xor - this is XOR bэйбi
//BinToStr - bin to str xyli
//------------------------------------------------------------------------------
//								not main function
//------------------------------------------------------------------------------
int ascii_cod(char x)
{
	int a;
	a = x;
	return a;
}
//------------------------------------------------------------------------------
//7 - BinToStr
//done
void BinToStr(string text)
{
	int size_text = text.size();
	double a = 7;
	int num = 0;
	int *rez = new int[(size_text/8)];
	int result = 0;
	int count = 0;
    int m = 0;
	int c = 8;
	string ascii_text;
	for(int j = 0; j < (size_text/8); j++)
	{

		for(int i = m; i < c; i++)
		{
			num = 0;
			if(text[i] == '1')
			{
				num = pow(2,a);
			}
			a = a - 1;
			result = result + num;
		}
		count++;
		m = 8*count;
		c = (8*count) + 8;
		rez[j] = result;
		result = 0;
		a = 7;
		cout<<rez[j]<<" ";
		ascii_text += static_cast<char>(rez[j]);
	}
	cout<<endl;
	cout<<"Text in ASCII: "<<ascii_text;
	cout<<endl;
}
//------------------------------------------------------------------------------
//									   VOID
//------------------------------------------------------------------------------
//1 - шифр цезаря по таблице аски
//done
void caesar_ascii(string plain_text, int size)
{
	ofstream fout;
	char *result = new char[size];
	int nomer = 1;
	int a;
		cout<<"Записать в файл или вывести в консоль? (1 - файл, 2 - консоль) ";
		cin>>a;
		cout << '\b';

		if(a==2)
		{
			for(int j = 0; j < 255; j++)
			{
				cout<<"строка № "<<nomer<<" - ";
				for(int i = 0; i < size; i++)
				{
					result[i] = plain_text[i] + j;
					cout<<result[i];
				}
				nomer++;
				cout<<endl;
			}
		}
		else if(a==1)
		{
			fout.open("otchet_caesar.txt");
			for(int j = 0; j < 255; j++)
			{
				fout<<"строка № "<<nomer<<" - ";
				for(int i = 0; i < size; i++)
				{
					result[i] = plain_text[i] + j;
					fout<<result[i];
				}
				nomer++;
				fout<<endl;
			}
			fout.close();
		}
}
//------------------------------------------------------------------------------
//2 - сортировка по длине строки
//not done
void sort_on_dlina_of_string()
{
	int size;
	cout<<"Введите длину строки: ";
	cin>>size;

	ifstream fin("task.txt");
	ofstream fout;
	string str;
	char *result = new char[size];
	fout.open("otchet_sort.txt");

	while(getline (fin, str))
	{
		fout<<str<<endl;
		if(str.size() == size)
		{
			for(int i = 0; i < str.size(); i++)
			{
				result[i] = str[i];
				fout<<result[i];
			}
			fout<<endl;
		}
		fout.close();
	}

}
//------------------------------------------------------------------------------
//3 - работа с регистрами
//done
void registr(string plain_text, int size)
{
	int choice;
	char *result = new char[size];
	char character;
	cout<<"Выберите действие: "<<endl;
		cout<<"1 - СТРОЧНЫЕ -> прописные"<<endl;
		cout<<"2 - прописные -> СТРОЧНЫЕ "<<endl;
		cin>>choice;
		cout << '\b';

		if(choice == 1)
		{
			for(int i = 0; i < size; i++)
			{
				character = plain_text[i];
				cout<<(char)tolower(character);
			}
			cout<<endl;
		}
		if(choice == 2)
		{
			for(int i = 0; i < size; i++)
			{
				character = plain_text[i];
				cout<<(char)toupper(character);
			}
			cout<<endl;
		}

}
//------------------------------------------------------------------------------
//4 - побитовый сдвиг
//done
void sdvig(string plain_text, int size)
{
	int *result = new int[size];
	char massiv[100];
	int bit;
	int choice;
	cout<<"1 - сдвиг влево, 2 - сдвиг вправо: ";
	cin>>choice;
	cout<<"Введите количество битов: ";
	cin>>bit;
	if(choice == 1)
	{
		cout<<"Plain: ";
		for(int q = 0; q < size; q++)
		{
			int buffer = ascii_cod(plain_text[q]);
			cout<<buffer<<" ";
		}
		cout<<endl;
		cout<<"dec: ";
		for(int i = 0; i < size; i++)
		{
			result[i] = (plain_text[i] - 48) << bit;
			cout<<result[i]<<" ";
		}
		cout<<endl;
		cout<<"bin: ";
		for(int j = 0; j < size; j++)
		{
			itoa(result[j], massiv, 2);
			cout<<massiv<<" ";
		}
		cout<<endl;
	}
	else if(choice == 2)
	{
        cout<<"Plain: ";
		for(int q = 0; q < size; q++)
		{
			int buffer = ascii_cod(plain_text[q]);
			cout<<buffer<<" ";
		}
		cout<<endl;
		cout<<"dec: ";
		for(int i = 0; i < size; i++)
		{
			result[i] = (plain_text[i] - 48) >> bit;
			cout<<result[i]<<" ";
		}
		cout<<endl;
		cout<<"bin: ";
		for(int j = 0; j < size; j++)
		{
			itoa(result[j], massiv, 2);
			cout<<massiv<<" ";
		}
		cout<<endl;
	}

}
//------------------------------------------------------------------------------
//5 - dec2hex(oct,bin)
//done
void convert(long long int number)
{
	char massiv[100];
	int choice;
	cout<<"1 - dec2hex, 2 - dec2oct, 3 - dec2bin: ";
	cin>>choice;
	if(choice == 1)
	{
		itoa(number, massiv, 16);
		cout<<"hex: "<<massiv;
		cout<<endl;
	}
	else if(choice == 2)
	{
		itoa(number, massiv, 8);
		cout<<"oct: "<<massiv;
		cout<<endl;
	}
	else if(choice == 3)
	{
		itoa(number, massiv, 2);
		cout<<"bin: "<<massiv;
		cout<<endl;
	}
}
//------------------------------------------------------------------------------
//6 - XOR
//done
void xor(string text_one, string text_two, int size_one, int size_two)
{
	int code_one;
	int code_two;
	char mass_one[100];
	char mass_two[100];
	string result_one = "";
	string result_two = "";
	string result = "";
	int a = 1;
	for(int i = 0; i < size_one; i++)
	{
		int buffer_one = ascii_cod(text_one[i]);
		itoa(buffer_one, mass_one, 2);
		string rez_one = mass_one;
		int len_one = rez_one.size();
		if(len_one < 8)
		{
			for(int j = 0; j < (8 - len_one) + 1; j++)
			{
				rez_one = "0" + rez_one;
				len_one = rez_one.size();
			}
		}
		else if(len_one > 8)
		{
			rez_one = rez_one.erase(1, (len_one - 8));
			len_one = rez_one.size();
		}

		result_one += rez_one;
	}
	for(int i = 0; i < size_two; i++)
	{
		int buffer_two = ascii_cod(text_two[i]);
		itoa(buffer_two, mass_two, 2);
		string rez_two = mass_two;
		int len_two = rez_two.size();
		if(len_two < 8)
		{
			for(int j = 0; j < (8 - len_two) + 1; j++)
			{
				rez_two = "0" + rez_two;
				len_two = rez_two.size();
			}
		}
		else if(len_two > 8)
		{
			rez_two = rez_two.erase(1, (len_two - 8));
			len_two = rez_two.size();
		}

		result_two += rez_two;
	}
	cout<<"\nString one in bin: ";
	for(int i = 0; i < result_one.size(); i++)
	{
		cout<<result_one[i];
		if((a % 8) == 0)
		{
			cout<<" ";
		}
		a++;
	}
	a = 1;
	cout<<endl;
	cout<<"String two in bin: ";
	for(int i = 0; i < result_two.size(); i++)
	{
		cout<<result_two[i];
		if((a % 8) == 0)
		{
			cout<<" ";
		}
		a++;
	}
	a = 1;
	cout<<endl;
	int size_result_one = result_one.size();
	int size_result_two = result_two.size();
	int count = 0;
	if(size_result_one > size_result_two)
	{
		for(int i = 0; i < size_result_one; i++)
		{
			int value = count;
			count++;
			if(count > size_result_two - 1)
			{
				count = 0;
			}
			int one = result_one[i];
			int two = result_two[value];
			if(one == two)
			{
				result += '0';
			}
			else
			{
				result += '1';
			}
		}
	}
	else if(size_result_one < size_result_two)
	{
		for(int i = 0; i < size_result_two; i++)
		{
			int value = count;
			count++;
			if(count > size_result_one - 1)
			{
				count = 0;
			}
			int one = result_one[value];
			int two = result_two[i];
			if(one == two)
			{
				result += '0';
			}
			else
			{
				result += '1';
			}
		}
	}
	else if(size_result_one == size_result_two)
	{
		int size = size_result_one;
		for(int i = 0; i < size; i++)
		{
			int one = result_one[i];
			int two = result_two[i];
			if(one == two)
			{
				result += '0';
			}
			else
			{
				result += '1';
			}
		}
	}
	cout<<"--------------XOR: ";
	for(int i = 0; i < result.size(); i++)
	{
		cout<<result[i];
		if((a % 8) == 0)
		{
			cout<<" ";
		}
		a++;
	}
	cout<<endl<<"\nXOR in dec: ";
	BinToStr(result);
	cout<<endl;
}
//------------------------------------------------------------------------------
//8 - Цезарь по алфавиту
void caesar_alphabet(string str, int value)
{
	char ENG_up[26] = {65, 66, 67, 68,
					   69, 70, 71, 72,
					   73, 74, 75, 76,
					   77, 78, 79, 80,
					   81, 82, 83, 84,
					   85, 86, 87, 88,
					   89, 90};

	char ENG_low[26] = {97,  98,  99,  100,
						101, 102, 103, 104,
						105, 106, 107, 108,
						109, 110, 111, 112,
						113, 114, 115, 116,
						117, 118, 119, 120,
						121, 122};
	int size = str.size();
	char *rez = new char[size];
	for(int q = 0; q < size; q++)
	{
		if(str[q] == ' ')
		{
			rez[q] = ' ';
        }
		else if(str[q] > 64 && str[q] < 91)
		{
			for(int j = 0; j < 26; j++)
			{
				if(str[q] ==  ENG_up[j])
				{
					if(value > 25)
					{
						int common = value/26;
						if((j+value) > 25)
						{
							rez[q] = ENG_up[(j + (value - (26 * common)))];
						}
					}
					else
					{
						rez[q] = ENG_up[(j + value)];
					}
				}
			}
		}

		else if(str[q] > 96 && str[q] < 123)
		{
			for(int j = 0; j < 26; j++)
			{
				if(str[q] ==  ENG_low[j])
				{
					if(value > 25)
					{
						int common = value/26;
						if((j+value) > 25)
						{
							rez[q] = ENG_low[(j + (value - (26 * common)))];
						}
					}
					else
					{
						rez[q] = ENG_low[(j + value)];
					}
				}
			}

		}
	}
    cout<<"ANSWER: ";
	for(int i = 0; i < size; i++)
	{
		cout<<rez[i];
	}
	cout<<endl;
}
//------------------------------------------------------------------------------
//                      		MAIN
//------------------------------------------------------------------------------
int main()
{
	//Русификация
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color F0");
	system("mode con cols=120 lines=30");

	int choice;

		for(int q = 0; q < 48; q++)
		{
//			Sleep(30);
			cout<<"*";
		}
		cout<<"\n";
//		cout<<"*           Программа для CTF от Hypika        *"<<endl;
		for(int q = 0; q < 46; q++)
		{
//			Sleep(30);
			if(q == 0 || q == 45)
			{
				cout<<"*";
			}
			else if(q == 19)
			{
				cout<<static_cast<char>(210);
			}
			else if(q == 20)
			{
				cout<<static_cast<char>(243);
			}
			else if(q == 21)
			{
				cout<<static_cast<char>(235);
			}
			else if(q == 22)
			{
				cout<<static_cast<char>(231);
			}
			else if(q == 23)
			{
				cout<<static_cast<char>(224)<<" ";
			}
			else if(q == 24)
			{
				cout<<static_cast<char>(228);
			}
			else if(q == 25)
			{
				cout<<static_cast<char>(235);
			}
			else if(q == 26)
			{
				cout<<static_cast<char>(255)<<" ";
			}
			else if(q == 27)
			{
				cout<<static_cast<char>(214);
			}
			else if(q == 28)
			{
				cout<<static_cast<char>(210);
			}
			else if(q == 29)
			{
				cout<<static_cast<char>(212);
			}
			else
			{
				cout<<" ";
            }
		}
		cout<<"\n";
        for(int q = 0; q < 48; q++)
		{
//			Sleep(30);
			cout<<"*";
		}
        cout<<"\n";
		cout<<"Что нужно сделать? \nВыбери цифру:"<<endl;
		cout<<"1 - шифр цезаря по таблице аски"<<endl;
		cout<<"2 - сортировка по длине строки"<<endl;
		cout<<"3 - работа с регистрами"<<endl;
		cout<<"4 - побитовый сдвиг"<<endl;
		cout<<"5 - dec2hex(oct,bin)"<<endl;
		cout<<"6 - XOR"<<endl;
		cout<<"7 - BinToStr"<<endl;
		cout<<"8 - шифр цезаря по английскому алфавиту"<<endl;
		cout<<"q - выход"<<endl;
		cout<<"Ваш выбор - ";
		cin>>choice;
		cout << '\b';

		if(choice == 1)
		{
			string text;
			cout<<"В конце строки поставьте знак ';'"<<endl;
			cout<<"Введите текст: ";
			getline(cin, text, ';');
			int size = text.size();
			caesar_ascii(text, size);
		}
		else if(choice == 2)
		{
			sort_on_dlina_of_string();
		}
		else if(choice == 3)
		{
			string str;
			cout<<"Введите текст: ";
			cin>>str;
			int size = str.size();
			registr(str, size);
		}
		else if(choice == 4)
		{
			string str;
			cout<<"Введите текст: ";
			cin>>str;
			int size = str.size();
			sdvig(str, size);
		}
		else if(choice == 5)
		{
			long long int number;
			cout<<"Введите число: ";
			cin>>number;
			convert(number);
		}
		else if(choice == 6)
		{
			string str_one;
			string str_two;
			cout<<"\nВведите первую строку: ";
			cin>>str_one;
			cout<<"Введите вторую строку: ";
			cin>>str_two;
			int size_one = str_one.size();
			int size_two = str_two.size();
			xor(str_one, str_two, size_one, size_two);
		}
		else if(choice == 7)
		{
			string str;
			cout<<"Введите текст: ";
			cin>>str;
			BinToStr(str);
		}
		else if(choice == 8)
		{
			string str;
			int value;
			cout<<"В конце строки поставьте знак ';'"<<endl;
			cout<<"Введите строку: ";
			getline(cin, str, ';');
			cout<<"Введите значение: ";
			cin>>value;
			caesar_alphabet(str, value);
		}
		else
		{
			cout<<"Когда-нибудь я допишу код"<<endl;
		}

	system("pause");
	return 0;
}
