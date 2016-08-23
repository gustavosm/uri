#include <bits/stdc++.h>


using namespace std;
int main ()
{
	int cases;
	int ans[10][10];
	int i;
	int j;
	
	cin >> cases;
	while (cases > 0)
	{
		cin >> ans[0][0];
		cin >> ans[2][0] >> ans[2][2];
		cin >> ans[4][0] >> ans[4][2] >> ans[4][4];
		cin >> ans[6][0] >> ans[6][2] >> ans[6][4] >> ans[6][6];
		cin >> ans[8][0] >> ans[8][2] >> ans[8][4] >> ans[8][6] >> ans[8][8];
		
		
		ans[8][1] = (ans[6][0] - ans[8][0] - ans[8][2])/2;
		ans[7][0] = ans[8][0] + ans[8][1];
		ans[7][1] = ans[8][1] + ans[8][2];
		
		ans[8][7] = (ans[6][6] - ans[8][6] - ans[8][8])/2;
		ans[7][6] = ans[8][6] + ans[8][7];
		ans[7][7] = ans[8][7] + ans[8][8];
		
		ans[8][5] = (ans[6][4] - ans[8][4] - ans[8][6])/2;
		ans[7][4] = ans[8][4] + ans[8][5];
		ans[7][5] = ans[8][5] + ans[8][6];
		
		ans[8][3] = (ans[6][2] - ans[8][2] - ans[8][4])/2;
		ans[7][2] = ans[8][2] + ans[8][3];
		ans[7][3] = ans[8][3] + ans[8][4];
		
		
		ans[6][1] = (ans[4][0] - ans[6][0] - ans[6][2])/2;
		ans[5][0] = ans[6][0] + ans[6][1];
		ans[5][1] = ans[6][1] + ans[6][2];

		
		ans[6][5] = (ans[4][4] - ans[6][4] - ans[6][6])/2;
		ans[5][4] = ans[6][4] + ans[6][5];
		ans[5][5] = ans[6][5] + ans[6][6];
		
		ans[6][3] = (ans[4][2] - ans[6][2] - ans[6][4])/2;
		ans[5][2] = ans[6][2] + ans[6][3];
		ans[5][3] = ans[6][3] + ans[6][4];
		
		
		ans[4][1] = (ans[2][0] - ans[4][0] - ans[4][2])/2;
		ans[3][0] = ans[4][0] + ans[4][1];
		ans[3][1] = ans[4][1] + ans[4][2];
		
		ans[4][3] = (ans[2][2] - ans[4][2] - ans[4][4])/2;
		ans[3][2] = ans[4][2] + ans[4][3];
		ans[3][3] = ans[4][3] + ans[4][4];
		
		
		ans[2][1] = (ans[0][0] - ans[2][0] - ans[2][2])/2;
		ans[1][0] = ans[2][0] + ans[2][1];
		ans[1][1] = ans[2][1] + ans[2][2];
		
		for (i = 0 ; i < 9; i++)
		{
			for (j = 0 ; j <= i; j++)
			{
				cout << ans[i][j];
				if (j != i) cout << ' ';
			}
			cout << '\n';
		}
		cases--;
	}
}

