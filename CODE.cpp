#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>

int a[100][100],n;

int cark(int );
int  *ozdegerbul ();
long int schur(int [], int);
void nilpotent();
int carpanlar(int [100], int);
long int determinant(int f[100][100],int a);


main()
{
	int islem,donme,i;
	int *ozdegerler;
	//Çark dönmesi
	printf("Carkin kac kere donecegi bilgisini giriniz : ");
	scanf("%d",&donme);
	
	//dönme sonucu iþlemin belirlenmesi
	islem = cark(donme);
	islem++;
	printf("\n\n\n%d Numarali islem yapilacaktir...\n",islem);
	
	if(islem == 1 ) ozdegerler = ozdegerbul();
	else if(islem == 2 ) printf("Ozvektor bulma islemi yapilamiyor...\n");
	else if(islem == 3 )  
	{
		ozdegerler = ozdegerbul();
		int Sozdegerler[30];
		printf("\n");
		
		
		int elemanS = 0;
		for(i = 1; i<=30; i++)
		{
			if(ozdegerler[i] != 0) {
			//	printf("%d != 0 \n",ozdegerler[i]);
				elemanS++;
			}
			else break;	
		}
		
		//elemanS--;
		printf("\nOzdeger sayisi = %d\n",elemanS);
		
		 for(i = 0; i < elemanS; i++ ) 
		{
            Sozdegerler[i] = *(ozdegerler+(i+1));
            printf("Sozdegerler[%d] : %d \n",i, Sozdegerler[i] );
			
		}
		
		long int sc ;
	 	sc = schur(Sozdegerler,(elemanS));
		printf("\nSinir Degeri : %d",sc);
	}
	else if(islem == 4 ) 
	{
		nilpotent();
	}

}	

/////////*****************////////////////
//Çark
int cark( int n){
	
	int islem,rastgele,sonSayi;
	srand(time(NULL));
	
   printf("\nUretilen Sayilar : \n");
   for(int i = 1; i<=n ; i++){
   	
   	rastgele=rand()%241;
    printf("%d \n",rastgele);
    sonSayi = rastgele;
    
   }
    
	islem = sonSayi%4;
	
	return islem;
}


/////////*****************////////////////
//Determinant

long int determinant(int f[100][100],int x)
{
  int isaret,c[100],b[100][100],j,p,q,t;
  long int d = 0;
  if(x==2)
  {
    d=0;
    d=(f[1][1]*f[2][2])-(f[1][2]*f[2][1]);
    return(d);
   }
  else
  {
    for(j=1;j<=x;j++)
    {        
      int satir=1,stun=1;
      
      for(p=1;p<=x;p++)
        {
          for(q=1;q<=x;q++)
            {
              if(p!=1&&q!=j)
              {
                b[satir][stun]=f[p][q];
                stun++;
                if(stun>x-1)
                 {
                   satir++;
                   stun=1;
                  }
               }
             }
         }
    
	 for(t=1,isaret=1;t<=(1+j);t++)
     isaret=(-1)*isaret;
     c[j]=isaret*determinant(b,x-1);
     }
     
     for(j=1,d=0;j<=x;j++)
     {
       d=d+(f[1][j]*c[j]);
      }
     return(d);
   }
}


/////////////****************////////////////
//Çarpanlar

int  carpanlar(int carpanlari[100], int sayi)
{
int x=1,i = 1,carpanSay = 0;
sayi = abs(sayi);
while(x<=sayi){

if(sayi%x==0){
//	printf("%d,",x);
	carpanlari[i] = x;
	i++;
	carpanSay++;
	
}
x++;
}

return carpanSay;
}


