#include<iostream>
#include<Windows.h>
#include<io.h>
#include<direct.h>
using namespace std;

char theme[20];

void ShowQestion()
{
	FILE* fp;
	char str[100];
	char answerFromFile;
	char answerFromUser;
	int cnt = 0;
	int var1 = _chdir("Questions");

	fopen_s(&fp, theme, "r");

	if (fp != NULL)
	{
		do
		{
			system("cls");

			for (size_t i = 0; i < 6; i++)
			{
				fgets(str, 100, fp);

				if (i==5)
				{
					answerFromFile = str[0];
					
				}
				else
				{
					cout << str;
				}
			}

			cnt++;

			cout << "Введите ответ - ";

			cin >> answerFromUser;

		} while (cnt<5);

		fclose(fp);
	}
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
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	setlocale(LC_ALL, "ru");

	cout << "Viktorina" << endl;

	Select_Theme();
}


int main()
{
	Viktorina();
}