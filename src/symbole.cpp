#include "symbole.h"

string Symbole::Str() { return SymboleTag[_id]; }

string IntegerSymb::Str() {
  return Symbole::Str() + "(" + std::to_string(_value) + ")";
}

string NonTerminal::Str() { return "NT(E)"; }