#include "state.h"

#include "automate.h"
#include "symbole.h"

State::~State() {
}

TransitionResult E0::Transit(Automate &automate, Symbole *s) {
  switch (s->GetId()) {
  case INT:
    // d3
    automate.Shift(s, new E3);
    break;
  case OPENPAR:
    // d2
    automate.Shift(s, new E2);
    break;
  case NON_TERMINAL:
    // d1
    automate.PushState(new E1);
    break;
  default:
    return TransitionReject;
    break;
  }

  return TransitionFalse;
}

TransitionResult E1::Transit(Automate &automate, Symbole *s) {

  switch (s->GetId()) {
  case PLUS:
    // d4
    automate.Shift(s, new E4);
    break;
  case MULT:
    // d5
    automate.Shift(s, new E5);
    break;
  case FIN:
    // accept
    return TransitionAccept;
    break;
  default:
    return TransitionReject;
    break;
  }

  return TransitionFalse;
}

TransitionResult E2::Transit(Automate &automate, Symbole *s) {
  switch (s->GetId()) {
  case INT:
    // d3
    automate.Shift(s, new E3);
    break;
  case OPENPAR:
    // d2
    automate.Shift(s, new E2);
    break;
  case NON_TERMINAL:
    // d6
    automate.PushState(new E6);
    break;
  default:
    return TransitionReject;
    break;
  }

  return TransitionFalse;
}

TransitionResult E3::Transit(Automate &automate, Symbole *s) {

  switch (s->GetId()) {
  case PLUS: {
    // r5
    // Symbole *symbole = automate.GetAndPopSymbole();
    return automate.Reduct(1, s);
  }; break;
  case MULT: {
    // r5
    // Symbole *symbole = automate.GetAndPopSymbole();
    return automate.Reduct(1, s);
  } break;
  case CLOSEPAR: {
    // r5
    // Symbole *symbole = automate.GetAndPopSymbole();
    return automate.Reduct(1, s);
  } break;
  case FIN: {
    // r5
    // Symbole *symbole = automate.GetAndPopSymbole();
    return automate.Reduct(1, s);
  } break;
  default:
    return TransitionReject;
    break;
  }

  return TransitionFalse;
}

TransitionResult E4::Transit(Automate &automate, Symbole *s) {

  switch (s->GetId()) {
  case INT:
    // d3
    automate.Shift(s, new E3);
    break;
  case OPENPAR:
    // d2
    automate.Shift(s, new E2);
    break;
  case NON_TERMINAL:
    // d7
    automate.PushState(new E7);
    break;
  default:
    return TransitionReject;
    break;
  }

  return TransitionFalse;
}

TransitionResult E5::Transit(Automate &automate, Symbole *s) {

  switch (s->GetId()) {
  case INT:
    // d3
    automate.Shift(s, new E3);
    break;
  case OPENPAR:
    // d2
    automate.Shift(s, new E2);
    break;
  case NON_TERMINAL:
    // d8
    automate.PushState(new E8);
    break;
  default:
    return TransitionReject;
    break;
  }

  return TransitionFalse;
}

TransitionResult E6::Transit(Automate &automate, Symbole *s) {

  switch (s->GetId()) {
  case PLUS:
    // d4
    automate.Shift(s, new E4);
    break;
  case MULT:
    // d5
    automate.Shift(s, new E5);
    break;
  case CLOSEPAR:
    // d9
    automate.Shift(s, new E9);
    break;
  default:
    return TransitionReject;
    break;
  }

  return TransitionFalse;
}

