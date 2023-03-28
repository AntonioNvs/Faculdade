#include "google_password.h"

#include <iostream>
#include <string>

void GooglePassword::insert(const std::string& url,
                            const std::string& login,
                            const std::string& password) {
  // TODO: Implemente este metodo
  if(!validPassword(password)) return;

  passwords_.insert({url, {login, password}});
}

void GooglePassword::remove(const std::string& url) {
  // TODO: Implemente este metodo
  passwords_.erase(url);
}


void GooglePassword::update(const std::string& url,
                            const std::string& login,
                            const std::string& old_password,
                            const std::string& new_password) {
  // TODO: Implemente este metodo
  /**
   * Este metodo nao pode inserir novas credenciais, apenas atualizar as
   * ja existentes. Alem disso, o login e/ou senha do usuario so podem ser
   * atualizados se a senha armazenada no sistema for igual a old_password.
   * Nao esqueca de verificar se o novo password tambem e valido.
   */
  if(passwords_.find(url) == passwords_.end()) return;
  
  if(passwords_[url].password == old_password && validPassword(new_password))
    passwords_[url] = {login, new_password};
}

void GooglePassword::printPasswords() {
  // TODO: Implemente este metodo
  /**
   * Exemplo de saida:
   * 3
   * aaa.site.com: login and password
   * www.site.com: login and password
   * zzz.site.com: login and password
   *
   */
  std::cout << passwords_.size() << std::endl;
  for(auto p : passwords_) {
    std::cout << p.first << ": " << p.second.login << " and " << p.second.password << std::endl;
  }
}

bool GooglePassword::validPassword(const std::string& password) const {
  // TODO: Implemente este metodo
  return !(password.find("123456") != string::npos || password.size() > 50 || password.size() < 6 || password.find(" ") != string::npos);
}

