#ifndef ARRAYLISTNOSTL_H
#define ARRAYLISTNOSTL_H

/********************************************************************************************************************************
�ļ����� arrayListNoSTL.h
���������� �̳��������linearList����������ÿ������ʵ������
�ο����ϣ�����.�����ݽṹ���㷨��Ӧ��C++���������ڶ��桷[M].��������е��ҵ�����磬2019.
���ڣ�2021/6/19
��Ȩ��2021-2025
���ߣ���Ӣΰ

��ʷ��1. 2021/6/19�½�arrayListNoSTLͷ�ļ���

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

		element[--listSize].~T();  // ��������T������������
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
}
#endif

