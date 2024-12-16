#include <iostream>
#include <tinyxml2.h>

using namespace tinyxml2;
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    const char* filename = argv[1];
    XMLDocument doc;
    XMLError result = doc.LoadFile(filename);
    if (result != XML_SUCCESS) {
        cout << "Error loading XML file!" << endl;
        return 1;
    }
    //test

    XMLElement* catalog = doc.FirstChildElement("catalog");
    if (catalog == nullptr) {
        cout << "No 'catalog' element found in the XML file!" << endl;
        return 1;
    }

    XMLElement* book = catalog->FirstChildElement("book");
    while (book != nullptr) {
        XMLElement* title = book->FirstChildElement("title");
        if (title != nullptr) {
            cout << "Title: " << title->GetText() << endl;
        }
        book = book->NextSiblingElement("book");
    }

    return 0;
}
