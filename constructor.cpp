#include <iostream>
#include <cstring>

// Forward declaration of the Example class
//class Example;

// Static member initialization


class Example {
    char* cStr;
    int& intRef;
    char name[100];
    static int A;
    
public:
    // Constructor
    Example(const char* str, int& ref, const char* n) : intRef(ref) {
        cStr = new char[strlen(str) + 1];
        strcpy(cStr, str);
        strncpy(name, n, sizeof(name) - 1);
        name[sizeof(name) - 1] = '\0'; // Ensure null-termination
        A++;
    }

    // Destructor
    ~Example() {
        delete[] cStr;
    }

    // Copy constructor
    Example(const Example& other) : intRef(other.intRef) {
        cStr = new char[strlen(other.cStr) + 1];
        strcpy(cStr, other.cStr);
        strncpy(name, other.name, sizeof(name) - 1);
        name[sizeof(name) - 1] = '\0'; // Ensure null-termination
        A++;
    }

    // Assignment operator
    Example& operator=(const Example& other) {
        if (this != &other) {
            delete[] cStr;

            cStr = new char[strlen(other.cStr) + 1];
            strcpy(cStr, other.cStr);
            strncpy(name, other.name, sizeof(name) - 1);
            name[sizeof(name) - 1] = '\0'; // Ensure null-termination

            // intRef is a reference, it cannot be reassigned
            // intRef = other.intRef; // This line is intentionally omitted
        }
        return *this;
    }

    // Function to display the values
    void display() const {
        std::cout << "cStr: " << cStr << "\n";
        std::cout << "intRef: " << intRef << "\n";
        std::cout << "name: " << name << "\n";
        std::cout << "A: " << A << "\n";
    }


};
int Example::A = 0;
int main() {
    int x = 10;
    Example ex("Hello", x, "ExampleName");
    ex.display();

    std::cout << "After changing x to 20:\n";
    x = 20;
    ex.display();

    Example ex2 = ex;
    ex2.display();
    
    return 0;
}

