#include <stdio.h>
#include <windows.h>

int printJournal();
int scanJournal();
struct JournalEntry{
    int date;
    char* particular1;
    char* particular2;
    int d_value;
    int c_value;
};
char name_buffer1[10];
char name_buffer2[10];

int main(){

char name1[10];
char name2[10];
int amount1=0;
int amount2=1;

struct JournalEntry journalEntry[10]={};
int i=0;

for(i=0;i<5;i++){
    printf("\nEnter Journal:\n");   
    printf("(Dr__)____|(Cr__)____\n");
    scanJournal(name1,name2,&amount1,&amount2);
    if(amount1!=amount2){
        printf("BOTH VALUE SHOULD BE SAME\n");
        continue;
    }
    journalEntry[i]=(struct JournalEntry){.date=0,.particular1=name1,.particular2=name2,
                         .d_value=amount1,.c_value=amount2};   
    
    printJournal(journalEntry[i]);
    
}

printf("EVERY JOURNAL ENTRY");
for(i=0;i<5;i++){
printJournal(journalEntry[i]);

}
}


int printJournal(struct JournalEntry journal){
printf("\n-------------------------------------------------\n");
printf("(Dr)%s :$%d \n\t\t(Cr)%s :$%d",journal.particular1,journal.d_value, 
                                journal.particular2,journal.c_valuel);
return 0;
}
int scanJournal(char* name1, char* name2, int* ptr1, int* ptr2){
    scanf("%s %d",name_buffer1,ptr1);
    memcpy(name1,name_buffer1,9);name1[9]='\0';
    scanf("%s %d",name_buffer2,ptr2);
    memcpy(name2,name_buffer2,9);name2[9]='\0';
}