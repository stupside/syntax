#include "lexer.h"

Symbole *Lexer::Consult() {
  if (!_buffer) {

    if (_head == _flux.length())
      _buffer = new Symbole(FIN);
    else {

      switch (_flux[_head]) {
      case '(':
        _buffer = new Symbole(OPENPAR);
        _head++;
        break;
      case ')':
        _buffer = new Symbole(CLOSEPAR);
        _head++;
        break;
      case '*':
        _buffer = new Symbole(MULT);
        _head++;
        break;
      case '+':
        _buffer = new Symbole(PLUS);
        _head++;
        break;
      default:
        if (_flux[_head] <= '9' && _flux[_head] >= '0') {
          int resultat = _flux[_head] - '0';
          int i = 1;
          while (_flux[_head + i] <= '9' && _flux[_head + i] >= '0') {
            resultat = resultat * 10 + (_flux[_head + i] - '0');
            i++;
          }
          _head = _head + i;
          _buffer = new IntegerSymb(resultat);
        } else {
          _buffer = new Symbole(ERROR);
        }
      }
    }
  }
  return _buffer;
}

void Lexer::Forward() { _buffer = nullptr; }
