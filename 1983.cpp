#include <bits/stdc++.h>


using namespace std;


int main()
{
	int stt;
	
	while (cin >> stt)
	{
		int num, aluno;
		double nota, atual;
		atual = 0.0;
		while (stt--)
		{
			cin >> num >> nota;
			
			if (nota > atual)
			{
				aluno = num;
				atual = nota;
			}
		}
		if (atual >= 8.0)
			cout << aluno << '\n';
		else cout << "Minimum note not reached\n";
	}
}
