#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <sstream>
using namespace std;

struct TreeNode {
    string name;
    bool isLocked;
    int id;
    TreeNode* parent;
    int anc_locked;
    int des_locked;
    vector<TreeNode*> child;

    TreeNode(string name, TreeNode* parent) {
        this->name = name;
        this->parent = parent;
        this->isLocked = false;
        this->id = 0;
        this->anc_locked = 0;
        this->des_locked = 0;
    }
};

void informDescendant(TreeNode* node, int val) {
    if (node == nullptr) return;
    node->anc_locked += val;
    for (auto des : node->child)
        informDescendant(des, val);
}

bool lock(TreeNode* node, int id) {
    if (node->isLocked) {
        cout << node->name << " is already locked.\n";
        return false;
    }
    if (node->anc_locked > 0 || node->des_locked > 0) {
        cout << node->name << " has locked ancestors or descendants.\n";
        return false;
    }

    TreeNode* cur = node->parent;
    while (cur != nullptr) {
        cur->des_locked += 1;
        cur = cur->parent;
    }

    informDescendant(node, 1);
    node->isLocked = true;
    node->id = id;
    cout << node->name << " is now locked by user " << id << endl;
    return true;
}

bool unlock(TreeNode* node, int id) {
    if (!node->isLocked || node->id != id) {
        return false;
    }

    TreeNode* cur = node->parent;
    while (cur != nullptr) {
        cur->des_locked -= 1;
        cur = cur->parent;
    }

    informDescendant(node, -1);
    node->isLocked = false;
    node->id = 0;
    return true;
}

bool getAllChild(TreeNode* node, vector<TreeNode*>& childList, int id) {
    if (node == nullptr) return true;

    if (node->isLocked) {
        if (node->id != id) return false;
        else childList.push_back(node);
    }

    if (node->des_locked == 0) return true;

    for (auto k : node->child) {
        if (!getAllChild(k, childList, id)) return false;
    }
    return true;
}

bool upgrade(TreeNode* node, int id) {
    if (node->isLocked || node->anc_locked > 0 || node->des_locked == 0) return false;

    vector<TreeNode*> childList;
    bool res = getAllChild(node, childList, id);
    if (!res) return false;

    informDescendant(node, 1);
    for (auto k : childList) {
        unlock(k, id);
    }

    node->isLocked = true;
    node->id = id;
    return true;
}

void printTree(TreeNode* node, int depth) {
    for (int i = 0; i < depth; i++) cout << "--";
    cout << node->name << " (Locked by: " << (node->isLocked ? to_string(node->id) : "None") << ")" << endl;
    for (auto child : node->child) {
        printTree(child, depth + 1);
    }
}

int main() {
    int n = 7;
    int m = 2;

    vector<string> nodes = {"World", "Asia", "Africa", "China", "India", "SouthAfrica", "Egypt"};
    vector<string> queries = {"1 China 9", "1 India 9", "2 India 9", "3 Asia 9", "1 India 3"};

    unordered_map<string, TreeNode*> map;
    TreeNode* root = new TreeNode(nodes[0], nullptr);
    map[nodes[0]] = root;

    queue<TreeNode*> q;
    q.push(root);
    int ind = 1;

    while (!q.empty() && ind < nodes.size()) {
        TreeNode* temp = q.front();
        q.pop();

        for (int i = 0; i < m && ind < nodes.size(); i++) {
            TreeNode* newNode = new TreeNode(nodes[ind], temp);
            temp->child.push_back(newNode);
            map[nodes[ind]] = newNode;
            q.push(newNode);
            ind++;
        }
    }

    for (auto query : queries) {
        istringstream iss(query);
        int type, id;
        string name;
        
        if (!(iss >> type >> name >> id)) {
            cout << "Invalid query format: " << query << endl;
            continue;
        }

        auto it = map.find(name);
        if (it == map.end()) {
            cout << "Node not found: " << name << endl;
            continue;
        }
        
        TreeNode* node = it->second;
        
        if (type == 1) {
            lock(node, id);
        } else if (type == 2) {
            if (unlock(node, id))
                cout << node->name << " unlocked by user " << id << endl;
            else
                cout << "Cannot unlock " << node->name << endl;
        } else if (type == 3) {
            if (upgrade(node, id))
                cout << node->name << " upgraded and locked by user " << id << endl;
            else
                cout << "Cannot upgrade " << node->name << endl;
        } else {
            cout << "Invalid operation type: " << type << endl;
        }
    }

    cout << "\nFinal Tree Status:\n";
    printTree(root, 0);

    // Free memory (not in original code, but good practice)
    for (auto& pair : map) {
        delete pair.second;
    }

    return 0;
}