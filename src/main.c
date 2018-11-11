#include <stdio.h>
#include <string.h>
#include "../include/boolean.h"
#include "../include/mesincommand.h"
#include "../include/array.h"

void InisialisasiOrder(TABOrder *TabInt){
    MakeEmptyArray(TabInt);
}

void PlaceOrder(TabInt *TABOrder){
    //namanya doang tabint sebenernya tabchar[20] (urg males ganti semua tabint jadi tabstring)
    char[20] placeholder;
    Elmt(*TABOrder, Neff(TABOrder)) = placeholder;
    Neff(*TABOrder)++;
}

void StartGame(){
    //isGameOn = true;
    printf("\n");
}

void NewGame(){
    //isGameOn = true;
    char namaUser[1000];
    printf("Masukkan Nama Chef : ");
    scanf("%s", namaUser);
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
    } while(!CommandIs("EXIT"));
    printf("\n");
}

int  main(){
    MainMenu();
    BacaCommand();
}