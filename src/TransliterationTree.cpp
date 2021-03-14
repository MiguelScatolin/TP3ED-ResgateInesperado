#include <sstream>
#include "TransliterationTree.h"

TransliterationTree::TransliterationTree() {
    root = Node<char>(0);
}

void TransliterationTree::AddNode(Node<char> *node, char newCharacter) {
    if (!node->GetItem()) {
        node->SetItem(newCharacter);
        return;
    }

    Node<char> *nodeToAdd;
    if (newCharacter > node->GetItem()) {
        if(!node->GetRight()) {
            nodeToAdd = new Node<char>(newCharacter);
            node->SetRight(nodeToAdd);
        }
        else
            AddNode(node->GetRight(), newCharacter);
    }
    else{
        if(!node->GetLeft()) {
            nodeToAdd = new Node<char>(newCharacter);
            node->SetLeft(nodeToAdd);
        }
        else
            AddNode(node->GetLeft(), newCharacter);
    }
}

void TransliterationTree::AddTree(std::string sequence) {
    for (char const &c: sequence)
        AddNode(&root, c);
}

std::string TransliterationTree::Encode(std::string messageToEncode) {
    return "a";
}

char TransliterationTree::GetCharacterByEncodedString(std::string encodedCharacterString) {
    Node<char> *p = &root;
    int number;

    for (char const &c: encodedCharacterString) {
        number = c - '0';
        if(number % 2)
            p = p->GetLeft();
        else
            p = p->GetRight();
    }

    return p->GetItem();
}

std::string TransliterationTree::Decode(std::string messageToDecode) {
    std::string encodedCharacterString, decodedMessage = "";

    std::istringstream iss(messageToDecode);

    iss.ignore(1);

    while(getline(iss, encodedCharacterString, 'x'))
    {
        decodedMessage += GetCharacterByEncodedString(encodedCharacterString);
    }

    return decodedMessage;
}