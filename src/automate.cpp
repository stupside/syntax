#include "automate.h"
#include "state.h"
#include "symbole.h"

Automate::~Automate() {
  while (!statestack.empty()) {
    statestack.pop();
  }
  while (!symbolstack.empty()) {
    symbolstack.pop();
  }
}

void Automate::Shift(Symbole *s, State *e) {
  symbolstack.push(s);
  statestack.push(e);
  if (s->IsTerminal()) {
    lexer.Forward();
  }
}

TransitionResult Automate::Reduct(int n, Symbole *s) {
  for (int i = 0; i < n; i++) {
    delete statestack.top();
    statestack.pop();
  }
  // After reduction, we need to handle the new symbol with the current state
  statestack.top()->Transit(*this, new NonTerminal);
  return statestack.top()->Transit(*this, s);
}

Symbole *Automate::GetAndPopSymbole() {
  Symbole *symbole = symbolstack.top();
  symbolstack.pop();
  return symbole;
}
