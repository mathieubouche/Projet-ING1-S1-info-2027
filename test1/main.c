#include "biblio.h"
void tuileL1(){
    char tablo[3][3]={{'#','_','#'},{'#','_','_'},{'#','#','#'}};
    for (int i=0; i<3;i++){
        for(int j=0; j<3; j++){
            printf("%3c",tablo[i][j]);
        }
        printf("\n");
    }
}
void tuileL2(){
    char tablo[3][3]={{'#','#','#'},{'#','_','_'},{'#','_','#'}};
    for (int i=0; i<3;i++){
        for(int j=0; j<3; j++){
            printf("%3c",tablo[i][j]);
        }
        printf("\n");
    }
}
void tuileL3(){
    char tablo[3][3]={{'#','#','#'},{'_','_','#'},{'#','_','#'}};
    for (int i=0; i<3;i++){
        for(int j=0; j<3; j++){
            printf("%3c",tablo[i][j]);
        }
        printf("\n");
    }
}
void tuileL4(){
    char tablo[3][3]={{'#','_','#'},{'_','_','#'},{'#','#','#'}};
    for (int i=0; i<3;i++){
        for(int j=0; j<3; j++){
            printf("%3c",tablo[i][j]);
        }
        printf("\n");
    }
}
void tuileI1(){
    char tablo[3][3]={{'#','_','#'},{'#','_','#'},{'#','_','#'}};
    for (int i=0; i<3;i++){
        for(int j=0; j<3; j++){
            printf("%3c",tablo[i][j]);
        }
        printf("\n");
    }
}
void tuileI2(){
    char tablo[3][3]={{'#','#','#'},{'_','_','_'},{'#','#','#'}};
    for (int i=0; i<3;i++){
        for(int j=0; j<3; j++){
            printf("%3c",tablo[i][j]);
        }
        printf("\n");
    }
}
void tuileT1(){
    char tablo[3][3]={{'#','_','#'},{'#','_','_'},{'#','_','#'}};
    for (int i=0; i<3;i++){
        for(int j=0; j<3; j++){
            printf("%3c",tablo[i][j]);
        }
        printf("\n");
    }
}
void tuileT2(){
    char tablo[3][3]={{'#','_','#'},{'_','_','#'},{'#','_','#'}};
    for (int i=0; i<3;i++){
        for(int j=0; j<3; j++){
            printf("%3c",tablo[i][j]);
        }
        printf("\n");
    }
}
void tuileT3(){
    char tablo[3][3]={{'#','_','#'},{'_','_','_'},{'#','#','#'}};
    for (int i=0; i<3;i++){
        for(int j=0; j<3; j++){
            printf("%3c",tablo[i][j]);
        }
        printf("\n");
    }
}
void tuileT4(){
    char tablo[3][3]={{'#','#','#'},{'_','_','_'},{'#','_','#'}};
    for (int i=0; i<3;i++){
        for(int j=0; j<3; j++){
            printf("%3c",tablo[i][j]);
        }
        printf("\n");
    }
}
void plateau(){
    char tablo[3][3]={{'#','#','#'},{'#','_','_'},{'#','_','#'}};
    char plato[7][7];
    plato[0][0]=tablo;
    printf("%3c",plato[0][0]);
}
int main(){
    plateau();
    return 0;
}