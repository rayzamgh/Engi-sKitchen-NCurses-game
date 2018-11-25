#include "../include/filemanager.h"
#include "../include/stackt.h"
#include<stdio.h>
int main()
{
    Stack Food = BacaStackFood("../save/Aditya/stack.txt");
    Stack Hand = BacaStackHand("../save/Aditya/stack.txt");
    printf("Isi Food\n");
    while(!IsEmptyStack(Food))
    {   
        Kata temp1;
        Pop(&Food,&temp1);
        printf("%s\n",temp1.TabKata);
    }
    printf("Isi Hand\n");
    while(!IsEmptyStack(Hand))
    {   
        Kata temp2;
        Pop(&Hand,&temp2);
        printf("%s\n",temp2.TabKata);
    }
    return 0;
}