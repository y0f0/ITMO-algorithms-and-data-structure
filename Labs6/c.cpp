#include <string>
#include <fstream>

using namespace std;

const int MOD = 1'000'000;

struct node {
    string key;
    string value;
    node* prev = nullptr;
    node* prev_key = nullptr;
    node* next = nullptr;
    node* next_key = nullptr;
};

node* hash_table[MOD];

int hash_(string key) {
	const int p = 31;
	int hash = 0, p_pow = 1;
	for (char i : key)
	{
		hash += (i - 'a' + 1) * p_pow;
		p_pow *= p;
	}
	if (hash >= 0) {
		return hash % MOD;
	}
	else {
		return (MOD- abs(hash) % MOD) % MOD;
	}
}


node* make_node(string& key, string& value) {
    node* hash = new node();
    hash->prev = nullptr;
    hash->prev_key = nullptr;
    hash->key = key;
    hash->value = value;
    hash->next_key = nullptr;
    hash->next = nullptr;
    return hash;
}

node* add_hash(node*& last, string& key, string& value) {
    node* hash = make_node(key, value);
    hash->prev = last;
    last->next = hash;

    return hash;
}

node* hash_put(string& key, string& value, node*& last) {
    int hash = hash_(key);
    node* head = hash_table[hash];

    if (head) {
        node* root = head;
        while (root->next) {
            if (root->key == key) {
                root->value = value;
                return nullptr;
            }
            root = root->next;
        }

        if (root->key != key) {
            node* new_hash = add_hash(root, key, value);
            new_hash->prev_key = last;

            if (last) last->next_key = new_hash;

            return new_hash;
        }

        else {
            root->value = value;
            return nullptr;
        }
    }

    else {
        hash_table[hash] = make_node(key, value);
        hash_table[hash]->prev_key = last;

        if (last) last->next_key = hash_table[hash];

        return hash_table[hash];
    }
}

void hash_delete(string& key, node*& last) {
	int hash = hash_(key);
	node* pointer = hash_table[hash];
	while (pointer) {
		if (pointer->key == key) {
			if (last == pointer) last = pointer->prev_key;
			if (pointer->prev_key) pointer->prev_key->next_key = pointer->next_key;
			if (pointer->next_key) pointer->next_key->prev_key = pointer->prev_key;
			if (pointer->prev) pointer->prev->next = pointer->next;
			if (pointer->next) pointer->next->prev = pointer->prev;
			if (pointer == hash_table[hash]) hash_table[hash] = NULL;
			free(pointer);
			return;
		}
		pointer = pointer->next;
	}
}

node* hash_find(string& key) {
    node* root = hash_table[hash_(key)];
    while (root) {
        if (root->key == key)
            return root;
        root = root->next;
    }
    return nullptr;
}



int main() {
    std::ifstream fin("linkedmap.in");
    std::ofstream fout("linkedmap.out");

    node* last = nullptr;
    string line;
    string key;
    string value;

    while (fin >> line) {
        fin >> key;

        if (line == "put") {
            fin >> value;
            node* pointer = hash_put(key, value, last);
            if (pointer) last = pointer;
        }

        if (line == "delete") {
            hash_delete(key, last);
        }

        if (line == "get") {
            bool ok = true;
            node* root = hash_table[hash_(key)];
            while (root) {
                if (root->key == key) {
                    fout << root->value << "\n";
                    ok = false;
                    break;
                }
                root = root->next;
            }
            if (ok) 
                fout << "none" << '\n';
        }

        if (line == "prev") {
            node* element = hash_find(key);

            if (element && element->prev_key) {
                fout << element->prev_key->value << "\n";
            } else {
                fout << "none" << '\n';
            }
        }

        if (line == "next") {
            node* element = hash_find(key);

            if (element && element->next_key) {
                fout << element->next_key->value << "\n";
            } else {
                fout << "none" << '\n';
            }
        }
    }
    
    fin.close();
    fout.close();
    return 0;
}
