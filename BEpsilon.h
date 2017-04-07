#ifndef BEPSILON_BEPSILON_H
#define BEPSILON_BEPSILON_H

#include <vector>

using namespace std;
template <typename Key, typename Value, int Degree>
class BEpsilon {

private:

    class Node {
    private:
        bool leaf;

        //if leaf == true
        Key key;
        Value value;

        //else
        //rep invariant: (Degree/2) <= keys.size() < (Degree)
        vector<Key> keys;
        vector<Node*> childern;
    };

    Node* root;

public:

    //update if Key exist;
    void insert(Key key, Value value) {
    }

    Value pointQuery(Key key) {
        return Value();
    }

    vector<Value> rangeQuery(Key minKey, Key maxKey) {
        return vector<Value>();
    }

    void remove(Key key) {
    }
};

#endif //BEPSILON_BEPSILON_H
