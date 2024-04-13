#include <iostream>
using namespace std;

// Structure to represent a book
struct Book {
    string isbn;
    string title;
    string author;
    double price;
    int quantity;
};

// Structure for a binary search tree (BST) node
struct Node {
    Book book;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(Book book) {
    Node* newNode = new Node;
    newNode->book = book;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Function to insert a book into the BST
Node* insertNode(Node* root, Book book) {
    // If the tree is empty, create a new node and return it
    if (root == nullptr) {
        return createNode(book);
    }

    // Otherwise, recursively insert the book in the appropriate subtree
    if (book.isbn < root->book.isbn) {
        root->left = insertNode(root->left, book);
    } else {
        root->right = insertNode(root->right, book);
    }

    return root;
}

// Function to search for a book by ISBN in the BST
Node* searchNode(Node* root, string isbn) {
    // If the tree is empty or the book is found at the root, return the root
    if (root == nullptr || root->book.isbn == isbn) {
        return root;
    }

    // If the book's ISBN is less than the root's ISBN, search in the left subtree
    if (isbn < root->book.isbn) {
        return searchNode(root->left, isbn);
    }

    // If the book's ISBN is greater than the root's ISBN, search in the right subtree
    return searchNode(root->right, isbn);
}

// Function to remove a book by ISBN from the BST
Node* removeNode(Node* root, string isbn) {
    // If the tree is empty, return nullptr
    if (root == nullptr) {
        return root;
    }

    // Otherwise, recursively remove the book in the appropriate subtree
    if (isbn < root->book.isbn) {
        root->left = removeNode(root->left, isbn);
    } else if (isbn > root->book.isbn) {
        root->right = removeNode(root->right, isbn);
    } else {
        // If the book is found, perform the removal
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // If the book has two children, find the inorder successor (smallest in the right subtree)
        Node* temp = root->right;
        while (temp->left != nullptr) {
            temp = temp->left;
        }

        // Copy the data of the inorder successor to the current node
        root->book = temp->book;

        // Recursively remove the inorder successor
        root->right = removeNode(root->right, temp->book.isbn);
    }

    return root;
}

// Function to display the details of a book
void displayBook(Book book) {
    cout << "ISBN: " << book.isbn << endl;
    cout << "Title: " << book.title << endl;
    cout << "Author: " << book.author << endl;
    cout << "Price: $" << book.price << endl;
    cout << "Quantity: " << book.quantity << endl;
    cout << endl;
}

// Function to display all books in the inventory (inorder traversal of the BST)
void displayInventory(Node* root) {
    if (root != nullptr) {
        displayInventory(root->left);
        displayBook(root->book);
        displayInventory(root->right);
    }
}

int main() {
    Node* root = nullptr; // Initialize the root of the BST

    cout << "Welcome to the Bookstore Inventory Management System!" << endl;

    while (true) {
        cout << "1. Add a book to the inventory" << endl;
        cout << "2. Remove a book from the inventory" << endl;
        cout << "3. Update the quantity of a book" << endl;
        cout << "4. Search for a book by ISBN" << endl;
        cout << "5. Display all books in the inventory" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Enter the book's ISBN: ";
            string isbn;
            cin >> isbn;

            cout << "Enter the book's title: ";
            string title;
            cin.ignore();
            getline(cin, title);

            cout << "Enter the book's author: ";
            string author;
            getline(cin, author);

            cout << "Enter the book's price: ";
            double price;
            cin >> price;

            cout << "Enter the book's quantity: ";
            int quantity;
            cin >> quantity;

            Book book;
            book.isbn = isbn;
            book.title = title;
            book.author = author;
            book.price = price;
            book.quantity = quantity;

            root = insertNode(root, book);
            cout << "Book added to the inventory successfully." << endl;
        } else if (choice == 2) {
            cout << "Enter the ISBN of the book to remove: ";
            string isbn;
            cin >> isbn;

            root = removeNode(root, isbn);
            cout << "Book removed from the inventory successfully." << endl;
        } else if (choice == 3) {
            cout << "Enter the ISBN of the book to update: ";
            string isbn;
            cin >> isbn;

            Node* node = searchNode(root, isbn);
            if (node != nullptr) {
                cout << "Enter the new quantity: ";
                int newQuantity;
                cin >> newQuantity;

                node->book.quantity = newQuantity;
                cout << "Quantity updated successfully." << endl;
            } else {
                cout << "Book not found in the inventory." << endl;
            }
        } else if (choice == 4) {
            cout << "Enter the ISBN of the book to search: ";
            string isbn;
            cin >> isbn;

            Node* node = searchNode(root, isbn);
            if (node != nullptr) {
                displayBook(node->book);
            } else {
                cout << "Book not found in the inventory." << endl;
            }
        } else if (choice == 5) {
            cout << "Inventory:" << endl;
            displayInventory(root);
        } else if (choice == 7) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
