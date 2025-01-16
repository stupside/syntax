#include <iostream>

#include "automate.h"
#include "lexer.h"
#include "state.h"
#include "symbole.h"

int main(int argc, char *argv[]) {

  if (argc < 2) {
    cout << "Usage: " << argv[0] << " <expression>" << endl;
    return 0;
  }

  string expr(argv[1]);

  Automate automate(expr);

  Lexer &lexer = automate.GetLexer();

  {
    Symbole *symbole = nullptr;

    while ((symbole = lexer.Consult())->GetId() != FIN) {

      const TransitionResult result =
          automate.GetCurrentState()->Transit(automate, symbole);

      switch (result) {
      case TransitionFalse:
      case TransitionAccept:
        break;
      case TransitionReject:
        std::cerr << "Syntax error " << symbole->Str() << std::endl;
        return 1;
      }
    }

    const TransitionResult result =
        automate.GetCurrentState()->Transit(automate, symbole);

    if (result == TransitionReject) {
      std::cerr << "Syntax error " << symbole->Str() << std::endl;
      return 1;
    }

    if (result == TransitionFalse) {
      cerr << "Expected end of expression but got " << symbole->Str() << endl;
      return 1;
    }

    symbole = automate.GetAndPopSymbole();

    cout << symbole->Str() << endl;
  }

  return 0;
}
