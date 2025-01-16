#pragma once

#include <iostream>
#include <ostream>
#include <string>

#include "symbole.h"

class Automate;

enum TransitionResult {
  TransitionAccept,
  TransitionFalse,
  TransitionReject,
};

class State {
public:
  State(std::string name) : _name(name) {}
  virtual ~State() = 0;

  virtual TransitionResult Transit(Automate &automate, Symbole *s) = 0;

protected:
  std::string _name;
};

class E0 : public State {
public:
  E0() : State("E0") {}
  ~E0() {}

  TransitionResult Transit(Automate &automate, Symbole *s);
};

class E1 : public State {
public:
  E1() : State("E1") {}
  ~E1() {}

  TransitionResult Transit(Automate &automate, Symbole *s);
};

class E2 : public State {
public:
  E2() : State("E2") {}
  ~E2() {}

  TransitionResult Transit(Automate &automate, Symbole *s);
};

class E3 : public State {
public:
  E3() : State("E3") {}
  ~E3() {}

  TransitionResult Transit(Automate &automate, Symbole *s);
};

class E4 : public State {
public:
  E4() : State("E4") {}
  ~E4() {}

  TransitionResult Transit(Automate &automate, Symbole *s);
};

class E5 : public State {
public:
  E5() : State("E5") {}
  ~E5() {}

  TransitionResult Transit(Automate &automate, Symbole *s);
};

class E6 : public State {
public:
  E6() : State("E6") {}
  ~E6() {}

  TransitionResult Transit(Automate &automate, Symbole *s);
};

class E7 : public State {
public:
  E7() : State("E7") {}
  ~E7() {}

  TransitionResult Transit(Automate &automate, Symbole *s);
};

class E8 : public State {
public:
  E8() : State("E8") {}
  ~E8() {}

  TransitionResult Transit(Automate &automate, Symbole *s);
};

class E9 : public State {
public:
  E9() : State("E9") {}
  ~E9() {}

  TransitionResult Transit(Automate &automate, Symbole *s);
};

#pragma endregion