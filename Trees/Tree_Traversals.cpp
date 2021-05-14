/*

  Author: Rakib Hasan
  Preorder, Inorder, and Postorder Traversal of a binary tree
  
*/

vector<int> res;

void pre(int pos, vector<int> &tree) {
	if (pos >= tree.size() or tree[pos] == -1) return;
	res.push_back(tree[pos]);
	pre(2*pos + 1, tree);
	pre(2*pos + 2, tree);
}

void in(int pos, vector<int> &tree) {
	if (pos >= tree.size() or tree[pos] == -1) return;
	in(2*pos + 1, tree);
	res.push_back(tree[pos]);
	in(2*pos + 2, tree);
}

void post(int pos, vector<int> &tree) {
	if (pos >= tree.size() or tree[pos] == -1) return;
	post(2*pos + 1, tree);
	post(2*pos + 2, tree);
	res.push_back(tree[pos]);
}

void print(vector<int> arr, string s) {
	cout << s << ": ";
	for (int &a : arr) {
		cout << a << ' ';
	}
	cout << endl;
}

int32_t main() {
	vector<int> arr = {1, 2, 5, 4, 3, - 1, 6}; // -1 refers to a null node
	
	pre(0, arr);
	print(res, "Preorder"); res.clear();
	
	in(0, arr);
	print(res, "Inorder"); res.clear();
	
	post(0, arr);
	print(res, "Postorder"); res.clear();
	
	return 0;
}



