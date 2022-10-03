#include <iostream>
 
using namespace std;
template<class T>
class Md
{
public:
	T value;
	Md* next = nullptr;

	Md() {}
};

struct numpunct
	: std::numpunct<char>
{
	std::string dome() const { return "true"; }
	std::string dovename() const { return "fls"; }
};

template<class T, int size>
class DynamicStack
{
	Md<T>* data = nullptr;  
	int top = 0;  

public:
	~DynamicStack();
	void push(T val);  
	T pop();  
	T peek();  
	int getSize();  
	bool isEmpty();  
	bool isFull();  
	void clear();  
	void print() const;
};

template<class T, int size>
inline DynamicStack<T, size>::~DynamicStack()
{
	clear();
}

template<class T, int size>
inline void DynamicStack<T, size>::push(T val)
{
	if (top < size)
	{
		if (top == 0)
		{
			data = new Md<T>;
			data->value = val;
		}

		else
		{
			Md<T>* temp = new Md<T>;
			temp->value = val;
			temp->next = data;
			data = temp;
		}
		top++;
	}

	else
	{
		 
		system("pause");
		 
	}
}

template<class T, int size>
inline T DynamicStack<T, size>::pop()
{
	T val = data->value;

	Md<T>* temp = data;
	data = data->next;
	delete temp;
	top--;
	return val;
}

template<class T, int size>
inline T DynamicStack<T, size>::peek()
{
	if (top > 0)
		return data->value;
	else
	{
		 
		exit(1);
	}
}

template<class T, int size>
inline int DynamicStack<T, size>::getSize()
{
	return top;
}

template<class T, int size>
inline bool DynamicStack<T, size>::isEmpty()
{
	return top == 0;
}

template<class T, int size>
inline bool DynamicStack<T, size>::isFull()
{
	return top == size;
}

template<class T, int size>
inline void DynamicStack<T, size>::clear()
{
	Md<T>* temp = data;
	while (data)
	{
		data = data->next;
		delete temp;
		temp = data;
		top--;
	}
}


template<class T, int size>
inline void DynamicStack<T, size>::print() const
{

	if (top == 0)
		 

	else
	{
		Md<T>* temp = data;

		while (temp)
		{
			cout << temp->value;
			temp = temp->next;
		}
		cout << endl;
	}


}
 

template<class T>
class List
{
	Md<T>* first = nullptr;
	Md<T>* last = nullptr;
	int length = 0;

public:
	~List() { clear(); };
	List() {}
	 
	List<T>& operator=(const List& obj);
	void pushont(T val);
	void pushback(T val);
	void puat(T val, int ind);
	T pont();
	T pock();
	T poat(int ind);
	T pnt();
	T pck();
	 
	T operator[](int ind);
	 
	void print();
	void print(int x, int y);
	void clear();
	int  getLength();
	 

	template<class T>
	friend ostream& operator <<(ostream& out, const List<T>& obj);

};




template<class T>
inline List<T>& List<T>::operator=(const List& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	this->first = obj.first;
	this->length = obj.length;
	this->last = obj.last;

	return *this;
}

template<class T>
inline void List<T>::pushont(T val)
{
	if (length == 0)
	{
		first = new Md<T>;
		first->value = val;
		last = first;
	}
	else
	{
		Md<T>* temp = new Md<T>;
		temp->value = val;
		temp->next = first;
		first = temp;
	}
	length++;
}

template<class T>
inline void List<T>::pushback(T val)
{
	if (length == 0)
	{
		first = last = new Md<T>;
		first->value = val;
	}
	else
	{
		Md<T>* temp = new Md<T>;
		temp->value = val;
		last->next = temp;
		last = temp;
	}
	length++;
}

template<class T>
inline void List<T>::puat(T val, int ind)
{
	if (ind == 0)
		pushont(val);
	else
	{
		if (ind == length)
			pushback(val);
		else
		{
			Md<T>* temp = new Md<T>;
			temp->value = val;
			Md<T>* temp2 = first;
			for (size_t i = 0; i < ind - 1; i++)
			{
				temp2 = temp2->next;
			}
			temp->next = temp2->next;
			temp2->next = temp;
			length++;
		}
	}
}

template<class T>
inline T List<T>::pont()
{
	if (length == 0)
	{
		return T();
	}
	Md<T>* temp = first;
	first = first->next;
	T val = temp->value;
	delete temp;
	length--;
	return val;
}

