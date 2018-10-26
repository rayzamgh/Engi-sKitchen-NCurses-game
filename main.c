#include <stdio.h>

void MainMenu(){
    printf("SELAMAT DATANG DI ENGI'S KITCHEN!!\n");
    do{
        PrintMainMenu();
        scanf("Masukan pilihan Anda : ", pilihanMenu);
        if(!IsPilihanMenuValid(pilihanMenu)){
            printf("Masukan pilihan Anda tidak valid\n");
        }
    } while(!IsPilihanMenuValid(pilihanMenu));
    switch(pilihanMenu){
        case 1:
            NewGame();
            break;
        case 2:
            StartGame();
            break;
        case 3:
            LoadGame();
            break;
        case 4:
            Exit();
            break;
    }
}

boolean IsPilihanMenuValid(char pilihanMenu){
    switch(pilihanMenu){
        case 1:
            return true;
            break;
        case 2:
            return true;
            break;
        case 3:
            return true;
            break;
        case 4:
            return true;
            break;
        default:
            return false;
    }
}

void PrintMainMenu(){
    printf("MAIN MENU : \n");
    printf("1. New Game\n");
    printf("2. Start Game\n");
    printf("3. Load Game\n");
    printf("4. Exit\n");
}

void NewGame(){
    //isGameOn = true;
    //minta nama
    StartGame();
}

void StartGame(){
    //isGameOn = true;
}

void LoadGame(){
    //isGameOn = true;
}

void Exit(){
    //isGameOn = false;
}

void Command(){
    do{
        PrintCommand();
        scanf("Masukan pilihan Anda : ", pilihanCommand);
        if(!IsPilihanCommandValid(pilihanCommand)){
            printf("Masukan pilihan Anda tidak valid\n");
        }
    } while(!IsPilihanCommandValid(pilihanCommand));
    switch(pilihanCommand){
        case "GU":
            GU();
            break;
        case "GD":
            GD();
            break;
        case "GL":
            GL();
            break;
        case "GR":
            GR();
            break;
        //dst
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

boolean IsPilihanCommandValid(char pilihanCommand){
    switch(pilihanCommand){
        case "GU":
            return true;
            break;
        case "GD":
            return true;
            break;
        case "GL":
            return true;
            break;
        case "GR":
            return true;
            break;
        //dst
        default:
            return false;
    }
}

int  main(){
    MainMenu();
}