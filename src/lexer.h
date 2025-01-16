#pragma once

#include <string>
#include "symbole.h"
using namespace std;

class Lexer {

   public:
      Lexer(string flux) : _flux(flux), _head(0), _buffer(nullptr) { }
      ~Lexer() { }

      Symbole * Consult();
      void Forward();

   protected:
      string _flux;
      unsigned int _head;
      Symbole * _buffer;
};
