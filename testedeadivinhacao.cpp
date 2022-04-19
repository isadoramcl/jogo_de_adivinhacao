
#include <iostream>
#include <cstdlib>
using namespace std;

int main (){
 
    cout << "*************************************" << endl;
    cout << "* Bem-vindo ao jogo de adivinhação! *" << endl;
    cout << "*************************************" << endl;

    srand (time(NULL));
    const int NUMERO_SECRETO = rand () % 100;
    int chute;
    double pontos = 1000.0;
    char dificuldade;
    int numero_de_tentativa = 0;

    cout << "Escolha o nível do jogo!" << endl << "Fácil (F), médio (M) ou difícil (D)" << endl;
    cin >> dificuldade;

    if (dificuldade == 'F'){
        numero_de_tentativa = 8;
    }else if (dificuldade == 'M'){
        numero_de_tentativa = 5;
    }else {
        numero_de_tentativa = 3;
    }

    for (int tentativa = 1; tentativa <= numero_de_tentativa; tentativa++){

            cout << "Tentativa " << tentativa << endl;
            cout << "Qual seu chute?" << endl;
            cin >> chute;
            bool acerto = chute == NUMERO_SECRETO;
            bool maior = chute > NUMERO_SECRETO;
            double pontos_perdidos = abs (chute - NUMERO_SECRETO)/2.0;
            pontos = pontos - pontos_perdidos;

            if(acerto){
                cout << "Você acertou!" << endl;
                break;
            }
            else if (maior) {
                cout << "O seu número é maior que o número secreto!" << endl;
            }else{
                cout << "O seu número é menor que o número secreto!" << endl;
            }

    }
    
    cout << "Fim de jogo" << endl;
    cout << "Você perdeu!" << endl;
    cout.precision (2);
    cout << fixed;
    cout << "Sua pontuação final é " << pontos << endl;
    

}