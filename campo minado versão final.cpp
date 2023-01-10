#include <iostream>
#include <time.h>
using namespace std;

#define linhas 10
#define colunas 40

int main()
{
    srand(time(NULL));
    int bombas = 0, dificuldade = 0, matrizMostrando[linhas][colunas] = {0}, matrizEscondida[linhas][colunas] = {0}, contadorDeBombas = 0, jogadasMaximas;
    int menu_inicial, v;

    while(true){

        system("cls"); 

    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
    cout << "x                                                 x" << endl;
    cout << "x                       MENU:                     x" << endl;
    cout << "x                                                 x" << endl;
    cout << "x                     1~JOGAR~                    x" << endl;
    cout << "x                                                 x" << endl;
    cout << "x                     2~SOBRE~                    x" << endl;
    cout << "x                                                 x" << endl;
    cout << "x                     3~SAIR~                     x" << endl;
    cout << "x                                                 x" << endl;
    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
        cin >> menu_inicial;
        system("cls");

       switch(menu_inicial){
       case 1:{

           cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
           cout << "x (escolha a dificuldade antes de iniciar o jogo) x" << endl;
           cout << "x                                                 x" << endl;
           cout << "x                  DIFICULDADE:                   x" << endl;
           cout << "x                                                 x" << endl;
           cout << "x                    1~FACIL~                     x" << endl;
           cout << "x                                                 x" << endl;
           cout << "x                    2~MEDIO~                     x" << endl;
           cout << "x                                                 x" << endl;
           cout << "x                   3~DIFICIL~                    x" << endl;
           cout << "x                                                 x" << endl;
           cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
               cin >> dificuldade;
               system("cls");

               //escolhar a dificuldade:

           int facil = 9, linhamedio = 9, colunamedio = 30, c, l;

           if(dificuldade == 1)
           {
               bombas = 9;
               c = facil; l = facil;
               jogadasMaximas = 72;
           }
           else if(dificuldade == 2)
           {
               bombas = 100;
               c = colunamedio; l = linhamedio;
               jogadasMaximas = 170;
           }
           else
           {
               bombas = 199;
               c = colunas; l = linhas;
               jogadasMaximas = 201;
           }

           int bombascolocadas = 0;

           //colocar a bomba de forma pseudo - aleatoria

           while(bombascolocadas != bombas){ //Colocando bombas em posições sorteadas e que não são bombas
               int linhaAleatoria = rand() % l;
               int colunaAleatoria = rand() % c;

               if(matrizEscondida[linhaAleatoria][colunaAleatoria] != 9)
               {
                   matrizEscondida[linhaAleatoria][colunaAleatoria] = 9;
                   bombascolocadas++;
               }
           }

           //saber a quantidade de bomba ao redor:

           for(int i = 0; i < bombas; i++)
           {
               for(int j = 0; j < bombas; j++)
               {
                   contadorDeBombas = 0;
                   if(matrizEscondida[i][j] != 9)
                   {   //checar a posição para ver se tem bomba?
                       if(matrizEscondida[i+1][j] == 9) // pra baixo
                           contadorDeBombas ++;
                       if(matrizEscondida[i+1][j+1] == 9) //diagonal pra baixo lado direito
                           contadorDeBombas ++;
                       if(matrizEscondida[i][j+1] == 9) // lado direito
                           contadorDeBombas ++;
                       if(matrizEscondida[i-1][j+1] == 9) // em cima lado direito
                           contadorDeBombas ++;
                       if(matrizEscondida[i-1][j] == 9) // em cima
                           contadorDeBombas ++;
                       if(matrizEscondida[i-1][j-1] == 9) // em cima lado esquerdo
                           contadorDeBombas ++;
                       if(matrizEscondida[i][j-1] == 9) // lado esquerdo
                           contadorDeBombas ++;
                       if(matrizEscondida[i+1][j - 1] == 9) // diagonal pra baixo lado esquerdo
                           contadorDeBombas ++;
                       matrizEscondida[i][j] = contadorDeBombas;
                   }
               }
          }

           //prova real da matriz fantasma:

           //        for(int i = 0; i < l; i++){
             //          cout << i << ": ";
               //     for(int j=0; j < c ; j++){
                 //          cout << matrizEscondida[i][j] << " ";
                   //    } cout << endl;
                   //}

           cout << endl;

           bool jogando = true;
           int contadorJogadas = 0;

           while(jogando){

               if(contadorJogadas == jogadasMaximas){
                   system("cls");
                   cout << "Voce Ganhou :)";
                   system("pause");
                   jogando = false;
                   break;
               }


               if(contadorJogadas > jogadasMaximas){
                   system("cls");
                   cout << "Voce Perdeu" << endl;
                   system("cls");
                   system("pause");

                   jogando = false;
                   break;
               }

               cout << "coordenadas:" << endl;
               cout << "x -> linha" << endl;
               cout << "y -> coluna" << endl;


               //impressão da matriz que vai ser vista pelo jogador:

               cout << endl;

               for(int i = 0;i<l;i++){
                   cout << endl << i << "->";
                   for(int j =0; j<c;j++){
                       if(j==c-1){
                           cout << "|" << matrizMostrando[i][j] << "|";
                       }else{
                           cout << "|" << matrizMostrando[i][j];
                           }
                       }
                   }


               int entradaLinha, entradaColuna;

       //escolhar as cooedenadas que o jogador quer

               do{
                   cout << endl;
                   cout << endl;
                   cout << "escolha a coordenada x:  ";
                   cin >> entradaLinha;
                   cout << "escolha a coordenada y:  ";
                   cin>> entradaColuna;
                   system("cls");

               } while(entradaLinha > l && entradaColuna > c);

               if(matrizEscondida[entradaLinha][entradaColuna] == 9){
                   system("cls");
                   cout << "Voce perdeu :c" << endl;
                   system("pause");
                   jogando = false;
                   break;
               }

               else
               {
                   matrizMostrando[entradaLinha][entradaColuna] = matrizEscondida[entradaLinha][entradaColuna];
               }

               contadorJogadas++;
               cout << endl;
               cout << "jogadas corretas: " << contadorJogadas << endl;
               cout << endl;
}



           break;
       }

       case 2:{
           system("cls");
           cout << endl;
           cout << "Universidade do Vale de Itajai - UNIVALI" << endl;
           cout << "Professor: Eduardo Alves da Silva" << endl;
           cout << "Aluno: Matheus Thurow" << endl;

           system("pause");
           system("cls");
           break;
       }
       case 3:{
           system("cls");

           return 0;
           break;

       }

       default:{
           system("cls");
           break;
       }

       return 0;
       }


}
   return 0;
}
