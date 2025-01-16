#pragma once

#include <map>
#include <string>

using namespace std;

enum SymboleId { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERROR, NON_TERMINAL };

const string SymboleTag[] = {"OPENPAR", "CLOSEPAR", "PLUS",   "MULT",
                             "INT",     "FIN",      "UNKNOWN_SYMBOLE", "NON_TERMINAL"};

class Symbole {
public:
  Symbole(SymboleId id) : _id(id) {}
  virtual ~Symbole() {}

  SymboleId GetId() const { return _id; }

  virtual string Str();

  virtual bool IsTerminal() { return true; }

protected:
  SymboleId _id;
};

class IntegerSymb : public Symbole {
public:
  IntegerSymb(int value) : Symbole(INT), _value(value) {}
  ~IntegerSymb() {}

  virtual string Str();
  inline unsigned int Value() const { return _value; }

protected:
  int _value;
};

class NonTerminal : public Symbole {
public:
  NonTerminal() : Symbole(NON_TERMINAL) {}
  ~NonTerminal() {}

  bool IsTerminal() { return false; }

  virtual string Str();
};