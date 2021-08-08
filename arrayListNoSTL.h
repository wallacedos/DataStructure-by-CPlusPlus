#ifndef ARRAYLISTNOSTL_H
#define ARRAYLISTNOSTL_H

/********************************************************************************************************************************
�ļ����� arrayListNoSTL.h
���������� �̳��������linearList����������ÿ������ʵ������
�ο����ϣ�����.�����ݽṹ���㷨��Ӧ��C++���������ڶ��桷[M].��������е��ҵ�����磬2019.
���ڣ�2021/6/19
��Ȩ��2021-2025
���ߣ���Ӣΰ

��ʷ��1. 2021/6/19�½�arrayListNoSTLͷ�ļ����������������
      2. 2021/7/17���ο����Ͽκ�ϰ���Ҫ�󣬷ḻ�����Ա�Ĺ��ܣ�������������һЩ���ܺ�����
	  3. 2021/8/8��һ���طḻ�����Ա�Ĺ��ܣ�����������һЩ���ܺ�����

********************************************************************************************************************************/

#include<iostream>
#include<sstream>
#include<string>

#include "sdf.h"
#include "linearList.h"
#include "myExceptions.h"
#include "changeLength1D.h"

using namespace std;

namespace DSLib
{
	template<class T>
	class arrayListNoSTL : public linearList<T>
	{
	public:
		// ���캯�����������캯������������
		arrayListNoSTL(int initialCapacity = 10);
		arrayListNoSTL(const arrayListNoSTL<T>&);
		~arrayListNoSTL() { delete[] element; }

		// ������������Ĺ��ܺ���
		bool empty() const { return listSize == 0; }
		int size() const { return listSize; }
		T& get(int theIndex) const;
		int indexOf(const T& theElement) const;
		void erase(int theIndex);
		void insert(int theIndex, const T& theElement);
		void output(ostream& out) const;

		// ����ķ���
		int capacity() const { return arrayLength; }
		void set(int theIndex, const T& theElement);
		void trimToSize();                                     // ʹ����ĳ��ȵ���max{listSize,1}
		void setSize(int theSize);                             // ʹ���Ա�Ĵ�С����ָ���Ĵ�С
		T& operator [](int i) const;                           // ����[]������
		bool operator==(const arrayListNoSTL<T> &theList) const;  // ����==������
		bool operator!=(const arrayListNoSTL<T>& theList) const;  // ����!=������
		bool operator<(const arrayListNoSTL<T>& theList) const;   // ����<������
		void push_back(const T& theElement);                      // ��Ԫ�ز嵽���Ա���Ҷ�
		void pop_back();                                          // �����Ա��Ҷ˵�Ԫ��ɾ��
		void swap(arrayListNoSTL<T>& theList);                    // �����������Ա�
		void reserve(const int theCapacity);                      // �������������Ϊ��ǰ������theCapacity�Ľϴ���
		T setA(int theIndex, const T& theElement);                // ��������ΪtheIndex����Ԫ��ΪtheElement��������ԭ����Ԫ��
		void clear();                                             // ������Ա�
		void removeRange(int start, int end);                     // ɾ��������ΧΪ[start, end)��Ԫ��
		int lastIndexOf(const T& theElement) const;               // ����ָ��Ԫ��������ʱ������
		void reverse();                                           // ԭ�صߵ����Ա��Ԫ��
		void leftShift(int i);                                    // �����Ա��Ԫ�������ƶ�i��λ��
		void circularShift(int i);                                // �����Ա�ѭ���ƶ�i��λ��
		void half();                                              // ��һ��ɾ��һ��

		// arrayListNoSTL�ĵ�����
		class iterator;
		iterator begin() { return iterator(element); }
		iterator end() { return iterator(element + listSize); }

		// ����һ���µ����Ա���a�ĵ�0��Ԫ�ؿ�ʼ������ذ���a��b��Ԫ��
		void meld(const arrayListNoSTL<T>& a, const arrayListNoSTL<T>& b);   

		// a��b����arrayListNoSTL���������������ǵ�Ԫ�ش����ҷǵݼ��������ù鲢�����㷨����һ���µ�
		// ���Ա�ʹ�����a��b������Ԫ��
		void merge(const arrayListNoSTL<T>& a, const arrayListNoSTL<T>& b);

