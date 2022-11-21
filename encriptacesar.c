#include<stdio.h>

int main()
{
    char msg[100], ch;
    int i, chave;


    printf("Escreva a mensagem a encriptar: \n ");
    gets(msg);

    printf("Escreva uma chave numerica entre 1 e 25 : ");
    scanf("%d", &chave);

    // precorre a string e avalia se todos os caracvteres estao entre a e z ou A e Z

    for(i = 0; msg[i] != '\0'; ++i){
        ch = msg[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch + chave;
            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            msg[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + chave;
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            msg[i] = ch;
        }
    }
    printf("A mensagem encriptada é: %s", msg);
    return 0;
}
