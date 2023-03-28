#include "japonesa.hpp"

#include <string>

std::string Japonesa::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da comida
   * japonesa.
   *
   * Exemplos:
   * 1X Comida japonesa - Combo 1, 4 sushis, 5 temakis e 6 hots.
   * 1X Comida japonesa - Combo 2, 5 sushis, 6 temakis e 8 hots.
   */
   
  return std::to_string(m_qtd) + "X Comida japonesa - " + 
         m_combinado + ", " + std::to_string(m_sushis) + " sushis, " +
         std::to_string(m_temakis) + " temakis e " + std::to_string(m_hots) + " hots.";
}

Japonesa::Japonesa(const std::string& combinado,
                   int sushis,
                   int temakis,
                   int hots,
                   int qtd,
                   float valor_unitario) {
  // TODO: Implemente este metodo.
  m_combinado = combinado;
  m_sushis = sushis;
  m_temakis = temakis;
  m_hots = hots;
  m_qtd = qtd;
  m_valor_unitario = valor_unitario;
}