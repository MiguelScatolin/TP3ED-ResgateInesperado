#ifndef TRANSLITERATION_TREE_H
#define TRANSLITERATION_TREE_H

#include <string>
#include "Node.h"

class TransliterationTree
{
    public:
        TransliterationTree();
        ~TransliterationTree();
        void AddTree(std::string sequence);
        std::string Encode(std::string messageToEncode);
        std::string Decode(std::string messageToDecode);

    private:
        Node<char> *root;
        void AddNode(Node<char> *node, char newCharacter);
        void DeleteSubTree(Node<char> *node);
        void Delete();
        std::string EncodeCharacter(char characterToEncode);
        char GetCharacterByEncodedString(std::string encodedCharacterString);
};

#endif