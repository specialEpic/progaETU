#include <iostream>
#include <climits>

using namespace std;

int menu ();
void memorycapacity ();
void bitINT ();
void bitFLOAT ();
void bitDOUBLE ();

int main()
{
	setlocale(LC_ALL, "ru_RU.utf8");
	int i = 5;
	while (i)
	{
		int k;
		switch (i)
		{
		case 0:
			return 0;
			break;
		case 1:
			memorycapacity();
			i = 5;
			break;
		case 2:
			bitINT();
			k = menu();
			if (k == 2 || !k) i = 5;
			else i = 2;
			break;
		case 3:
			bitFLOAT();
			k = menu();
			if (k == 2 || !k) i = 5;
			else i = 3;
			break;
		case 4:
			bitDOUBLE();
			k = menu();
			if (k == 2 || !k) i = 5;
			else i = 4;
			break;
		case 5:
			cout << endl << "МЕНЮ:" << endl <<
				"1. Вывод объёма памяти в байтах, отводимого под различные типы данных" << endl <<
				"2. Вывод на экран двоичного представления в памяти целого числа" << endl <<
				"3. Вывод на экран двоичного представления в памяти типа float" << endl <<
				"4. Вывод на экран двоичного представле ния в памяти типа double" << endl << 
				"0. Выход" << endl << endl <<
				"Выберите пункт: ";
			int k;
			cin >> k;
			i = k;
			break;
		default:
			i = 5;
			break;
		}
	}
	return 0;
}

void memorycapacity ()
  {
    cout << endl <<"Под различные типы данных на этом компьютере отводится памяти в байтах:" << endl <<
            endl << "int\t\t" << sizeof (int) << 
			endl << "short int\t" << sizeof (short int) << 
			endl << "long int\t" << sizeof (long int) <<
            endl << "float\t\t" << sizeof (float) << 
			endl << "double\t\t" << sizeof (double) << 
			endl << "long double\t" << sizeof (long double) << 
			endl << "char\t\t" << sizeof (char) << 
			endl << "bool\t\t" << sizeof (bool) << endl << endl;
  }

void bitINT ()
  {
    int Int;
    int mask=(1<<((sizeof(int)*CHAR_BIT)-1));
    cout << endl << "Введите целое число: ";
    cin >> Int;
    cout << endl << "Двоичное представление в памяти введённого числа (знаковый разряд отделён пробелом):" << endl;
    cout << (Int & mask ? "1 " : "0 ");
    Int<<=1;
    for (int unsigned i=0; i<((sizeof(int)*CHAR_BIT)-1); i++)
      {
        cout << (Int & mask ? "1" : "0");
        Int<<=1;
      }
    cout << endl;
  }
  
void bitFLOAT ()
  {
    union
      {
        float Float;
		    char Char[3];
      };
    char mask=1<<7;
    int bitCount=32;
    cout << endl << "Введите вещественное число: ";
    cin >> Float;
    cout << endl << "Двоичное представление данного числа:" << endl;
    for (int i=3; i>=0; i--)
      {
        for (int j=0; j < CHAR_BIT; j++)
          {
            cout << (Char[i] & mask ? "1" : "0");
            Char[i]<<=1;
            if (bitCount==24||bitCount==32) cout << " ";
            bitCount--;
            if (!bitCount) break;
          }
        if (!bitCount) break;
      }
    cout << endl;
  }
  
void bitDOUBLE ()
  {
    union
      {
        double Double;
		    char Char[7];
      };
    char mask=1<<7;
    int bitCount=64;
    cout << endl << "Введите вещественное число: ";
    cin >> Double;
    cout << endl << "Двоичное представление данного числа:" << endl;
    for (int i=7; i>=0; i--)
      {
        for (int j=0; j < CHAR_BIT; j++)
          {
            cout << (Char[i] & mask ? "1" : "0");
            Char[i]<<=1;
            if (bitCount==53||bitCount==64) cout << " ";
            bitCount--;
            if (!bitCount) break;
          }
        if (!bitCount) break;
      }
    cout << endl;
  }

  
int menu ()
  {
    int k;
    cout << endl << "Меню:" << endl << 
		"1) Продолжить" << endl << 
		"2) Вернуться в главное меню" << endl << endl << 
		"Выберите пункт: ";
    cin >> k;
    return k;
  }
