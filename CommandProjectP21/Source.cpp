#include<iostream>
#include<Windows.h>
#include<io.h>
using namespace std;

char theme[20];

void ShowQestion()
{
	cout << theme;
}

void Select_Theme()
{
	_finddata_t fileinfo;
	intptr_t ptr;
	int res = 0;

	if ((ptr = _findfirst("Questions\\*.txt", &fileinfo)) != -1)
	{
		while (!res)
		{
			cout << fileinfo.name << endl;
			res = _findnext(ptr, &fileinfo);
		}
	}
	_findclose(ptr);

	cout << endl;

	cout << "Выберите тему" << endl;

	cin >> theme;

	ShowQestion();

}

void Viktorina()
{
	setlocale(LC_ALL, "ru");

	cout << "Viktorina" << endl;
	
	Select_Theme();
}


int main()
{
	Viktorina();
}