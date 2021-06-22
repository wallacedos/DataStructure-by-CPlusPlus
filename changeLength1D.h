// change the length of an array

#ifndef CHANGELENGTH1D_H
#define CHANGELENGTH1D_H

/********************************************************************************************************************************
�ļ����� changeLength1D.h
���������������Ա�洢�ռ䲻��ʱ����չ���Ա���ڴ棬����չ��̬����ĳ��ȡ�
�ο����ϣ�����.�����ݽṹ���㷨��Ӧ��C++���������ڶ��桷[M].��������е��ҵ�����磬2019.
���ڣ�2021/6/19
��Ȩ��2021-2025
���ߣ���Ӣΰ

��ʷ��1. 2021/6/19�½�changeLength1Dͷ�ļ���

********************************************************************************************************************************/
#include "myExceptions.h"

using namespace std;

namespace DSLib
{
	int min(int a, int b)
	{
		return a < b ? a : b;
	}

	template<class T>
	void changeLength1D(T*& a, int oldLength, int newLength)
	{
		if (newLength < 0)
			throw illegalParameterValue("new length must be >= 0");

		T* temp = new T[newLength];              // ������
		int number = min(oldLength, newLength);  // ��Ҫ���Ƶ�Ԫ�ظ���
		copy(a, a + number, temp);
		delete[] a;                              // �ͷ��ڴ�
		a = temp;
	}
}
#endif
