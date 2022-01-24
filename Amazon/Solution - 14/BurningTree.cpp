#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    Node *root = new Node(stoi(ip[0]));

    queue<Node *> queue;
    queue.push(root);
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        Node *currNode = queue.front();
        queue.pop();

        
        string currVal = ip[i];
        if (currVal != "N") {

            currNode->left = new Node(stoi(currVal));

            queue.push(currNode->left);
        }
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        if (currVal != "N") {

            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution14 {
public:
    int minTime(Node* root, int target)
    {
        unordered_map <Node*, Node*> parent;
        unordered_map <Node*, bool> visited;
        queue<Node*> q;
        int time = 0;
        q.push(root);
        Node * trgt;
        while (!q.empty()){
            int n = q.size();
            while (n--){
                Node *temp = q.front();
                q.pop();
                if (temp -> data == target){
                    trgt = temp;
                }
                if (temp->left != NULL){
                    q.push(temp->left);
                    parent[temp->left] = temp;
                }
                if (temp->right != NULL){
                    q.push(temp->right);
                    parent[temp->right] = temp;
                }
            }
        }
        q.push(trgt);
        visited[trgt] = true;
        while (!q.empty()){
            int n = q.size();
            while (n--){
                Node * temp = q.front();
                q.pop();
                if (temp -> left != NULL && visited[temp->left] == false){
                    q.push(temp->left);
                    visited[temp->left] = true;
                }
                if (temp -> right != NULL && visited[temp->right] == false){
                    q.push(temp->right);
                    visited[temp->right] = true;
                }
                if (parent[temp] != NULL && visited[parent[temp]] == false){
                    q.push(parent[temp]);
                    visited[parent[temp]] = true;
                }
            }
            time++;
        }
        return time - 1;
    }
};

int main(){
    int tc;
    scanf("%d ", &tc);
    while (tc--){
        string treeString;
        getline(cin, treeString);
        int target;
        cin >> target;
        Node *root = buildTree(treeString);
        Solution14 obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();

    }


    return 0;
}
// } Driver Code Ends