		// �����������Ա�a��b��a����*this������Ϊż����Ԫ�أ�b���������Ԫ��
		void split(arrayListNoSTL<T>& a, arrayListNoSTL<T>& b);


	protected:
		void checkIndex(int theIndex) const; // �������theIndex����Ч�ģ��׳�illegalIndex�쳣
		
		T* element;            // 1D����ָ��
		int arrayLength;       // 1D���������
		int listSize;          // ���Ա���Ԫ�صĸ���
	};

	template<class T>
	arrayListNoSTL<T>::arrayListNoSTL(int initialCapacity)
	{   // ���캯��
		if (initialCapacity < 1)
		{
			ostringstream s;
			s << "Initial capacity = " << initialCapacity << " Must be > 0";
			throw illegalParameterValue(s.str());
		}
		arrayLength = initialCapacity;
		element = new T[arrayLength];
		listSize = 0;
	}

	template<class T>
	arrayListNoSTL<T>::arrayListNoSTL(const arrayListNoSTL<T>& theList)
	{   // �������캯��
		arrayLength = theList.arrayLength;
		listSize = theList.listSize;
		element = new T[arrayLength];

		// �������Ա�Ԫ�ص���ǰ���Ա�
		for (int i = 0; i < listSize; i++)
			element[i] = theList.element[i];
	}

	template<class T>
	void arrayListNoSTL<T>::checkIndex(int theIndex) const
	{   // ��֤����theIndex�Ƿ���0��listSize - 1֮��.
		if (theIndex < 0 || theIndex >= listSize)
		{
			ostringstream s;
			s << "index = " << theIndex << " size = " << listSize;
			throw illegalIndex(s.str());
		}
	}

	template<class T>
	T& arrayListNoSTL<T>::get(int theIndex) const
	{   // �������Ա�������ΪtheIndex��Ԫ�أ��������Ƿ��������쳣
		checkIndex(theIndex);
		return element[theIndex];
	}

	template<class T>
	int arrayListNoSTL<T>::indexOf(const T& theElement) const
	{   // �������Ա���Ԫ��theElement��һ�γ���ʱ������
	    // �����Ա�������Ԫ��theElement
		for (int i = 0; i < listSize; i++)
			if (element[i] == theElement) return i;

		// û�г���Ԫ��theElementʱ������-1
		return -1;
	}

	template<class T>
	void arrayListNoSTL<T>::erase(int theIndex)
	{   // ɾ�����Ա�������ΪtheIndex����Ԫ�أ��������Ƿ��������쳣
		checkIndex(theIndex);

		// ����theIndex�Ϸ����ƶ�theIndex���Ԫ��
		for (int i = theIndex + 1; i < listSize; i++)
			element[i - 1] = element[i];

		element[--listSize].~T();  // ��������T����������
	}

	template<class T>
	void arrayListNoSTL<T>::insert(int theIndex, const T& theElement)
	{   // ������ΪtheIndex������Ԫ��theElement
		if (theIndex < 0 || theIndex > listSize)
		{   // ��Ч������theIndex
			ostringstream s;
			s << "index = " << theIndex << " size = " << listSize;
			throw illegalIndex(s.str());
		}

		// ��Ч��������ȷ�����Ա�Ŀռ��Ƿ���
		if (listSize == arrayLength)
		{   // ���Ա�Ŀռ䲻�������ԭ���Ա�Ŀռ�����չ
			changeLength1D(element, arrayLength, 2 * arrayLength);
			arrayLength *= 2;
		}

		// ����theIndex��֮���Ԫ������һ��λ��
		for (int i = listSize - 1; i >= theIndex; i--)
			element[i + 1] = element[i];

		element[theIndex] = theElement;

		listSize++;
	}

	template<class T>
	void arrayListNoSTL<T>::output(ostream& out) const
	{   //�����Ա��е�Ԫ�ز��뵽�����out��
		for (int i = 0; i < listSize; i++)
			out << element[i] << "  ";
	}

