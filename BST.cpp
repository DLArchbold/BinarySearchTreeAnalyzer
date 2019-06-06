#include <iostream>
#include <fstream>
#include <algorithm>
#include "BST.h"


using namespace std;


BST::BST() {
	root = NULL;
	count = 0;
}


bool BST::empty() {
	if (count == 0) return true;
	return false;
}


int BST::size() {
	return count;
}


void BST::preOrderPrint() {
	if (root == NULL) return;// handle special case
	else preOrderPrint2(root);// do normal process
	cout << endl;
}


void BST::preOrderPrint2(BTNode *cur) {
	if (cur == NULL) return;
	cur->item.print(cout);
	preOrderPrint2(cur->left);
	preOrderPrint2(cur->right);
}


void BST::inOrderPrint() {
	if (root == NULL) return;// handle special case
	else inOrderPrint2(root);// do normal process
	cout << endl;
}


void BST::inOrderPrint2(BTNode *cur) {
	if (cur == NULL) return;
	inOrderPrint2(cur->left);
	cur->item.print(cout);
	inOrderPrint2(cur->right);
}


void BST::postOrderPrint() {
	if (root == NULL) return;// handle special case
	else postOrderPrint2(root);// do normal process
	cout << endl;
}


void BST::postOrderPrint2(BTNode *cur) {
	if (cur == NULL) return;
	postOrderPrint2(cur->left);
	postOrderPrint2(cur->right);
	cur->item.print(cout);
}



int BST::countNode() {
	int	counter = 0;
	if (root == NULL) return 0;
	countNode2(root, counter);
	return counter;
}


void BST::countNode2(BTNode *cur, int &count) {
	if (cur == NULL) return;
	countNode2(cur->left, count);
	countNode2(cur->right, count);
	count++;
}


bool BST::findGrandsons(type grandFather) {
	if (root == NULL) return false;
	return (fGS2(grandFather, root));
}


bool BST::fGS2(type grandFather, BTNode *cur) {
	if (cur == NULL) return false;
	//if (cur->item == grandFather) {
	if (cur->item.compare2(grandFather)){

		fGS3(cur, 0);// do another TT to find grandsons
		return true;
	}
	if (fGS2(grandFather, cur->left)) return true;
	return fGS2(grandFather, cur->right);
}


void BST::fGS3(BTNode *cur, int level) {
	if (cur == NULL) return;
	if (level == 2) {
		cur->item.print(cout);
		return;  // No need to search downward
	}
	fGS3(cur->left, level + 1);
	fGS3(cur->right, level + 1);
}



void BST::topDownLevelTraversal() {
	BTNode			*cur;
	Queue		    q;


	if (empty()) return; 	// special case
	q.enqueue(root);	// Step 1: enqueue the first node
	while (!q.empty()) { 	// Step 2: do 2 operations inside
		q.dequeue(cur);
		if (cur != NULL) {
			cur->item.print(cout);

			if (cur->left != NULL)
				q.enqueue(cur->left);

			if (cur->right != NULL)
				q.enqueue(cur->right);
		}
	}
}

//insert for BST
bool BST::insert(type newItem) {
	BTNode	*cur = new BTNode(newItem);
	if (!cur) return false;		// special case 1
	if (root == NULL) {
		root = cur;
		count++;
		return true; 			// special case 2
	}
	insert2(root, cur);			// normal
	count++;
	return true;
}


void BST::insert2(BTNode *cur, BTNode *newNode) {
	//if (cur->item > newNode->item) {
	if (cur->item.compare1(newNode->item)){
		if (cur->left == NULL)
			cur->left = newNode;
		else
			insert2(cur->left, newNode);
	}
	else {
		if (cur->right == NULL)
			cur->right = newNode;
		else
			insert2(cur->right, newNode);
	}
}



bool BST::remove(type item) {
	if (root == NULL) return false; 		// special case 1: tree is empty
	return remove2(root, root, item); 		// normal case
}

