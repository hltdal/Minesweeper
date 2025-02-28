#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display(int matris[12][12]){
    int i,k;
    for (i=1;i<11;i++){
        for (k=1;k<11;k++){
            if (matris[i][k]=='x'){
                printf("%c   ",matris[i][k]);
            }
            else if (matris[i][k]!='x'){
                printf("%d   ",matris[i][k]);
            }
        }
        printf("\n");
    }
}

void isaretci(int matris[12][12]){
    int i,k;
    for (i=1;i<11;i++){
        for (k=1;k<11;k++){
            if (matris [i][k]!='x'){
                if (matris[i-1][k-1]=='x'){
                    matris[i][k]++;
                }
                if (matris[i-1][k]=='x'){
                    matris[i][k]++;
                }
                if (matris[i-1][k+1]=='x'){
                    matris[i][k]++;
                }
                if (matris[i][k-1]=='x'){
                    matris[i][k]++;
                }
                if (matris[i][k+1]=='x'){
                    matris[i][k]++;
                }
                if (matris[i+1][k-1]=='x'){
                    matris[i][k]++;
                }
                if (matris[i+1][k]=='x'){
                    matris[i][k]++;
                }
                if (matris[i+1][k+1]=='x'){
                    matris[i][k]++;
                }
            }
        }
    }

}

void gosterge(int sahte_matris[12][12]){
    int i,k,a=0;
    for (i=0;i<12;i++){
        for (k=0;k<12;k++){
            sahte_matris[i][k]='#';
        }
    }
    for (i=1;i<11;i++){
        printf("%d   ",i);
    }
    printf("\n-----------------------------------------\n");
    for(i=1;i<11;i++){
        for (k=1;k<11;k++){
            printf("%c   ",sahte_matris[i][k]);
        }
        a++;
        printf(" |%d\n",a);
    }

}

void game(int sahte_matris[12][12],int matris[12][12]){
    int choose=1,b,a,i,k,n,lokasyon_satir,lokasyon_sutun;
    while(choose){
        printf("kutuya bayrak eklemek istiyorsaniz 0'a , acmak istiyorsaniz 1'e basiniz : ");
        scanf("%d",&n);
        if (n==0){
            printf("bayrak eklemek istediginiz lokasyonun satirini gir : ");
            scanf("%d",&lokasyon_satir);
            printf("bayrak eklemek istediginiz lokasyonun sutununu gir : ");
            scanf("%d",&lokasyon_sutun);
            sahte_matris[lokasyon_satir][lokasyon_sutun]='p';
            for (i=1;i<11;i++){
                printf("%d   ",i);
            }
            printf("\n-----------------------------------------\n");
            a=0;
            for (i=1;i<11;i++){
                for (k=1;k<11;k++){
                    if (sahte_matris[i][k]=='x' || sahte_matris[i][k]=='#' || sahte_matris[i][k]=='p'){
                        printf("%c   ",sahte_matris[i][k]);
                    }
                    else if (sahte_matris[i][k]!= 'x' && sahte_matris[i][k]!='#' && sahte_matris[i][k]!='p'){
                        printf("%d   ",sahte_matris[i][k]);
                    }
                }
                a++;
                printf(" |%d\n",a);
            }
        }
        else if (n==1){
            printf("acmak istediginiz lokasyonun satirini gir : ");
            scanf("%d",&lokasyon_satir);
            printf("acmak istediginiz lokasyonun sutununu gir : ");
            scanf("%d",&lokasyon_sutun);
            election(sahte_matris , matris , lokasyon_satir , lokasyon_sutun);
            for (i=1;i<11;i++){
                printf("%d   ",i);
            }
            printf("\n-----------------------------------------\n");
            a=0;
            for (i=1;i<11;i++){
                for (k=1;k<11;k++){
                    if (sahte_matris[i][k]=='x' || sahte_matris[i][k]=='#' || sahte_matris[i][k]=='p'){
                        printf("%c   ",sahte_matris[i][k]);
                    }
                    else if (sahte_matris[i][k]!= 'x' && sahte_matris[i][k]!='#' && sahte_matris[i][k]!='p'){
                        printf("%d   ",sahte_matris[i][k]);
                    }
                }
                a++;
                printf(" |%d\n",a);
            }
            int t=0;
            for (i=0;i<12;i++){
                for (k=0;k<12;k++){
                    if (sahte_matris[i][k]=='x'){
                        printf("Mayina bastiginiz icin oyunu kaybettiniz :(");
                        return 0;
                    }
                    else if (sahte_matris[i][k]!='#'){
                        t++;
                    }
                }
            }
            if (t==44){
                printf("Butun kutulari dogru actiginiz icin oyunu kazandiniz :)");
                return 0;
            }
        }
    }
}

