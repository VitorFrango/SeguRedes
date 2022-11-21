#include<stdio.h>

int main()
{
    char msg[100], ch;
    int i, chave;
    printf("Escreva a mensagem a desencriptar: ");
    gets(msg);
    printf("Escreva uma chave numerica entre 1 e 25: ");
    scanf("%d", &chave);
    for(i = 0; msg[i] != '\0'; ++i){
        ch = msg[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch - chave;
            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }
            msg[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch - chave;
            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }
            msg[i] = ch;
        }
    }
    printf("A mensagem decifrada é: %s", msg);
    return 0;
}
