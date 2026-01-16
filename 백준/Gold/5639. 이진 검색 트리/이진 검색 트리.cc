#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct Node
{
	int key;
	Node* left;
	Node* right;
	Node(int key) : key(key), left(nullptr), right(nullptr) {}
};

void func(Node* cur)
{
	if (cur == nullptr) return;
	func(cur->left);
	func(cur->right);
	cout << cur->key << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int num;
	Node* root = nullptr;
	while (scanf("%d", &num) != EOF) {
		if (root == nullptr)
		{
			root = new Node(num);
			continue;
		}
		Node* cur = root;
		while (true)
		{
			if (num < cur->key)
			{
				if (cur->left == nullptr) break;
				cur = cur->left;
			}
			else
			{
				if (cur->right == nullptr) break;
				cur = cur->right;
			}
		}
		if (num < cur->key) cur->left = new Node(num);
		else cur->right = new Node(num);
	}
	func(root);
}