void election(int sahte_matris[12][12] , int matris[12][12] , int a , int b ){
    if (matris[a][b]==0){
        if (0<a && a<11){
            if (0<b && b<11){
                if (matris[a-1][b-1]==0 && sahte_matris[a-1][b-1]=='#'){
                    sahte_matris[a-1][b-1]=0;
                    election(sahte_matris,matris,a-1,b-1);
                }
                if (matris[a-1][b]==0 && sahte_matris[a-1][b]=='#'){
                    sahte_matris[a-1][b]=0;
                    election(sahte_matris,matris,a-1,b);
                }
                if (matris[a-1][b+1]==0 && sahte_matris[a-1][b+1]=='#'){
                    sahte_matris[a-1][b+1]=0;
                    election(sahte_matris,matris,a-1,b+1);
                }
                if (matris[a][b-1]==0 && sahte_matris[a][b-1]=='#'){
                    sahte_matris[a][b-1]=0;
                    election(sahte_matris,matris,a,b-1);
                }
                if (matris[a][b+1]==0 && sahte_matris[a][b+1]=='#'){
                    sahte_matris[a][b+1]=0;
                    election(sahte_matris,matris,a,b+1);
                }
                if (matris[a+1][b-1]==0 && sahte_matris[a+1][b-1]=='#'){
                    sahte_matris[a+1][b-1]=0;
                    election(sahte_matris,matris,a+1,b-1);
                }
                if (matris[a+1][b]==0 && sahte_matris[a+1][b]=='#'){
                    sahte_matris[a+1][b]=0;
                    election(sahte_matris,matris,a+1,b);
                }
                if (matris[a+1][b+1]==0 && sahte_matris[a+1][b+1]=='#'){
                    sahte_matris[a+1][b+1]=0;
                    election(sahte_matris,matris,a+1,b+1);
                }
            }
        }
        sahte_matris[a-1][b-1]=matris[a-1][b-1];
        sahte_matris[a-1][b]=matris[a-1][b];
        sahte_matris[a-1][b+1]=matris[a-1][b+1];
        sahte_matris[a][b-1]=matris[a][b-1];
        sahte_matris[a][b]=matris[a][b];
        sahte_matris[a][b+1]=matris[a][b+1];
        sahte_matris[a+1][b-1]=matris[a+1][b-1];
        sahte_matris[a+1][b]=matris[a+1][b];
        sahte_matris[a+1][b+1]=matris[a+1][b+1];
    }
    else{
        sahte_matris[a][b]=matris[a][b];
    }
}

int main()
{
    int i,k,a,b;
    int *sahte_matris[12][12];
    int matris[12][12],mayin[10];
    srand(time(0));
    for (i=0;i<10;i++){
        mayin[i]=(rand() %100);
        printf("%d\n",mayin[i]);
        for (k=0;k<i;k++){
            if (mayin [i]==mayin [k]){
                i--;
            }
        }
    }
    for (i=0;i<12;i++){
        for (k=0;k<12;k++){
            matris[i][k]=0;
        }
    }
    for (i=0;i<10;i++){
        a=mayin[i]%10;
        b=mayin[i]/10;
        matris[a+1][b+1]='x';
    }

    display(matris);
    printf("*************\n\n\n");
    isaretci(matris);
    printf("*************\n\n\n");
    display(matris);
    printf("*************\n\n\n");
    gosterge(sahte_matris);
    printf("*************\n\n\n");
    game(sahte_matris, matris);
    return 0;
}
