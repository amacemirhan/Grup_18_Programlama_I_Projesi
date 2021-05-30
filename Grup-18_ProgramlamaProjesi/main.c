#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <conio.h>

//Grup-18 Programlama I dersi d�nem projesi  Tic-Tac-Toe oyunu

char matris[22][34];//Oyunun g�r�n�m�n�n yaz�ld��� genel matris
//Tablodaki 9 adet karenin en sol �st k��esi koordinatlar�
int kareKoordinat[9][3]={{1,1,1},{1,12,2},{1,23,3},{8,1,4},{8,12,5},{8,23,6},{15,1,7},{15,12,8},{15,23,9}};
int kare[10]={0,1,2,3,4,5,6,7,8,9};

void deleteMatris(){//Matrisin i�indeki karakterleri silen fonksiyon
    for(int a=0;a<22;a++){
       for(int b=0;b<34;b++){
        matris[a][b]=' ';
        }
    }
    for(int i=1;i<11;i++)
    kare[i]=i;
}
void printKareOrtasiSayi(){//Tablodaki 9 adet karenin ortalar�n� numaralar�n�n yerle�tirilmesini sa�layan fonksiyon
    int i,j,w;
    for(int a=0;a<9;a++){
            i=kareKoordinat[a][0];
            j=kareKoordinat[a][1];
            w=kareKoordinat[a][2];
        for(int b=0;b<22;b++){
       for(int c=0;c<34;c++){
        if(b==i && c==j){
            matris[b+2][c+4]=w+'0';
        }
        }
    }
    }
}
void printO(int Koordinat){//Matrise numaras� gelen kareye O yazd�rma fonksiyonu
    int i,j;
    for(int k=0;k<9;k++){
        if(kareKoordinat[k][2]==Koordinat){
            i=kareKoordinat[k][0];
            j=kareKoordinat[k][1];
        }
    }
    for(int a=0;a<22;a++){
       for(int b=0;b<34;b++){
        if(a==i && b==j){
            matris[a][b+3]='_';
            matris[a][b+4]='_';
            matris[a][b+5]='_';
            matris[a][b+6]='_';
            matris[a+4][b+3]='_';
            matris[a+4][b+4]='_';
            matris[a+4][b+5]='_';
            matris[a+4][b+6]='_';
            matris[a+2][b+1]='/';
            matris[a+1][b+2]='/';
            matris[a+3][b+8]='/';
            matris[a+4][b+7]='/';
            matris[a+1][b+7]='\\';
            matris[a+2][b+8]='\\';
            matris[a+3][b+1]='\\';
            matris[a+4][b+2]='\\';
            matris[a+2][b+4]=' ';//O yazd�r�rken yazd�rmadan �nceki karenin ortas�ndaki numaray� siliyor
        }
        }
    }

}
void printX(int Koordinat){//Matrise numaras� gelen kareye X yazd�rma fonksiyonu
    int i,j;
    for(int k=0;k<9;k++){
        if(kareKoordinat[k][2]==Koordinat){
            i=kareKoordinat[k][0];
            j=kareKoordinat[k][1];
        }
    }
    for(int a=0;a<22;a++){
       for(int b=0;b<34;b++){
        if(a==i && b==j){
            matris[a+1][b+3]='\\';// C de sola yat�k tek '\' yazd�rmak i�in arka arkaya iki tane yaz�l�r compiler onu tek alg�lar
            matris[a+1][b+6]='/';
            matris[a+2][b+4]='\\';
            matris[a+2][b+5]='/';
            matris[a+3][b+4]='/';
            matris[a+3][b+5]='\\';
            matris[a+4][b+3]='/';
            matris[a+4][b+6]='\\';
        }
        }
    }
}
void printMatris(){//Matrisi konsola yazd�r�r
    for(int i=0;i<22;i++){
        for(int j=0;j<34;j++){
        printf("%c",matris[i][j]);
    }
    printf("\n");
    }
};
void mainMatris(){//Temel oyun tablosunu olu�turur
    for(int i=0;i<22;i++){
       for(int j=0;j<34;j++){
        if((i==0 && j%11==0)||(i==7 && j%11==0)||(i==14 && j%11==0)||(i==21 && j%11==0)){
            matris[i][j]='+';
        }
        else if(i==0 || i==7 || i==14 || i==21){
            matris[i][j]='-';
        }else if(j%11==0){
            matris[i][j]='|';
        }
        }
    }
}
int kazanmaKontrol(){
    if (kare[1] == kare[2] && kare[2] == kare[3])
        return 1; //Kazanma durumu
    else if (kare[4] == kare[5] && kare[5] == kare[6])
        return 1; //Kazanma durumu

    else if (kare[7] == kare[8] && kare[8] == kare[9])
        return 1; //Kazanma durumu

    else if (kare[1] == kare[4] && kare[4] == kare[7])
        return 1; //Kazanma durumu

    else if (kare[2] == kare[5] && kare[5] == kare[8])
        return 1; //Kazanma durumu

    else if (kare[3] == kare[6] && kare[6] == kare[9])
        return 1; //Kazanma durumu

    else if (kare[1] == kare[5] && kare[5] == kare[9])
        return 1; //Kazanma durumu

    else if (kare[3] == kare[5] && kare[5] == kare[7])
        return 1; //Kazanma durumu
    else if (kare[1] != 1 && kare[2] != 2 && kare[3] != 3
             && kare[4] != 4 && kare[5] != 5 && kare[6] != 6
             && kare[7] != 7 && kare[8] != 8 && kare[9] != 9)
        return -1; //Beraberlik durumu
    else
        return  0; // Oynun devamlilik durumu
}
void OpeningScreen(){//A��l�� ekran� bast�rma fonksiyonu
	printf(" /$$$$$$$$  /$$   /$$$$$$$$          /$$$$$$$$  /$$$$$$$$$  /$$$$$$$$           /$$$$$$$$   /$$$$$$   /$$$$$$$$\n");
	printf("|___/$$__/ |__/  | $$_____/         |___/$$__/ | $$ ___/$$ | $$_____/          |___/$$__/  /$$___/$$ | $$_____/\n");
	printf("   | $$    | $$  | $$                  | $$    | $$   | $$ | $$                   | $$    | $$  | $$ | $$      \n");
	printf("   | $$    | $$  | $$       /$$$$$$    | $$    | $$   | $$ | $$        /$$$$$$    | $$    | $$  | $$ | $$$$$$$ \n");
	printf("   | $$    | $$  | $$      |______/    | $$    | $$$$$$$$$ | $$       |______/    | $$    | $$  | $$ | $$____/ \n");
	printf("   | $$    | $$  | $$                  | $$    | $$   | $$ | $$                   | $$    | $$  | $$ | $$      \n");
	printf("   | $$    | $$  | $$$$$$$$            | $$    | $$   | $$ | $$$$$$$$             | $$    |  $$$$$$/ | $$$$$$$$\n");
	printf("   |__/    |__/  |________/            |__/    |__/   |__/ |________/             |__/     \\______/  |________/\n\n\n");
	printf("Ama� �� adet O veya X\'i �apraz-yatay-dikey olarak s�ralamakt�r.\n�nce X ba�lar, sonraki her tur �nceki oyunun kazanan� ba�lar.\n");
	printf("Ba�lamak icin herhangi bir tu�a bas�n�z...");
	getch();
	system("CLS");
}




