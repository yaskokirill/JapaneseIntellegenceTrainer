#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>

#define MIN_NUMBER 1
#define MAX_NUMBER 9

#define ERROR_MSG "ERROR! Wrong answer (������������ �����). Try again..."

using namespace std;

int rand_number(int, int);
bool rand_operation();
int read_int(string);
string convert_to_string(long, bool);

int main() {
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	char yesno;

	do {
		system("cls");

		cout << "Exercises that you perform for just 2-5 minutes every day";
		cout << "\nhelp to actively develop your memory, thinking and attention.";

		cout << "\n\n����������, ������� �� ���������� ����� 2-5 ����� ������ ����,";
		cout << "\n������� ������� ��������� ������, �������� � ��������.\n";

		int number = read_int("\nInput number of exercise (���������� �������� ��������): ");

		cout << "\nLet's do it (������� ���)!" << endl;
		long start_time = time(NULL);
		cout << "\nSTART time (��������� �����): " + convert_to_string(start_time, true) << "\n\n";

		int error = 0;
		int count = 0;

		for (int i = 0; i < number; i++)
		{
			int a = rand_number(MIN_NUMBER, MAX_NUMBER);

			int b = rand_number(MIN_NUMBER, MAX_NUMBER);
			while (b == a) {
				b = rand_number(MIN_NUMBER, MAX_NUMBER);
			}

			int c = rand_number(MIN_NUMBER, MAX_NUMBER);
			while (c == a || c == b) {
				c = rand_number(MIN_NUMBER, MAX_NUMBER);
			}

			bool operation = rand_operation();

			if (a < b && !operation) {
				int t = a;
				a = b;
				b = t;
			}

			int result = operation ? a + b - c : a - b + c;

			if (result < 0) {
				int t = b;
				b = c;
				c = t;

				result = operation ? a + b - c : a - b + c;
			}

			string msg = to_string(i + 1) + ") ";
			msg += to_string(a);

			if (operation) {
				msg += " + " + to_string(b) + " - ";
			}
			else {
				msg += " - " + to_string(b) + " + ";
			}

			msg += to_string(c) + " = ";

			int answer;

			do {
				answer = read_int(msg);
				if (answer != result) {
					cout << ERROR_MSG << endl;
				}
			} while (answer != result);
		}

		long finish_time = time(NULL);
		cout << "\nFINISH time (�������� �����): " + convert_to_string(finish_time, true) << endl;

		cout << "\nYour TOTAL time for exercises (���� ����� �����): "
			+ convert_to_string(finish_time - start_time, false) << endl;

		cin.ignore();
		cout << "\nTry again (��������� ��� ���)? (y/n)";
		yesno = tolower(_getch());

	} while (yesno == 'y');

	system("cls");

	cout << "\nDo not forget about daily training to develop your intellect.";
	cout << "\nNo excuses!!! ";
	cout << "\n�� ��������� � ���������� ����������� ��� �������� ���� � ������ ����������.";
	cout << "\n������� ����������!!!";
	cout << "\n\nSee you (�������� ���) ... :)\n\n";

	return 0;
}