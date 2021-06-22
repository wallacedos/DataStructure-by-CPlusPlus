#ifndef LINEARLIST_H
#define LINEARLIST_H

/********************************************************************************************************************************
�ļ����� linearList.h
���������� ���Ա������࣬�����࣬���ܺ�����Ϊ���麯����
�ο����ϣ�����.�����ݽṹ���㷨��Ӧ��C++���������ڶ��桷[M].��������е��ҵ�����磬2019.
���ڣ�2021/6/19
��Ȩ��2021-2025
���ߣ���Ӣΰ

��ʷ��1. 2021/6/19�½�linearListͷ�ļ���

********************************************************************************************************************************/

#include <iostream>

using namespace std;

namespace DSLib
{
	template<class T>
	class linearList
	{
	public:
		virtual ~linearList() {};        // ���������������������о��廯
		virtual bool empty() const = 0;  // ���麯���������Ա�Ϊ�գ�����true�����򷵻�false
		virtual int size() const = 0;    // ���麯�����������Ա�Ĵ�С�������Ա���Ԫ�صĸ���

		// ���麯�����������Ա�������ΪtheIndex����Ԫ��
		virtual T& get(int theIndex) const = 0;   
		// ���麯�����������Ա���Ԫ��theElement��һ�γ���ʱ�������������Ա���û�и�Ԫ�أ��򷵻�-1
		virtual int indexOf(const T& theElement) const = 0; 
		// ���麯����ɾ�����Ա�������ΪtheIndex��Ԫ�أ�ԭ���Ա�������ΪtheIndex���Ԫ����ǰ�ƶ�һ��λ��
		virtual void erase(int theIndex) = 0;
		// ���麯���������Ա�������ΪtheIndexλ�ô�����һ��Ԫ�أ�ԭ���Ա�������ΪtheIndex�����Ԫ������ƶ�һ��λ��
		virtual void insert(int theIndex, const T& theElement) = 0;
		// ���麯���������Ա�����������out
		virtual void output(ostream& out) const = 0;
	};
}
#endif


