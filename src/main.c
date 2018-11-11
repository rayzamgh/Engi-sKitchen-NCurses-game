#include <stdio.h>
#include <string.h>
#include "../include/boolean.h"

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
    boolean isValid;
    if(pilihanMenu == '1'){
        isValid = true;
    }else if(pilihanMenu == '2'){
        isValid = true;
    }else if(pilihanMenu == '3'){
        isValid = true;
    }else if(pilihanMenu == '4'){
        isValid = true;
    }else{
        isValid = false;
    }
    return isValid;
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

boolean IsPilihanCommandValid(char pilihanCommand[10]){
    boolean isValid;
    if(strcmp(pilihanCommand,"GU") == 0){
        isValid = true;
    }else if(strcmp(pilihanCommand, "GD") == 0){
        isValid = true;
    }else if(strcmp(pilihanCommand, "GL") == 0){
        isValid = true;
    }else if(strcmp(pilihanCommand, "GR") == 0){
        isValid = true;
    }else if(strcmp(pilihanCommand, "ORDER") == 0){
        isValid = true;
    }else if(strcmp(pilihanCommand, "PUT") == 0){
        isValid = true;
    }else if(strcmp(pilihanCommand, "TAKE") == 0){
        isValid = true;
    }else if(strcmp(pilihanCommand, "CH") == 0){
        isValid = true;
    }else if(strcmp(pilihanCommand, "CT") == 0){
        isValid = true;
    }else if(strcmp(pilihanCommand, "PLACE") == 0){
        isValid = true;
    }else if(strcmp(pilihanCommand, "GIVE") == 0){
        isValid = true;
    }else if(strcmp(pilihanCommand, "RECIPE") == 0){
        isValid = true;
    }else if(strcmp(pilihanCommand, "SAVE") == 0){
        isValid = true;
    }else if(strcmp(pilihanCommand, "LOAD") == 0){
        isValid = true;
    }else if(strcmp(pilihanCommand, "EXIT") == 0){
        isValid = true;
    }else{
        isValid = false;
    }
    return isValid;
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

void Command(){
    char pilihanCommand[10];
    do{
        PrintCommand();
        printf("Masukan pilihan Anda : ");
        scanf("%s", pilihanCommand);
        if(!IsPilihanCommandValid(pilihanCommand)){
            printf("Masukan pilihan Anda tidak valid\n");
            printf("\n");
        }
    } while(!IsPilihanCommandValid(pilihanCommand));
    printf("\n");
    if(strcmp(pilihanCommand, "GU") == 0){
        GU();
    }else if(strcmp(pilihanCommand,"GD") == 0){
        GD();
    }else if(strcmp(pilihanCommand, "GL") == 0){
        GL();
    }else if(strcmp(pilihanCommand, "GR") == 0){
        GR();
    }else if(strcmp(pilihanCommand, "ORDER") == 0){
        ORDER();
    }else if(strcmp(pilihanCommand, "PUT") == 0){
        PUT();
    }else if(strcmp(pilihanCommand, "TAKE") == 0){
        TAKE();
    }else if(strcmp(pilihanCommand, "CH") == 0){
        CH();
    }else if(strcmp(pilihanCommand, "CT") == 0){
        CT();
    }else if(strcmp(pilihanCommand, "PLACE") == 0){
        PLACE();
    }else if(strcmp(pilihanCommand, "GIVE") == 0){
        GIVE();
    }else if(strcmp(pilihanCommand, "RECIPE") == 0){
        RECIPE();
    }else if(strcmp(pilihanCommand, "SAVE") == 0){
        SAVE();
    }else if(strcmp(pilihanCommand, "LOAD") == 0){
        LOAD();
    }else if(strcmp(pilihanCommand, "EXIT") == 0){
        EXIT();
    }
}

int  main(){
    MainMenu();
    Command();
}