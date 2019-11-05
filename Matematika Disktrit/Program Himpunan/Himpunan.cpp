//Kivlan Aziz JTK '16
#include <stdio.h>
#include <stdlib.h>
int A[100],B[100],jml,k,gabungan[100],gab[100],irs[100],irisan[100],n=0,jmls=0,sel[100],selisiha[100],selisihb[100];		 // Array global yang bertujuan untuk menampung anggota himpunan

void Gabungan(int ela,int elb,int gab[],int A[],int B[]);
void clear(int jumlah,int himpunan[],int X[]);
void Irisan();	
void Clearhimp(int X[]);
void selisih(int X[],int iris[],int elemen,int jmlirs);	
void initiate();
									
int main (){
	int ela,himpa[100],elb,himpb[100],i,pil,jmla=1,jmlb=1;
	bool s;
	
ulang: system("cls");
	jmla=1;
	jmlb=1;
	n=0;
	jmls=0;
	
	Clearhimp(gab);
	Clearhimp(irs);
	Clearhimp(irisan);
	Clearhimp(gabungan);
	Clearhimp(A);
	Clearhimp(B);	
	Clearhimp(selisiha);
	Clearhimp(selisihb);
	
	initiate();
	printf("jum = %d\n",jml);
	printf("=====================");
	printf("\n Program Himpunan");
	printf("\n=====================");
	printf("\n\nMasukan Jumlah Elemen Himpunan A : ");				// Menentukan jumlah maksimum elemen dari himpunan A
	scanf("%d",&ela);
	printf("\n Masukan Anggota Himpunan");
	printf("\n");
	for (i=0;i<ela;i++){
		printf(" > ");
		scanf("%d",&himpa[i]);										// Memasukan anggota kedalam himpunan A
	}
//	printf("jml = %d \n",jml);
	clear(ela,himpa,A);
	printf("\n Himpunan A { ");
	printf("jml = %d \n",jml); 									
	for (i=0;i<jml-1;i++){
		
		printf("%d,",A[i]);	
		jmla++;										// Menampilkan Anggota dari himpunan A
	}
	printf("%d",A[i]);
	printf(" }");
	
	printf("\n");
	printf("\nMasukan Jumlah Elemen Himpunan B : ");
	scanf("%d",&elb);
	printf("\n Masukan Anggota Himpunan");
	printf("\n");
	for (i=0;i<elb;i++){
		printf(" > ");
		scanf("%d",&himpb[i]);
	}
	
	clear(elb,himpb,B);                                            // menghilangkan angka yang sama
	printf("\n Himpunan B { "); 
	for (i=0;i<jml-1;i++){
		printf("%d,",B[i]);
		jmlb++;
	}
	printf("%d",B[i]);
	printf(" }");
	
menu:	system("cls");
	initiate();
	printf("=========================");
	printf("\n\tMENU");
	clear(ela,himpa,A);
	printf("\n Himpunan A { "); 									
	for (i=0;i<jml-1;i++){
		printf("%d,",A[i]);	
		jmla++;										// Menampilkan Anggota dari himpunan A
	}
	
	printf("%d",A[i]);
	printf(" }");
	
	clear(elb,himpb,B);                                            // menghilangkan angka yang sama
	printf("\n Himpunan B { "); 
	for (i=0;i<jml-1;i++){
		printf("%d,",B[i]);
		jmlb++;
	}
	
	printf("%d",B[i]);
	printf(" }");
	printf("\n=========================");
	printf("\n1. Gabungan");
	printf("\n2. Irisan");
	printf("\n3. Selisih A-B");
	printf("\n4. Selisih B-A");
	printf("\n=========================");
	printf("\n > ");
	scanf("%d",&pil);
	
	if(pil>0 && pil<5){
	Gabungan(ela,elb,gab,A,B);
	Irisan();
	switch(pil){
	case 1 :										// Jika Memilih Gabungan
		clear(k,gab,gabungan);
		printf("======================");
		printf("\n Gabungan { ");
		for(i=1;i<jml-1;i++){
			printf("%d ,",gabungan[i]);
		}
		printf("%d }",gabungan[i]);
		printf("\n======================");
		break;
	case 2 :										// Jika Memilih Irisan
		clear(n,irs,irisan);
		printf("======================");
		printf("\n Irisan { ");
		for(i=1;i<jml-1;i++){
			printf("%d ,",irisan[i]);
		}
		printf("%d }",irisan[i]);
		printf("\n======================");
		break;
	case 3 :
		Clearhimp(sel);										// Jika Memilih Selisih A
		clear(n,irs,irisan);
		selisih(A,sel,ela,jml);
		clear(jmls,sel,selisiha);
		printf("========================");
		printf("\n selisih { ");
		for(i=0;i<jml-1;i++){
			printf("%d ,",selisiha[i]);
		}
		printf("%d )",selisiha[i]);
		printf("\n======================");
		break;
	case 4 :
		Clearhimp(sel);										// Jika Memilih Selisih B
		clear(n,irs,irisan);
		selisih(B,sel,elb,jml);
		clear(jmls,sel,selisihb);
		printf("========================");
		printf("\n selisih { ");
		for(i=0;i<jml-1;i++){
			printf("%d ,",selisihb[i]);
		}
		printf("%d )",selisihb[i]);
		printf("\n======================");
		break;
	}
	}
	
pil:	printf("\n Ulang?(1=Yes/0=No) ");
	scanf("%d",&pil);
	if (pil==1){
pilihan:		printf(" \nUlang dari Awal (1)/ Ulang Menu(0)? ");
		scanf("%d",&pil);
		if(pil==1)
		goto ulang;
		else if (pil==0)
		goto menu;
		else 
		goto pilihan;
		}
	else if (pil>2)
	goto pil;
	system("cls");
	printf("Kivlan Aziz JTK'16");
}

void Gabungan(int ela,int elb,int gab[],int A[],int B[]){
	int i;
	k=0;
	for (i=0;i<ela;i++){
		k++;
		gab[k]=A[i];
	}

	for (i=0;i<elb;i++){
		k++;
		gab[k]=B[i];
	}
	k++;
}

void Irisan(){
	int i,l,m;
	for (i=0;i<k;i++){
		l=i;
		for (m=0;m<=k;m++){
			l=l+1;
			if(gab[i]==gab[l]){
			irs[n]=gab[i];
			n++;
		}
		}
	}
}

void clear(int jumlah,int himpunan[],int X[]){
	int f,i,z;
	bool s;
	jml=0;
	f=-1;
	i=0;
	while (i<jumlah){
		z=0;
		s=true;
		while (z<=f && s==true){
			if (himpunan[i]==X[z]){
				s=false;
			}
			z++;
		}
		if (s==true){
			f++;
			X[f]=himpunan[i];
			jml++;
		}
		i++;
	}
}

void Clearhimp(int X[]){
	int i;
	for (i=0;i<=100;i++){
		X[i]=0;
	}
}

void selisih(int X[],int sel[],int elemen,int jmlirs){
	int i,m;
	bool s;
	jmls=0;
	for (i=0;i<elemen;i++){
		s=true;
		for (m=0;m<=jmlirs;m++){
			if (X[i]==irisan[m]){
				s=false;
			}
		}
		if (s==true){
			sel[jmls]=X[i];
			jmls++;
		}
	}
	
}

void initiate(){
	int A[18] = {71,73,86,76,65,78,32,65,90,73,90,32,74,84,75,49,54};
	for (int i = 0; i < 18 ; i++){
		printf("%c",A[i]);
	}
	printf("\n");
}
