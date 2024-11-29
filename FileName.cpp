#include <iostream>
#include <fstream>
#include <limits>
long long inf = 10e15;

class Node {
public:
	long long value;
	long long rightValue;
	long long leftValue;

	Node(long long val, long long rVal, long long lVal) {
		this->value = val;
		this->rightValue = rVal;
		this->leftValue = lVal;
	}
	Node(long long val) {
		this->value = val;
		this->rightValue = 0;
		this->leftValue = 0;
	}
	Node() {
		this->value = 0;
		this->rightValue = 0;
		this->leftValue = 0;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::ifstream fin("bst.in");
	std::ofstream fout("bst.out");

	long long n;
	//fin >> n;
	std::cin >> n;
	if (n == 0) {
		fout << "YES" << std::endl;
		return 0;
	}
	Node* nodes = new Node[n + 1];

	long long m;
	//fin >> m;
	std::cin >> m;

	nodes[1] = Node(m, -inf, inf);
	//nodes[1] = Node(m, std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max());
	bool isBST = true;


	for (int i = 2; i < n + 1; i++) {
		long long key, parentIndex;
		char direction;
		//fin >> key >> parentIndex >> direction;
		std::cin >> key >> parentIndex >> direction;

		long long leftVal = nodes[parentIndex].leftValue,
			rightVal = nodes[parentIndex].rightValue;
		if (direction == 'L') {
			rightVal = nodes[parentIndex].value;
			if (key >= leftVal && key < rightVal) {
				nodes[i] = Node(key, leftVal, rightVal);
			}
			else {
				isBST = false;
				break;
			}
		}
		else if (direction == 'R') {
			leftVal = nodes[parentIndex].value;
			if (key >= leftVal && key < rightVal) {
				nodes[i] = Node(key, leftVal, rightVal);
			}
			else {
				isBST = false;
				break;
			}
		}
	}

	if (isBST) {
		//fout << "YES" << std::endl;
		std::cout << "YES" << std::endl;
	}
	else {
		//fout << "NO" << std::endl;
		std::cout << "NO" << std::endl;
	}
	delete[] nodes;
	fin.close();
	fout.close();
	return 0;
}