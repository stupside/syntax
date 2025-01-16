#pragma once

#include "lexer.h"
#include "state.h"
#include "stdlib.h"
#include "symbole.h"

#include <queue>
#include <stack>

class Automate {

private:
  Lexer lexer;

  std::stack<State *> statestack;
  std::stack<Symbole *> symbolstack;

public:
  Automate(std::string &chaine) : lexer(chaine) { this->PushState(new E0); }

  ~Automate();

  inline Lexer &GetLexer() { return this->lexer; }

  TransitionResult Reduct(int n, Symbole *s);
  void Shift(Symbole *s, State *e);

  Symbole *GetAndPopSymbole();
  void PushSymbole(Symbole *s) { symbolstack.push(s); }
  void PushState(State *s) { statestack.push(s); }
  State *GetCurrentState() { return statestack.top(); }
};

#pragma endregion