#include "main.hpp"

#include "lexer.hpp"

#include <iostream>
#include <sstream>

constexpr auto input_string = "{test:30}";

int main(void) {
    Lexer *x = new Lexer(input_string);
    
    return 0;
}
