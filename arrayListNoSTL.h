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
      2. 2021/7/17���ο����Ͽκ�ϰ���Ҫ�󣬷ḻ�����Ա�Ĺ��ܣ�������������һЩ���ܺ���

********************************************************************************************************************************/

#include<iostream>
#include<sstream>
#include<string>

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
}
#endif

