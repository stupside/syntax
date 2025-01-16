# Syntax Analyzer

A C++ syntax analyzer for evaluating arithmetic expressions using LALR(1) parsing and automata theory.

## Overview

This analyzer processes arithmetic expressions containing:
- Integer numbers
- Addition (+)
- Multiplication (*)
- Parentheses for grouping
- Proper error handling for invalid inputs

## Prerequisites

- C++17 compatible compiler (g++ recommended)
- Make build system
- Unix-like environment (Linux/MacOS)

## Quick Start

```bash
# Build the project
make build

# Run with an example expression
./out/bin/syntax "2+3*4"
# Output: 14

# Try nested expressions
./out/bin/syntax "(5+3)*(2+1)"
# Output: 24
```

## Development Setup

1. Clone the repository
2. Install dependencies
3. Build the project:
   ```bash
   make build
   ```
4. Run tests:
   ```bash
   make test
   ```

## Project Structure

```
.
├── src/                 # Source code
│   ├── automate.cpp     # Automaton implementation
│   ├── automate.h       # Automaton declarations
│   ├── lexer.cpp        # Lexical analyzer
│   ├── lexer.h          # Token definitions
│   ├── state.cpp        # State machine logic
│   ├── state.h          # State declarations
│   ├── symbole.cpp      # Symbol handling
│   ├── symbole.h        # Symbol definitions
│   └── main.cpp         # Entry point
├── out/                 # Build outputs
├── test.sh              # Test file
├── Makefile             # Build configuration
└── README.md            # This file
```

## Technical Implementation

### Parser Design
- LALR(1) parsing technique
- Bottom-up evaluation
- Stack-based automaton

### Simplified Supported Grammar
```
E → E + E
E → E * E
E → (E)
E → number
```

### Error Handling

The analyzer detects and reports:
- Invalid tokens
- Mismatched parentheses
- Incomplete expressions
- Invalid operations

Example error:
```bash
./out/bin/syntax "2+"
# Output: Syntax error: unexpected end of expression
```

## License

Released under the MIT License. See LICENSE file for details.