int main()
{
    	setlocale(LC_ALL, "Turkish");
	OpeningScreen();
    int scoreX=0,scoreO=0;
    char devam;
    char isaret;
    int currentHamle;
    int player=1;
    int kontrol;
    int hata=0;
    int sayac=0;

    do{
        deleteMatris();
        mainMatris();
        printKareOrtasiSayi();
        system("CLS");
        if(sayac!=0)
        player++; //kazanan ilk oynar
        sayac++;
        do{
        printMatris();
        player = (player % 2) ? 1 : 2; //siradaki oyuncuyu belirlemek icin
        isaret = (player % 2) ? 'X' : 'O'; //siradaki oyuncunun isaretini belirlemek icin
        printf(" %c ==> %d.oyuncunun s�ras�, say� girin:",isaret,player);
        scanf("%d",&currentHamle);
        system("CLS");
        if(currentHamle == 1 && kare[1] == 1)
            kare[1] = isaret;
        else if(currentHamle == 2 && kare[2] == 2)
            kare[2] = isaret;
        else if(currentHamle == 3 && kare[3] == 3)
            kare[3] = isaret;
        else if(currentHamle == 4 && kare[4] == 4)
            kare[4] = isaret;
        else if(currentHamle == 5 && kare[5] == 5)
            kare[5] = isaret;
        else if(currentHamle == 6 && kare[6] == 6)
            kare[6] = isaret;
        else if(currentHamle == 7 && kare[7] == 7)
            kare[7] = isaret;
        else if(currentHamle == 8 && kare[8] == 8)
            kare[8] = isaret;
        else if(currentHamle == 9 && kare[9] == 9)
            kare[9] = isaret;
        else{
            hata++;
            printf("\n***GE�ERS�Z HAMLE***\n\n");
            continue; //gecersiz bir hareket olursa atlat
            }
        if(isaret == 'X')
            printX(currentHamle);//X'i bas
        if(isaret == 'O')
            printO(currentHamle);//O'yu bas

        kontrol = kazanmaKontrol(); //kontrol fonksiyonu
        player++;
    }while(kontrol == 0);
    if(hata==1)
    hata--;
    if(hata != 1){
    printMatris();
    if(kontrol==1){
        if(isaret=='X')
        scoreX++;
        else
        scoreO++;
        system("color 20");
        printf(" %c ==> %d.oyuncu kazand�!!\n",isaret,player%2+1);
        printf("X oyuncu: %d \t O oyuncu: %d\n",scoreX,scoreO);
    }
    if(kontrol==-1){
    	system("color 60");
    	printf("BERABERL�K!!\n");
	}
    printf("Bir daha oynamak ister misin[e/h]?");
    devam = getche();
    system("color 07");
    printf("\n");
    }

    }while(devam != 'h' && devam == 'e');
    if(scoreX > scoreO) //X OYUNCU KAZANDI (PUAN OLARAK)
    printf("-------- X oyuncusu %d puan ile kazand� \t O oyuncusu ise %d puan ile kaybetti! --------",scoreX,scoreO);
    else if(scoreO > scoreX) //O OYUNCU KAZANDI (PUAN OLARAK)
    printf("-------- O oyuncusu %d puan ile kazand� \t X oyuncusu ise %d puan ile kaybetti! --------",scoreO,scoreX);
    else if(scoreX == scoreO) //Puanlar e�it olursa
    printf("-------- �ki oyuncu da ayn� puan� ald�! Kimse kazanamad� :D --------");
    getch();
    return 0;
}



