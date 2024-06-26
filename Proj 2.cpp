//mobina yousefi
#include<iostream>
using namespace std;

bool isAlphaNum(char c) {
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '1' && c <= '9'))
		return true;

	return false;
}

template <typename T> class Stack {
	private:
		const static int defaultSize = 100;
		T *array;
		int top;
		int maxSize;
	public:
		Stack(int max = defaultSize) {
			array = new T[max];
			top = -1;
			maxSize = max;
		}

		bool isFull() {
			if (top == maxSize - 1) return true;
			return false;
		}

		bool isEmpty() {
			if (top == -1) return true;
			return false;
		}

		void Add(T x) {
			if (isFull())
				cout << "Stack is full" << endl;
			else
				array[++top] = x;
		}

		T Delete() {
			if (isEmpty()) {
				cout << "Stack is empty" << endl;
				return 0;
			} else
				return array[top--];
		}

		T first() {
			if (isEmpty()) {
				cout << "Stack is empty" << endl;
				return 0;
			} else
				return array[top];
		}
};


string postfixToInfix(string postfix) {
	int length = postfix.length();
	Stack<string> stack(length);

	for (int i = 0; i < length; i++) {
		if (isAlphaNum(postfix[i])) {
			stack.Add(string(1, postfix[i])); // tabdil char be string
		} else {
			string a = stack.Delete();
			string b = stack.Delete();
			stack.Add("(" + b + postfix[i] + a + ")");
		}
	}

	return stack.Delete();
}

string postfixToPrefix(string postfix) {
	int length = postfix.length();
	Stack<string> stack(length);

	for (int i = 0; i < length; i++) {
		if (isAlphaNum(postfix[i])) {
			stack.Add(string(1, postfix[i])); // tabdil char be string
		} else {
			string a = stack.Delete();
			string b = stack.Delete();
			stack.Add(postfix[i] + b + a);
		}
	}

	return stack.Delete();
}

string prefixToInfix(string prefix) {
	int length = prefix.length();
	Stack<string> stack(length);

	for (int i = length - 1; i >= 0; i--) {
		if (isAlphaNum(prefix[i])) {
			stack.Add(string(1, prefix[i]));
		} else {
			string a = stack.Delete();
			string b = stack.Delete();
			stack.Add("(" + a + prefix[i] + b + ")");
		}
	}

	return stack.Delete();
}

string prefixToPostfix(string prefix) {
	int length = prefix.length();
	Stack<string> stack(length);

	for (int i = length - 1; i >= 0; i--) {
		if (isAlphaNum(prefix[i])) {
			stack.Add(string(1, prefix[i]));
		} else {
			string a = stack.Delete();
			string b = stack.Delete();
			stack.Add(a + b + prefix[i]);
		}
	}

	return stack.Delete();
}



int main() {
	cout << "1. Infix\n2. Prefix\n3. Postfix\n> ";
	int number;
	cin>>number;
	string infix;
	string prefix;
	string postfix;

	switch(number) {
		case 1:
			cin>>infix;
			cout<<"postfix= ";//InToPos(infix);
			cout<<"prefix= ";//InToPre(infix);
			break;
		case 2:
			cin>>prefix;
			cout<<"postfix= " << prefixToPostfix(prefix) << endl;
			cout<<"infix= " << prefixToInfix(prefix) << endl;
			break;
		case 3:
			cin>>postfix;
			cout<<"prefix= " << postfixToPrefix(postfix) << endl;
			cout<<"infix= " << postfixToInfix(postfix) << endl;
			break;
		default:
			cout<<"not exist";
			break;
	}
	return 0;
}