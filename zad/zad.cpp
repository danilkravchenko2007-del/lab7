#include <iostream>
#include <math.h>

using namespace std;

void FuncCalculate(double x)
{
	if (x <= 0 || x > 4)
	{
		cout << "X должен быть в интервале (0; 4]\n";
		return;
	}
	double step = (double)(4 - x) / 10.;
	double s = x;

	for (int i = 0; i < 10; i++)
	{
		double func = sin(s) / s;
		cout << func;
		if (i < 9) cout << ", ";
		else cout << ".";
		s += step;
	}
	cout << endl;
}
void FibonacciNumbersSum(int MAX)
{
	setlocale(LC_ALL, "Russian");
	int n = 1;
	unsigned long long a = 0; // F(1)
	unsigned long long b = 1; // F(2)
	unsigned long long s = a; // Сумма

	if (MAX <= 0)
	{
		cout << "Число MAX должно быть больше 0\n";
		return;
	}

	while (s <= MAX)
	{
		s += b;
		n++;

		unsigned long long next = a + b;
		a = b;
		b = next;
	}
	cout << "S = " << s << "\n";
	cout << "N = " << n << "\n";
}

void Credit(double sum, int period, double percent)
{
	double monthly_percent = percent / 12. / 100.;
	double payment = sum / period;
	double summa = 0;
	printf("==============================================\n");
	printf("%-4s %-10s %-10s %-10s\n", "Мес.", "Долг", "Процент", "Платеж");
	printf("==============================================\n");

	for (int i = 1; i <= period; i++)
	{
		double pr = sum * monthly_percent;
		double pay = payment;
		printf("%-4d %-10.2lf %-10.2lf %-10.2lf\n", i, sum, pr, pay + pr);
		sum -= pay;
		summa += pr;
	}

	printf("==============================================\n");
	printf("Всего процентов: %.2lf\n", summa);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	
	// Задание 1
	cout << "===== Задание 1 =====\n";
	double x;
	cout << "Введите начальную точку интервала возможных значений аргумента: ";
	cin >> x;
	FuncCalculate(x);

	// Задание 2
	cout << "===== Задание 2 =====\n";
	unsigned long long MAX;
	cout << "Введите число MAX: ";
	cin >> MAX;
	cout << endl;
	FibonacciNumbersSum(MAX);

	// Задание 3
	cout << "===== Задание 3 =====\n";
	double sum, percent;
	int period;
	//Вводим сумму
	printf("Сумма (руб.) ->");
	scanf_s("%lf", &sum);
	// Вводим срок
	printf("Срок (мес.) -> ");
	scanf_s("%d", &period);
	//Вводим процентную ставку
	printf("Процентная ставка (годовых) -> ");
	scanf_s("%lf", &percent);

	Credit(sum, period, percent);
	return 0;
}