//////////////////////*******////////////////////////////
//Özdeðer
int  *ozdegerbul ()
{
	//***///	
	FILE *ozdegerYAZ;
	ozdegerYAZ = fopen("ozdeger.txt","w");
	//***///
	
	
	printf("\n--- Ozdegerbul() islemi yapilacaktir ---\n");
	
	int i,j;
  printf("\nMatrisin boyutunu(n) giriniz  : ");
  scanf("%d",&n);
  printf("\nMatrisin elemanlarini giriniz : \n");
  for(i=1;i<=n;i++)
  {
  for(j=1;j<=n;j++)
  {
  printf("a[%d][%d] = ",i,j);
  scanf("%d",&a[i][j]);
  }
  }
	
	//matrisi yazdýr
	printf("\n\n---------- Girilen A Matrisi --------------\n");    
  for(i=1;i<=n;i++)
     {
          printf("\n");
          for(j=1;j<=n;j++)
          {     
               printf("\t%d \t",a[i][j]);
          }
     }
	
	//***//Dosyaya yazdýr
	fprintf(ozdegerYAZ,"\n\n---------- Girilen A Matrisi --------------\n"); 
	for(i=1;i<=n;i++)
     {
          printf("\n");
          for(j=1;j<=n;j++)
          {     
               fprintf(ozdegerYAZ, "%d ",a[i][j]);
          }
          fprintf(ozdegerYAZ,"\n");
 	}
	//***//
	
	
	//Tahmini Özdeðerlerin(lamda) deneneceði matrisleri hazýrla
	int adeneme[100][100];
     for(i=1;i<=n;i++)
     {
          for(j=1;j<=n;j++)
          {     
              adeneme[i][j] = a[i][j];
          }
     }
     int adenemeN[100][100];
     for(i=1;i<=n;i++)
     {
          for(j=1;j<=n;j++)
          {     
              adenemeN[i][j] = a[i][j];
          }
     }
     
     //A Matrisinin determinantýný yazdýr
    printf("\n \n");
	printf("\n A matrisinin determinanti =  %d .",determinant(a,n));
	
	//***//dosyaya determinanto da yaz
	fprintf(ozdegerYAZ,"\n A matrisinin determinanti =  %d .",determinant(a,n));
	
	
	//determinantý çarpanlarýna ayýr
	int carpan[100],dt;
    dt = determinant(a,n);
    int carpanSayisi;
    carpanSayisi = carpanlar(carpan,dt);
 
  printf("\nDeterminantin(%d)  Carpanlari : ",dt);
  for(i = 1; i <= carpanSayisi; i++)
  {
  	printf("%d,",(carpan[i]));
  }
  
  //***//Çarpanlarý dosyaya da yaz
  fprintf(ozdegerYAZ,"\nDeterminantin(%d)  Carpanlari : ",dt);
  for(i = 1; i <= carpanSayisi; i++)
  {
  	fprintf(ozdegerYAZ,"%d, ",(carpan[i]));
  }
  
  

  int kd[100],ekd = 0;
  for(i = 1; i <= carpanSayisi; i++)
  {	
	     kd[i] = carpan[i];
  	     ekd++;		 
  }
	
	printf("\nOzdeger olabilecek (denenecek)degerler (%d tane) : ",ekd*2);
  for(i = 1; i <= ekd; i++)
  {
  	printf("%d, %d, ",(kd[i]),(-1)*kd[i]);
  }
	//***///dosyaya
	fprintf(ozdegerYAZ,"\nOzdeger olabilecek (denenecek)degerler (%d tane) : \n",ekd*2);
  for(i = 1; i <= ekd; i++)
  {
  	fprintf(ozdegerYAZ,"%d, %d, ",(kd[i]),(-1)*kd[i]);
  }
	
	
	
	
	//Deðerlerin denenmesi...Hangileri (i==j) elemanlardan çýkrýlýnca detereminant deðeri = 0 oluyor?
  int ozdegerler[30],ozdegerlerN[30],oz = 1, ozN = 1;
  long int subdet,subdetN;
  for(int lamda = 1; lamda <= ekd; lamda++)
  {
  	
  	for(i=1;i<=n;i++)
     {
          for(j=1;j<=n;j++)
          {     
              adeneme[i][j] = a[i][j];
          }
     }
  	
  	 for(i=1;i<=n;i++)
     {
          for(j=1;j<=n;j++)
          {     
              adenemeN[i][j] = a[i][j];
          }
     }
  	
  	
  	for(i=1;i<=n;i++)
     {
         
          for(j=1;j<=n;j++)
          {     
               if(i == j) {
               	
               	adeneme[i][j] = a[i][j] - kd[lamda];
                adenemeN[i][j] = a[i][j] + kd[lamda];
  	
			   }
              
          }
	
     }

      		subdet = determinant(adeneme,n);  
		  	printf("\nlamda = %d icin determinant = %d",kd[lamda],subdet);
		  	fprintf(ozdegerYAZ,"\nlamda = %d icin determinant = %d",kd[lamda],subdet);
          	if(subdet == 0 && (ozdegerler[oz-1] != kd[lamda])) 
		  {
          	ozdegerler[oz] = kd[lamda] ;
          	oz++;
		  }
	    
		  subdetN = determinant(adenemeN,n);
		  printf("\nlamda = %d icin determinant = %d",(-1)*kd[lamda],subdetN);
		  fprintf(ozdegerYAZ,"\nlamda = %d icin determinant = %d",(-1)*kd[lamda],subdetN);
		  if(subdetN == 0) 
		  {
          ozdegerler[oz] = (-1)*kd[lamda] ;
          	oz++;
		  }
     
     
/*	printf("\n\n---------- Matrix A is --------------\n");    
	for(int ii=1;ii<=n;ii++)
     {
          printf("\n");
          for(int jj=1;jj<=n;jj++)
          {     printf("\t%d \t",adeneme[ii][jj]);
          }
          
     }*/
     
   /*  printf("\n\n---------- Matrix A is --------------\n");    
	for(int ii=1;ii<=n;ii++)
     {
          printf("\n");
          for(int jj=1;jj<=n;jj++)
          {     printf("\t%d \t",adenemeN[ii][jj]);
          }
          
     }*/


  }
	
	printf("\n\nOzdegerler : ");
  for(i = 1 ; i<= (oz-1); i++)
  {
  	printf("%d, ",ozdegerler[i]);
  }
	ozdegerler[oz] = 0;
	
	//***//dosya
	fprintf(ozdegerYAZ,"\n\nOzdegerler : ");
  for(i = 1 ; i<= (oz-1); i++)
  {
  	fprintf(ozdegerYAZ,"%d, ",ozdegerler[i]);
  }	
	
	
	
	return ozdegerler;
}





