#include <iostream>
#include <string.h>
using namespace std;

class Node
{
public:
    char data;
    Node *left, *right;
};

class Stack
{
    Node *data[30];
    int top;

public:
    Stack() { top = -1; }
    bool empty() { return top == -1; }
    void push(Node *p) { data[++top] = p; }
    Node *pop() { return (top == -1) ? nullptr : data[top--]; }
    Node *peek() { return (top == -1) ? nullptr : data[top]; }
};

class Tree
{
    Node *root;

public:
    Tree() { root = nullptr; }

    void buildFromPrefix(char prefix[])
    {
        // Clean up any existing tree before building a new one
        if (root != nullptr) {
            deleteEntireTree();
        }

        Stack s;
        int len = strlen(prefix);
        
        // Process the prefix expression from right to left
        for (int i = len - 1; i >= 0; i--)
        {
            Node *newNode = new Node;
            newNode->data = prefix[i];
            newNode->left = newNode->right = nullptr;

            // If operand, push to stack
            if (isalnum(prefix[i]))
            {
                s.push(newNode);
            }
            // If operator, pop two nodes and connect
            else
            {
                if (!s.empty()) {
                    newNode->right = s.pop();  // First pop becomes right child
                }
                if (!s.empty()) {
                    newNode->left = s.pop();   // Second pop becomes left child
                }
                s.push(newNode);
            }
        }
        
        // Set the root to the final tree
        root = s.pop();
        cout << "Expression tree built successfully.\n";
    }

    void nonRecursivePostOrder()
    {
        if (root == nullptr)
        {
            cout << "Tree is empty.\n";
            return;
        }

        Stack s1, s2;
        s1.push(root);

        // First use s1 to traverse and s2 to store nodes in postorder
        while (!s1.empty())
        {
            Node *temp = s1.pop();
            s2.push(temp);

            if (temp->left)
                s1.push(temp->left);
            if (temp->right)
                s1.push(temp->right);
        }

        // Print nodes from s2
        cout << "Post-order traversal (non-recursive): ";
        while (!s2.empty())
        {
            cout << s2.pop()->data << " ";
        }
        cout << endl;
    }

    void deleteTree(Node *temp)
    {
        if (!temp)
            return;
        
        deleteTree(temp->left);
        deleteTree(temp->right);
        cout << "Deleting Node: " << temp->data << endl;
        delete temp;
    }

    void deleteEntireTree()
    {
        if (!root)
        {
            cout << "Tree is already empty.\n";
            return;
        }
        deleteTree(root);
        root = nullptr;
        cout << "Expression tree deleted successfully.\n";
    }
};

int main()
{
    Tree t;
    int choice;
    char expr[30];

    do
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Build Expression Tree from Prefix\n";
        cout << "2. Post-order Traversal (Non-Recursive)\n";
        cout << "3. Delete Expression Tree\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter prefix expression: ";
            cin >> expr;
            t.buildFromPrefix(expr);
            break;
        case 2:
            t.nonRecursivePostOrder();
            break;
        case 3:
            t.deleteEntireTree();
            break;
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
//+--a*b/def

