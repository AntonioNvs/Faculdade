#include <bits/stdc++.h>


using namespace std;

int main(){
    int numero;
    cin>>numero;
    int parada = 0;

    while(numero > parada)
    {    
        string entrada;
        long long int tempo; 

        cin>>tempo;
        getchar();
        getline (cin,entrada);

        int total = entrada.size();
        
        for(int j=tempo%total;j<total;j++)
        {
            cout<<entrada[j];
        }
        for(int k=0;k<tempo%total;k++)
        {
            cout<<entrada[k];
        }
        cout<<endl;
        
    }
    
}