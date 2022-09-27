#include <iostream>

using namespace std;

int main(){

    // 1) Declare uma variável do tipo inteiro e atribua o valor '10'
    int x = 10;

    // 2) Declare um ponteiro para inteiros e inicialize com valor nulo (aka 'nullptr')
    int *p = nullptr;

    // 3) Declare um vetor de inteiros e inicialize com valores de 9 a 0 (nessa ordem)
    int v[]= {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    // 4) Imprima o ENDEREÇO da variável declarada em (1)
    cout << &x << endl;

    // 5) Imprima o CONTEÚDO da variável declarada em (1)
    cout << x << endl;

    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    cout << &p << endl;

    // 7) Imprima o CONTEÚDO da variável declarada em (2)
    cout << p << endl;
    
    // 8) Imprima o ENDEREÇO da variável declarada em (3)
    cout << &v << endl;

    // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)
    cout << &(v[0]) << endl;

    // 10) Imprima o CONTEÚDO da primeira posição da variável declarada em (3)
    cout << v[0] << endl;

    // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)
    p = &x;

    // 12) Imprima o CONTEÚDO da variável declarada em (2)
    cout << p << endl;

    // 13) Imprima o CONTEÚDO da varíavel que é apontada por (2)
    cout << *p << endl;

    // 14) Imprima o resultado da comparação do ENDEREÇO de (1) e do CONTEÚDO de (2)
    cout << (&x == p) << endl;

    // 15) Coloque o VALOR '5' na varíavel que é apontada pela variável de (2)
    *p = 5;

    // 16) Imprima o CONTEÚDO da variável declarada em (1)
    cout << x << endl;

    // 17) Atribua o CONTEÚDO da variável de (3) à variável de (2)
    p = v;

    // 18) Imprima o CONTEÚDO da variável declarada em (2) 
    cout << p << endl;

    // 19) Imprima o CONTEÚDO da variável que é apontada pela variável de (2)
    cout << *p << endl;

    // 20) Atribua o ENDEREÇO da primeira posição de (3) à variável de (2)
    p = &(v[0]);

    // 21) Imprima o CONTEÚDO da variável declarada em (2) 
    cout << p << endl;

    // 22) Imprima o CONTEÚDO da variável que é apontada pela variável de (2) 
    cout << *p << endl;

    // 23) Imprima os elementos de (3) utilizando a notação [] (e.g. v[i])
    for(int i = 0; i < 9; i++)
        cout << v[i] << " ";

    cout << v[9] << endl;

    // 24) Imprima os elementos de (3) utilizando a notação ponteiro/deslocamento (e.g. *(v + i))
    for(int i = 0; i < 9; i++)
        cout << *(v + i) << " ";

    cout << *(v + 9) << endl;
    
    return 0;
}