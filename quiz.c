//Autores: Guilherme Reale e Matheus Giraldi//
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //Para escrever textos em português//
#include <time.h>   //Para gerar uma semente aleatória a cada vez que o programa é executado//
#include <string.h> //Para trabalhar com strings//

int points (int n); //Esta função retorna a pontuação correspondente ao número de erros (10 para 0, 7 para 1, 5 para 2, e 0 para 3)//
int find (int n,int a[12]); //Procura por instâncias iguais de um número em um vetor//
void upper(char a[]);//Converte o texto para caixa alta//

int main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));

    char *pergunta[] = {"Quem foi o criador da linguagem C?","O jogo Doom foi escrito na linguagem C (V/F).","Qual a palavra-chave usada para definir uma diretiva em C?","Qual símbolo é utilizado para aplicar uma tabulação horizontal em uma string?\na) \\n\nb) \\a\nc) \\t","O comando \'break\' termina a iteração atual e parte para a próxima (V/F).","Qual é a sintaxe correta para um loop \'for\' em C?\na) for (inicialização;condição;incremento)\nb) for (condição;incremento;inicialização)\nc) for (incremento;condição;inicialização)","Qual a função utilizada para percorrer os elementos de um vetor em C?","Qual é o símbolo usado para se referir a um elemento de um vetor em C?","A forma correta de declarar uma matriz de inteiros em C é int[][] matriz (V/F).","O laço \'do-while\' garante que um comando seja executado ao menos uma vez (V/F).","Qual é a função utilizada para calcular o tamanho de um vetor em C?","Qual o operador utilizado para acessar o endereço de memória de uma variável em C?"}, 
    *gabarito[] = {"DENNIS-RITCHIE","V","DEFINE","C","F","A","FOR","[]","F","V","SIZEOF","&"};
    char resposta[20];
    int score[2]={0,0},random[12],i;//score[0] é a pontuação do jogador B, e score[1] é a do jogador A//

    //Este trecho gera um vetor de números aleatórios e diferentes entre si//
    for (i = 0; i < 12; i++)
    {
        do
        {
            random[i] = rand() % 12;
        } while (find(random[i],random));
        
    } 
    printf("\n-------------------Quiz do Guilherme e do Matheus-------------------\n\n-------------------INSTRUÇÕES-------------------\n\n\tUse hífen ao invés de espaço para escrever a palavra\n\tEx.: \'João-Miguel\' ao invés de \'João Miguel\'\n\tPerguntas que terminarem com \'(V/F)\' devem ser respondidas com \'v\' ou \'f\' para verdadeiro ou falso, respectivamente.\n\tPerguntas com alternativas devem ser respondidas com a letra da alternativa correta (\'a\' ou \'b\' ou \'c\').\n\tAs respostas podem ser em letra maiúscula ou minúsucla.\n\n-------------------QUE COMECE O JOGO!-------------------\n\n");

    for ( i = 0; i < 12; i++)
    {
        //'count' controla a quantidade de erros. Quando o jogador comete um erro, 'count' decresce 1. O loop termina em 'count' == 0//
        int count=3;
        printf("\nPergunta %d\n\n",i+1);
        do
        {
            printf("%s\n\n",pergunta[random[i]]);
            printf("Jogador %c: ",(count+i)%2?'A':'B');//Aqui, foi usado (count+1) para que A e B se alternem para responder primeiro//
            scanf("%s",resposta);
            upper(resposta); //A resposta é convertida para caixa alta//

            //Como strcmp retorna 0 para strings iguais, A negação (!) é utilizada.//
            if(!strcmp(resposta,gabarito[random[i]]))
            {
                printf("Resposta certa!\n");
                score[(count+i)%2]+=points(count);
                count = 0;
            }
            else
            {
                printf("Resposta errada!\n");
                count--;
            }
        } while (count>0);

        printf("\nPontuação de A: %d\nPontuação de B: %d\n",score[1],score[0]);
    }

    printf("\n----------------------------------------\n\nPontuação final:\nA: %d\nB: %d\n",score[1],score[0]);

    if(score[1]>score[0])
    {
        printf("\nA é o vencedor! O prêmio fica por conta do Layhon!\n");
    }
    else if(score[0]>score[1])
    {
        printf("\nB é o vencedor! O prêmio fica por conta do professor!\n");
    }
    else
    {
        printf("\nEmpate!\n");
    }
}

int find (int n,int a[12])
{
    int i,count=0;
    for (i = 0; i < 12; i++)
    {
        if(n==a[i])
        {
            count++;
        }
    }
    if(count>1)
    {
        return 1;
    }
    else
    {
        return 0;
    }  
}

int points(int n)
{
    if(n==3)
    {
        return 10;
    }
    else if(n==2)
    {
        return 7;
    }
    else if(n==1)
    {
        return 5;
    }
    else
    {
        return 0;
    }
}

void upper(char a[])
{
    int i;
    for ( i = 0; i < strlen(a); i++)
    {
        if(a[i] >= 97 && a[i] <= 122)
        {
            a[i] -= 32;
            /*A posição das letras na tabela ASCII segue um padrão: uma letra minúscula i tem a posição igual a da letra maiúscula I mais 32.
            Assim, se a[i] estiver entre a letra 'a'(97) e 'z' (122), é subtraído 32 de a[i], para obter a letra maiúscula.*/
        }
            
    }
    
}