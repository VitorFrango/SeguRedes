#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


    long int    p,q,n,t,flag,e[100],d[100],temp[100],j,tot[100],en[100],i;
    char        msg[100];
    int         primo(long int);


    void        ce();
    long int    cd(long int);
    void        encripta();
    void        desencript();
    int         main()
    {

        // Solicita introdução de 2 numeros primos
        printf("\nEscreva um numero primo\n");
            scanf("%ld",&p);
            flag=primo(p);
                if(flag==0)
                {
                    printf("\nNão é numero primo\n");
                    exit(1);
                }
        printf("\nEscreva outro numero primo \n");
        scanf("%ld",&q);

        flag=primo(q);
        if(flag==0||p==q)
        {
            printf("\nNão é numero primo\n");
            exit(1);
        }
        printf("\nEscreva uma mensagem sem espaços\n");
        fflush(stdin);
        scanf("%s",msg);

        // calcula o numero de totiente (co primos)
        for(i=0;msg[i]!=NULL;i++)
            tot[i]=msg[i];
        n=p*q;
        t=(p-1)*(q-1);
        ce();

        // valores para a chave publica e privada
        printf("\nValores possiveis para  'e' e 'd' \n");
        for(i=0;i<j-1;i++)
            printf("\n%ld\t%ld",e[i],d[i]);
            encripta();
            desencript();
        return 0;
    }

    int primo(long int pr)
    {
        int i;
        j=sqrt(pr);
        for(i=2;i<=j;i++)
        {
            if(pr%i==0)
                return 0;
        }
        return 1;
    }

    void ce()
    {
        int k;
        k=0;
        for(i=2;i<t;i++)
        {
            if(t%i==0)
                continue;
            flag=primo(i);
            if(flag==1&&i!=p&&i!=q)
            {
                e[k]=i; flag=cd(e[k]);
                if(flag>0)
                {
                    d[k]=flag;
                    k++;
                }
                if(k==99)
                    break;
            }
        }
    }

    long int cd(long int x)
    {
        long int k=1;
        while(1)
        {
            k=k+t;
            if(k%x==0)
                return(k/x);
        }
    }
    void encripta()
    {
        long int pt,ct,key=e[0],k,len;
        i=0;
        len=strlen(msg);
        while(i!=len)
        {
            pt=tot[i];
            pt=pt-96;
            k=1;
            for(j=0;j<key;j++)
            {
                k=k*pt;
                k=k%n;
            }
            temp[i]=k;
                ct=k+96;
                en[i]=ct;
            i++;
        }
        en[i]=-1;

        printf("\nA mesangem encriptada é: \n");
        for(i=0;en[i]!=-1;i++)
            printf("%c",en[i]);
    }
    void desencript()
    {
        long int pt,ct,key=d[0],k;
        i=0;

        while(en[i]!=-1)
        {
            ct=temp[i];
            k=1;
            for(j=0;j<key;j++)
            {
                k=k*ct;
                k=k%n;
            }
                pt=k+96;
                tot[i]=pt;
                i++;
        }
        tot[i]=-1;

        printf("\nA mensagem desencriptada é: \n");
        for(i=0;tot[i]!=-1;i++)
            printf("%c",tot[i]);
    }