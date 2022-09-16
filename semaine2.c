#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct age{
	int jour;
	char mois;
	int annee;
};
typedef struct age date_ns;

struct Personne{
	char nom[100];
	char prenom[100];
	date_ns age;
};
typedef struct Personne p;

int getInt(){
	char line[100];
	int num;
	while(1){
	
	fgets(line,100,stdin);
		if(sscanf(line,"%d ",&num)!=1)
		{
			puts("error");
		}else break;
	}
	return num;
}

void getstring(char *str){
	char line[100];
	while(1){
	
	fgets(line,100,stdin);
		if(sscanf(line,"%s",str)!=1)
		{
			puts("error");
		}else break;
	}
	
	
}

p * initialiser(p *a ,int b){
	return a = malloc(b * sizeof(p));
	return a;
}

void insererelement(p *a,int b){
	int i;
	for(i=0;i<b;i++){
		printf("enter votre nom  : ");
		//strcpy(	a.nom,getstring());
		getstring(a[i].nom);
		printf("enter votre prenom  : ");
		getstring(a[i].prenom); 
		printf("enter annee de votre ns  : ");
		a[i].age.annee=getInt();
		printf("enter mois de votre ns  : ");
		a[i].age.mois=getInt();
		printf("enter jour de votre ns  : ");
		a[i].age.jour=getInt();
	}
}

void affichage(p *a,int b){
	int i;
	for(i=0;i<b;i++){
		printf("votre nom  : %s \n",a[i].nom);
		printf("votre prenom  : %s \n",a[i].prenom);
		printf("votre annee de ns  : %d \n",a[i].age.annee);
		printf("votre mois  : %d \n",a[i].age.mois);
		printf("votre jour  : %d \n",a[i].age.jour);
	}
		
}



void triparselection(p *a,int b){
	int i,j;
	p c,*t=NULL;
	for(i=0;i<b-1;i++){
		for(j=i+1;j<b;j++){
			if(a[j].age.annee>a[i].age.annee){
				c=a[i];
				a[i]=a[j];
				a[j]=c;
			}
		}
	
	}
	
	for(i=0;i<b-1;i++){
		for(j=i+1;j<b;j++){
			if(a[j].age.annee==a[i].age.annee && a[j].age.mois>a[i].age.mois){
				c=a[i];
				a[i]=a[j];
				a[j]=c;
			}
		}
	
	}
	
		
	
}


void pp(p *a,int b){
	int i=0;
    	triparselection(a,b);
    	printf("le plus petit est \n");
     	printf("votre nom  : %s \n",a[i].nom);
	    printf("votre prenom  : %s \n",a[i].prenom);
		printf("votre annee de ns  : %d \n",a[i].age.annee);
		printf("votre mois  : %d \n",a[i].age.mois);
		printf("votre jour  : %d \n",a[i].age.jour);
		
		
		
		
}

void pg(p *a,int b){
	int i=0;
		printf("le plus grand est \n");
		printf("votre nom  : %s \n",a[b-1].nom);
	    printf("votre prenom  : %s \n",a[b-1].prenom);
		printf("votre annee de ns  : %d \n",a[b-1].age.annee);
		printf("votre mois  : %d \n",a[b-1].age.mois);
		printf("votre jour  : %d \n",a[i].age.jour);
		
}




void mage(p *a,int b){
	int i, anneactuelle=2022;
	float s,m;
	for(i=0;i<b;i++){
	      s+=(anneactuelle-a[i].age.annee);
	}
	m=s/b;
	printf("le moyenne d age est %f : ",s/b );
}




int main(){
	int a,c,i=0;
	p *p1=NULL;
	
	 printf("saisir la dimension du tableau : ");
	a=getInt();
    p1=initialiser(p1,a);
	insererelement(p1,a);
	printf("****************\n");
	affichage(p1,a);
	
	
	do{
		printf("pour trie un tableau taper 1 : \n");
	printf("pour l etudiant le plus grand taper 2 : \n");
	printf("pour l etudiant le plus petit taper 3 : \n");
	printf("pour moyenne age des etudiant  taper 4 : \n");
	printf("pour quiter taper   taper 5: ");
	c=getInt();
	
	
	switch(c){
	case 1:	triparselection(p1,a);affichage(p1,a); break;
	case 2: pg(p1,a); break;
	case 3:	pp(p1,a); break;
	case 4:	mage(p1,a); break;
	case 5:  i=1;break;
	}
		
	}while(i==0);
	
	/*
	printf("\ntrie \n");
	
	printf("\n****************** \n");
	pgpp(p1,a);
		printf("\n****************** \n");
		mage(p1,a);*/
	return 0;
}
