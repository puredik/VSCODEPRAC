#include <stdio.h>
#include <windows.h>

int printJournal();

struct Balance{
    int d_value;
    int c_value;
};

struct JournalEntry{
    int date;
    const char* particular1;
    const char* particular2;
    int d_value;
    int c_valuel;
};

int main(){
char* name1;
char* name2;
int amount1=0;
int amount2=1;
struct Balance balance={0,0};
struct JournalEntry journalEntry[10];
int i=0;

    for (int i = 0; i < 10; i++)
    {
        journalEntry[i].date=0;
    }
    
while(1){
amount1=0;
amount2=1;
printf("\nEnter Journal:\n");
printf("(Dr__)____|(Cr__)____\n");
while(amount1!=amount2)
{
    scanf("%c%d%c%d",name1,&amount1,name2,&amount2);
    if(amount1!=amount2){
        printf("BOTH VALUE SHOULD BE SAME\n");
    }
    journalEntry[0].particular1=name1;
    journalEntry[0].particular2=name2;
    journalEntry[0].d_value=amount1;
    journalEntry[0].c_valuel=amount2;
    
}
}
}

int printJournal(struct JournalEntry journal){
printf("\nJournal:\n");
printf("(Dr)%s :$%d \n\t\t(Cr)%s :$%d",journal.particular1,journal.d_value, 
                                journal.particular2,journal.c_valuel);
return 0;
}