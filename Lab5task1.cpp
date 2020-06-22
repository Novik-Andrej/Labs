#include <iostream>

using namespace std;

struct bstree {

	char* key;

	int value;

	bstree* left, * right;

};

struct bstree* bstree_create(char*, int);

//Создание элемента(O(1))

void bstree_add(struct bstree*, char*, int);

//Добавление элемента(Худший случай–O(n), Средний случай–O(log n))

struct bstree* bstree_lookup(struct bstree*, char*);

//Поиск элемента(Худший случай–O(n), Средний случай–O(log n))

struct bstree* bstree_min(struct bstree*);

//Поиск элемента с минимальным значением(Худший случай–O(n), Средний случай–O(log n))

struct bstree* bstree_max(struct bstree*);

//Поиск элемента с максимальным значением(Худший случай–O(n), Средний случай–O(log n))

void show(bstree*&); //Обход дерева(O(n)

	void del(bstree*&);

bstree* bstree_create(char* key, int value) {

	bstree* node;

	node = new bstree;

	if (node) {

		node->key = _strdup(key);

		node->value = value;

		node->left = 0;

		node->right = 0;

	}

	return node;

}

void bstree_add(bstree* tree, char* key, int value) {

	bstree* root;

	bstree* node;

	if (!tree) return;

	root = tree;

	while (tree) {

		root = tree;

		if (strcmp(key, tree->key) < 0)

			tree = tree->left;

		else if (strcmp(key, tree->key) > 0)

			tree = tree->right;

		else return;

	}

	node = bstree_create(key, value);

	if ((strcmp(key, root->key) < 0))

		root->left = node;

	else

		root->right = node;

}

bstree* bstree_lookup(bstree* tree, char* key) {

	if (!tree)return 0;

	if (strcmp(tree->key, key) == 0)

		return tree;

	if (strcmp(key, tree->key) < 0) {

		if (tree->left)

			bstree_lookup(tree->left, key);

		else return 0;

	}

	else if (strcmp(key, tree->key) > 0) {

		if (tree->right)

			bstree_lookup(tree->right, key);

		else return 0;

	}

}

bstree* bstree_min(bstree* tree) {

	if (tree->left)

		bstree_min(tree->left);

	else return tree;

}

bstree* bstree_max(bstree* tree) {

	if (tree->right)

		bstree_max(tree->right);

	else return tree;

}

void show(bstree*& tree) {

	if (tree) {

		show(tree->left);

		cout << tree->key << " - " << tree->value << endl;

		show(tree->right);

	}

}

void del(bstree*& tree) {

	if (tree) {

		del(tree->left);

		del(tree->right);

		delete tree;

		tree = 0;

	}
}
int main() {

	char key[30] = "root";

	bstree* tree = bstree_create(key, strlen(key));

	


	for (int i = 0; i < 5; i++) {

		cout << "input >>> ";

		cin.getline(key, 30);

		bstree_add(tree, key, strlen(key));

	}

	cout << "TREE:\n\n";

	show(tree);

	cout << endl;

	bstree* temp;

	temp = bstree_min(tree);

	cout << "Min element >>> " << temp->key << " - " << temp->value << endl;

	temp = bstree_max(tree);

	cout << "Max element >>> " << temp->key << " - " << temp->value << endl;

	cout << "Search for >>> ";

	char find[30];

	cin.getline(find, 30);

	temp = bstree_lookup(temp, find);

	cout << "Searched element >>> " << temp->key << " - " << temp->value << endl;

	del(tree);

}