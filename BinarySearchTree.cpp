/**
 * \file BinarySearchTree.cpp
 *
 * \author Hannah White
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * \brief Class that implements nodes-- basically a doubly-linked list used to populate the BST
 */
class Node
{
public:
	Node() {}
	virtual ~Node() {}
	bool HasLeft();
	bool HasRight();
	void SetLeft(Node* l) {Left = l;}
	Node* GetLeft() { return Left; }
	void SetRight(Node* r) { Right = r; }
	Node* GetRight() { return Right; }

	int GetKey() { return Key; }
	void SetKey(int key) { Key = key; }

private:
	Node* Left = nullptr;
	Node* Right = nullptr;
	int Key;
};

bool Node::HasLeft()
{
	if (Left != nullptr)
	{
		return true;
	}

	return false;
}

bool Node::HasRight()
{
	if (Right != nullptr)
	{
		return true;
	}

	return false;
}


/**
 * \brief Class that implements BST, utilizes nodes
 */
class BST
{
public:
	BST() {}
	virtual ~BST();

	void Insert(Node* n, int key);
	void Search(Node* n);
	void Destroy(Node* n);
	void Destroy();
	void SetRoot(Node* r) { Root = r; }
	Node* GetRoot() { return Root; }

private:
	Node* Root = nullptr;
};

BST::~BST()
{
	Destroy();
}

void BST::Insert(Node* n, int key)
{
	if (key < n->GetKey())
	{
		// not a leaf node
		if (n->HasLeft() == true)
		{
			Insert(n->GetLeft(), key);
		}
		// found a spot to add the new node
		else
		{
			// create the new node and set it as child of parent
			n->SetLeft(new Node);
			// set the key
			n->GetLeft()->SetKey(key);
		}
	}
	else if (key > n->GetKey())
	{
		if (n->HasRight() == true)
		{
			Insert(n->GetRight(), key);
		}
		// found a spot to add the new node
		else
		{
			// create the new node and set it as a child of parent
			n->SetRight(new Node);
			// set the key
			n->GetRight()->SetKey(key);
		}
	}
	
}

void BST::Destroy()
{
	Destroy(Root);
}

void BST::Destroy(Node* n)
{
	if (n != nullptr)
	{
		Destroy(n->GetLeft());
		Destroy(n->GetRight());
		delete n;
	}
}

void Preorder(Node* n)
{
	if (n != nullptr)
	{
		cout << n->GetKey() << " ";
		Preorder(n->GetLeft());
		Preorder(n->GetRight());
	}


}

void Inorder(Node* n)
{
	if (n != nullptr)
	{
		Inorder(n->GetLeft());
		cout << n->GetKey() << " ";
		Inorder(n->GetRight());
	}
}

void Postorder(Node* n)
{
	if (n != nullptr)
	{
		Postorder(n->GetLeft());
		Postorder(n->GetRight());
		cout << n->GetKey() << " ";
	}
}

int main(int argc, const char * argv[])
{
	ifstream file(argv[1]);
	// error checking to see if file opened
	if (!file.is_open()) {
		cout << "Could not open file.\n";
		exit(1);
	}

	BST Tree;

	string word;

	int count = 0;
	while (!file.eof())
	{
		getline(file, word, ' ');
		if (count == 0)
		{
			Tree.SetRoot(new Node);
			Tree.GetRoot()->SetKey(stoi(word));
		}
		else
		{
			Tree.Insert(Tree.GetRoot(), stoi(word));
		}
		
	}

	Preorder(Tree.GetRoot());
	cout << endl;
	Inorder(Tree.GetRoot());
	cout << endl;
	Postorder(Tree.GetRoot());
	system("pause");
}