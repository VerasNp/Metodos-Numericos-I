#include "NewtonRaphsonComDerivadaNumerica.hpp"
#include "Derivacao.hpp"
#include <cmath>

void NewtonRaphsonComDerivadaNumerica::calcula_raiz(double x0) {
    int k = 1;
    double x_k = 0.0, raiz = 0.0;
    bool continuar_iteracao = true;

    // Checando se o x inicial já é próximo o suficiente da raíz.
    if (std::abs(this->get_funcao().get_valor_funcao(x0)) < this->get_erro()) {
        raiz = x0;
        continuar_iteracao = false;
    }

    this->iteracoes_de_x.push_back(x0);

    while (continuar_iteracao) {
        x_k = x0 - (this->get_funcao().get_valor_funcao(x0)/this->derivador.derivar(this->get_funcao(), x0));
        this->iteracoes_de_x.push_back(x_k);

        /* Resultado do método é invalidado por estouro do número máximo de iterações */
        if (k > this->get_max_iteracoes()) {
            this->set_raiz_valida(false);
            this->set_num_passos(this->get_max_iteracoes());
            return;
        }

        if ( (std::abs(this->get_funcao().get_valor_funcao(x_k)) < this->get_erro()) && (std::abs(x_k - x0) < this->get_erro()) ) {
            raiz = x_k;
            continuar_iteracao = false; 
        }

        x0 = x_k;
        k++;
    }

    this->set_num_passos(this->iteracoes_de_x.size());
}