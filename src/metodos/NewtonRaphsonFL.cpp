#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

#include "NewtonRaphsonFL.hpp"
#include "NewtonRaphson.hpp"
#include <cmath>



NewtonRaphsonFL::NewtonRaphsonFL(int max_passos, double erro, Polinomio& funcao, double lambda) : NewtonRaphson(max_passos, erro, funcao) {
    this->lambda = lambda;
}

double NewtonRaphsonFL::get_lambda() const {
    return this->lambda;
}
void NewtonRaphsonFL::set_lambda(double l) {
    this->lambda = l;
}

void NewtonRaphsonFL::calcula_raiz(double x0) {
    int k = 1;
    double xk = x0;
    bool continuar = true;

    //Primeiro, adicionamos xk no vector de iterações
    this->get_iteracoes_de_x().push_back(xk);

    //Calculando a derivada da função
    Polinomio derivada = this->get_funcao().get_funcao_derivada();

    //Inicialmente xw = x0, pois ambos pontos se jogados na função derivada possuem módulo >= lambda
    double xw = x0;

    while (continuar) {
        //Verificar se já passamos do limite de passos(numero máximo)
        if (k > this->get_max_iteracoes()) {
            //Não temos raiz válida
            continuar = false;
            this->set_raiz_valida(false);
            this->set_num_passos(this->get_max_iteracoes());
            return;
        }

        //Caso contrário, iremos nos preocupar com a próxima aproximação
        if (std::abs(derivada.get_valor_funcao(xk)) > this->get_lambda()) {
            xk = xk - (this->get_funcao().get_valor_funcao(xk) / derivada.get_valor_funcao(xk));
        }
        else {
            xk = xk - (this->get_funcao().get_valor_funcao(xk) / derivada.get_valor_funcao(xw));
        }

        //Verificar se atualizo o xw ou não
        if (std::abs(derivada.get_valor_funcao(xk)) >= this->get_lambda()) {
            //Atualizo o xw
            xw = xk;
        }

        //Verificar se atendemos a condição de parada
        if ((std::abs(this->get_funcao().get_valor_funcao(xk)) < this->get_erro()) && (std::abs(xk - (this->get_iteracoes_de_x().back())) < this->get_erro())) {
            continuar = false;
            this->set_raiz_valida(true);
            this->set_num_passos(k);
        }

        //Acrescentamos a nova aproximação no vector de iterações
        this->get_iteracoes_de_x().push_back(xk);

        //Incrementar o k
        k++;
    }
}

std::string NewtonRaphsonFL::get_nome() {
    return "Newton Raphson FL";
}

std::string NewtonRaphsonFL::get_nome_abreviado() {
    return "NR-FL";
}

std::string NewtonRaphsonFL::get_classe(int precision) {
    Polinomio p = this->get_funcao();

    std::stringstream ss;
    ss << std::fixed << std::setprecision(precision) << this->get_nome_abreviado() << "(a3: " << p[0] << ", a2: " << p[2]/9 << ", lambda: " << this->lambda << ", erro: " << this->get_erro() << ")";

    return ss.str();
}