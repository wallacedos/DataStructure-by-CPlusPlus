/********************************************************************************************************************************
�ļ����� main.cpp
���������������������Բ�����ع��ܺ��������ݽṹ�ࡣ������Ϣ���ɹ�ע΢�Ź��ںŵ��������ģ�⣬���е�ר�����㷨�����ݽṹ��������
          �����˹��ڱ�������ÿ���������ӵ���ϸ������
�ο����ϣ�����.�����ݽṹ���㷨��Ӧ��C++���������ڶ��桷[M].��������е��ҵ�����磬2019.
�汾��1.0
���ڣ�2021/5/1
��Ȩ��2021-2025
���ߣ���Ӣΰ

��ʷ��1.2021/5/1�����ˡ��������ָ����ݹ麯�����Ĳ������ӡ�

********************************************************************************************************************************/

#include <iostream>

#include "sdf.h"

using namespace std;
using namespace DSLib;

int main()
{
	// �������ָ�벿��, ����Ҫ���иò������ݣ��뽫������Ч����ע�͵�
	/*
	char c = 'c';
	char* pc = &c;   // ��ָ��pcָ��char�ͱ���c���׵�ַ

	cout << "c = " << c << " *pc = " << *pc << " &c = " << (void*)&c << " pc = " << (void*)pc << endl;
	cout << "&c==pc " << ((void*)& c == (void*)pc) << endl;
	cout << "c = " << c << " *(&c) = " << *(&c) << " pc = " << (void*)pc << " *(&pc) = " << (void*)(*(&pc)) << endl;
	

	cout << "sizeof(char) = " << sizeof(char) <<" sizeof(c)="<<sizeof(c)<<endl;
	cout << "sizeof(char*) = " << sizeof(char*) << " sizeof(pc) = " << sizeof(pc) << endl;

	cout << endl;

	double d = 123.02;
	double* pd = NULL;  

	cout << "pd = " << pd << " &pd = " << &pd << endl;

	pd = &d; // ��ָ��ָ��double�ͱ������׵�ַ

	// ָ����ռ�ڴ���ֽ��������ڱ���ƽ̨�����ڱ���ƽ̨��һ�������ֳ��ȣ��������ֳ�32λ��ֻռ4�ֽ�
	cout << "sizeof(double*) = " << sizeof(double*) << " sizeof(pd) = " << sizeof(pd) << endl;  
	cout << "d = " << d << endl;

	// *���𵽽��������ã�����һ��Կ�ף��ܹ��õ�ָ��ָ��ı�����ָ�����pd�洢�ű���d�ĵ�ַ��*pd��õ�����d
	*pd = 5.0 ;   // �����в�ʹ�ñ���d�����ı�d��ֵ
	cout << "d = " << d << endl;
	cout << endl;

	int num[5] = { 1,2,3,4,5 };  // ���ס����洢��һ���ַ�������ڴ���
	int* pi = num;   // ������num���������׵�ַ����&(num[0])�ȼ�

	// ��֤����ĵ�ַ��������
	for (int i = 0; i < 5; i++)
	{
		cout <<"&num[i] = "<<&num[i] << endl;
	}

	// �����в�ʹ������num����ӡ������
	for (int i = 0; i < 5; i++)
	{
		cout << *(pi + i) << endl;  // piָ��������׵�ַ��(pi+i)ָ��pi+i*sizeof(int)���ĵ�ַ
	}
	*/

	// �������ݹ麯��
	char* s = new char[3];
	cout << "�ַ�����sΪ��";
	for (int i = 0; i < 3; i++)
	{
		s[i] = 'a' + i;   // �ַ�����s��Ϊ��'a','b','c'}
		cout << s[i];
	}
	cout << endl;
	cout << "����ַ������ȫ���У�" << endl;
	permutations(s, 0, 2);   // ����ַ�����s��ȫ����

	cout << "ʹ�õݹ����Ackermann������" << endl;
	int result = Ackermann(2, 2); cout << result << endl;

	cout << "ʹ�õݹ���������Ǹ����������Լ����" << endl;
	result = gcd(10, 15); cout << result << endl;

	cout << "ʹ�õݹ����Ԫ��x�Ƿ������ַ�����s��" << endl;
	cout << xBelongA(s, 'b', 3) << endl;

	cout << "����ַ�����s�������Ӽ���" << endl;
	int mark[3] = {0, 0, 0};
	print_subset(s, mark, 0, 3);
	delete[]s;  // ͨ���ؼ���new����Ŀռ䣬��ʹ��ʱһ��Ҫdelete

	cout << "���������λ�ñ仯����:" << endl;
	list<int> r; 
	list<int>::iterator i;
	calcGrayCode(r, 3);
	
	for (i=r.begin();i!=r.end();i++)
	{
		if (i == r.begin())
		{
			cout << *i;
		}
		else
		{
			cout << " " << *i;
		}
	}
	return 0;
}