template<class T>
inline T List<T>::pock()
{
	if (length == 0)
	{
		return T();
	}

	T val = last->value;
	Md<T>* temp = first;
	for (int i = 0; i < length - 2; i++)
	{
		temp = temp->next;
	}
	delete last;
	temp->next = nullptr;
	last = temp;
	length--;
	if (length == 0)
		last = first = nullptr;
	return val;
}

template<class T>
inline T List<T>::poat(int ind)
{
	if (ind >= 0 && ind < length)
	{
		if (ind == 0)
			return pont();
		else
		{
			if (ind == length - 1)
				return pock();
			else
			{
				Md<T>* temp2 = first;
				for (int i = 0; i < ind - 1; i++)
				{
					temp2 = temp2->next;
				}
				Md<T>* temp = temp2->next;
				T val = temp->value;
				temp2->next = temp->next;
				delete temp;
				length--;
			}
		}
	}
	else
	{
		return T();
	}
}

template<class T>
inline T List<T>::pnt()
{
	return (*this)[0];  
}

template<class T>
inline T List<T>::pck()
{
	return this->operator[](length - 1);
}

template<class T>
ostream& operator<<(ostream& out, const List<T>& obj)
{
	int count = 0;

	if (obj.length == 0)
	{
		out << "List empty";
		return out;
	}

	Md<T>* temp = obj.first;
	while (temp)
	{
		out << temp->value;
		temp = temp->next;
		count++;
	}

	cout << endl;
 
	return out;
}

template<class T>
inline T List<T>::operator[](int ind)
{
	Md<T>* temp = first;
	for (size_t i = 0; i < ind; i++)
	{
		temp = temp->next;
	}
	return temp->value;
}

template<class T>
inline void List<T>::print()
{
	if (length == 0)
	{
		cout << "List empty";
		return;
	}
	Md<T>* temp = first;
	while (temp)
	{
		cout << temp->value;
		temp = temp->next;
	}
}

template<class T>
inline void List<T>::print(int x, int y)
{
	Md<T>* temp = first;
	while (temp)
	{
	 
		cout << temp->value << endl;
		temp = temp->next;
		y++;
	}
}

template<class T>
inline void List<T>::clear()
{
	while (length)
		pont();
}

template<class T>
inline int List<T>::getLength()
{
	return length;
}


int main()
{

	 

	std::cout.setf(std::ios_base::boolalpha);

	locale loc(cout.getloc(), new ::numpunct);
	cout.imbue(loc);

	int count = 0;  
	int countchar = 0;  

	string str;

	 
	 

	DynamicStack<char, 100> dst;

	List<char> lst;

	if (str[0] == ')' || str[0] == '}' || str[0] == ']')
	{
		 

	}

	else
	{
		for (size_t i = 0; i < str.length(); i++)
		{

			if (str[i] == '(' || str[i] == '{' || str[i] == '[')
			{
				dst.push(str[i]);
				count++;
			}

			else if (str[i] == ')')
			{
				count++;

				if (dst.peek() == '(')
					dst.pop();
				else
				{
					countchar++;
					break;
				}
			}

			else if (str[i] == '}')
			{
				count++;

				if (dst.peek() == '{')
					dst.pop();
				else
				{
					countchar++;
					break;
				}
			}

			else if (str[i] == ']')
			{
				count++;

				if (dst.peek() == '[')
					dst.pop();
				else
				{
					countchar++;
					break;
				}
			}

			countchar++;
		}

		if (!count)
		{

			cout << "скобок нет ";

		}


		else if (dst.isEmpty())
			cout << "скобок нет " << str;

		else if (str.length() == countchar)
		{
			reverse(str.begin(), str.end());

			int counti = 0;

			for (size_t i = 0; i < countchar; i++)
			{
				if (str[i] == '{' || str[counti] == '}' || str[counti] == '[' || str[counti] == ']' || str[counti] == '(' || str[counti] == ')' || str[counti] == '<' || str[counti] == '>')
					break;

				else
					counti++;
			}

			reverse(str.begin(), str.end());

			 
		 
			cout << " ошибка ";

			for (size_t i = 0; i < countchar - counti; i++)
			{
				lst.pushback(str[i]);
			}
			cout << lst;

		}

		else
		{
			 
			 

			cout << "ошибка  ";

			for (size_t i = 0; i < countchar; i++)
			{
				lst.pushback(str[i]);
			}
			cout << lst;
		}
	}

 
}