bool BST::remove2(BTNode *pre, BTNode *cur, type item) {

	// Turn back when the search reaches the end of an external path
	if (cur == NULL) return false;

	// normal case: manage to find the item to be removed
	//if (cur->item == item) {
	if (cur->item.compare2(item)){
		if (cur->left == NULL || cur->right == NULL)
			case2(pre, cur);	// case 2 and case 1: cur has less than 2 sons
		else
			case3(cur);		// case 3, cur has 2 sons
		count--;				// update the counter
		return true;
	}

	// Current node does NOT store the current item -> ask left sub-tree to check
	//if (cur->item > item)
	if (cur->item.compare1(item))
		return remove2(cur, cur->left, item);

	// Item is not in the left subtree, try the right sub-tree instead
	return remove2(cur, cur->right, item);
}


void BST::case2(BTNode *pre, BTNode *cur) {

	// special case: delete root node
	if (pre == cur) {
		if (cur->left != NULL)	// has left son?
			root = cur->left;
		else
			root = cur->right;

		free(cur);
		return;
	}

	if (pre->right == cur) {		// father is right son of grandfather? 
		if (cur->left == NULL)			// father has no left son?
			pre->right = cur->right;			// connect gfather/gson
		else
			pre->right = cur->left;
	}
	else {						// father is left son of grandfather?
		if (cur->left == NULL)			// father has no left son? 
			pre->left = cur->right;				// connect gfather/gson
		else
			pre->left = cur->left;
	}

	free(cur);					// remove item
}


void BST::case3(BTNode *cur) {
	BTNode		*is, *isFather;

	// get the IS and IS_parent of current node
	is = isFather = cur->right;
	while (is->left != NULL) {
		isFather = is;
		is = is->left;
	}

	// copy IS node into current node
	cur->item = is->item;

	// Point IS_Father (grandfather) to IS_Child (grandson)
	if (is == isFather)
		cur->right = is->right;		// case 1: There is no IS_Father    
	else
		isFather->left = is->right;	// case 2: There is IS_Father

	// remove IS Node
	free(is);
}

bool BST::deepestNodes()
{


	BTNode *cur = root;
	string tree;



	//cout << Height(cur, tree) << endl;
	//cout << tree << endl;

	if (PrintDeepestNodes(root, Height(cur)) == false)
	{
		return false;
	}














	return true;
}
bool BST::PrintDeepestNodes(BTNode* root, int levels)
{
	if (!root) return false;

	if (levels == 0)
		 root->item.print(cout);

	else if (levels > 0)
	{
		PrintDeepestNodes(root->left, levels - 1);
		PrintDeepestNodes(root->right, levels - 1);
		return true;
	}

	return false;
}



int BST::Height(BTNode *cur) {
	


	
	
	
	if (root == NULL || cur == NULL)
	{
		
		return -1;
	}

	
	
	
	
	return max(Height(cur->left), Height(cur->right))+1;


}



bool BST::display(int order, int source)
{
	if (empty())
	{
		return false;
	}



	if (order == 1)
	{
		if (source == 1)
		{
			inOrderPrint();
		}
		else if (source == 2)
		{
			inOrderPrintToFile();
		}
	}




	if (order == 2)
	{
		if (source == 1)
		{
			ReverseinOrderPrint();
		}
		else if (source == 2)
		{
			ReverseinOrderPrintToFile();
		}
	}






	return true;
}






void BST::inOrderPrintToFile() {
	if (root == NULL) return;// handle special case
	else
	{
		ofstream output;
		output.open("student-info.txt");
		inOrderPrint2ToFile(root, output);
		output << endl;
		output.close();
	}// do normal process
	
}


void BST::inOrderPrint2ToFile(BTNode *cur, ofstream &output) {
	if (cur == NULL) return;
	inOrderPrint2ToFile(cur->left, output);
	cur->item.print(output);
	inOrderPrint2ToFile(cur->right, output);
}



void BST::ReverseinOrderPrint() {
	if (root == NULL) return;// handle special case
	else ReverseinOrderPrint2(root);// do normal process
	cout << endl;
}

void BST:: ReverseinOrderPrint2(BTNode *cur) {
	if (cur == NULL) return;
	ReverseinOrderPrint2(cur->right);
	cur->item.print(cout);
	ReverseinOrderPrint2(cur->left);
}