TransitionResult E7::Transit(Automate &automate, Symbole *s) {

  switch (s->GetId()) {
  case PLUS: {
    // r2
    // E -> E + E
    IntegerSymb *symbole1 = (IntegerSymb *)automate.GetAndPopSymbole();
    automate.GetAndPopSymbole();
    IntegerSymb *symbole2 = (IntegerSymb *)automate.GetAndPopSymbole();

    int val = symbole1->Value() + symbole2->Value();

    automate.PushSymbole(new IntegerSymb(val));

    return automate.Reduct(3, s);
  } break;
  case MULT:
    // r5
    automate.Shift(s, new E5);
    break;
  case CLOSEPAR: {
    // r2
    // E -> E + E
    IntegerSymb *symbole1 = (IntegerSymb *)automate.GetAndPopSymbole();
    automate.GetAndPopSymbole();
    IntegerSymb *symbole2 = (IntegerSymb *)automate.GetAndPopSymbole();

    int val = symbole1->Value() + symbole2->Value();

    automate.PushSymbole(new IntegerSymb(val));

    return automate.Reduct(3, s);
  } break;
  case FIN: {
    // r2
    // E -> E + E
    IntegerSymb *symbole1 = (IntegerSymb *)automate.GetAndPopSymbole();
    automate.GetAndPopSymbole();
    IntegerSymb *symbole2 = (IntegerSymb *)automate.GetAndPopSymbole();

    int val = symbole1->Value() + symbole2->Value();

    automate.PushSymbole(new IntegerSymb(val));

    return automate.Reduct(3, s);
  } break;
  default:
    return TransitionReject;
    break;
  }

  return TransitionFalse;
}

TransitionResult E8::Transit(Automate &automate, Symbole *s) {

  switch (s->GetId()) {
  case PLUS: {
    // r3
    // E -> E * E
    IntegerSymb *symbole1 = (IntegerSymb *)automate.GetAndPopSymbole();
    automate.GetAndPopSymbole();
    IntegerSymb *symbole2 = (IntegerSymb *)automate.GetAndPopSymbole();

    int val = symbole1->Value() * symbole2->Value();

    automate.PushSymbole(new IntegerSymb(val));

    return automate.Reduct(3, s);
  } break;
  case MULT: {
    // r3
    // E -> E * E
    IntegerSymb *symbole1 = (IntegerSymb *)automate.GetAndPopSymbole();
    automate.GetAndPopSymbole();
    IntegerSymb *symbole2 = (IntegerSymb *)automate.GetAndPopSymbole();

    int val = symbole1->Value() * symbole2->Value();

    automate.PushSymbole(new IntegerSymb(val));

    return automate.Reduct(3, s);
  } break;
  case CLOSEPAR: {
    // r3
    // E -> E * E
    IntegerSymb *symbole1 = (IntegerSymb *)automate.GetAndPopSymbole();
    automate.GetAndPopSymbole();
    IntegerSymb *symbole2 = (IntegerSymb *)automate.GetAndPopSymbole();

    int val = symbole1->Value() * symbole2->Value();

    automate.PushSymbole(new IntegerSymb(val));

    return automate.Reduct(3, s);
  } break;
  case FIN: {
    // r3
    // E -> E * E
    IntegerSymb *symbole1 = (IntegerSymb *)automate.GetAndPopSymbole();
    automate.GetAndPopSymbole();
    IntegerSymb *symbole2 = (IntegerSymb *)automate.GetAndPopSymbole();

    int val = symbole1->Value() * symbole2->Value();

    automate.PushSymbole(new IntegerSymb(val));

    return automate.Reduct(3, s);
  } break;
  default:
    return TransitionReject;
    break;
  }

  return TransitionFalse;
}

TransitionResult E9::Transit(Automate &automate, Symbole *s) {

  switch (s->GetId()) {
  case PLUS: {
    // r4
    // E -> (E)
    automate.GetAndPopSymbole();
    Symbole *symbole = automate.GetAndPopSymbole();
    automate.GetAndPopSymbole();
    automate.PushSymbole(symbole);
    return automate.Reduct(3, s);
  } break;
  case MULT: {
    // r4
    // E -> (E)
    automate.GetAndPopSymbole();
    Symbole *symbole = automate.GetAndPopSymbole();
    automate.GetAndPopSymbole();
    automate.PushSymbole(symbole);
    return automate.Reduct(3, s);
  } break;
  case CLOSEPAR: {
    // r4
    // E -> (E)
    automate.GetAndPopSymbole();
    Symbole *symbole = automate.GetAndPopSymbole();
    automate.GetAndPopSymbole();
    automate.PushSymbole(symbole);
    return automate.Reduct(3, s);
  } break;
  case FIN: {
    // r4
    // E -> (E)
    automate.GetAndPopSymbole();
    Symbole *symbole = automate.GetAndPopSymbole();
    automate.GetAndPopSymbole();
    automate.PushSymbole(symbole);
    return automate.Reduct(3, s);
  } break;
  default:
    return TransitionReject;
    break;
  }

  return TransitionFalse;
}