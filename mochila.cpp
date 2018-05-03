#include <iostream>  
#include <algorithm> 
#include <fstream>
#include <stdlib.h>
using namespace std;

int MochilaInt(int n, int M, int pesos[], int valores[])
{
    int Array[n+1][M+1]; 

   for (int i=0;i<= n;i++)  { 
       for (int j=0;j<=M;j++)   { 
           if (i==0||j==0) Array[i][j] = 0;
           else if (pesos[i-1]<=j) Array[i][j] = max(Array[i-1][j],valores[i-1] + Array[i-1][j-pesos[i-1]]);                                                                 
           else Array[i][j] = Array[i-1][j];                                                                                                 
       }
   }
return Array[n][M];
}

int main(void)
{   

	int ord[1000000];
	string teste;
	cout << "Arquivo de teste: ";
	cin >> teste;
	ifstream in(teste.c_str());
	char num[10];
	int fim = 0;
	while(!in.eof()){
		in >> num;
		ord[fim] = atoi(num);
		fim++;
	}
	
	int n = ord[0];
	int M = ord[1];
	int pesos[n];
	int valores[n];
	int count = 0;

	for (int i=2; i < 2*n+2; i = i+2)
	{
		pesos[count] = ord[i];
		valores[count] = ord[i+1];
		count++;
	}

/*    int pesos[] = {1,2,5, 6, 7, 9, 11}; //teste
    int valores[] = {1, 6, 18, 22, 28, 40, 60};

    int M = 23;
    int n = sizeof(valores)/sizeof(valores[0]);

	cin >> n >> M;
 
	for (int i=0; i < n; ++i)
	{
		cin >> pesos[i] >> valores[i];
	}*/

    cout << "Valor ótimo: " <<  MochilaInt(n,M,pesos,valores) << endl;
    return 0;
}
