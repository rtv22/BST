#include <iostream>
#include <fstream>



using namespace std;

template <class T>
struct Node
{
	T element;
	Node<T> *left, *right, *pparent;
};

template <class T>
class BST {
private:
	Node<T> *root;
	int count;
public:
	BST();
	~BST();
	void deleteNode(Node<T>* temp);
	void show(ostream&cout, Node<T> *Tree);
	void add(const T&);
	bool search(const T&, Node<T> *Tree);
	void input(const string file);
	void output(const string file);
	Node<T>* MinElement(Node<T>* min);
	Node<T>* getroot();
	int getcount() const;
	bool remove_element(Node<T>* parent, Node<T>* current, const T& val);
	bool deleteVal(const T& value);

};


template <typename T> BST<T>::BST() {
	root = nullptr;
	count = 0;
}

template <typename T>
BST<T>::~BST()
{
	deleteNode(root);
}

template<typename T>
void BST<T>::deleteNode(Node<T>* temp)
{
	if (!temp)
		return;
	if (temp->left)
	{
		deleteNode(temp->left);
		temp->left = nullptr;
	}

	if (temp->right)
	{
		deleteNode(temp->right);
		temp->right = nullptr;
	}
	delete temp;
}

template <typename T> void BST<T>::show(ostream&cout, Node<T> *Tree) {
	if (Tree != NULL) {

		cout << Tree->element << endl;;
		show(cout, Tree->left);
		show(cout, Tree->right);

	}
}

template <typename T> void BST<T>::add(const T &x) {
	Node<T>* daughter = new Node<T>;
	daughter->element = x;
	daughter->left = daughter->right = nullptr;
	Node<T>* parent = root;
	Node<T>* temp = root;

	while (temp)
	{
		parent = temp;
		if (x < temp->element)
			temp = temp->left;
		else temp = temp->right;
	}

	if (!parent)
		root = daughter;
	else {
		if (x < parent->element)
			parent->left = daughter;
		else
			parent->right = daughter;
	}
	count++;
}


template <typename T> Node<T>* BST<T>::getroot() {
	return root;
}

template <typename T> int BST<T>::getcount() const {
	return count;
}

template <typename T> void BST<T>::input(const string file) {
	ifstream fin(file);
	try
	{
		int temp;
		while (!fin.eof())
		{

			fin >> temp;
			add(temp);

		}
		fin.close();
	}
	catch (int i)
	{
		cout << "This file don't find" << endl;
	}

}

template <typename T> void BST<T>::output(const string file) {
	ofstream fout(file);
	show(fout, root);
	fout.close();
}

template <typename T> bool BST<T>::search(const T&x, Node<T>* Tree) {
	if (Tree == nullptr)
		return false;
	if (x == Tree->element) {
		return true;
	}
	else if (x < Tree->element) {
		search(x, Tree->left);
	}
	else search(x, Tree->right);
}

template <typename T> Node<T>* BST<T>::MinElement(Node<T>* min) {
	if (min->left == nullptr)
		return min;
	else
		return MinElement(min->left);


}

template<typename T>
bool BST<T>::remove_element(Node<T>* parent, Node<T>* current, const T& val)
{
	if (!current) return false;
	if (current->data == val)
	{
		if (current->left == NULL || current->right == NULL) {
			Node<T>* temp = current->left;
			if (current->right) temp = current->right;
			if (parent) {
				if (parent->left == current) {
					parent->left = temp;
				}
				else {
					parent->right = temp;
				}
			}
			else {
				this->root = temp;
			}
		}
		else {
			Node<T>* validSubs = current->right;
			while (validSubs->left) {
				validSubs = validSubs->left;
			}
			T temp = current->data;
			current->data = validSubs->data;
			validSubs->data = temp;
			return remove_element(current, current->right, temp);
		}
		delete current;
		count--;
		return true;
	}
	if (current->data > val)
		return remove_element(current, current->left, val);
	else
		return remove_element(current, current->right, val);
}

template<typename T>
bool BST<T>::deleteVal(const T& value)
{
	return this->remove_element(NULL, root, value);
}
