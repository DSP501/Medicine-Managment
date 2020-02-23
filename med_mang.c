#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>
#include<time.h>
#include<dos.h>
#include<math.h>



typedef struct node
{
	char id[6];
	char medi_name[20];
	int quantity;  // total packetd or bottel
	float sp;   // selling price
	float cost;    // cost price
	float profit;  
	char pur_date[8];
	char exp_date[8];
	char manu_date[8];
	char comp_name[20];
	struct node *next;
	struct node *prev;

}node;

typedef struct
{
	node *start;
}MEDICINE;

typedef struct
{
	char customer[20];
	char medname[20];
	char id[6];
	int  quant;
	float total;
	char bill_no[5];
}cust;


void box();
void box2();
void display(MEDICINE *m);
void display2(MEDICINE *m);
void gotoxy(int x,int y);
void main_box(MEDICINE *m);
void bye();

  
  node* search(MEDICINE *m, char  idd[])
  {
  	node *p;
  	
  	p=m->start;
  	
  	while(strcmp(p->id,idd)!=0)
  	p=p->next;
  
  	return p;
  }

  
  void Sale(MEDICINE *m)
  {
  	system("cls");
  	system("COLOR 3F");
  	
  	box2();
  	box();
  	display2(m);
  
    if(m->start==NULL)
    { 
        gotoxy(40,25);
    	printf("NO MEDICINE IN STOCK,CAN'T SALE");
    	getch();
    	main_box(m);
    	
	}
    
  	cust c;

  	char idd[6];
    char ch;  	
  	node *p,*temp;
  	
  	fflush(stdin);
    gotoxy(7,9);
  	printf("Customer Name :");
  	gotoxy(28,9);
  	gets(c.customer);
  	
  	gotoxy(35,9);
    printf("BILL-NO");
    gotoxy(45,9);
    gets(c.bill_no);
    fflush(stdin);
  	
  	gotoxy(7,11);
  	printf("Medicine Id :");
  
  	gotoxy(28,11);fflush(stdin);
  	gets(idd);
  	strcpy(c.id,idd);
  	
  	temp=search(m,idd); 
  	
  	
  	gotoxy(7,13);
  	printf("Med-Name :");
  	gotoxy(28,13);
  	puts(temp->medi_name);
  	
  	gotoxy(7,15);
  	printf("Quantity :");
  	gotoxy(28,15);
  	while(1)
  	{
  		scanf("%d",&c.quant);
  		if(	c.quant > temp->quantity || c.quant < 0)
  		{
  			 MessageBox(0,"PL ENTER CORRECT QUANTITY","ERROR",0);
		}
		else
		break;	
	}
	
	
	gotoxy(7,17);
	printf("TOTAL :");
	gotoxy(28,17);
	printf("%.2f",(c.quant * temp->sp));
	
	c.total = c.quant * temp->sp;
   
  	gotoxy(20,25);
  	printf("CONFIRM YOUR TRANSACTION  y YES  or  n NO");
  	gotoxy(20,26);
  	fflush(stdin);
  	scanf("%s",&ch);
  	
  	
  	if(ch == 'y' || ch == 'Y')
  	{
  			
  	
  		FILE *fp,*fp2;
  		fp = fopen("SALES.txt","a");
  		fp2 = fopen("SALES.dat","w");
  		if(fp==NULL && fp2 == NULL )
  		{
  		   MessageBox(0,"CAN NOT FIND FILE","ERROR",0);	
		}
		else
		{
		    temp->quantity = temp->quantity - c.quant;
			time_t tm = time(NULL);
			time(&tm);
			fprintf(fp,"\n\n\n\n\t\t\t\t%s\n\n",ctime(&tm));
		
		    fprintf(fp,"ID\t\tBILL_NO\t\tCUSTOMER_NAME\t\tMEDICINE\t\tQUANTITY\t\tTOTOAL\n");
		    fprintf(fp,"%s\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%d\t\t\t%f\n",c.id,c.bill_no,c.customer,temp->medi_name,c.quant,c.total);  
			fprintf(fp,"------------------------------------------------\n\n");
			
	
		     p=m->start;
			 while(p!=NULL) 
		     {
		     		fprintf(fp2,"%s\t%s\t%s\t%s\t%s\t%s\t%f\t%f\t%f\t%d\n",p->comp_name , p->id , p->medi_name,p->exp_date,p->manu_date,p->pur_date,p->cost,p->sp,p->profit,p->quantity);
		     		p=p->next;
			 }
		      
		      
		      
			MessageBox(0,"TRANSACATION COMPLETE","DONE",0);
			fclose(fp);	
			
		}
	}
	
  	getch();
  	main_box(m);
  	
  }



