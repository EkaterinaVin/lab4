#include <iostream>
using namespace std;
template <class T>

class TQueue
{
protected:
	int size;
	int start;
	int end;
	int count;
	T* mas;

public:
	TQueue(int n = 0)
	{
		if (n <= 0)
			throw "wrong size";
		size = n;
		start = 0;
		end = -1;
		count = 0;
		mas = new T[size]();
	}
	TQueue(TQueue <T>& q)
	{
		size = q.size;
		start = q.start;
		end = q.end;
		count = q.count;
		mas = new T[size];
		for (int i = 0; i < size; i++) {
			mas[i] = q.mas[i];
		}
	}
	~TQueue()
	{
		delete[] mas;
	}

	void Push(T a) {
		if (this->IsFull()) 
			throw "queue is full";
		
		end = (end + 1) % size;
		mas[end] = a;
		count++;
		
	}

	T Pop() {
		if (this->IsEmpty())
			throw "queue is empty";
		
		T a = mas[start];
		start = (start + 1) % size;
		count--;
		return a;

	}

	bool IsFull()
	{
		if (count == size)
			return true;
		else
			return false;
	}
	bool IsEmpty()
	{
		if (count == 0)
			return true;
		else
			return false;
	}
	T getEnd()
	{
		return mas[end];
	}
	int getCount()
	{
		return count;
	}
	T getStart()
	{
		if (this->IsEmpty())
			throw "queue is empty";
		return mas[start];
	}
	int getSize()
	{
		return size;
	}


	friend ostream& operator << (ostream& ostr, const TQueue<T>& a) {
		for (int i = 0; i < a.count ; i++) {
			ostr << a.mas[(a.start+i)%a.size] << " ";
			
		}
		ostr << endl;
		return ostr;
	}
	friend istream& operator >> (istream& istr, TQueue<T>& a) {
		for (int i = 0; i < a.size; i++)
		{
			istr >> a.mas[i];
			a.count++;
		}
		a.end = a.size-1;
		return istr;
	}
};
