#include "pedido.hpp"

#include "produto.hpp"

using namespace std;

Pedido::~Pedido() {
  // TODO: Implemente este metodo.
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_produtos
   */

  while(!m_produtos.empty())
    delete m_produtos.front(), m_produtos.pop_front();
}

void Pedido::setEndereco(const std::string& endereco) {
  // TODO: Implemente este metodo.
  m_endereco = endereco;
}

float Pedido::calculaTotal() const {
  float sum = 0.0;
  for(auto it = m_produtos.begin(); it != m_produtos.end(); it++)
    sum += (*it)->getValor() * (*it)->getQtd();
  return sum;
}

void Pedido::adicionaProduto(Produto* p) {
  m_produtos.push_back(p);
}

std::string Pedido::resumo() const {
  // TODO: Implemente este metodo.
  /**
   * Aqui voce deve percorrer a lista de produtos para criar um resumo completo
   * do pedido. A cada iteracao, utilize o metodo descricao de cada produto para
   * montar o resumo do pedido. Por fim, adicione o endereco de entrega.
   *
   */
  string resum;
  for(auto it = m_produtos.begin(); it != m_produtos.end(); it++)
    resum += (*it)->descricao() + "\n";
  resum += "Endereco: " +  m_endereco;
  
  return resum;
}