	// ���ز�����<<
	template <class T>
	ostream& operator<<(ostream& out, const arrayListNoSTL<T>& x)
	{
		x.output(out); return out;
	}

	// ��Ԫ��theElement�滻����ΪtheIndex��Ԫ�أ��������Ƿ��������쳣
	template <class T>
	void arrayListNoSTL<T>::set(int theIndex, const T& theElement)
	{
		checkIndex(theIndex);
		element[theIndex] = theElement;
	}

	template<class T>
	void arrayListNoSTL<T>::trimToSize()
	{
		// ʹ����ĳ��ȵ���max{listSize,1}
		if (arrayLength == listSize)   // ������ĳ���arrayLength�����Ա�ĳ�����ȣ�ֱ�ӷ���
		{
			return;
		}

		if (listSize == 0)          // �����Ա�ĳ���Ϊ0����Ҫ������ĳ��ȵ���Ϊ1
		{
			delete [] element; // �ͷ�ԭ����ռ�
			element = new T[1];
			arrayLength = 1;
			return;
		}

		// ���������arrayLength����listSizeʱ����Ҫ�ı�����ĳ���
		changeLength1D(element, listSize, listSize);
		arrayLength = listSize;
	}

	template<class T>
	void arrayListNoSTL<T>::setSize(int theSize)
	{
		if (theSize < 0 || theSize>this->capacity())  // ������С��0�����ߴ�������ĳ��ȣ���Ҫ���쳣
		{
			// ��Ч�Ĳ���theSize
			ostringstream s;
			s << "parameter theSize = " << theSize<< "is illegal. It must be in the range of 0 to "<<this->capacity()<<".";
			throw illegalParameterValue(s.str());
		}

		if (listSize <= theSize)  
		{
			return;
		}
		else
		{
			for (int i = theSize; i < listSize; i++)
			{
				element[i].~T();   // ��������T�������������ͷŶ�������Ա�Ԫ��
			}
			listSize = theSize;
		}
	}

	// ���ز�����[]
	template <class T>
	T& arrayListNoSTL<T>::operator [](int i) const
	{
		checkIndex(i);
		return element[i];
	}

	template <class T>
	bool arrayListNoSTL<T>::operator== (const arrayListNoSTL<T>& theList) const
	{
		bool ret = false;
		if (this->listSize != theList.size())   // ���������Ա�ĳ��Ȳ���ȣ�ֱ�ӷ���false
		{
			return ret;
		}

		ret = true;
		for (int i = 0; i < this->listSize; i++)
		{
			if (this->element[i] != theList[i])
			{
				ret = false;
				return ret;
			}
		}

		return ret;
	}

	template<class T> 
	bool arrayListNoSTL<T>::operator!= (const arrayListNoSTL<T>& theList) const
	{
		return !(*this == theList);
	}

	template<class T>
	bool arrayListNoSTL<T>::operator< (const arrayListNoSTL<T>& theList) const
	{
		bool ret = false;
		if (this->listSize != theList.size())   // ���������Ա�ĳ��Ȳ���ȣ�ֱ�ӷ���false
		{
			return ret;
		}

		ret = true;
		for (int i = 0; i < this->listSize; i++)
		{
			if (this->element[i]>=theList[i])
			{
				ret = false;
				return ret;
			}
		}

		return ret;
	}

	template<class T> 
	void arrayListNoSTL<T>::push_back(const T& theElement)
	{
		// ȷ�����Ա�Ŀռ��Ƿ���
		if (listSize == arrayLength)
		{   // ���Ա�Ŀռ䲻�������ԭ���Ա�Ŀռ�����չ
			changeLength1D(element, arrayLength, 2 * arrayLength);
			arrayLength *= 2;
		}
		
		this->element[listSize] = theElement;
		listSize++;
	}

	template<class T>
	void arrayListNoSTL<T>::pop_back()
	{
		if (this->listSize == 0)
		{
			// ���Ա��Ѿ�����
			ostringstream s;
			s << "the list is empty()";
			throw exceptionInfo(s.str());
		}

		listSize--;
		this->element[listSize].~T();   // ��������T����������
	}

