#include"bst.h"
#include"tests.h"
#include<iostream>

using std::cout;
using std::endl;
using std::cin;

int main() {

	int testNum = 0;
	while (cout << endl << "Enter Test Number and check for the expected results.  A negative value will quit" << endl
		&& cin >> testNum
		&& cout << endl 
		&& testNum >= 0) {
		
		
		switch (testNum) {
		// Test cases (expected results in comments)
		case 0: {
			BinarySearchTree<int> bst;

			cout << bst.empty() << endl;	// 1
			cout << bst.height() << endl;	// 0
			cout << endl;
			break;
		}
		case 1: {
			BinarySearchTree<int> bst;

			// Insert node as root
			bst.insert(8);
			cout << bst.empty() << endl;	// 0
			cout << bst.height() << endl;	// 1
			cout << bst.min() << endl;		// 8
			cout << bst.max() << endl;		// 8
			cout << endl;
			break;
		}
		case 2: {
			BinarySearchTree<int> bst;

			bst.insert(8);

			// Test duplicate
			bst.insert(8);
			cout << bst.empty() << endl;	// 0
			cout << bst.height() << endl;	// 1
			cout << bst.min() << endl;		// 8
			cout << bst.max() << endl;		// 8
			cout << endl;
			break;
		}

		case 3: {
			BinarySearchTree<int> bst;
			bst.insert(8);
			cout << bst.empty() << endl;	// 0
			cout << bst.height() << endl;	// 1
			cout << bst.min() << endl;		// 8
			cout << bst.max() << endl;		// 8
			cout << endl;


			// Insert to left
			bst.insert(6);
			cout << bst.empty() << endl;	// 0
			cout << bst.height() << endl;	// 2
			cout << bst.min() << endl;		// 6
			cout << bst.max() << endl;		// 8
			cout << endl;

			break;
		}
		case 4: {
			BinarySearchTree<int> bst;
			bst.insert(8);
			cout << bst.empty() << endl;	// 0
			cout << bst.height() << endl;	// 1
			cout << bst.min() << endl;		// 8
			cout << bst.max() << endl;		// 8
			cout << endl;

			// Insert to left
			bst.insert(6);
			cout << bst.empty() << endl;	// 0
			cout << bst.height() << endl;	// 2
			cout << bst.min() << endl;		// 6
			cout << bst.max() << endl;		// 8
			cout << endl;

			// Insert to right
			bst.insert(13);
			cout << bst.empty() << endl;	// 0
			cout << bst.height() << endl;	// 2
			cout << bst.min() << endl;		// 6
			cout << bst.max() << endl;		// 13
			cout << endl;
			break;
		}

		case 5: {
			BinarySearchTree<int> bst;
			bst.insert(8);
			bst.insert(6);
			bst.insert(13);
			bst.insert(3);
			bst.insert(7);
			bst.insert(10);
			bst.insert(20);
			cout << bst.empty() << endl;	// 0
			cout << bst.height() << endl;	// 3
			cout << bst.min() << endl;		// 3
			cout << bst.max() << endl;		// 20
			break;
		}
		case 6: {
			BinarySearchTree<int> bst;
			bst.insert(8);
			bst.insert(6);
			bst.insert(13);
			bst.insert(3);
			bst.insert(7);
			bst.insert(10);
			bst.insert(20);
			bst.printInorder();				// 3 6 7 8 10 13 20
			break;
		}
		case 7: {
			BinarySearchTree<int> bst;
			bst.insert(8);
			bst.insert(6);
			bst.insert(13);
			bst.insert(3);
			bst.insert(7);
			bst.insert(10);
			bst.insert(20);
			bst.printPreorder();			// 8 6 3 7 13 10 20
			break;
		}
		case 8: {
			BinarySearchTree<int> bst;
			bst.insert(8);
			bst.insert(6);
			bst.insert(13);
			bst.insert(3);
			bst.insert(7);
			bst.insert(10);
			bst.insert(20);
			bst.printPostorder();			// 3 7 6 10 20 13 8
			break;
		}
		case 9: {
			BinarySearchTree<int> bst;
			bst.insert(8);
			bst.insert(6);
			bst.insert(13);
			bst.insert(3);
			bst.insert(7);
			bst.insert(10);
			bst.insert(20);
			cout << bst.find(6) << endl;		// 1
			cout << bst.find(999) << endl;	// 0
			break;
		}
		case 10: {
			BinarySearchTree<int> bst;
			bst.insert(8);
			bst.insert(6);
			bst.insert(13);
			bst.insert(3);
			bst.insert(7);
			bst.insert(10);
			bst.insert(20);
			bst.insert(22);

			cout << bst.empty() << endl;	// 0
			cout << bst.height() << endl;	// 4
			cout << bst.min() << endl;		// 3
			cout << bst.max() << endl;		// 22
			cout << endl;

			bst.printInorder();				// 3 6 7 8 10 13 20 22
			cout << endl;
			bst.printPreorder();			// 8 6 3 7 13 10 20 22
			cout << endl;

			//					//				22
			//					//			20
			//					//		13
			bst.printTree();	//			10
								//	8
								//			7	
								//		6
								//			3
			break;
		}
		case 11: {
			BinarySearchTree<int> bst;
			bst.insert(8);
			bst.insert(6);
			bst.insert(13);
			bst.insert(3);
			bst.insert(7);
			bst.insert(10);
			bst.insert(20);
			bst.insert(22);

			bst.remove(20); // This implementation uses the right sub tree
							// Your tree will appear slightly differently if you
							// use the left subtree.

			cout << bst.empty() << endl;	// 0
			cout << bst.height() << endl;	// 3
			cout << bst.min() << endl;		// 3
			cout << bst.max() << endl;		// 22
			cout << endl;


			bst.printInorder();				// 3 6 7 8 10 13 22
			cout << endl;
			bst.printPreorder();			// 8 6 3 7 13 10 22
			cout << endl;
			
			//					//			22
			//					//		13
			bst.printTree();	//			10
								//	8
								//			7	
								//		6
								//			3
			break;
		}
		case 12: {
			BinarySearchTree<int> bst;
			bst.insert(8);
			bst.insert(6);
			bst.insert(13);
			bst.insert(3);
			bst.insert(7);
			bst.insert(10);
			bst.insert(20);
			bst.insert(22);

			bst.remove(20); // This implementation uses the right sub tree
							// Your tree will appear slightly differently if you
							// use the left subtree.

			bst.remove(6);

			cout << bst.empty() << endl;	// 0
			cout << bst.height() << endl;	// 3
			cout << bst.min() << endl;		// 3
			cout << bst.max() << endl;		// 22
			cout << endl;

			bst.printInorder();				// 3 7 8 10 13 22
			cout << endl;
			bst.printPreorder();			// 8 7 3 13 10 22
			cout << endl;


			//					//				
			//					//			22
			//					//		13
			bst.printTree();	//			10
								//	8
								//		
								//		7
								//			3
			break;
		}
		default:
			// Runtime test of your BST implementation and several stl containers.  
			int test_size = 1000;
			test_insert(test_size); //Must have implemented bst::insert
			test_search(test_size); //Must have implemented bst::find
			test_delete(test_size); //Must have implemented bst::remove
			
			break;
		}

		
	}//while testNum
	return 0;
}
