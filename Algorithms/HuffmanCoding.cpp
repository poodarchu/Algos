#include <iostream>

using namespace std;

void HuffmanCoding(int* pWeight, int N, vector<vector<char>>& codeDict) {
	if (N <= 0)
		return;
	int m = 2*N-1;
	HuffmanNode* pHuffmanTree = new HuffmanNode[m];
	int s1, s2;
	
	int i;
	// 建立叶子节点（初始化）
	for (int i = 0;i < N;i++) {
		pHuffmanTree[i].nWeight = pWeight[i];
	}
	// 每次选择权值最小的两个节点，建树。
	for(int i = N; i < m; i++) {
		SelectNode(pHuffmanTree, i, s1, s2);
		pHuffmanTree[s1].nParent = pHuffmanTree[s2].nParent = i;
		pHuffmanTree[i].nLeft = s1;
		pHuffmanTree[i].nRifht = s2;
		pHuffmanTree[i].nWeight = pHuffmanTree[s1].nWeight + pHuffmanTree[s2].nWeight;
	}
	
	// 根据建好的 Huffman 树从叶子到根计算每个节点的编码
	int node, nParent;
	for (int i = 0; i < N; i++) {
		vector<char>& cur = codeDict[i];
		node = i;
		nParent = pHuffmanTree[node].nParent;
		while (nParent != 0) {
			if (pHuffmanTree[nParent].nLeft == node)
				cur.push_back('0');
			else
				cur.push_back('1');
				
			node = nParent;
			nParent = pHuffmanTree[node].nParent;
		}
		reverse(cur.begin(), cur.end());
	}
}

void SelectNode(const HuffmanNode* pHuffmanTree, int n, int& s1, int& s2) {
	s1 = -1;
	s2 = -2;
	int nMin = -1;
	int nMin2 = -1;
	for (int i = 0; i < n; i++) {
		if ((pHuffmanTree[i].nParent == 0) && (pHuffmanTree[i].nWeight > 0)) {
			if((s1 < 0) || (nMin1 > pHuffmanTree[i].nWeight)) {
				s2 = s1;
				nMin2 = nMin1;
				s1 = i;
				nMin1 = pHuffmanTree[s1].nWeight;
			} else if ((s2 < 0) || (nMin2 > pHuffmanTree[i].nWeight)) {
				s2 = i;
				nMin2 = pHuffmanTree[s2].nWeight;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	
}