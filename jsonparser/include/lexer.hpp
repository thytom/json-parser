#pragma once

#include <pthread.h>
#include <string>
#include <string_view>
#include <optional>

enum TokenType {
    OBJ_START,
    OBJ_END,
};

class Token {
    public:
        std::optional<TokenType> m_type = {}; 
        std::string m_contents = NULL;
        Token(std::optional<TokenType> type, std::string contents) :m_type(type),m_contents(contents) {

        }
        static std::optional<TokenType> ident(char c);
        static std::pair<int, Token> chomp(std::string in);
        void print(void);
};

class Lexer {
public:
    Lexer (std::string input);
private:
    std::string m_input;
};
