#ifndef TRANSLITERATION_TREE_H
#define TRANSLITERATION_TREE_H

#include <string>
#include "Node.h"

class TransliterationTree
{
    public:
        TransliterationTree();
        void AddTree(std::string sequence);
        std::string Encode(std::string messageToEncode);
        std::string Decode(std::string messageToDecode);

    private:
        Node<char> root;
        void AddNode(Node<char> *node, char newCharacter);
        char GetCharacterByEncodedString(std::string encodedCharacterString);
};

#endif