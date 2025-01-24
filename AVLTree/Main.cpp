#include<iostream>
#include<queue>
using namespace std;


class TreeNode
{
public:
	int val;
	TreeNode* left, * right;
	TreeNode(int v)
	{
		val = v;
		left = NULL;
		right = NULL;
	}
	~TreeNode(){
		delete left;
		delete right;
		//delete this;
	}
	

};


class AVLTree {
	TreeNode* head;
public:
	AVLTree() {
		head = NULL;
	}

	void insert(int v)
	{

		TreeNode* root = head;
		TreeNode* temp = new TreeNode(v);
		if (root == NULL)
		{
			head = temp;
			return;
		}
		while (root!=NULL)
		{
			if (root->val == v)
			{
				return;
			}

			if (root->val > v)
			{
				if(	root->left == NULL)
				{
					root->left = temp;
					return;
				}
				root = root->left;
			}
			else if (root->val < v)
			{
				if (root->right == NULL)
				{
					root->right = temp;
					return;
				}

				root = root->right;
			}

			

		}


	}


	void remove(int v)
	{
		remove(v, head);
	}

	void display()
	{
		queue<TreeNode*> bfs;

		bfs.push(head);

		while (!bfs.empty())
		{
			int s = bfs.size();

			for (int i = 0; i < s; i++)
			{
				TreeNode* t = bfs.front();
				cout << t->val << ": ";
				bfs.pop();
				if (t->left != NULL)
				{
					cout << t->left->val << "L ";
					bfs.push(t->left);
				}
				if (t->right != NULL)
				{
					cout << t->right->val << "R ";
					bfs.push(t->right);
				}


			}

			cout << endl;
		}
	
	}


private:
	TreeNode* remove(int v, TreeNode* root)
	{
		if (root == NULL)
			return root;

		if (root->val == v)
		{
			if (root->left == NULL && root->right == NULL) // leaf
			{
				delete root;
				return NULL;
			}

			if (root->left == NULL)
			{
				TreeNode* l = root->right;
				delete root;
				return l;
			}
			if (root->right == NULL)
			{
				TreeNode* r = root->left;
				delete root;
				return r;
			}

			else
			{
				TreeNode* s = root->left;

				while (s->right != NULL)
				{
					s = s->right;
				}

				root->val = s->val;

				root->left = remove(s->val, root->left);

				return root;

			}
		}

		if (root->val > v)
		{
			root->left = remove(v, root->left);
		}
		else
		{
			root->right = remove(v, root->right);
		}



		return root;
	}



};
int main()
{
	cout << "Hello World" << endl;

	AVLTree Tree;

	Tree.insert(40);
	Tree.insert(20);
	Tree.insert(30);
	Tree.insert(10);
	Tree.insert(50);
	Tree.insert(60);
	Tree.insert(11);
	Tree.display();
	cout << " ************************\n";
	Tree.remove(20);
	Tree.display();
	return 0;

}