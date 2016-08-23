#include <bits/stdc++.h>

using namespace std;
 
#define MAX_CHARS 200000
#define ALPHABET_SIZE 26
 
struct State
{
    int len;
    int link;
    int next[ALPHABET_SIZE];
};
 
class SuffixAutomata
{
    State *m_state;
    int m_stateCount;
    int m_last;
 
public:
    SuffixAutomata(unsigned int maxStates);
    void extend(int sym);
    void reset();
    int64_t substringCount() const;
};
 
 
SuffixAutomata::SuffixAutomata(unsigned int maxStates)
{
    m_state = new State[maxStates];
    reset();
}
 
void SuffixAutomata::extend(int sym)
{
    int cur = m_stateCount++;
    m_state[cur].len = m_state[m_last].len+1;
    memset(m_state[cur].next,0,sizeof(int)*ALPHABET_SIZE);
 
    int p;
    for(p = m_last; p != -1 && m_state[p].next[sym] == 0; p = m_state[p].link) {
        m_state[p].next[sym] = cur;
    }
 
    if(p == -1) {
        m_state[cur].link = 0;
    }
    else {
        int q = m_state[p].next[sym];
        if(m_state[p].len + 1 == m_state[q].len)
            m_state[cur].link = q;
        else {
            int clone = m_stateCount++;
            m_state[clone].len = m_state[p].len + 1;
            memcpy(m_state[clone].next,m_state[q].next,sizeof(int)*ALPHABET_SIZE);
            m_state[clone].link = m_state[q].link;
 
            for(; p != -1 && m_state[p].next[sym] == q; p = m_state[p].link) {
                m_state[p].next[sym] = clone;
            }
 
            m_state[q].link = m_state[cur].link = clone;
        }
    }
 
    m_last = cur;
}
 
 
int64_t SuffixAutomata::substringCount() const
{
    int64_t count = 0;
    int stateCount = m_stateCount;
    for(int i = 1; i < stateCount; ++i) {
        count += m_state[i].len - m_state[m_state[i].link].len;
    }
    return count;
}
 
void SuffixAutomata::reset()
{
    m_state[0].len = 0;
    m_state[0].link = -1;
    memset(m_state[0].next,0,sizeof(int)*ALPHABET_SIZE);
    m_stateCount = 1;
    m_last = 0;
}
 
int main(int argc, char *argv[]) {
 
    char input[MAX_CHARS+1];
    int64_t substrCount;
 
    SuffixAutomata sa(MAX_CHARS*2);
     
    while(scanf("%s",input) != EOF) 
    {
    	getchar();
        const char *p = input;
        substrCount = 0;
        
        while(*p) {
            if(*p >= 'a' && *p <= 'z') {
                int sym = (int)(*p - 'a');
                sa.extend(sym);
                substrCount += sa.substringCount();
            }
            else if(*p == '?') { 
                printf("%llu\n",substrCount);
            }
            ++p;
        }
 
        sa.reset();
    }
    return 0;
}
