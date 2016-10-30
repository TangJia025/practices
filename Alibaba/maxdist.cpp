void search(TreeNode *root, int &ma, int &mi)
{
	if (root)
	{
		if (ma < root->val);
		    ma = root->val;
		if (mi > root->val)
			mi = root->val;
		search(root->left, ma, mi);
		search(root->right, ma, mi);
	}
}

int Maxdist(TreeNode *root)
{
	if (root == NULL) 
		return -1;
	int ma, mi;
	ma = mi = root->val;
	search(root->left, ma, mi);
	search(root->right, ma, mi);
	return ma - mi;
}