void BST::ReverseinOrderPrintToFile() {
	if (root == NULL) return;// handle special case
	else
	{
		ofstream output;
		output.open("student-info.txt");
		ReverseinOrderPrint2ToFile(root, output);
		output << endl;
		output.close();
	}// do normal process

}


void BST::ReverseinOrderPrint2ToFile(BTNode *cur, ofstream &output) {
	if (cur == NULL) return;
	ReverseinOrderPrint2ToFile(cur->right, output);
	cur->item.print(output);
	ReverseinOrderPrint2ToFile(cur->left, output);
}





bool BST::CloneSubtree(BST t1, type item)
{
	if (t1.root == NULL)
	{
		return false;
	}
	

	BTNode *cur = t1.root;
	
	
	FindBTNClone(t1, cur, item);

	



	return true;
}



bool BST::FindBTNClone(BST &t1, BTNode *cur, type item)
{

	
	if (cur == NULL)
		return false;

	if (cur->item.id  == item.id)//Compare root of subtree you wanna find (item.id) with tree (t1)
	{
		
		
		
		
		
		insert(cur->item); //Insert into t2 once root is found

		/* USE NORMAL BINARY TREE TRAVERAL TO GET AND INSERT ALL NODES*/


		InsertSubNodes(t1, cur->left);
		InsertSubNodes(t1, cur->right);
		return true;




	}
	




	if (cur->item.id > item.id)
	{
		if (FindBTNClone(t1, cur->left, item) == false)
		{
			return false;
		}
	}
	else
	{
		if (FindBTNClone(t1, cur->right, item) == false)
		{
			return false;
		}
	}









	return true;


}


void BST::InsertSubNodes(BST &t1, BTNode *cur)
{


	if (cur == NULL )
	{

		return;

	}

	
	
	insert(cur->item);

	InsertSubNodes(t1, cur->left);
	

	InsertSubNodes(t1, cur->right);


	return;


}
















bool BST::printAncestor(type item)
{

	BTNode *cur = root;
	if (root == NULL)
		return false;

	int count = 0;

	if (empty())
	{
		return false;
	}
	

	if (root->item.id == item.id)
	{
		cout << "\nThere is no ancestor for this item.\n";
	}
	else
	{
		if (cur->item.id > item.id)
		{
			
			if (FindBTNode(cur->left, item, count) == false)
			{
				cout << "There are no ancestors. ";
				return false;
			}
			else{
				cout << cur->item.id << " ";
			}

		}
		else {
			
			if (FindBTNode(cur->right, item, count) == false)
			{
				cout << "There are no ancestors. ";
				return false;
			}
			else{
				cout << cur->item.id << " ";
			}
		}
	}











	return true;
}

bool BST::FindBTNode(BTNode *cur, type item, int &count)
{
	
	count++;
	
	if (cur == NULL)
	{	
		


		return false;
	}
	if (cur->item.id == item.id)
	{
		
		cout << "List of ancestors for " << item.id << ": ";
		
		return true;
	}


	

	if (cur->item.id > item.id)
	{
		
		if (FindBTNode(cur->left, item, count) == true)
		{
			cout << cur->item.id << " ";
		}
		else
		{
			return false;
		}
		return true;
	}
	else
	{
		
		if (FindBTNode(cur->right, item, count) == true)
		{
			cout << cur->item.id << " ";
		}
		else
		{
			return false;
		}
		return true;
	}
	

	return false;

}






bool BST::printSpiral()
{
	if (empty())
	{
		return false;
	}
	
	int h = Height(root);
	


	bool flag = false;
	for (int levelcounter = 0; levelcounter <= h; levelcounter++)
	{
		printSubLevels(root, levelcounter, flag);
		flag = !flag;
	}





	return true;
}


void BST::printSubLevels(BTNode *root, int level, int flag)
{
	
	
	 if (level > 0 && root != NULL)
	{
		if (flag == true)
		{
			
			printSubLevels(root->left, level - 1, flag);
			printSubLevels(root->right, level - 1, flag);
		}
		else
		{
			
			printSubLevels(root->right, level - 1, flag);
			printSubLevels(root->left, level - 1, flag);
		}
	}

	 if (root == NULL)
		 return;
	 if (level == 0)
		 root->item.print(cout);


}