	template<class T>
	void arrayListNoSTL<T>::swap(arrayListNoSTL<T>& theList)
	{
		int temp = 0;
		temp = arrayLength;
		arrayLength = theList.arrayLength;
		theList.arrayLength = temp;
		
		temp = listSize;
		listSize = theList.listSize;
		theList.listSize = temp;

		T* p = element;
		element = theList.element;
		theList.element = p;

		p = NULL;
	}

	template<class T> 
	void arrayListNoSTL<T>::reserve(const int theCapacity)
	{
		if (this->arrayLength>= theCapacity)
		{
			return;
		}

		changeLength1D(element, listSize, theCapacity);
		arrayLength = theCapacity;
	}

	template<class T>
	T arrayListNoSTL<T>::setA(int theIndex, const T& theElement)
	{
		checkIndex(theIndex);
		T ret = element[theIndex];
		element[theIndex] = theElement;
		return ret;
	}

	template<class T>
	void arrayListNoSTL<T>::clear()
	{
		delete [] element;  // �ͷ�ԭ����ռ�
		T* temp = new T[arrayLength];
		element = temp;
		listSize = 0;
	}

	template<class T>
	void arrayListNoSTL<T>::removeRange(int start, int end)
	{
		if (start < 0 || end > listSize)
			throw illegalIndex();

		if (start >= end) // ֱ�ӷ���
			return;

		// �ƶ�end֮���Ԫ��
		copy(element + end, element + listSize, element + start);

		// �ͷ�֮���Ԫ��
		int newSize = listSize - end + start;
		for (int i = newSize; i < listSize; i++)
			element[i].~T();

		listSize = newSize;
	}

	template<class T>
	int arrayListNoSTL<T>::lastIndexOf(const T& theElement) const
	{
		int theIndex = -1;
		for (int i = listSize - 1; i >= 0; i--)
		{
			if (element[i] == theElement)
			{
				theIndex = i;
				return theIndex;
			}
		}
		return theIndex;
	}

	template<class T>
	void arrayListNoSTL<T>::reverse()
	{
		for (int i = 0; i < (listSize / 2); i++)
		{
			swapElement(element + i, element + listSize - i - 1);
		}
	}

	template<class T>
	void arrayListNoSTL<T>::leftShift(int i)
	{
		if (i <0 || i>listSize)
		{
			// ��Ч�Ĳ���i
			ostringstream s;
			s << "parameter i = " <<i<< "is illegal. It must be in the range of 0 to " << listSize<< ".";
			throw illegalParameterValue(s.str());
		}

		int newSize = 0;
		if (i<= listSize)
		{
			newSize = listSize - i;
			copy(element + i, element + listSize, element);
		}

		// ʣ��Ԫ��������
		for (int i = newSize; i < listSize; i++)
			element[i].~T();

		listSize = newSize;
	}

	template<class T>
	void arrayListNoSTL<T>::circularShift(int i)
	{
		if (i<0 || i>listSize)
		{
			// ��Ч�Ĳ���i
			ostringstream s;
			s << "parameter i = " << i << "is illegal. It must be in the range of 0 to " << listSize << ".";
			throw illegalParameterValue(s.str());
		}

		T* s = new T[i];    // ������������s
		for (int k = 0; k < i; k++)
		{
			s[k] = element[k];
		}

		for (int k = 0; k < (listSize - i); k++)
		{
			element[k] = element[k + i];
		}

		for (int k = (listSize - i); k < listSize; k++)
		{
			element[k] = s[k - listSize + i];
		}
		delete[]s;
		s = NULL;
	}

	template<class T>
	void arrayListNoSTL<T>::half()
	{
		int newListSize = (listSize + 1) / 2;
		for (int i = 0; i < newListSize; i++)
		{
			element[i] = element[2 * i];
		}

		for (int i = newListSize; i < listSize; i++)
		{
			element[i].~T();
		}
		
		listSize = newListSize;
	}

	// ���Ա�ĵ�����
	template<class T>
	class arrayListNoSTL<T>::iterator
	{
	public:
		typedef bidirectional_iterator_tag iterator_category;
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;

		// ���캯��
		iterator(T* thePosition = 0) { position = thePosition; }

		// �����ò�����
		T& operator*() const { return *position; }
		T* operator->() const { return &*position; }

