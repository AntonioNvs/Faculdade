#include "pizza.hpp"

#include <string>

std::string Pizza::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da pizza.
   *
   * Exemplos:
   * 2X Pizza Calabresa, 4 pedacos e borda recheada.
   * 2X Pizza Calabresa, 4 pedacos sem borda recheada.
   */
   
  return std::to_string(m_qtd) + "X Pizza " + m_sabor + ", " + std::to_string(m_pedacos) +
         " pedacos " + (m_borda_recheada ? "e borda recheada." : "e sem borda recheada.");
}

Pizza::Pizza(const std::string& sabor,
             int pedacos,
             bool borda_recheada,
             int qtd,
             float valor_unitario) {
  // TODO: Implemente este metodo.
  m_sabor = sabor;
  m_pedacos = pedacos;
  m_borda_recheada = borda_recheada;
  m_qtd = qtd;
  m_valor_unitario = valor_unitario;
}