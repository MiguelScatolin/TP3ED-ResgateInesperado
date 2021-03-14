#include <iostream>
#include <fstream>
#include <sstream>
#include "TransliterationTree.h"

int main(int argc, char* argv[]) {
    try {
        if(argc < 2)
            throw "Nome do arquivo de entrada não informado.";

        std::ifstream commandFile(argv[1]);

        if (!commandFile.is_open())
            throw  "Erro ao abrir arquivo de mapa";

        TransliterationTree tree = TransliterationTree();
        std::string s;
        while(getline(commandFile, s)) {
            std::istringstream iss (s);
            char commandType = iss.get();
            iss.ignore(2);
            std::string message, encodedMessage, decodedMessage;
            std::getline(iss, message);

            switch (commandType)
            {
                case 'A':
                    tree.AddTree(message);
                    break;
                case 'C':
                    encodedMessage = tree.Encode(message);
                    std::cout << encodedMessage << std::endl;
                    break;
                case 'D':
                    decodedMessage = tree.Decode(message);
                    std::cout << decodedMessage << std::endl;
            }
        }

        return 0;
    }
    catch (char exception[]) {
        std::cout << exception;
        return -1;
    }
}