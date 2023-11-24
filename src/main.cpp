#include <cstddef>
#include <iostream>
#include <vector> 
#include <iomanip>

#include "Painel.hpp"
#include "Utils.hpp"
#include "GaussJordan.hpp"


using namespace std;
using namespace metodos_numericos1::outputs;
using namespace metodos_numericos1::metodos;


int main()
{
    Painel painel;
    vector<vector<double>> matriz_c = {{1, 3, 2, 9}, {0, 3, 1, 1}, {0, 0, 2, 9}, {0, 0, 0, -2}};

    vector<double> vetor_v = {2, 0, 12, 9};

    GaussJordan* gauss_jordan = new GaussJordan(matriz_c, vetor_v, 2);

    Imprimir::matriz(gauss_jordan->get_matriz_c());

    gauss_jordan->resolve_sistema_linear();
    Imprimir::vetor(gauss_jordan->get_vetor_v_inicial());
    Imprimir::vetor(gauss_jordan->get_vetor_d_deslocamentos()); // Vetor Resposta
    Imprimir::vetor(gauss_jordan->get_vetor_amplitudes()); // Vetor Resposta multiplicado por 'a'

    cout << gauss_jordan->get_balanco_quebra() << "\n";
    cout << gauss_jordan->get_determinante_matriz_c() << "\n";
    return 0;
}