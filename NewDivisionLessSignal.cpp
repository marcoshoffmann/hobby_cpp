#include <iostream>
#include <array>

using namespace std;

float divide(float x, float y)
{
	for (int i=1; i<=x; i++)
	{
		if ((i * y) < x && (i + 1) * y > x)
		{
			float result = i;
			int rest_x10 = (x - (y * i)) * 10;
			cout << y << " === " << i << endl;
			cout << rest_x10 << endl;
			for (int j=1; j<=rest_x10; j++)
			{
				if ((j * y) < rest_x10 && ((j + 1) * y) > rest_x10)
				{
					float result = i + (j * 0.1);
					return result;
				}
				else if ((j * y) == rest_x10)
				{
					float result = i + (j * 0.1);
					return result;
				}
			}
		}
		else if ((i * y) == x)
		{
			float value1 = i;
			return value1;
		}
	}
}

array<float, 2> choose_values()
{
	float first, second;
	while (true)
	{
		array<float, 2> selected;
		cout << "Por favor, digite um numero: ";
		cin >> first;
		if (!cin.fail())
		{
			selected[0] = first;
			cout << "Por favor, digite a quantidade de vezes que quer dividir o numero: ";
			cin >> second;
			if (!cin.fail())
			{
				selected[1] = second;
				if (selected[0] == 0 || selected[1] == 0)
				{
					cout << "Selecione valores diferentes de ZERO\n";
				}
				else
				{
					return selected;
				}
			}
			else
			{
				cout << "Deve selecionar um float! Opcao invalida!\n";
				cin.clear();
				cin.ignore();
				continue;
			}
		}
		else
		{
			cout << "Deve selecionar um float! Opcao invalida!\n";
			cin.clear();
			cin.ignore();
			continue;
		}
	}
}

char new_operation()
{
	char choice;
	while (true)
	{
		cout << "Deseja fazer um novo calculo? [Y/N]: ";
		cin >> choice;
		choice = toupper(choice);
		if (choice == 'Y' || choice == 'N')
		{
			return choice;
		}
		else
		{
			system("clear");
			cout << "Selecione uma opção válida!\n";
		}
	}
}

int main()
{	
	system("clear");
	char choice; 
	while (true)
	{
		array<float, 2> numbers = choose_values();
		float result = divide(numbers[0], numbers[1]);
		cout << "Resultado eh: " << result << endl;
		char _choice = new_operation();
		
		switch (_choice)
		{
			case 'Y':
				system("clear");
				continue;
			case 'N':
				cout << "Programa finalizado!\n";
				return 0;
		}
	}
}
