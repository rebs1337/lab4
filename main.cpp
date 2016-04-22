#include <iostream>
#include <cmath>
#include <string>

using namespace std;
const int N = 6;

int coeffcient(int n);
void show (int n);
int length (int digit[]);
void final (int n);

int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);
	final(n);
	cout << endl << endl;
}

int coeffcient (int n)
{
	unsigned long long k = 1, total = n;
	if (n==0)
	{
		cout << "podana liczba to 0 -> brak wspolczynnika";
		return k = 0;
	}
	
	while (total > 0)
	{
		if (total % 10 == 1 || total % 10 == 0)
			total /= 10;
		else
		{
			k++;
			total = n * k;
		}
		if (k > 1000000)
		{
			cout << "wspolczynnik i suma sa za duze, nie przeczytam! ";
			return k = 0;
		}
	}
	return k;
}

void show (int n)
{
	if (n == 1000000)
	{
		cout << "milion ";
		return;
	}
	if (n == 0)
	{
		cout << "zero ";
		return;
	}
	if (n > 1000000)
	{
		cout << "*liczba za duza, nie umiem przeczytac* ";
		return;
	}
	int *digit = new int [N];
	for (int p = 0, b = 10; p < N; p++)
		digit[p] = fmod((n / (pow(b,p))), b);
	int lth = length(digit);
	string numerals[4][9] = {
		{"jeden ", "dwa ", "trzy ", "cztery ", "piec ", "szesc ", "siedem ", "osiem ", "dziewiec "},
		{"jedenascie ", "dzwanascie ", "trzynascie ", "czternascie ", "pietnascie ", "szesnascie ", "siedemnascie ", "osiemnascie ", "dziewietnascie "},
		{"dziesiec ", "dzwadziescia ", "trzydziesci ", "czterdziesci ", "piescdziesiat ", "szescdziesiat ", "siedemdziestat ", "osiemdziesiat ", "dziewiecdziesiat "},
		{"sto ","dwiescie ", "trzysta ", "czterysta ", "piecset ", "szescset ", "siedemset ", "osiemset ", "dziewiecset "}
	};
	string tysiac[3] = {"tysiac ", "tysiace ", "tysiecy "};
	
	switch (lth)
	{
		case 6:
			cout << numerals[3][(digit[5])-1];
		case 5:
			if (digit[4] > 1)
				cout << numerals[2][(digit[4])-1];
			if (digit[4] == 1 && digit[3] != 0)
				cout << numerals[1][(digit[3])-1];
			if (digit[4] == 1 && digit[3] == 0)
				cout << numerals [2][0];
		case 4:
			if (digit[3] != 0 && digit[4] != 1)
			{
				if (digit[3] == 1 && digit[4] == 0)
					cout << tysiac[0];
				else
				{
					cout << numerals[0][(digit[3])-1];
				
					if (digit[3] > 1 && digit[3] < 5)
						cout << tysiac[1];
					else
						cout << tysiac[2];
				}
			}
			else 
				cout << tysiac [2];
		case 3:
			if (digit[2] != 0)
				cout << numerals[3][(digit[2])-1];
		case 2:
			if (digit[1] > 1)
				cout << numerals[2][(digit[1])-1];
			if (digit[1] == 1 && digit[0] != 0)
			{
				cout << numerals[1][(digit[0])-1];
				break;
			}
			if (digit[1] == 1 && digit[0] == 0)
				cout << numerals[2][0];
		case 1:
			if (digit[0] != 0)
			{
				cout << numerals[0][(digit[0])-1];
				break;
			}
		}
	delete [] digit;
}

int length(int digit[])
{
	int i = N;
	for (; i >= 0 ; i--)
	{
		if (digit[i-1] != 0)
			return i;
	}
	return i;
}

void final (int n)
{
	cout << "Twoja liczba to: " << n << ", slownie: "; show(n); cout << endl;
	unsigned long long k = coeffcient(n); 
	if (k == 0)
		return;
	cout << "jej wspolczynnik to: " << k << ", czyli "; show(k);
	unsigned long long suma = coeffcient(n)*n;
	cout << "\nsuma wynosi: " << suma << " slownie: "; show(suma);
}