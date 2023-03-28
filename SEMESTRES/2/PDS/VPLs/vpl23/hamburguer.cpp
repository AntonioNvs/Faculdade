#include "hamburguer.hpp"

#include <string>

std::string Hamburguer::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada do Hamburguer.
   *
   * Exemplos:
   * 1X Hamburguer X-tudo artesanal.
   * 1X Hamburguer X-tudo simples.
   */
   
  return std::to_string(m_qtd) + "X Hamburguer " + m_tipo + (m_artesanal ? " artesanal." : " simples.");
}

Hamburguer::Hamburguer(const std::string& tipo,
                       bool artesanal,
                       int qtd,
                       float valor_unitario) {
  // TODO: Implemente este metodo.
  m_tipo = tipo;
  m_artesanal = artesanal;
  m_qtd = qtd;
  m_valor_unitario = valor_unitario;
}