void display2(MEDICINE *m)
{
  	
  	gotoxy(120,3);
	printf("MEDICINE DATA");
	 
  	int i;
  	
  	node *p;
  	
  	if(m->start==NULL)
  	{
  	   gotoxy(125,15);
	   printf("NO MEDICINE FOUND");	
	   //return;
	}
	
	else
	{
		p=m->start;
		
		gotoxy(86,7);
		printf("ID");
		gotoxy(91,7);
		printf("MEDI_NAME");
		gotoxy(101,7);
		printf("QUANTITY");
		gotoxy(111,7);
		printf("PRICE");
		gotoxy(121,7);
		printf("EXP_DATE");
		gotoxy(131,7);
		printf("COMPANY_NAME");
		
		i=9;
		while(p!=NULL)
		{
			gotoxy(86,i);
			puts(p->id);
			gotoxy(91,i);
			puts(p->medi_name);
			gotoxy(101,i);
			printf("%d",p->quantity);
			gotoxy(111,i);
			printf("%.2f",p->sp);
			gotoxy(121,i);
			puts(p->exp_date);
			gotoxy(131,i);
			puts(p->comp_name);
			
			i=i+2;
			p=p->next;
			
		}
			
	}
	 	
}


  void display(MEDICINE *m)
  {
  	system("cls");
  	system("COLOR  2F");
  	//box_table();
  	box();
  	
  	gotoxy(35,3);
	printf("MEDICINE DATA");
	 
  	int i;
  	
  	node *p;
  	
  	if(m->start==NULL)
  	{
  	   gotoxy(25,15);
	   printf("NO MEDICINE FOUND");	
	   //return;
	}
	
	else
	{
		p=m->start;
		
		gotoxy(6,7);
		printf("ID");
		gotoxy(11,7);
		printf("MEDI_NAME");
		gotoxy(27,7);
		printf("QUANTITY");
		gotoxy(37,7);
		printf("PRICE");
		gotoxy(47,7);
		printf("EXP_DATE");
		gotoxy(57,7);
		printf("COMPANY_NAME");
		
		i=9;
		while(p!=NULL)
		{
			gotoxy(6,i);
			puts(p->id);
			gotoxy(11,i);
			puts(p->medi_name);
			gotoxy(27,i);
			printf("%d",p->quantity);
			gotoxy(37,i);
			printf("%.2f",p->sp);
			gotoxy(47,i);
			puts(p->exp_date);
			gotoxy(57,i);
			puts(p->comp_name);
			
			i=i+2;
			p=p->next;
			
		}	
		
	}
	 getch();
	 main_box(m);

  }


    void EnterMed(MEDICINE *m)
   {   
        char ch;
        FILE *fp;
        fp = fopen("SALES.dat","a");
        if(fp == NULL)
        {
        	MessageBox(0,"CAN NOT FIND FILE","ERROR",0);
		}
        
			
        
        while(1) {
		
	    node *newrec,*p;
    	newrec = (node*)malloc(sizeof(node));
		
		system("cls");
           
         system("COLOR F0");
         
         gotoxy(35,3);
         printf("MEDICINE ENTRY");
        
    	
        box();
    	
    	fflush(stdin);
    	gotoxy(10,10);
        printf("Medicine id :");
        gotoxy(35,10);
    	gets(newrec->id);
    	
    	
    	gotoxy(10,12);
    	printf("Medicine Name :");
        gotoxy(35,12);
        gets(newrec->medi_name);
    	
    	gotoxy(10,14);
    	printf("Company Name :");
        gotoxy(35,14);
    	gets(newrec->comp_name);
    	
    	gotoxy(10,16);
    	printf("Quantitiy:");
        gotoxy(35,16);
        scanf("%d",&newrec->quantity);
        
        fflush(stdin);
        
        gotoxy(10,18);
    	printf("Purchase Date");
        gotoxy(35,18);
        gets(newrec->pur_date);
        
        gotoxy(45,18);
    	printf("Exp Date");
        gotoxy(65,18);
        gets(newrec->exp_date);
        
        gotoxy(10,20);
    	printf("Manufacturing Date");
        gotoxy(35,20);
        gets(newrec->manu_date);
        
        gotoxy(10,22);
    	printf("Cost");
        gotoxy(35,22);
        scanf("%f",&newrec->cost);
        
        gotoxy(45,22);
    	printf("selling price");
        gotoxy(65,22);
        scanf("%f",&newrec->sp);
        
        newrec->profit=newrec->sp-newrec->cost;
        
        if(m->start==NULL)
        {
        	m->start=newrec;
        
        	newrec->next=NULL;
        	newrec->prev=NULL;
        
		}
        
    	else
    	{
    		p=m->start;
    		while(p->next!=NULL)
    		p=p->next;
    		
    		p->next=newrec;
    		newrec->next=NULL;
    		newrec->prev=p;
    	
		}
		
		fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%f\t%f\t%f\t%d\n",newrec->comp_name , newrec->id , newrec->medi_name,newrec->exp_date,newrec->manu_date,newrec->pur_date,newrec->cost,newrec->sp,newrec->profit,newrec->quantity);
		
		gotoxy(5,40); fflush(stdin);
		printf("Do You Want To Continue?  Y/y YES  or  N/n  NO");
		gotoxy(5,41);
		scanf("%c",&ch);
		
		if(ch=='N' || ch=='n')
		break;
		
    
   } 
        
    	fclose(fp);
    	main_box(m);
    	
}



