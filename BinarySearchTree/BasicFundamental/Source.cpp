#include "BSTree.h"

int main()
{
	BSTree t1;
	int arr[] = { 7,10,14,20,36,47,55,63,72,86,92 };
	t1.createBalancedTree(arr, 0, 10);
	int val, choice, s, e;
	do {
		cout << "\nMENU\n";
		cout << "1.  Insert.\n";
		cout << "2.  Remove.\n";
		cout << "3.  InOrder\n";
		cout << "4.  Search.\n";
		cout << "5.  RecSearch.\n";
		cout << "6.  PreOrder.\n";
		cout << "7.  PostOrder.\n";
		cout << "8.  Count Nodes.\n";
		cout << "9.  Get Height.\n";
		cout << "10. Find Min.\n";
		cout << "11. Find Max.\n";
		cout << "12. Find Min Recursion.\n";
		cout << "13. Find Max Recursion.\n";
		cout << "14. Convert Into Double Tree.\n";
		cout << "15. Print All Paths.\n";
		cout << "16. Display In a Range.\n";
		cout << "17. Exit.\n";
		cout << "Enter your choice: ";
		cin >> choice;
		while (choice < 1 || choice > 17) {
			cout << "Invalid CHoice. Enter again: ";
			cin >> choice;
		}
		switch (choice) {
		case 1:
			cout << "Enter an element: ";
			cin >> val;
			if (t1.insert(val))
				cout << "Element INSERTED.\n";
			else
				cout << "Element NOT Inserted.\n";
			break;
		case 2:
			cout << "Enter an element: ";
			cin >> val;
			if (t1.remove(val))
				cout << "Element Removed.\n";
			else
				cout << "Element NOT Remvoed.\n";
			break;
		case 3:
			cout << "Elements of the Tree(InOrder): ";
			t1.inOrder();
			cout << endl;
			break;
		case 4:
			cout << "Enter an element: ";
			cin >> val;
			if (t1.search(val))
				cout << "Value Found.\n";
			else
				cout << "Value NOT Found.\n";
			break;
		case 5:
			cout << "Enter an element: ";
			cin >> val;
			if (t1.recSearch(val))
				cout << "Value Found.\n";
			else
				cout << "Value NOT Found.\n";
			break;
		case 6:
			cout << "Elements of the Tree(PreOrder): ";
			t1.preOrder();
			cout << endl;
			break;
		case 7:
			cout << "Elements of the Tree(PostOrder): ";
			t1.postOrder();
			cout << endl;
			break;
		case 8:
			cout << "Number of Nodes: " << t1.countNodes() << endl;
			break;
		case 9:
			cout << "Height of Tree: " << t1.getHeight() << endl;
			break;
		case 10:
			cout << "Minimum Element: " << t1.findMin() << endl;
			break;
		case 11:
			cout << "Maximum Element: " << t1.findMax() << endl;
			break;
		case 12:
			cout << "Minimum Element: " << t1.findMinRec() << endl;
			break;
		case 13:
			cout << "Maximum Element: " << t1.findMaxRec() << endl;
			break;
		case 14:
			t1.doubleTree();
			cout << "Double Tree Created.\n";
			break;
		case 15:
			cout << "All Possible Paths from Root to Leaves: ";
			t1.printAllPaths();
			cout << endl;
		case 16:
			cout << "Enter the range.";
			cout << endl << "Enter the starting value: ";
			cin >> s;
			cout << "Enter the ending value: ";
			cin >> e;
			t1.displayInRange(s, e);
			cout << endl;
		}
	} while (choice != 17);

	return 0;
}