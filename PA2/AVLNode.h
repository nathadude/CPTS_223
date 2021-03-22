#pragma once
#include <ostream>
using namespace std;
//Dylan Meyer


template <class T>
class AVLNode
{

private:
	//what the node contains
	T data;

	//the "link" to the next node
	AVLNode* left = nullptr;
	AVLNode* right = nullptr;

	//height of node
	int height;

public:
	//.cpp functions

//Construction
	AVLNode(T newPayload, int newHeight) {
		setPayload(newPayload);
		setHeight(newHeight);
	}

	//Access
	T getPayload() const {
		return data;
	}

	AVLNode* newNode(int data)
	{
		AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
		node->data = data;
		node->left = nullptr;
		node->right = nullptr;

		return node;
	}


	AVLNode* getLeft() const {
		return left;
	}

	AVLNode* getRight() const {
		return right;
	}

	int getHeight() const {
		return height;
	}

	//Modify
	void setPayload(T newData) {
		data = newData;
	}

	void setLeft(AVLNode* newLeft) {
		left = newLeft;
	}

	void setRight(AVLNode* newRight) {
		right = newRight;
	}

	void setHeight(int newHeight) {
		height = newHeight;
	}


	//Overload
	friend ostream& operator <<(ostream& outStream, const AVLNode& node) {
		outStream << node.data;
		return(outStream);
	}

	//Destroy
	~AVLNode() {

	}


};