COORD coord = {0, 0};
void gotoxy(int x, int y)
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void box()
{
     int i,j;
     gotoxy(5,5);
     printf("%c",201);
     
     gotoxy(80,5);
     printf("%c",187);
     
     gotoxy(5,35);
     printf("%c",200);
     
     gotoxy(80,35);
     printf("%c",189);
     
     
     for(i=6;i<80;i++)
     {
        gotoxy(i,5);
        printf("%c",205);
       
        gotoxy(i,35);
       printf("%c",205);
       
	 }
	 
	 for(i=6;i<35;i++)
	 {
	 	gotoxy(5,i);
       	printf("%c",186);
        gotoxy(80,i);
        printf("%c",186);
	 }
	
}

void box2()
{
	
     int i,j;
     gotoxy(85,5);
     printf("%c",201);
     
     gotoxy(160,5);
     printf("%c",187);
     
     gotoxy(85,35);
     printf("%c",200);
     
     gotoxy(160,35);
     printf("%c",189);
     
     
     for(i=86;i<160;i++)
     {
        gotoxy(i,5);
        printf("%c",205);
       
        gotoxy(i,35);
       printf("%c",205);
       
	 }
	 
	 for(i=6;i<35;i++)
	 {
	 	gotoxy(85,i);
       	printf("%c",186);
        gotoxy(160,i);
        printf("%c",186);
	 }
	
}

  void main_box(MEDICINE *m)
{
	 system("cls");
	 int ch;
	
	 system("COLOR F0");
	 box();
	 // SetConsoleTitle("MEDICAL MANAGMENT SYSTEM");
	 //  SMALL_RECT windowSize = {0, 0, 90, 100};
	 gotoxy(35,3);
	 printf("WELCOME SIR!");
	  
	gotoxy(10,10);
	printf("1-Enter Medicine Data");
	gotoxy(10,11);
	printf("2-Check Medicine");
	gotoxy(10,12);
	printf("3-Sale Medicine");
	gotoxy(10,13);
	printf("4-Exit");
	
	gotoxy(6,40);
	printf("Enter Your Choice");
	gotoxy(6,41);
	
	
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1: animation(10);EnterMed(m);break;
		
		case 2: animation(11);display(m);;break;
		
		case 3: animation(12);Sale(m);break;
	     
		case 4: animation(13);return;
		
		default:
			printf("wrong choice");
			main_box(m);
	
	}
	
	
	

}


int  animation(int x)
{
		int i;

	for (i=35; i>=7; i--)
	{
		Sleep(30);
		gotoxy(7,i);
		//clreol();
	}
	for (i=7; i<=x; i++)
	{
		//clreol();
		Sleep(40);
		gotoxy(7,i);
	}
}

void bye()
{
	system("cls");
	box();
	gotoxy(35,15);
    printf("THANK YOU!");
    gotoxy(35,21);
   
    gotoxy(60,27);
    printf("DEVELOPER");
    gotoxy(60,29);
    printf("DHRUVESH PANCHAL");
}
    

void getData(MEDICINE *m)
{
	FILE *fp;
        fp = fopen("SALES.dat","r");
        if(fp == NULL)
        {
        	MessageBox(0,"CAN NOT FIND FILE","ERROR",0);
		}
		
		
		
    	while(!feof(fp))
    	{
    		
    	 node *newrec,*p;
         newrec = (node*)malloc(sizeof(node));
         fscanf(fp,"%s%s%s%s%s%s%f%f%f%d",&newrec->comp_name , &newrec->id , &newrec->medi_name,&newrec->exp_date,&newrec->manu_date,&newrec->pur_date,&newrec->cost,&newrec->sp,&newrec->profit,&newrec->quantity);
         
            if(m->start==NULL)
           {
            	m->start=newrec;
        
            	newrec->next=NULL;
        	    newrec->prev=NULL;
              
	       }
	       
	       else
    	{
    		p=m->start;
    		while(p->next!=NULL)
    		p=p->next;
    		
    		p->next=newrec;
    		newrec->next=NULL;
    		newrec->prev=p;
    	
		}
	    	
	    	
         
		}
		
		fclose(fp);
}

int main()
{
	 MEDICINE m;
	 m.start=NULL;
	 getData(&m);
     main_box(&m);
     bye();
    
    
	 
	 
	 

}