		// ����
		iterator& operator++()   // ǰ������
		{
			++position; return *this;
		}
		iterator operator++(int) // ��������
		{
			iterator old = *this;
			++position;
			return old;
		}

		// �Լ�
		iterator& operator--()   // ǰ���Լ�
		{
			--position; return *this;
		}
		iterator operator--(int) // �����Լ�
		{
			iterator old = *this;
			--position;
			return old;
		}

		// !=��==�������Ķ��庯��
		bool operator!=(const iterator right) const
		{
			return position != right.position;
		}
		bool operator==(const iterator right) const
		{
			return position == right.position;
		}
	protected:
		T* position;
	};  

	template<class T>
	void arrayListNoSTL<T>::meld(const arrayListNoSTL<T>& a, const arrayListNoSTL<T>& b)
	{
		delete[]element;
		int aListSize = a.listSize;
		int bListSize = b.listSize;

		int newListSize = aListSize + bListSize;

		// ȷ�����Ա�Ŀռ��Ƿ���
		if (newListSize> arrayLength)
		{
			arrayLength = newListSize;
		}

		listSize = newListSize;
		element = new T[arrayLength];

		if (aListSize == bListSize)
		{
			for (int i = 0; i < aListSize; i++)
			{
				element[2*i] = a.element[i];
				element[2 * i + 1] = b.element[i];
			}
		}
		else if (aListSize > bListSize)
		{
			for (int i = 0; i < bListSize; i++)
			{
				element[2 * i] = a.element[i];
				element[2 * i + 1] = b.element[i];
			}
			copy(a.element+bListSize, a.element+aListSize, element+(2 * bListSize));
		}
		else if (aListSize < bListSize)
		{
			for (int i = 0; i < aListSize; i++)
			{
				element[2 * i] = a.element[i];
				element[2 * i + 1] = b.element[i];
			}
			copy(b.element + aListSize, b.element + bListSize, element + (2 * aListSize));
		}
		else
		{
			// ����δ������쳣
			ostringstream s;
			s <<"the program has triggered an undefined exception...";
			throw undefinedException(s.str());
		}
	}

	template<class T>
	void arrayListNoSTL<T>::merge(const arrayListNoSTL<T>& a, const arrayListNoSTL<T>& b)
	{
	    int ca = 0;                       // ���Ա�a���α�
		int cb = 0;                       // ���Ա�b���α�
		int ct = 0;                       // ��ǰ���Ա���α�
		
	    // �ͷŵ�ǰ���Ա���Ϊ��ǰ���Ա����������ڴ�ռ�
		delete[] element;
		arrayLength = a.listSize + b.listSize;
		element = new T[arrayLength];

		// ��a��b���鲢
		while ((ca < a.listSize) && (cb < b.listSize))
			if (a.element[ca] <= b.element[cb])
				element[ct++] = a.element[ca++];
			else
				element[ct++] = b.element[cb++];

		// ����ʣ��Ԫ��
		copy(a.element + ca, a.element + a.listSize, element + ct);
		ct += a.listSize - ca;
		copy(b.element + cb, b.element + b.listSize, element + ct);
		ct += b.listSize - cb;

		listSize = ct;
	}

	template<class T>
	void arrayListNoSTL<T>::split(arrayListNoSTL<T>& a, arrayListNoSTL<T>& b)
	{
		int aListSize = (listSize + 1) / 2;
		int bListSize = listSize - aListSize;
		delete[]a.element;
		delete[]b.element;

		int aArrayLength = aListSize > a.arrayLength ? aListSize : a.arrayLength;
		int bArrayLength = bListSize > b.arrayLength ? bListSize : b.arrayLength;

		a.element = new T[aArrayLength];
		b.element = new T[bArrayLength];
		a.arrayLength = aArrayLength;
		b.arrayLength = bArrayLength;
		a.listSize = aListSize;
		b.listSize = bListSize;

		for (int i = 0; i < aListSize; i++)
		{
			a.element[i] = element[2 * i];
		}

		for (int i = 0; i < bListSize; i++)
		{
			b.element[i] = element[2 * i + 1];
		}
	}
}
#endif

