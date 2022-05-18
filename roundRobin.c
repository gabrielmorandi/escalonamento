//O codigo foi escrito baseando-se no exemplo mostrado no video para uma compreensao facilitada
//Pessoas pagando contas em um caixa que so permite certo numero de contas
#include <stdlib.h>
#include <stdio.h>
#define tam 30 //namero maximo de pessoas

int pessoas[tam];           //Fila de pessoas
int NumEscolhidoPessoas;
int quantum;                //Numero de contas pra pagar no caixa

void contas(){       //Para que o usuario possa testar com diferentes quantidades de contas
    int numero;
    int i;
    for (i=1; i<=NumEscolhidoPessoas; i++){
        printf("\nDigite o numero de contas a pagar da pessoa %d:", i);
        scanf("%d", &numero);               //Leitura de valor inserido pelo usuario
        pessoas[i]= numero;                 //cada pessoa recebe o valor informado
    }
}

void fila(){
    int contadorFila=NumEscolhidoPessoas;            //contagem de pessoas que estao na fila
    int frenteFila = 1;                 //Primeira posicao da fila
    while(contadorFila !=0){
        while(pessoas[frenteFila] <= 0){ //Tira pessoas que nao tem contas da primeira posicao
            frenteFila++;
            if(frenteFila>= NumEscolhidoPessoas) //Faz a rotacao
                frenteFila=0;
        }
        printf("\n\nA pessoa %d vai para o caixa com %d contas", frenteFila , pessoas[frenteFila]);
        printf("\nPaga ate %d contas", quantum);
        pessoas[frenteFila] = pessoas[frenteFila] - quantum;        //Pagamento de quantum contas
        if( pessoas[frenteFila]<=0){
            printf("\nE sai da fila.\n");
            contadorFila--;
        }
        else{
            printf("\nE vai pro final da fila com %d contas restantes.\n", pessoas[frenteFila]);
        }
        frenteFila++;                               //Atualiza primeira posicao
            if(frenteFila>NumEscolhidoPessoas)    //Faz a rotacao
                frenteFila=0;
        system("PAUSE");
    }
}

main(){
printf("::::::: Programa exemplo sobre round-robin :::::::");
printf("\nDigite o numero maximo de contas a pagar no caixa (quantum): ");
scanf("%d", &quantum);
printf("\nDigite o numero de pessoas na fila: ");
scanf("%d", &NumEscolhidoPessoas);
contas();
fila();
printf("\n\n::::::::: Fim ::::::::::\n");
getch();

}
