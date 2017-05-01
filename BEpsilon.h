#ifndef BEPSILON_BEPSILON_H
#define BEPSILON_BEPSILON_H

#include <iostream>
#include <vector>

using namespace std;

template<typename Key, typename Value, int B>
class BEpsilonTree {
public:
    BEpsilonTree() : root(NULL) {}

    void insert(Key key, Value value);

    Value pointQuery(Key key);

    vector<Value> rangeQuery(Key minKey, Key maxKey);

    void remove(Key key);

private:

    typedef class Node {
    public:

        Node(bool leaf, Node *parent = NULL, Node *sibling = NULL);

        /**
        Check if node is is full, node is full when it has B children.

        @return true if node is full, false else.
        */
        bool isFull();

        /**
        Approximately search a key in subtree rooted with this node,
        if a given key is in the range of some leaf keys it will return that
        leaf else it will return the first or the last leaf.

        @param key to look up for.
        @return a leaf which the given key is in the range of this leaf keys.
        */
        Node *approximateSearch(Key key);

        // A function that returns the index of the first key that is greater
        // or equal to k
        int findKey(Key key);

        //A function to find the index of this node in the his parent children vector
        int getOrder();


        // A utility function to split the child of this node. ix is index
        // of child in child vector. The Child must be full when this
        // function is called
        void splitChild(int ix, Node *child);


        // A utility function to insert a new key in the subtree rooted with
        // this node. The assumption is, the node must be non-full when this
        // function is called
        void insert(Key key, Value value);

        //A utility function to make sure that all the leaf is on the same height.
        //should call after the key-value insertion from the leaf.
        void insertKeysUpdate();

    private:
        bool leaf;
        Node *parent;
        vector<Key> keys;

        //if this node is a leaf
        //values.size() == keys.size(),for now it's equal to 1, keys.size.max == B-1;
        vector<Value> values;
        Node *sibling;

        //if the node is internal
        //children.size() == keys.size()+1;
        vector<Node *> children;

        friend class BEpsilonTree;
    } Node;

    Node *root;
};

template<typename Key, typename Value, int B>
BEpsilonTree<Key, Value, B>::Node::Node(bool leaf, Node *parent, Node *sibling) {
    this->parent = parent;
    this->sibling = sibling;
    this->leaf = leaf;
};

template<typename Key, typename Value, int B>
bool BEpsilonTree<Key, Value, B>::Node::isFull() {
    //choose the max number of key and values in each node according to the block size.
    return this->keys.size() == B;
}

template<typename Key, typename Value, int B>
int BEpsilonTree<Key, Value, B>::Node::getOrder() {
    int ix = 0;
    //for sure this node isn't root and full, we check it before this function call.
    typedef typename vector<BEpsilonTree<Key, Value, B>::Node *>::iterator iterator;
    for (iterator it = this->parent->children.begin(); it != this->parent->children.end(); it++) {
        if ((*it) == this) {
            return ix;
        } else {
            ix++;
        }
    }
};

template<typename Key, typename Value, int B>
void BEpsilonTree<Key, Value, B>::Node::splitChild(int ix, BEpsilonTree<Key, Value, B>::Node *left_child) {

    //this node is the parent of right and left child.
    // Create a new node which is going to store (child->keys.size()-1) keys of child
    BEpsilonTree<Key, Value, B>::Node *right_child = new BEpsilonTree<Key, Value, B>::Node(left_child->leaf,
                                                                                           left_child->parent,
                                                                                           left_child->sibling);

    //update the sibling of both child and new node, add the new node between the child and the new node.
    //if the nods is internal and not a leaf, the sibling will be NULL.
    right_child->sibling = left_child->sibling;
    left_child->sibling = left_child->leaf ? right_child : NULL;

    //update to move the minimum number of children for each node, and not 1.
    //B should be grater than 2, else infinite loop will occur.
    int middle_ix = B / 2;


    if (left_child->leaf) {
        right_child->keys.insert(right_child->keys.begin(),
                                 left_child->keys.begin() + middle_ix,
                                 left_child->keys.end());

        left_child->keys.erase(left_child->keys.begin() + middle_ix,
                               left_child->keys.end());

        right_child->values.insert(right_child->values.begin(),
                                   left_child->values.begin() + middle_ix,
                                   left_child->values.end());

        left_child->values.erase(left_child->values.begin() + middle_ix,
                                 left_child->values.end());

        this->keys.insert(this->keys.begin() + ix, right_child->keys[0]);
    } else {

        //find the appropriate key and its index.
        int key = left_child->keys[middle_ix];
        int key_ix = 0;
        while ((key_ix >= 0) && (key_ix < this->keys.size()) && (this->keys[key_ix] < key)) {
            key_ix++;
        }

        this->keys.insert(this->keys.begin() + key_ix, key);

        right_child->keys.insert(right_child->keys.begin(),
                                 left_child->keys.begin() + (middle_ix + 1),
                                 left_child->keys.end());

        left_child->keys.erase(left_child->keys.begin() + (middle_ix),
                               left_child->keys.end());

        right_child->children.insert(right_child->children.begin(),
                                     left_child->children.begin() + middle_ix + 1,
                                     left_child->children.end());

        // w/o this, compilation error, with nested template in dependent scope.
        typedef typename vector<BEpsilonTree<Key, Value, B>::Node *>::iterator iterator;
        for (iterator it = left_child->children.begin() + middle_ix + 1; it != left_child->children.end(); it++) {
            (*it)->parent = right_child;
        }

        left_child->children.erase(left_child->children.begin() + middle_ix + 1,
                                   left_child->children.end());


    }

    //set the new node as a child of this node
    this->children.insert(this->children.begin() + (ix + 1), right_child);

};