//////////////******************/////////////////
//schur
long int schur(int ozd[], int boyut)
{
	//***//
	FILE *schurYAZ;
	schurYAZ = fopen("schur.txt","w");
	//***//
	
	
	printf("\n---Schur islemi yapilacaktir.---\n");
	int i,j;
	long int ozdegerKare = 0, elemanlarKare = 0;
	//özdegerlerin kareleri toplamýný bul
	for(i = 0; i < boyut; i++)
	{
		ozdegerKare += ozd[i]*ozd[i];
	}
	
  //***//
  fprintf(schurYAZ,"Özdegerlerin kareleri toplamý : \n");
  for(i = 0; i < boyut; i++)
	{
		fprintf(schurYAZ,"(%d)^2 + ",ozd[i]);
		ozdegerKare += ozd[i]*ozd[i];
		
	}
	ozdegerKare = ozdegerKare/2;
  fprintf(schurYAZ," = %d",ozdegerKare);
  
  
  
   printf("\nMatrisin boyutunu(n) giriniz  : ");
  scanf("%d",&n);
  printf("\nMatrisin elemanlarini giriniz : \n");
  for(i=1;i<=n;i++)
  {
  for(j=1;j<=n;j++)
  {
  printf("a[%d][%d] = ",i,j);
  scanf("%d",&a[i][j]);
  }
  }
  
  	//***//Dosyaya yazdýr
	fprintf(schurYAZ,"\n\n---------- Girilen A Matrisi --------------\n"); 
	for(i=1;i<=n;i++)
     {
          printf("\n");
          for(j=1;j<=n;j++)
          {     
               fprintf(schurYAZ, "%3d ",a[i][j]);
          }
          fprintf(schurYAZ,"\n");
 	}


	for(i=1;i<=n;i++)//kullanýcýnýn girdiði matris
     {					
          for(j=1;j<=n;j++)
          {     
              elemanlarKare += a[i][j]*a[i][j];
          }
     }
	

	
	if(ozdegerKare < elemanlarKare)
	{
			printf("\nScur Teoremi : %d < %d\n",ozdegerKare,elemanlarKare);
			//***//
			fprintf(schurYAZ,"\n--->Schur Teoremi : %d < %d\n",ozdegerKare,elemanlarKare);	
	} 
	
	if(ozdegerKare == elemanlarKare)
	{
			printf("\nScur Teoremi : %d <= %d\n",ozdegerKare,elemanlarKare);
			//***//
			fprintf(schurYAZ,"\n--->Schur Teoremi : %d <= %d\n",ozdegerKare,elemanlarKare);	
	} 
	
	
	//***//
	fprintf(schurYAZ,"Matris elemanlarýnýn kareleri toplamý = %d\n",elemanlarKare);
	fprintf(schurYAZ,"\nSchur sýnýr deðeri : %d\n",elemanlarKare);

	return elemanlarKare;
	
}


