#include <stdio.h>

int main(){
    char cmd;
    
    do{
        printf("Enter a command(a or d): ");
        scanf(" %c", &cmd);

        if((cmd!='a')&&(cmd!='d')){
            printf("Invalid Command: %c\n", cmd);
        }

    }while((cmd!='a')&&(cmd!='d'));

    switch(cmd){
        case 'a':
        printf("Attack!\n");
        break;

        case 'd':
        printf("Defend!\n");
        break;
    }
   




    return 0;
}