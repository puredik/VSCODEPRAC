#include <stdio.h>
#include <windows.h>

typedef struct Ledger_Record{
    int date;
    int debit_or_credit;
    char* name;
    int amount;
}Ledger_Record;
typedef struct Ledger{
    int debit_record_size;
    int credit_record_size;
    char* accountName;
    Ledger_Record* debit_records;
    Ledger_Record* credit_records;   
}Ledger;
int printJournal();
int scanJournal();
typedef struct JournalEntry{
    int date;
    char* particular1;
    char* particular2;
    int d_value;
    int c_value;
}JournalEntry;
int printTotalJournal(JournalEntry *journal, int n);
char name_buffer1[10];
char name_buffer2[10];

int main(){

Ledger* ledgers;
Ledger ledger;
Ledger_Record ledger_record;
char name1[10];
char name2[10];
int amount1=0;
int amount2=1;
int choice;
JournalEntry journalEntry[10]={};
int journal_counter=0;
int i=0;
int journal_len=5;
int end_program=0;
while(end_program!=1){


printf("\n1.Journal\t2.Ledger\t3.TrialBalance\t4.Profit&Loss\n");
printf("Enter Your Action-------------------------------------:");
scanf("%d",&choice);
switch(choice){
    case 1:
            printf("Dr___ $____ ,Cr___ $____\n");
            scanJournal(name1,name2,&amount1,&amount2);
            if(amount1!=amount2)
            {printf("BOTH VALUE SHOULD BE SAME\n");break;}
            journalEntry[journal_counter]=(JournalEntry){.date=journal_counter,.d_value=amount1,.c_value=amount2,.particular1=name1,.particular2=name2};
            journal_counter++;
            break;
    case 2:
            
            ledgers = (Ledger*) malloc(sizeof(Ledger)*5);

            ledgers[0].debit_records= (Ledger_Record*)malloc(sizeof(Ledger_Record)*5);
            ledgers[0].accountName=journalEntry[0].particular1;
            ledger_record.debit_or_credit=0;
            ledger_record.name=journalEntry[0].particular2;
            ledger_record.amount=journalEntry[0].d_value;
            ledgers[0].debit_records[0]=ledger_record;

            ledgers[1].credit_records= (Ledger_Record*)malloc(sizeof(Ledger_Record)*5);
            ledgers[1].accountName = journalEntry[0].particular2;
            ledger_record.debit_or_credit=1;
            ledger_record.name=journalEntry[0].particular1;
            ledger_record.amount=journalEntry[0].c_value;
            ledgers[1].credit_records[0]=ledger_record;


            printf("DR\t\t%s A/C\t\tCR",ledgers[0].accountName);
            printf("\n-----------------------------------------\n");
            printf("To %s\t%d",ledgers[0].debit_records[0].name,ledgers[0].debit_records[0].amount);

            printf("\n\nDR\t\t%s A/C\t\tCR",ledgers[1].accountName);
            printf("\n-----------------------------------------\n");
            printf("\t\t\tBy %s\t%d",ledgers[1].credit_records[0].name,ledgers[1].credit_records[0].amount);
            break;


    default:end_program=1;
            printf("\nProgram End"); 
            break;
}
// for(i=0;i<journal_len;i++){
//     printf("\nEnter Journal:\n");   
//     printf("(Dr__)____|(Cr__)____\n");
//     scanJournal(name1,name2,&amount1,&amount2);
//     if(amount1!=amount2){
//         printf("BOTH VALUE SHOULD BE SAME\n");
//         continue;
//     }
//     journalEntry[i]=(JournalEntry){.date=0,.particular1=name1,.particular2=name2,
//                          .d_value=amount1,.c_value=amount2};   
//     printJournal(journalEntry[i]);     
// }
// printTotalJournal(journalEntry,journal_len);
}
}


int printJournal(JournalEntry journal){
printf("\n-------------------------------------------------\n");
printf("(Dr)%s :$%d \n\t\t(Cr)%s :$%d",journal.particular1,journal.d_value, 
                                journal.particular2,journal.c_value);
printf("\n");
return 1;
}

int printTotalJournal(JournalEntry *journal, int n){
int i;

printf("\n\n\nEVERY JOURNAL ENTRY");
for(i=0;i<n;i++){
printJournal(journal[i]);

}

}
int scanJournal(char* name1, char* name2, int* ptr1, int* ptr2){
    scanf("%s %d",name_buffer1,ptr1);
    memcpy(name1,name_buffer1,9);name1[9]='\0';
    scanf("%s %d",name_buffer2,ptr2);
    memcpy(name2,name_buffer2,9);name2[9]='\0';
}
//version2