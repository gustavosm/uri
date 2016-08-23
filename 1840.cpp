#include <bits/stdc++.h>
 
 
using namespace std;
 
string ordem = "32AKJQ7654";
 				
string manilha[4];
int j;
struct card
{
    char op;
    char np;
     
    card() {op = '4'; np = 'D';}
    card(string s) : op(s[0]), np(s[1]) {}
     
    bool operator == (const card &other) const
    {
    	int flag = 0;
    	for (int i = 0 ; i < 4; ++i)
    	{
    		if ((op == manilha[i][0] && np == manilha[i][1]) || (other.op == manilha[i][0] && other.np == manilha[i][1]))
    		{
    			
    			flag = 1;
    			break;
    		}
    	}
    	if (!flag)
	        return op == other.op;
	    else return op == other.op && np == other.np;
    }
    bool operator < (const card &other) const
    {
        int pos1 = -1, pos2 = -1;
         
        for (int i = 0 ; i < 4; ++i)
        {
            if (this->op == manilha[i][0] && this->np == manilha[i][1]) pos1 = i;
            if (other.op == manilha[i][0] && other.np == manilha[i][1]) pos2 = i;
        }
        int t = pos1 != -1;
        int g = pos2 != -1;
         
        if (t && !g) return false;
        if (g && !t) return true;
        if (!t && !g) 
        {
            int posx1, posx2;
            for (j = 0; j < ordem.size() ; ++j)
            {
                if (this->op == ordem[j]) posx1 = j;
                if (other.op == ordem[j]) posx2 = j;
            }
            return posx1 > posx2;
        }
        else
        {
            return pos1 < pos2;
        }
    }
};
 
void add(string v)
{
    if (v[0] == '4') {manilha[0] = (("5D"));manilha[1] = (("5S"));manilha[2] = (("5H"));manilha[3] = (("5C"));}
    if (v[0] == '5') {manilha[0] = (("6D"));manilha[1] = (("6S"));manilha[2] = (("6H"));manilha[3] = (("6C"));}
    if (v[0] == '6') {manilha[0] = (("7D"));manilha[1] = (("7S"));manilha[2] = (("7H"));manilha[3] = (("7C"));}
    if (v[0] == '7') {manilha[0] = (("QD"));manilha[1] = (("QS"));manilha[2] = (("QH"));manilha[3] = (("QC"));}
    if (v[0] == 'Q') {manilha[0] = (("JD"));manilha[1] = (("JS"));manilha[2] = (("JH"));manilha[3] = (("JC"));}
    if (v[0] == 'J') {manilha[0] = (("KD"));manilha[1] = (("KS"));manilha[2] = (("KH"));manilha[3] = (("KC"));}
    if (v[0] == 'K') {manilha[0] = (("AD"));manilha[1] = (("AS"));manilha[2] = (("AH"));manilha[3] = (("AC"));}
    if (v[0] == 'A') {manilha[0] = (("2D"));manilha[1] = (("2S"));manilha[2] = (("2H"));manilha[3] = (("2C"));}
    if (v[0] == '2') {manilha[0] = (("3D"));manilha[1] = (("3S"));manilha[2] = (("3H"));manilha[3] = (("3C"));}
    if (v[0] == '3') {manilha[0] = (("4D"));manilha[1] = (("4S"));manilha[2] = (("4H"));manilha[3] = (("4C"));}
}
int main()
{
    string vira;
    int n;
    string s[4];
    int v[4] = {0};
    int vencedor[4] = {0};
    card play[4];
    while (cin >> n >> vira)
    {
        add(vira);
        for (int i = 0 ; i < 4; ++i) v[i] = vencedor[i] = 0;
         
        for (int i = 0 ; i < 4; ++i)
        {
            cin >> s[i] >> v[i];
        }
         
        while (n--)
        {
            for (int i = 0 ; i < 4; ++i)
                cin >> play[i].op >> play[i].np;
            card aux = play[0];
             
            for (int i = 1; i < 4; ++i)
            	if (aux < play[i]) aux = play[i];
            
            	
			int cnt = 0;    
			int pos = -1;            
            for (int i = 0; i < 4; ++i)
            {
                if (aux == play[i])
                {
       			    ++cnt;
       			    pos = i;     
                }
            }
            if (cnt == 1) ++vencedor[pos];
        }
         
        int menor = INT_MAX;
        int alerta;
        int pos;
        for (int i = 0 ; i < 4; ++i)
        {
            if (menor > abs(v[i] - vencedor[i]))
            {
                pos = i;
                alerta = 0;
                menor = abs(v[i] - vencedor[i]);
            }
            else if (menor == abs(v[i] - vencedor[i])) alerta = 1;
        }
        if (!alerta)
       		cout << s[pos] << '\n';
        else cout << "*\n";
         
    }   
}