/////////////*********************/////////////////////////////
//Nilpotent
void nilpotent()
{

	//***//
	FILE *nilpotentYAZ;
	nilpotentYAZ = fopen("nilpotent.txt","w");

	printf("\n---Nilpotenet islemi yapilacaktir.---\n");
	int  toplam = 0,n;
    
	printf("Matrisin boyutu giriniz : ");
    scanf("%d",&n);
    int a[100][100], a2[100][100];
	long int  carpim[100][100];
    
    int rastgele;
    srand(time(NULL)); 
    //matris deðerlerini rastgele üretiyorum
    for(int i=1; i<=n; i++)
	{
        for(int j=1; j<=n; j++)
		{	
   			rastgele = (rand()%30) - 15;
   			
			a[i][j] = rastgele;
			printf("a[%d][%d] = %d\n", i, j,a[i][j]);
        }
    }
    printf("\n");
    
    //***//
    fprintf(nilpotentYAZ,"\nRastgele üretilen A matrisi aþaðýdaki gibidir : \n");
	for(int i=1; i<=n; i++)
	{
        for(int j=1; j<=n; j++)
		{
            fprintf(nilpotentYAZ,"%2d ",a[i][j]);
        }
        fprintf(nilpotentYAZ,"\n");
    }
	

	for(int i=1; i<=n; i++)
	{
        for(int j=1; j<=n; j++)
		{
            a2[i][j] = a[i][j];
        }
    }
    
    
    int us = 1;
    do
	{
	    us++;
		printf("\n%d.Derece : \n",us);
		
		for(int i=1; i<=n; i++)
	{  
        for(int j=1; j<=n; j++)
		{
            for(int k=1; k<=n; k++)
			{
                toplam += a[i][k] * a2[k][j]; 
            }
            carpim[i][j] = toplam;  
            toplam = 0;  
            printf("%d ", carpim[i][j]); 
        }
      printf("\n");
    }
      
      //***//
        fprintf(nilpotentYAZ,"\nA^%d Aþaðýdaki Gibidir : \n",us);
       for(int i=1; i<=n; i++)
	{
        for(int j=1; j<=n; j++)
		{
            fprintf(nilpotentYAZ,"%2d ",carpim[i][j]);
        }
        
        fprintf(nilpotentYAZ,"\n");
    }
      
      
      
	  //a2 matrisini carpima eþitleme
	  for(int i=1; i<=n; i++)
	  {
        for(int j=1; j<=n; j++)
		{
            a2[i][j] = carpim[i][j];
        }
    }
      
      //a2 kontrol et 0 ise eðer us = 17 yap (break)
      int sayac = 0;
	  for(int i=1; i<=n; i++)
	{
        for(int j=1; j<=n; j++)
		{
            if(a2[i][j] == 0) sayac++;
        }
    }
      
    if(sayac == (n*n))
	{
    	printf("A matrisinin %d. kuvveti (A^%d) = 0 oldugundan Nilpotenttir...",us,us);
    	fprintf(nilpotentYAZ,"A matrisinin %d. kuvveti (A^%d) = 0 oldugundan Nilpotenttir...",us,us);
		us = 17;
	}
      
      
	
	}while(us != 17);
    
    printf("\n-->Matris Nilpotent Degildir.\n");
    fprintf(nilpotentYAZ,"\n-->Matris Nilpotent Degildir.\n");
    
}

















