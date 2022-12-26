#include <stdio.h>
#include <windows.h>
#include "mystring.h"
#include "myqueue.h"
#define ASSET 0
#define LIABILITY 1
#define CAPITAL 2
#define PROFIT 3
#define LOSS 4
#define NOT_SET -1
#define ENOUGH20 10


typedef struct Ledger_Record{
    int date;
    char name[ENOUGH20];
    int amount;
}Ledger_Record;

typedef struct Ledger{
    int balance;
    int id;
    int account_info;//0 for asset , 1 for liabilitiy , 2 for capital, 3 for profit, 4 for loss .. if not set -1;
    int debit_record_size;
    int credit_record_size;
    char accountName[ENOUGH20];
    Ledger_Record* debit_records;
    Ledger_Record* credit_records;   
}Ledger;

typedef struct JournalEntry{
    int date;
    char particular1[ENOUGH20];
    char particular2[ENOUGH20];
    int d_value;
    int c_value;
}JournalEntry;

int printJournal();
int scanJournal();
int printTotalJournal(JournalEntry *journal, int n);
void set_5num_zero(int* a, int* b, int* c, int* d, int* e);
char name_buffer1[ENOUGH20];
char name_buffer2[ENOUGH20];

int main(){
NAME_VAL_QUEUE debit_balance_queue;
NAME_VAL_QUEUE credit_balance_queue;
NAME_VAL pair;
NAME_VAL pair2;
Char4s char4s;
Ledger* ledgers;
Ledger balance;
Ledger_Record ledger_record;
char name1[ENOUGH20];
char name2[ENOUGH20];
int amount1=0;
int amount2=1;
int choice;
int is_particular1_account=0;
int is_particular2_account=0;
debit_balance_queue=make_queue(50);
credit_balance_queue=make_queue(50);
JournalEntry* journalEntry=(JournalEntry*)malloc(sizeof(JournalEntry)*100);
int journal_counter=0;
int i=0;
int j=0;
int k=0;
int journal_len=5;
int end_program=0;
int ledgers_size=0;
char balance_check_input[100];
int count_asset_accounts=0;
int count_liability_accounts=0;
int count_capital_accounts=0;
int count_profit_accounts=0;
int count_loss_accounts=0;
int debit_balance=0;
int credit_balance=0;
while(end_program!=1){


printf("\n1.Journal\t2.Ledger\t3.TrialBalance\n");
printf("Enter Your Action:");
scanf("%d",&choice);
switch(choice){
    case 1:
            printf("___Dr  ___$  ___Cr  ___$\n");
            scanJournal(name1,name2,&amount1,&amount2);
            if(amount1!=amount2)
            {printf("BOTH VALUE SHOULD BE SAME\n");break;}
            journalEntry[journal_counter]=(JournalEntry){.date=journal_counter,.d_value=amount1,.c_value=amount2};
            memcpy(journalEntry[journal_counter].particular1,name1,ENOUGH20);
            memcpy(journalEntry[journal_counter].particular2,name2,ENOUGH20);
            journal_counter++;
            break;

    case 2: 
                
                ledgers = (Ledger*) malloc(sizeof(Ledger)*ENOUGH20);
                ledgers_size=0;
                for(i=0;i<ENOUGH20;i++){
                    
                    ledgers[i]=(Ledger){.accountName="NOTHING",.account_info=-1};
                    ledgers[i].credit_record_size=0;
                    ledgers[i].debit_record_size=0;
                    ledgers[i].account_info=NOT_SET;    
                    ledgers[i].id=0;
                    ledgers[i].balance=0;
                    ledgers[i].debit_records=(Ledger_Record*)malloc(sizeof(Ledger_Record)*ENOUGH20);
                    ledgers[i].credit_records=(Ledger_Record*)malloc(sizeof(Ledger_Record)*ENOUGH20);
                    
                    for(j=0;j<ENOUGH20;j++){
                    ledgers[i].debit_records[j]=(Ledger_Record){.amount=0,.name="EMPTY"};
                    ledgers[i].credit_records[j]=(Ledger_Record){.amount=0,.name="EMPTY"};
                    }
                
                }
                
                for(i=0;i<journal_counter;i++){
                is_particular1_account=0;
                is_particular2_account=0;
                    //printf("    Checking %d journal\n",i);
                j=0; 
                do{//printf("checking %d ledger\n",j);
                    //printf("finding %s and %s\n",journalEntry[i].particular1,journalEntry[i].particular2);
                     if(strcmp(journalEntry[i].particular1,ledgers[j].accountName)==0){
                        is_particular1_account=1;
                       // printf("there is %s account\n",ledgers[j].accountName);
                     }
                     if(strcmp(journalEntry[i].particular2,ledgers[j].accountName)==0){
                        is_particular2_account=1;
                        //printf("there is %s account\n",ledgers[j].accountName);
                     }
                     j++;
                }while(j<ledgers_size);
                //printf("Found status: ACC1 %d ACC2 %d\n",is_particular1_account,is_particular2_account);
                if(!is_particular1_account){
                   // printf("making %s account\n",journalEntry[i].particular1);
                    memcpy(ledgers[ledgers_size].accountName,journalEntry[i].particular1,ENOUGH20);
                    ledgers_size++;
                }
                if(!is_particular2_account){
                    //printf("making %s account\n",journalEntry[i].particular2);
                    memcpy(ledgers[ledgers_size].accountName,journalEntry[i].particular2,ENOUGH20);
                    ledgers_size++;
                    }
                j=0;
                do{
                    if(strcmp(ledgers[j].accountName,journalEntry[i].particular1)==0)
                    {   
                        ledgers[j].debit_records[ledgers[j].debit_record_size].amount=journalEntry[i].d_value;
                        memcpy(ledgers[j].debit_records[ledgers[j].debit_record_size].name,journalEntry[i].particular2,ENOUGH20);
                        ledgers[j].debit_record_size++;
                        
                    }
                    if(strcmp(ledgers[j].accountName,journalEntry[i].particular2)==0)
                    { 
                        ledgers[j].credit_records[ledgers[j].credit_record_size].amount=journalEntry[i].c_value;
                        memcpy(ledgers[j].credit_records[ledgers[j].credit_record_size].name,journalEntry[i].particular1,ENOUGH20);
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
                printf("To %s\t%d\t\t\t",string_trim_10(ledgers[i].debit_records[j].name),ledgers[i].debit_records[j].amount);
                printf("BY %s  %d\t\n",string_trim_10(ledgers[i].credit_records[j].name),ledgers[i].credit_records[j].amount);
                }
                for(j=ledgers[i].credit_record_size;j<ledgers[i].debit_record_size;j++){
                printf("To %s  %d\n",string_trim_10(ledgers[i].debit_records[j].name),ledgers[i].debit_records[j].amount);
                }
            }
            else if(ledgers[i].debit_record_size<=ledgers[i].credit_record_size){
                for(j=0;j<ledgers[i].debit_record_size;j++){
                printf("To %s  %d\t\t\t",string_trim_10(ledgers[i].debit_records[j].name),ledgers[i].debit_records[j].amount);
                printf("BY %s  %d\t\n",string_trim_10(ledgers[i].credit_records[j].name),ledgers[i].credit_records[j].amount);
                }
                for(j=ledgers[i].debit_record_size;j<ledgers[i].credit_record_size;j++){
                printf("\t\t\t\t\tBy %s\t%d\n",string_trim_10(ledgers[i].credit_records[j].name),ledgers[i].credit_records[j].amount);
                }
            }
            
            }free(ledgers);
            break;

    case 3://trial balance// for each ledger define type.
                ledgers = (Ledger*) malloc(sizeof(Ledger)*ENOUGH20);
                ledgers_size=0;
                for(i=0;i<ENOUGH20;i++){
                    
                    ledgers[i]=(Ledger){.accountName="NOTHING",.account_info=-1};
                    ledgers[i].credit_record_size=0;
                    ledgers[i].debit_record_size=0;
                    ledgers[i].account_info=NOT_SET;    
                    ledgers[i].id=0;
                    ledgers[i].balance=0;
                    ledgers[i].debit_records=(Ledger_Record*)malloc(sizeof(Ledger_Record)*ENOUGH20);
                    ledgers[i].credit_records=(Ledger_Record*)malloc(sizeof(Ledger_Record)*ENOUGH20);
                    
                    for(j=0;j<ENOUGH20;j++){
                    ledgers[i].debit_records[j]=(Ledger_Record){.amount=0,.name="EMPTY"};
                    ledgers[i].credit_records[j]=(Ledger_Record){.amount=0,.name="EMPTY"};
                    }
                
                }
                
                for(i=0;i<journal_counter;i++){
                is_particular1_account=0;
                is_particular2_account=0;
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
                    memcpy(ledgers[ledgers_size].accountName,journalEntry[i].particular1,ENOUGH20);
                    ledgers_size++;
                }
                if(!is_particular2_account){
                    memcpy(ledgers[ledgers_size].accountName,journalEntry[i].particular2,ENOUGH20);
                    ledgers_size++;
                    }
                j=0;
                do{
                    if(strcmp(ledgers[j].accountName,journalEntry[i].particular1)==0)
                    {   
                        ledgers[j].debit_records[ledgers[j].debit_record_size].amount=journalEntry[i].d_value;
                        memcpy(ledgers[j].debit_records[ledgers[j].debit_record_size].name,journalEntry[i].particular2,ENOUGH20);
                        ledgers[j].debit_record_size++;
                    }
                    if(strcmp(ledgers[j].accountName,journalEntry[i].particular2)==0)
                    { 
                        ledgers[j].credit_records[ledgers[j].credit_record_size].amount=journalEntry[i].c_value;
                        memcpy(ledgers[j].credit_records[ledgers[j].credit_record_size].name,journalEntry[i].particular1,ENOUGH20);
                        ledgers[j].credit_record_size++;
                    }
                j++;
                }while(j<ledgers_size);
                }
                //initialized ledger.
                for(i=0;i<ledgers_size;i++){
                    ledgers[i].id=i+1;
                }

                for(i=0;i<ledgers_size;i++){
                    
                  if((strcmp(ledgers[i].accountName,"capital")==0)||(strcmp(ledgers[i].accountName,"Capital")==0)||(strcmp(ledgers[i].accountName,"CAPITAL")==0))
                    {ledgers[i].account_info=CAPITAL;count_capital_accounts++;}

                }//init CAPITAL

                for(i=0;i<ledgers_size;i++){
                    if(ledgers[i].account_info==-1){
                    printf("%d.%s\n",ledgers[i].id,ledgers[i].accountName,ledgers[i].account_info);
                }}
                printf("WHICH ACCOUNTS ARE ASSET?:");
                //scanf("%c",&balance_check_input[0]);
                
                fputs(balance_check_input,stdin);
                scanf("%[^\n]s",balance_check_input);
                
                
                char4s = parse_num_string(balance_check_input);
                for(i=0;i<char4s.count;i++){
                    
                    for(j=0;j<ledgers_size;j++){
                        if(ledgers[j].id==atoi(char4s.ptr[i]))
                        {
                            ledgers[j].account_info=ASSET;count_asset_accounts++;
                        }
                    }
                }free(char4s.ptr);

                //set asset;
                memcpy(balance_check_input,"                    ",ENOUGH20);balance_check_input[ENOUGH20]='\0';
                
                for(i=0;i<ledgers_size;i++){
                    if(ledgers[i].account_info== NOT_SET ){
                    printf("\n\n%d.%s\n",ledgers[i].id,ledgers[i].accountName);
                    }
                }
                printf("WHICH ACCOUNTS ARE LIABILITY?:");
                scanf("%c",&balance_check_input[0]);
                fputs(balance_check_input,stdin);
                scanf("%[^\n]s",balance_check_input);

                char4s = parse_num_string(balance_check_input);
                for(i=0;i<char4s.count;i++){
                    
                    for(j=0;j<ledgers_size;j++){
                        if(ledgers[j].id==atoi(char4s.ptr[i]))
                        {
                            ledgers[j].account_info=LIABILITY;count_liability_accounts++;
                        }
                    }
                }
                free(char4s.ptr);//check liability
                memcpy(balance_check_input,"                    ",ENOUGH20);balance_check_input[ENOUGH20]='\0';

                for(i=0;i<ledgers_size;i++){
                    if(ledgers[i].account_info== NOT_SET ){
                    printf("\n\n%d.%s\n",ledgers[i].id,ledgers[i].accountName);
                    }
                }
                printf("WHICH ACCOUNTS ARE PROFIT?:");
                //scanf("%c",&balance_check_input[0]);
                fputs(balance_check_input,stdin);
                scanf("%[^\n]s",balance_check_input);
                
                char4s = parse_num_string(balance_check_input);
                for(i=0;i<char4s.count;i++){
                    
                    for(j=0;j<ledgers_size;j++){
                        if(ledgers[j].id==atoi(char4s.ptr[i]))
                        {
                            ledgers[j].account_info=PROFIT;count_profit_accounts++;
                        }
                    }
                }free(char4s.ptr);//set profit
                memcpy(balance_check_input,"                    ",ENOUGH20);balance_check_input[ENOUGH20]='\0';
                
                
                for(i=0;i<ledgers_size;i++){
                    if(ledgers[i].account_info== NOT_SET ){
                    printf("\n\n%d.%s\n",ledgers[i].id,ledgers[i].accountName);
                    }
                }
                printf("WHICH ACCOUNTS ARE LOSS?:");
                //scanf("%c",&balance_check_input[0]);
                fputs(balance_check_input,stdin);
                scanf("%[^\n]s",balance_check_input);
                

                char4s = parse_num_string(balance_check_input);
                
                printf("\n");
                for(i=0;i<char4s.count;i++){
                    
                    for(j=0;j<ledgers_size;j++){
                        //printf("CHECKING ledger%s %d whether its same as %s\n",ledgers[j].accountName,ledgers[j].id,char4s.ptr[i]);
                        if(ledgers[j].id==atoi(char4s.ptr[i]))
                        {
                            //printf("CHANGED %s account VALUE TO %d",ledgers[j].accountName,LOSS);
                            ledgers[j].account_info=LOSS;count_loss_accounts++;
                        }
                    }
                }free(char4s.ptr);//set LOSS
                memcpy(balance_check_input,"                    ",ENOUGH20);balance_check_input[ENOUGH20]='\0';
                
                for(i=0;i<ledgers_size;i++){
                    for(j=0;j<ledgers[i].credit_record_size;j++){
                        ledgers[i].balance-=ledgers[i].credit_records[j].amount;
                    }
                    for(j=0;j<ledgers[i].debit_record_size;j++){
                        ledgers[i].balance+=ledgers[i].debit_records[j].amount;
                    }
                }
                for(i=0;i<ledgers_size;i++){
                    if(ledgers[i].account_info==LIABILITY || ledgers[i].account_info==CAPITAL ||
                        ledgers[i].account_info== PROFIT){
                            ledgers[i].balance=ledgers[i].balance*(-1);
                        }
                }

                        enqueue_with_string(&debit_balance_queue,(NAME_VAL){.val=0},"__ASSET__");count_asset_accounts++;
                for(i=0;i<ledgers_size;i++){
                    //printf("CHECKED %s info was %d\n",ledgers[i].accountName,ledgers[i].account_info);
                    if(ledgers[i].account_info==ASSET){
                        
                        enqueue_with_string(&debit_balance_queue,(NAME_VAL){.val=ledgers[i].balance},ledgers[i].accountName);
                        //printf("ENQUEUED %s\n",ledgers[i].accountName);
                        //printf("NOW i is %d ledger size is %d \n",i,ledgers_size);
                    }  
                }
                        //printf("ENDED ASSET ENQUEUE\n");
                        enqueue_with_string(&debit_balance_queue,(NAME_VAL){.val=0},"___LOSS___");count_loss_accounts++;
                        //printf("ENQUEUED LOSS\n");

                for(i=0;i<ledgers_size;i++){
                    if(ledgers[i].account_info==LOSS){
                        
                        enqueue_with_string(&debit_balance_queue,(NAME_VAL){.val=ledgers[i].balance},ledgers[i].accountName);
                    } 

                }

                        enqueue_with_string(&credit_balance_queue,(NAME_VAL){.val=0},"_LIABIL_");count_liability_accounts++;

                for(i=0;i<ledgers_size;i++){
                    if(ledgers[i].account_info==LIABILITY){
                        
                        enqueue_with_string(&credit_balance_queue,(NAME_VAL){.val=ledgers[i].balance},ledgers[i].accountName);
                        //printf("ENQUEUEED %s %d\n",ledgers[i].accountName,i);    
                    }
                }
                        enqueue_with_string(&credit_balance_queue,(NAME_VAL){.val=0},"_CAPITAL_");count_capital_accounts++;

                for(i=0;i<ledgers_size;i++){
                    if(ledgers[i].account_info==CAPITAL){
                        
                        enqueue_with_string(&credit_balance_queue,(NAME_VAL){.val=ledgers[i].balance},ledgers[i].accountName);
                    } 
                }

                        enqueue_with_string(&credit_balance_queue,(NAME_VAL){.val=0},"__PROFIT__");count_profit_accounts++;

                for(i=0;i<ledgers_size;i++){
                    if(ledgers[i].account_info==PROFIT){
                        
                        enqueue_with_string(&credit_balance_queue,(NAME_VAL){.val=ledgers[i].balance},ledgers[i].accountName);
                    }  
                }

                printf("\n---------------------------------------------\n");
                printf("|                BALANCE SHEET             |");
                printf("\n---------------------------------------------\n");
                j=((count_asset_accounts+count_loss_accounts)>(count_liability_accounts+count_capital_accounts+count_profit_accounts))?(count_asset_accounts+count_loss_accounts):(count_liability_accounts+count_capital_accounts+count_profit_accounts);
                for(i=0;i<j;i++){
                    pair=dequeue(&debit_balance_queue);
                    
                        
                        if(strcmp(pair.name,"empty")==0){
                            printf("\t\t\t\t");
                        }else{
                            if(pair.val==0){
                            printf("%s    \t\t\t",pair.name);
                            }else{
                            printf("%s  %d\t\t\t",pair.name,pair.val);
                            debit_balance+=pair.val;
                            }
                        }
                    pair=dequeue(&credit_balance_queue);
                    
                        if(strcmp(pair.name,"empty")==0){
                           
                        }else{
                            if(pair.val==0){
                            printf("%s    \t\t\n",pair.name);
                            }else{
                            printf("%s  %d\t\t\n",pair.name,pair.val);
                            credit_balance+=pair.val;}
                        }

                }
                printf("\n==========================================\n");
                printf("TOTAL\t%d\t\t\t\t%d",debit_balance,credit_balance);
                





                set_5num_zero(&count_asset_accounts,&count_capital_accounts,&count_liability_accounts,&count_loss_accounts,&count_profit_accounts);
                
                free(ledgers);
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
    memcpy(name1,name_buffer1,ENOUGH20-1);name1[ENOUGH20-1]='\0';
    scanf("%s %d",name_buffer2,ptr2);
    memcpy(name2,name_buffer2,ENOUGH20-1);name2[ENOUGH20-1]='\0';
}

void set_5num_zero(int* a, int* b, int* c, int* d, int* e){
    *a = 0; *b =0; *c=0,*d=0,*e=0;
}

//version3