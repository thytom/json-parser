#include "lexer.hpp"

#include <iostream>
#include <utility>

Lexer::Lexer(std::string input) : m_input(input) {
    std::cout << "Lexer created!!" << std::endl
        << "Inputted String: " << m_input << std::endl;

    std::string s = m_input;
    int idx = 0;
    while (idx < s.length()) {
        std::pair<int, Token> r = Token::chomp(s.substr(idx));

        idx += r.first;
        r.second.print();

        std::cout << std::endl;
        if(r.first == 0) break;
    }
}

/**
 * Return a tokentype
 */
std::optional<TokenType> Token::ident(char c) {
    switch(c) {
        case '{' : return OBJ_START; break;
        case '}' : return OBJ_END; break;
        default  : return {}; break;
    }
}

/**
 * Return a pair, the token found, then the rest of the string
 */
std::pair<int, Token> Token::chomp(std::string in) {
    std::optional<TokenType> t = Token::ident(in[0]);
    if(t.has_value()) {
        // We found something
        switch(t.value()) {
            case OBJ_START : return std::pair<int, Token>(1, Token(OBJ_START, "{"));
            case OBJ_END : return std::pair<int, Token>(1, Token(OBJ_END, "}"));
        }

    } else {
        size_t i = 0;
        for(i = 0; i < in.length() && !Token::ident(in[i]).has_value(); i++);
        return std::pair<int, Token> (i, Token({}, in.substr(0, i)));
    }

    __builtin_unreachable();
}

void Token::print(void) {
    std::cout << "<";
    if(m_type.has_value()) {
        switch (m_type.value()) {
            case OBJ_START: std::cout << "OBJ_START"; break;
            case OBJ_END: std::cout << "OBJ_END"; break;
        }
    } else {
        std::cout << "UNKNOWN";
    }
    std::cout << ": " << m_contents << ">";
}
