#include "includes.h"

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// Medium -- #116 -- accepted
class TreeQuestions {
public:
    static Node* connect(Node* root) {
        if (root == NULL) return root;
        Node* current;
        Node* start;

        start = root;

        while (start)
        {
            current = start;

            while (current)
            {
                if (current->left)
                    current->left->next = current->right;

                if (current->right && current->next)
                {
                    current->right->next = current->next->left;
                }

                current = current->next;
                
            }

            start = start->left;
        }

        return root;
    }
};
