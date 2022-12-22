#include <stdio.h>

typedef struct Ledger_Record{
    int date;
    int debit_or_credit;//0debit 1 credit;
    char name[10];
    int amount;
}Ledger_Record;

typedef struct Ledger{
    int debit_record_size;
    int credit_record_size;
    char accountName[10];
    Ledger_Record* debit_records;
    Ledger_Record* credit_records;   
}Ledger;

int printJournal();
int scanJournal();

typedef struct JournalEntry{
    int date;
    char particular1[10];
    char particular2[10];
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
int is_particular1_account=0;
int is_particular2_account=0;
JournalEntry journalEntry[10]={};
int journal_counter=0;
int i=0;
int j=0;
int journal_len=5;
int end_program=0;
int ledgers_size=0;
ledgers = (Ledger*) malloc(sizeof(Ledger)*10);

for(i=0;i<10;i++){
    
    ledgers[i]=(Ledger){.accountName="NOTHING"};
    ledgers[i].credit_record_size=0;
    ledgers[i].debit_record_size=0;
    ledgers[i].debit_records=(Ledger_Record*)malloc(sizeof(Ledger_Record)*10);
    ledgers[i].credit_records=(Ledger_Record*)malloc(sizeof(Ledger_Record)*10);
    
    for(j=0;j<10;j++){
    ledgers[i].debit_records[j]=(Ledger_Record){.amount=0,.name="EMPTY"};
    ledgers[i].credit_records[j]=(Ledger_Record){.amount=0,.name="EMPTY"};
    }
  
}

while(end_program!=1){


printf("\n1.Journal\t2.Ledger\t\n");
printf("Enter Your Action:");
scanf("%d",&choice);
switch(choice){
    case 1:
            printf("___Dr___$___Cr___$\n");
            scanJournal(name1,name2,&amount1,&amount2);
            if(amount1!=amount2)
            {printf("BOTH VALUE SHOULD BE SAME\n");break;}
            journalEntry[journal_counter]=(JournalEntry){.date=journal_counter,.d_value=amount1,.c_value=amount2};
            memcpy(journalEntry[journal_counter].particular1,name1,10);
            memcpy(journalEntry[journal_counter].particular2,name2,10);
            journal_counter++;
            break;

    case 2: for(i=0;i<journal_counter;i++){
                j=0; 
                do{
                     if(strcmp(journalEntry[i].particular1,ledgers[j].accountName)==0){
                        is_particular1_account=1;
                     }
                     if(strcmp(journalEntry[i].particular2,ledgers[j].accountName)==0){
                        
                        is_particular2_account=1;
                     }
                     j++;
                }while(j<ledgers_size);
                if(!is_particular1_account){
                    memcpy(ledgers[ledgers_size].accountName,journalEntry[i].particular1,10);
                    ledgers_size++;
                }
                if(!is_particular2_account){
                    memcpy(ledgers[ledgers_size].accountName,journalEntry[i].particular2,10);
                    ledgers_size++;
                    }
                j=0;
                do{
                    if(strcmp(ledgers[j].accountName,journalEntry[i].particular1)==0)
                    {   
                        ledgers[j].debit_records[ledgers[j].debit_record_size].amount=journalEntry[i].d_value;
                        memcpy(ledgers[j].debit_records[ledgers[j].debit_record_size].name,journalEntry[i].particular2,10);
                        ledgers[j].debit_record_size++;
                    }
                    if(strcmp(ledgers[j].accountName,journalEntry[i].particular2)==0)
                    { 
                        ledgers[j].credit_records[ledgers[j].credit_record_size].amount=journalEntry[i].c_value;
                        memcpy(ledgers[j].credit_records[ledgers[j].credit_record_size].name,journalEntry[i].particular1,10);
                        ledgers[j].credit_record_size++;
                    }
                j++;
                }while(j<ledgers_size);
            }
            for(i=0;i<ledgers_size;i++){
            printf("\n\n-----------------------------------------------------------");
            printf("\n|DR\t\t\t%s A/C\t\t\tCR|",ledgers[i].accountName);
            printf("\n-----------------------------------------------------------\n");
            if(ledgers[i].debit_record_size>ledgers[i].credit_record_size){
                for(j=0;j<ledgers[i].credit_record_size;j++){
                printf("To %s\t%d\t\t\t",ledgers[i].debit_records[j].name,ledgers[i].debit_records[j].amount);
                printf("BY %s\t%d\t\t\n",ledgers[i].credit_records[j].name,ledgers[i].credit_records[j].amount);
                }
                for(j=ledgers[i].credit_record_size;j<ledgers[i].debit_record_size;j++){
                printf("To %s\t%d\n",ledgers[i].debit_records[j].name,ledgers[i].debit_records[j].amount);
                }
            }
            else if(ledgers[i].debit_record_size<=ledgers[i].credit_record_size){
                for(j=0;j<ledgers[i].debit_record_size;j++){
                printf("To %s\t%d\t\t\t\t",ledgers[i].debit_records[j].name,ledgers[i].debit_records[j].amount);
                printf("BY %s\t%d\t\t\n",ledgers[i].credit_records[j].name,ledgers[i].credit_records[j].amount);
                }
                for(j=ledgers[i].debit_record_size;j<ledgers[i].credit_record_size;j++){
                printf("\t\t\t\t\t\tBy %s\t%d",ledgers[i].credit_records[j].name,ledgers[i].credit_records[j].amount);
                }
            }
            
            }
            break;


    default:
            end_program=1;
            printf("\nProgram End"); 
            break;
}
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
int scanJournal(char* name1, char* name2, int* ptr1, int* ptr2){// name_buffer<-cash, name1<-name_buffer<-cash// name_buffer<-diya
    scanf("%s %d",name_buffer1,ptr1);
    memcpy(name1,name_buffer1,9);name1[9]='\0';
    scanf("%s %d",name_buffer2,ptr2);
    memcpy(name2,name_buffer2,9);name2[9]='\0';
}
//version3