template<typename Key, typename Value, int B>
void BEpsilonTree<Key, Value, B>::Node::insertKeysUpdate() {
    if (this->isFull()) {
        if (this->parent == NULL) {//this is root :)
            Node *node = new Node(false);
            //move it the the end;
            this->parent = node;
            node->children.insert(node->children.begin(), this);
            node->splitChild(0, this);
        } else {
            this->parent->splitChild(this->getOrder(), this);
            this->parent->insertKeysUpdate();
        }
    }
};

template<typename Key, typename Value, int B>
void BEpsilonTree<Key, Value, B>::Node::insert(Key key, Value value) {

    //for finding the key position, we'll start with last index
    int ix = this->keys.size() - 1;
    //find the key index.
    while (ix >= 0 && keys[ix] > key) {
        ix--;
    }

    if (this->leaf) {
        this->keys.insert(this->keys.begin() + (ix + 1), key);
        this->values.insert(this->values.begin() + (ix + 1), value);
        this->insertKeysUpdate();
    } else {//this is internal node
        ix = ix == -1 ? 0 : ix;
        if (this->keys[ix] < key) {
            ix++;
        }
        this->children[ix]->insert(key, value);
    }
};

template<typename Key, typename Value, int B>
typename BEpsilonTree<Key, Value, B>::Node *BEpsilonTree<Key, Value, B>::Node::search(Key key){
    Node *res = root;

    while (!res->leaf) {
        int pos = 0;
        for (int i = 0; i < res->keys.size() && key < res->keys[i]; ++i) {
            pos = i == 0 ? 0 : i + 1;
        }
        res = res->children[pos];
    }
    return res;
}
/*
 * the API B+ function
 * insert: A function for insertion to the tree
 * rangeQuery:
 * Query:
 * remove: A function to remove a key from the tree.s
 * */

template<typename Key, typename Value, int B>
void BEpsilonTree<Key, Value, B>::insert(Key key, Value value) {
    if (root == NULL) { // if the Tree is empty
        root = new Node(true);
        root->keys.insert(root->keys.begin(), key);
        root->values.insert(root->values.begin(), value);
    } else { //if the root is not null.
        root->insert(key, value);
        if (root->parent != NULL) {
            root = root->parent;
        }
    }
};

template<typename Key, typename Value, int B>
vector<Value> BEpsilonTree<Key, Value, B>::rangeQuery(Key minKey, Key maxKey) {
    vector<Value> res;
    if (root != NULL) {
        //get appropriate leafs
        Node *minNode = root->search(minKey);
        Node *maxNode = root->search(maxKey);
        Node *current = minNode;

        while (current != maxNode) {
            for (int i = 0; i < current->keys.size(); ++i) {
                if (minKey < current->keys[i] && current->keys[i] < maxKey) {
                    res.insert(current->values[i]);
                }
            }
            current = current->sibling;
        }
    }
    return res;
}

template<typename Key, typename Value, int B>
Value BEpsilonTree<Key, Value, B>::pointQuery(Key key) {
    return rangeQuery(key,key)[0];
};

template<typename Key, typename Value, int B>
void BEpsilonTree<Key, Value, B>::remove(Key key) {
    return;
}

#endif //BEPSILON_BEPSILON_H
