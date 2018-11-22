#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include "../include/boolean.h"
#include "../include/mesincommand.h"
#include "../include/mesinkatakomparasi.h"
#include "../include/array.h"
#include "../include/layar.h"
#include "../include/point.h"
#include "../include/queue.h"
#include "../include/stackt.h"
#include "../include/bintree.h"
#include "../include/movement.h"

/* Global Variable */
char namaUser[20] = "";
boolean isGameOn = false;
LAYAR L;
int lebarLayar = 120;
int tinggiLayar = 40;
POINT player;
/* --------------- */

void InisialisasiOrder(TabInt *TabOrder){
    
}

void PlaceOrder(TabInt *TABOrder){

}

void GambarLayar()
{
    CreateTabel(&L,1,1,lebarLayar,tinggiLayar,1,1);
    CreateGarisHorizontal(&L,0,lebarLayar,5);
    CreateGarisVertikal(&L,30,1,tinggiLayar);
    CreateGarisVertikal(&L,60,1,5);
    CreateGarisVertikal(&L,75,1,5);
    CreateGarisVertikal(&L,lebarLayar-30,5,tinggiLayar);
    CreateGarisHorizontal(&L,1,30,(int)tinggiLayar/2);
    CreateGarisHorizontal(&L,lebarLayar-30,lebarLayar,(int)tinggiLayar/2);
    PutTextAt(&L,5,3,namaUser);
    PutTextAt(&L,35,3,"Money : 500");
    PutTextAt(&L, 65,3,"Life : 2");
    PutTextAt(&L,80,3,"Time : 5");
    printLayar(L);
}

void Update()
{

}

void StartGame(){
    isGameOn = true;
    printf("\n");
}

void NewGame(){
    //isGameOn = true;
    while(IsSameString(namaUser,"")){
        printf("Masukkan Nama Chef : ");
        scanf("%s", namaUser);
    }
    StartGame();
}

void LoadGame(){
    //isGameOn = true;
    printf("\n");
}

void Exit(){
    //isGameOn = false;
    printf("\n");
}

boolean IsPilihanMenuValid(char pilihanMenu){
    return (pilihanMenu >= '1' && pilihanMenu <= '4');
}

void PrintMainMenu(){
    printf("MAIN MENU : \n");
    printf("1. New Game\n");
    printf("2. Start Game\n");
    printf("3. Load Game\n");
    printf("4. Exit\n");
}

void MainMenu(){
    char pilihanMenu;
    printf("SELAMAT DATANG DI ENGI'S KITCHEN!!\n");
    do{
        PrintMainMenu();
        printf("Masukan pilihan Anda : ");
        scanf("%c", &pilihanMenu);
        if(!IsPilihanMenuValid(pilihanMenu)){
            printf("Masukan pilihan Anda tidak valid\n");
            printf("\n");
        }
    } while(!IsPilihanMenuValid(pilihanMenu));
    printf("\n");
    if(pilihanMenu == '1'){
        NewGame();
    }else if(pilihanMenu == '2'){
        StartGame();
    }else if(pilihanMenu == '3'){
        LoadGame();
    }else if(pilihanMenu == '4'){
        Exit();
    }
}

void PrintCommand(){
    printf("DAFTAR COMMAND\n");
    printf("GU : Go Up\n");
    printf("GD : Go Down\n");
    printf("GL : Go Left\n");
    printf("GR : Go Right\n");
    printf("ORDER\n");
    printf("PUT\n");
    printf("TAKE\n");
    printf("CH\n");
    printf("CT\n");
    printf("PLACE\n");
    printf("GIVE\n");
    printf("RECIPE\n");
    printf("SAVE\n");
    printf("LOAD\n");
    printf("EXIT\n");
}

void GU(){

    printf("\n");
}

void GD(){

    printf("\n");
}

void GL(){

    printf("\n");
}

void GR(){

    printf("\n");
}

void ORDER(){

    printf("\n");
}
 
void PUT(){

    printf("\n");
}

void TAKE(){

    printf("\n");
}

void CH(){

    printf("\n");
}

void CT(){

    printf("\n");
}

void PLACE(){

    printf("\n");
}

void GIVE(){

    printf("\n");
}

void RECIPE(){
    
    printf("\n");
}

void SAVE(){

    printf("\n");
}

void LOAD(){

    printf("\n");
}

void EXIT(){

    printf("\n");   
}

void BacaCommand(){
    char pilihanCommand[10];
    do{
        GambarLayar();
        PrintCommand();
        printf("Masukan pilihan Anda : ");
        STARTCOMMAND();
        if(CommandIs("GU")){
            GU();
        }else if(CommandIs("GD")){
            GD();
        }else if(CommandIs("GL")){
            GL();
        }else if(CommandIs("GR")){
            GR();
        }else if(CommandIs("ORDER")){
            ORDER();
        }else if(CommandIs("PUT")){
            PUT();
        }else if(CommandIs("TAKE")){
            TAKE();
        }else if(CommandIs("CH")){
            CH();
        }else if(CommandIs("CT")){
            CT();
        }else if(CommandIs("PLACE")){
            PLACE();
        }else if(CommandIs("GIVE")){
            GIVE();
        }else if(CommandIs("RECIPE")){
            RECIPE();
        }else if(CommandIs("SAVE")){
            SAVE();
        }else if(CommandIs("LOAD")){
            LOAD();
        }else if(CommandIs("EXIT")){
            EXIT();
        }else{
            printf("Masukan pilihan Anda tidak valid\n");
        }
        Update();
    } while(!CommandIs("EXIT"));
    printf("\n");
}

int  main(){
    MainMenu();
    CreateEmptyLayar(&L,lebarLayar,tinggiLayar);
    BacaCommand();
}