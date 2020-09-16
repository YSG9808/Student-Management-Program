#include <stdio.h>
#include <stdlib.h>
#define START_ID 1201001
#include <string.h>

void fprint();
void fprint1();
void fprint2();
//void search();
//void stquery1();
//void stquery2();
//void update();
//void update1();
//void update2();

struct student {
	char name[20];
	char address[20];
	char phonenumber[20];
	char rrn[20];
	char id[20];
 	char major[20];
	char email[20];
	char graduation[20];
	char rest[20];
	char leave[20];
	char entrance[20];
	char graduationdate[20];
	char restdate[20];
	char leavedate[20];
	char entrancedate[20];
	char grade[20];
	char scholarship[20];
	char award[20];
};

struct educationalpersonnel {
	char name[20];
	char address[20];
        char phonenumber[20];
        char rrn[20];
        char id[20];
        char major[20];
        char email[20];
        char contract[20]; 
};

struct asset {
        char name[20];
        char id[20];
        char date[20];
        char price[20];
        char position[20];
	char mo[20];
	char md[20];
};

void main(){

	int category = 0;
	int a = 0;
	char chac;
	int b = 0;
	int c = 0;

	while(1){
		printf("select category(0:student, 1:educational personnel, 2:asset, 3:quit) : ");
		scanf("%d", &category);
		switch(category){
				case 0: while(1){
						printf("select menu (0:register, 1:search, 2:modify)");
						scanf("%d",&a);
						switch(a){
							case 0: fprint();
								break;

							case 1: //search();
								break;

							case 2: //update();
								break;

							default: printf("\ninput correct number");
						}
				       printf("continue? (y/n)");
		       		       scanf("%c",&chac);
				       if(chac != 'y')
					       break;
					}

				case 1: while(1){
						printf("select menu (0:register, 1:search, 2:modify)");
						scanf("%d",&b);
						switch(b){
							case 0: fprint1();
								break;
							
							case 1: //search1();
							   	break;
							
							case 2: //update1();
								break;

							default: printf("\ninput correct number");
						}
				       printf("continue?(y/n)");
		       		       scanf("%c", &chac);
				       if(chac != 'y')
						break;
				       }


				case 2: while(1){
						printf("select menu (0:register, 1:search, 2:modify)");					
						scanf("%d",&c);
						switch(c){
							case 0: fprint2();
								break;
							
							case 1: //search2();
								break;

							case 2: //update();
								break;
							
							default: printf("\ninput correct number");
						}
				       printf("continue?(y/n)");
		       		       scanf("%c", &chac);
				       if(chac != 'y')
						break;
		 		       }
		 			
			 	case 3: return;


				default: printf("\ninput correct number");

				}
				printf("continue?(y/n)");
				scanf("%c", &chac);
		       		if(chac != 'y')
					break;		

	}		

}



                                   //register
				    

				    				 
void fprint() {
	struct student rec;
	FILE *fp; 
	char c;
	
	fp = fopen("./info.txt", "w");
	if(fp == NULL){
		printf("\nerror while reading file");
		return;
	}

/*	printf("%d %s %s %s %s %s %s \n", "id", "name", "address", "phonenumber", "rrn", "major", "email");
   	while (scanf("%d %s %s %s %s %s %s", &rec.id, rec.name, rec.address, rec.phonenumber, rec.rrn, rec.major, rec.email) == 3) {
      	fseek(fp, (rec.id - START_ID)* sizeof(rec),  SEEK_SET);
      	fwrite(&rec, sizeof(rec), 1, fp);
   	}
   
	fclose(fp);
   	exit(0);
}*/


	printf("name / address /  phonenumber /  resident registration number / id / major / email");
	scanf("%s %s %s %s %s %s %s", rec.name, rec.address, rec.phonenumber, rec.rrn, rec.id, rec.major, rec.email);
	fprintf(fp, "%s %s %s %s %s %s %s", rec.name, rec.address, rec.phonenumber, rec.rrn, rec.id, rec.major, rec.email);
	
	printf("continue?(y/n)");
	scanf("%c", &c);
	while (c == 'y');
	
	fflush(fp);
	fclose(fp);
} 

void fprint1(){
	struct educationalpersonnel rec;
	FILE *fp;
	fp = fopen("./info1.txt", "w");
	if(fp == NULL){
		printf("\nerror while reading file");
		return;
	}
printf("id/ address / phonenumber / resident registration number / contract date / major / email / name");
scanf("%s %s %s %s %s %s %s %s", rec.id, rec.address, rec.phonenumber, rec.rrn, rec.contract, rec.major, rec.email, rec.name);
fflush(stdin);
fprintf(fp, "%s %s %s %s %s %s %s %s", rec.contract, rec.address, rec.phonenumber, rec.rrn, rec.id, rec.major, rec.email, rec.name);
fflush(fp);
fclose(fp);
}

void fprint2(){
        struct asset rec;
        FILE *fp;
        fp = fopen("./info2.txt", "w");
        if(fp == NULL){
                printf("\nerror while reading file");
                return;
        }
printf("name / id / date / price / position / management officer / management department");
scanf("%s %s %s %s %s %s %s", rec.name, rec.id, rec.date, rec.price, rec.position, rec.mo, rec.md);
fflush(stdin);
fprintf(fp, "%s %s %s %s %s %s %s", rec.name, rec.id, rec.date, rec.price, rec.position, rec.mo, rec.md);
fflush(fp);
fclose(fp);
}


                                   //search

/*void search() {
   struct student rec;
   FILE *fFile;
   int id;
   char word;
   
   if((fFile = fopen("./info.txt", "r")) == NULL) {
      fprintf(stderr, "error while opening file\n");
      return;
   }

   do {
   printf("Write ID for search : ");
   if(scanf("%d", &id) == 1) {
      fseek(fFile, (id - START_ID) * sizeof(Student), SEEK_SET);
      if((fread(&rec, sizeof(rec), 1, fFile) > 0) && (rec.id != 0)) 
         printf("-------------------------------------------------------------------------\n");
        printf("id address  phonenumber rrn name major email");   
        printf("%d %s %s %s %s %s %s \n", rec.id, rec.address, rec.phonenumber, rec.rrn, rec.name, rec.major, rec.email);
      	else printf("%d X", id);
	}
   	else printf("error");
	return;

  	printf("continue?");
        scanf("%c", &word);
        } while (c == 'y');
	
   	fclose(fp);
   	exit(0);
}*/

