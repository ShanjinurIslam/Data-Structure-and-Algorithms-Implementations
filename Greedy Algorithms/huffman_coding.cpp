#include <bits/stdc++.h>
#define COUNT 5
using namespace std;

typedef struct Treenode
{
    char c;
    float frequency;
    Treenode *left;
    Treenode *right;
} Node;

bool Compare(Node *a, Node *b)
{
    return a->frequency > b->frequency;
}

//taken from geeksforgeeks

void print2DUtil(Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->c << "\n";

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(Node *root)
{
    print2DUtil(root, 0);
}

int main()
{
    string s = "Sed ut perspiciatis unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos qui ratione voluptatem sequi nesciunt. Neque porro quisquam est, qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Quis autem vel eum iure reprehenderit qui in ea voluptate velit esse quam nihil molestiae consequatur, vel illum qui dolorem eum fugiat quo voluptas nulla pariatur?";
    map<char, int> char_map;
    priority_queue<Node *, vector<Node *>, std::function<bool(Node *, Node *)>> p(Compare);

    for (auto u : s)
    {
        char_map[u]++;
    }

    for (auto u : char_map)
    {
        Node *node = (Node *)malloc(sizeof(Node));
        node->c = u.first;
        node->frequency = u.second;
        node->left = NULL;
        node->right = NULL;
        p.push(node);
    }

    while (!(p.size() == 1))
    {

        Node *a = p.top();
        p.pop();
        Node *b = p.top();
        p.pop();
        Node *node = (Node *)malloc(sizeof(Node));
        node->c = '*';
        node->frequency = a->frequency + b->frequency;
        node->left = a;
        node->right = b;
        p.push(node);
    }

    Node *final = p.top();
    print2D(final);
    return 0;
}