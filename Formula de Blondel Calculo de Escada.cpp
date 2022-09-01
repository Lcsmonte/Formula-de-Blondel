// Este programa leva em consideração a formula de Blondel para Calculo de Escadas;
// A Formula de Blondel se limita aos intervalos de 63 a 64;

#include <iostream>
#include <math.h>

using namespace std;

void Quote_1();
void Quote_2();
void Quote_4();
void Quote_5();
int Select();
double N_DG(double H_DG, double Altura);
void Relatorio(double Altura_Degrau, double Base_Degrau, double N_Degraus, double Altura_Escada);
const int Blondel_64 = 64;
const int Blondel_63 = 63;

int main()
{

	Quote_1();

	int choice = Select();

	if (choice == 1)

	{
		system("cls");

	//-----------------------------------------------------------------------//

		Quote_4();

		int Altura = 0;

	do {

		if (Altura != 0)
		{
			cout << "Digite um valor Valido para a altura da Escada" << endl;
		}

		cin >> Altura;

	} while (Altura < 48);

		system("cls");
		
	//-------------------------------------------------------------------------//

		Quote_5();

		double Num_DG=0;
		double Alternative_Num_DG = 0;

		int get;

		double B_DG=0;
		double Alternative_B_DG = 0;

		double H_DG=0;
		double Alternative_H_DG = 0;

		do {

			if (H_DG != 0) 
			{
				cout << "Digite um valor Valido para a altura do Degrau" << endl;
			}

			cin >> H_DG;

		} while (H_DG > 18 || H_DG < 16);

		system("cls");
	//----------------------------------------------------------------------------------//

		Num_DG = N_DG(H_DG, Altura);

		int Minus_Num_DG = round(Num_DG);
	
		if (Num_DG - Minus_Num_DG > 0 || Num_DG - Minus_Num_DG == 0)
		{
			Num_DG = Minus_Num_DG;
			Alternative_Num_DG = Num_DG + 1;
		}

		else if (Minus_Num_DG - Num_DG > 0)
		{
			Num_DG = Minus_Num_DG;
			Alternative_Num_DG = Num_DG;
			Num_DG = Num_DG - 1; // Alternativo sempre deverá ser a maior opção
		}

		H_DG = Altura / Num_DG;

		B_DG = Blondel_63 - 2 * H_DG;

		if (((2 * H_DG + B_DG) - Blondel_63) > 0.1 || ((2 * H_DG + B_DG) - Blondel_63) < -0.1)
		{
			cout << "Erro, Escada fora do Padrão";

			return 1;
		}

		if ((round(B_DG) + 2 * H_DG) >= 63 && (round(B_DG) + 2 * H_DG) <= 64)
		{
			B_DG = round(B_DG);
		}

		if (H_DG >= 16 && H_DG <= 18 && B_DG >= 28 && B_DG <= 32)
		{
			Relatorio(H_DG, B_DG, Num_DG, Altura);
		}

		else 
		{
			cout << "Primeiro relatorio cancelado por medidas fora de padrão\n\n";
		}
	//----------------------------------------------------------------------------------//

		Alternative_H_DG = Altura / Alternative_Num_DG;

		Alternative_B_DG = Blondel_64 - 2 * Alternative_H_DG;

		if (((2 * Alternative_H_DG + Alternative_B_DG) - Blondel_64) > 0.1 || ((2 * Alternative_H_DG + Alternative_B_DG) - Blondel_64) < -0.1)
		{
			cout << "Erro, Escada fora do Padrão";

			return 1;
		}

		if ((round(Alternative_B_DG) + 2 * Alternative_H_DG) >= 63 && (round(Alternative_B_DG) + 2 * Alternative_H_DG) <= 64)
		{
			Alternative_B_DG = round(Alternative_B_DG);
		}
		else if ((round(Alternative_B_DG - 0.5) + 2 * Alternative_H_DG) >= 63 && (round(Alternative_B_DG - 0.5) + 2 * Alternative_H_DG) <= 64)
		{
			Alternative_B_DG = round(Alternative_B_DG-0.5);
		}

		if (Alternative_H_DG >= 16 && Alternative_H_DG <= 18 && Alternative_B_DG >= 28 && Alternative_B_DG <= 32)
		{
			Relatorio(Alternative_H_DG, Alternative_B_DG, Alternative_Num_DG, Altura);
		}

		else

		{
			cout << "Segundo relatorio cancelado por medidas fora de padrão\n\n";
		}

		system("PAUSE");
	}
	
	//-------------------------------------------------------------------------------//
	if (choice == 2)
	{
		system("cls");

		cout << "AREA EM CONSTRUCAO\n\n";

	}


	return 0;

	}

int Select()
{
	while (true)
	{
		int set = 0;

		cin >> set;
		if (set == 1 || set == 2)
			return set;

		cout << "Digite um valor valido";
	}
}

int Blondel()
{
	Quote_2();
	int BL_value;
	cin >> BL_value;

	switch (BL_value)
	{
	case 1:
		return 63;

	case 2:
		return 64;

	default:
		cout << "Digite um valor valido";
		break;
	}

}

double N_DG(double H_DG, double Altura) 
{
	int set_value = Altura / H_DG;

	return set_value;
}

void Relatorio(double Altura_Degrau, double Base_Degrau, double N_Degraus, double Altura_Escada)
{
	cout << "|======================================|" << endl
		<< "|          Relatorio da ESCADA         |" << endl
		<< "|======================================|" << endl;
	
	cout << "Altura do Espelho: " << Altura_Degrau << endl;
	cout << "Comprimento do Piso: " << Base_Degrau << endl;
	cout << "Numero de Degraus: " << N_Degraus << endl;
	cout << "Altura da Escada: " << Altura_Escada << endl;
	cout << "\n\n\n";

}

void Quote_1()
{
	cout << "|======================================|" << endl
		<< "|Selecione qual item deseja dimensionar|" << endl
		<< "|======================================|" << endl;

	cout << "1. Escada" << endl
		<< "2. Rampa" << endl;
}

void Quote_2()
{
	cout << "|======================================|" << endl
		<< "|    Escolha o Parametro de Blondel    |" << endl
		<< "|======================================|" << endl;

	cout << "1. B + 2H = 63" << endl
		<< "2. B + 2H = 64" << endl;
}

void  Quote_4()
{
	cout << "|=====================================================|" << endl
		<< "|   Informe a altura total da escada em Centimetros   |" << endl
		<< "|=====================================================|" << endl;
}

void Quote_5()
{
	cout << "|=====================================================|" << endl
		<< "|        Informe a altura do Degrau que Deseja        |" << endl
		<< "|=====================================================|" << endl;

}


