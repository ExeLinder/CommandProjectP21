#include<iostream>
#include<Windows.h>
#include<io.h>
#include<direct.h>
using namespace std;

char theme[20];
char answerFromFile[25];
char answerFromUser[25];

char** dataTheme;
int row = 0;
int questionCnt = 0;

void loadFile()
{
	dataTheme = new char* [100];

	for (size_t i = 0; i < 100; i++)
	{
		dataTheme[i] = new char[100];
	}

	FILE* fp;
	int var1 = _chdir("Questions");

	fopen_s(&fp, theme, "r");

	if (fp != NULL)
	{
		while (row < 100)
		{
			fgets(dataTheme[row], 100, fp);

			if ((dataTheme[row])[0] == '#')
			{
				break;
			}

			row++;
		}
		fclose(fp);
	}
}
void FinalResult()
{
	cout << "Результат - " << questionCnt << " - вопросов:" << endl;

	cout << endl;

	for (size_t i = 0; i < questionCnt; i++)
	{
		cout << answerFromFile[i] << " ";
	}

	cout << endl;

	for (size_t i = 0; i < questionCnt; i++)
	{
		cout << answerFromUser[i] << " ";
	}
	cout << endl;
}

void ShowQestion()
{
	for (size_t i = 0; i < row; i++)
	{
		system("cls");

		for (size_t j = 0; j < 6; j++)
		{
			if (j == 5)
			{
				answerFromFile[questionCnt] = (dataTheme[i+j])[0];

			}
			else
			{
				cout << dataTheme[i+j];
			}
		}

		i += 5;

		cout << "Введите ответ - ";

		cin >> answerFromUser[questionCnt];

		questionCnt++;

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

	cout << "Выберите тему - ";

	cin >> theme;

	loadFile();
}

void Viktorina()
{
	setlocale(LC_ALL, "ru");

	cout << "Viktorina" << endl;

	Select_Theme();

	ShowQestion();

	//FinalResult();

	for (size_t i = 0; i < 100; i++)
	{
		delete[] dataTheme[i];
	}

	delete[] dataTheme;
}


int main()
{
	Viktorina();



}