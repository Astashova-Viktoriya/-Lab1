/*���. 1. �7 ����� ������������ ����� ��������� ��� ��������, ������� ����������� ���� ��
�����������, ���� �� ��������. ���� ������������� ������� � ������� �����������, ��
������� 0.
�������� �.*/
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

	int  **InputMatrix (int &m, int &n)
	{
		//���� �������
		int **mas;
		mas = new int*[m]; 
		for ( int i = 0; i < m; i++) 
				mas[i] = new int[n];

		return mas;
	}

	//������ �������
	void PrintMatrix (int **mas, int &m, int &n)
	{
		for (int i = 0; i < m; i++) 
		{
			for (int j = 0; j < n; j++) 
				cout << setw(3) << mas[i][j] << "  "; 
				cout << endl;
		}     
		cin.get();
	}

	//���� ��������� ������� � �������
	void InputMatrConsol (int m, int n, int **mas)
	{
		for ( int i = 0; i < m; i++)
			{ 
				for ( int j = 0; j < n; j++) 
					{ 
						cout << "������� ������� " << "[" << i << "][" << j << "]  "; 
						cin >> mas[i][j]; 
					}
			}
		cout << endl;
		PrintMatrix(mas, m, n);

	}

	void InputMatrRandom (int m, int n, int **mas)
	{
		for ( int i = 0; i < m; i++)
			{ 
				for ( int j = 0; j < n; j++) 
					{ 
						mas[i][j] = 1 + rand () % 51; //��������� ���������� ������� �� 0 �� 50 
					}
			}
		cout << endl;
		PrintMatrix(mas, m, n);
	}

	int **InputMatrFile(int &m, int &n)
	{
		char* Fname;
		int **mas;
			cout << "������� ��� �����: " << endl;
			cin >> Fname;
			ifstream file(Fname);
			//file.open(Fname);
		if (!file.is_open())
			{
				cout << "\n���� �� ������.\n";
				mas = NULL;
				return mas;
			}
		else 
		{
			if (!file.eof())   // ��������� ����������� �������
				file >> m;
			if (!file.eof())
				file >> n;

			mas = InputMatrix(m, n);// �������������� �������

			for (int i = 0; i < m; i++)
				{
					for (int j = 0; j < n; j++)
						{
							if (!file.eof())
							file >> mas[i][j];
						}
					}
			}
	file.close();
	PrintMatrix(mas, m, n);
	return mas;
	}



	int Menu ()
	{
		cout << "	**************************************************** \n";
		cout << "	*                       ����                       * \n";
		cout << "	**************************************************** \n";
		cout << "	*  1 - ������ ������� � �������                    * \n";
		cout << "	*--------------------------------------------------* \n";
		cout << "	*  2 - ��������� ������� ������������� ����������  * \n";
		cout << "	*--------------------------------------------------* \n";
		cout << "	*  3 - ��������� ������� �� �����                  * \n";
		cout << "	**************************************************** \n";
		int num;
		do {
			cin >> num;
			if ((num != 1) && (num != 2) && (num != 3))
				cout << "������ ������������ ��������. ��������� ����.\n";
		} while ((num != 1) && (num != 2) && (num != 3));

		
		getchar();
		cout << "\n"; 
		return num;
	}

void Task (int **mas, int &m, int &n)
{
	int k = 0;
	for (int j = 0; j < n; j++)
		{
			int i = 1;
			while ((i <= m-1) && (mas[i-1][j] < mas[i][j]) )// ����������
				i++;
			if (i == m) 
			cout <<"������������ ������� � "<< j+1 << " ������� " << mas[i-1][j] << endl; // �������� max �������, �.� ���������
			else 
			{ 
				i = 1;
				while ((i <= m-1) && (mas[i-1][j] > mas[i][j])) // �������
					i++;
				if (i == m) 
			cout << "������������ ������� � "<< j+1 << " ������� " << mas[0][j] << endl; //  �������� max �������, �.� ������
				else
				{
					cout << "������� " << j+1 << " ������������ " << endl;
					k++;
				}
			}
		}
		if ( k == n) 
		 cout <<  "0 - ������������� �������� ���" << endl;
		cin.get();
delete [] mas;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int **matrix; 
	int m = 0; int n = 0;

	//����� ������� ����� �������
	int number = Menu ();
	switch (number) 
		{
			case 1: 
				cout<<"������� ����������� ������� M x N"<<endl;
				cout<<"������� ���������� ����� m = ";
				cin>>m;
				cout<<"������� ���������� �������� n = ";
				cin>>n;
				matrix = InputMatrix(m, n);//�������������� �������
				InputMatrConsol(m, n, matrix); //��������� �������
				break;
			case 2: 
				cout<<"������� ����������� ������� M x N"<<endl;
				cout<<"������� ���������� ����� m = ";
				cin>>m;
				cout<<"������� ���������� �������� n = ";
				cin>>n;
				matrix = InputMatrix(m, n);//�������������� �������
				InputMatrRandom(m, n, matrix); //��������� �������
				break;
			case 3: matrix = InputMatrFile(m, n);
				break;
		}

	Task(matrix, m, n);
	system("pause");				
	return 0;
}


