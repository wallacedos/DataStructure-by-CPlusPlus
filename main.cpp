/********************************************************************************************************************************
�ļ����� main.cpp
���������������������Բ�����ع��ܺ��������ݽṹ�ࡣ������Ϣ���ɹ�ע΢�Ź��ںŵ��������ģ�⣬���е�ר�����㷨�����ݽṹ��������
		  �����˹��ڱ�������ÿ���������ӵ���ϸ������
�ο����ϣ�����.�����ݽṹ���㷨��Ӧ��C++���������ڶ��桷[M].��������е��ҵ�����磬2019.
�汾��1.0
���ڣ�2021/5/1
��Ȩ��2021-2025
���ߣ���Ӣΰ

��ʷ��1. 2021/5/1�����ˡ��������ָ����ݹ麯�����Ĳ������ӣ�
	  2. 2021/5/9�����ˡ��������򷽷������µĲ������ӣ�
	  3. 2021/5/23�����ˡ���ʶ�����������µĲ������ӣ�
	  4. 2021/6/20�����ˡ����Ա�һ�����������������µĲ�������
	  5. 2021/7/17�����ˡ����Ա��������ḻ���ܡ����µĲ�������

********************************************************************************************************************************/

#include <iostream>          // C++��׼���������ͷ�ļ�

// #include "sdf.h"         // ����01��02��Ҫ���õ��Զ���ͷ�ļ�

//#include <vector>          // ����03��Ҫ���õ�ͷ�ļ�

#include "arrayListNoSTL.h"

using namespace std;
using namespace DSLib;   // �����Զ������뺯�����ڵ������ռ�

int main()
{
	// 01-0�� �������ָ�벿��, ����Ҫ���иò������ݣ��뽫������Ч�����ע�͵�
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


	//01-1�� �������ݹ麯�����֣�����Ҫ���иò������ݣ��뽫������Ч�����ע�͵�
	/*
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
	*/

	// 02�� �������򷽷��Ĳ��Գ�������Ҫ���иò������ݣ��뽫������Ч�����ע�͵�
	/*
	int num[5] = {1,2,0,2,3};
	int* a = new int[5];
	cout << "����������Ϊ��" << endl;
	for (int i = 0; i < 5; i++)
	{
		a[i] = num[i];
		cout << a[i] << " ";
	}
	cout << endl;

	int r[5] = { 0 };
	calcRank(a, 5, r);
	rearrange(a, 5, r);
	cout << "ԭ�����ŷ�������������" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	// ������a���¸�ֵ
	for (int i = 0; i < 5; i++)
	{
		a[i] = num[i];
	}
	bubbleSort(a, 5);
	cout << "ð�����򷽷�����������" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	// ������a���¸�ֵ
	for (int i = 0; i < 5; i++)
	{
		a[i] = num[i];
	}
	selectionSort(a, 5);
	cout << "ѡ�����򷽷�����������" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	// ������a���¸�ֵ
	for (int i = 0; i < 5; i++)
	{
		a[i] = num[i];
	}
	insertionSort(a, 5);
	cout << "�������򷽷�����������" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	delete[] a; a = NULL;
	*/

	// 03: ��ʶ������
	/*
	int x[3] = { 3,2,1};
	cout << "ʹ��ָ���������x��" << endl;
	for (int* y = x; y != x + 3; y++) // ��ָ��y��������x
	{
		cout <<*y<< " ";
	}
	cout << endl;

	vector<int> v1(x, x + 3);  // �ѵ�ַ����[x,x+3)�д洢�����ݿ�����v1
	vector<int>::iterator i;
	cout << "ʹ�õ������������һά����v1��Ԫ�أ�" << endl;
	for (i = v1.begin(); i != v1.end(); i++)
	{
		cout<< *i<< " ";
	}
	cout << endl;


	vector<int> v2(v1.begin() + 1, v1.end());  // �ѵ�ַ����[v1.begin()+1, v1.end())������v2
	cout << "ʹ�õ������������һά����v2��Ԫ�أ�" << endl;
	for (i = v2.begin(); i != v2.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;

	int m = 3;
	int n = 2;
	vector<vector<int>> v3(m, vector<int>(n, 0));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			v3[i][j] = (i+1) * (j+1);   // ��ֵ
		}
	}

	vector<vector<int>>::iterator rowIter;  // ��ά�������е�����
	vector<int>::iterator colIter;          // ÿһ�еĵ�����
	cout << "ʹ�õ�����������ʶ�ά����v3��Ԫ�أ�" << endl;
	for (rowIter=v3.begin();rowIter!=v3.end();rowIter++)
	{
		for (colIter = (*rowIter).begin(); colIter != (*rowIter).end(); colIter++)
		{
			cout << *colIter << " ";
		}
		cout << endl;
	}
	*/

	// 04 ���Ա�һ������������
    /*
	linearList<double>* x = new arrayListNoSTL<double>(20);
	arrayListNoSTL<int> y(2), z;

	// ������������
	cout << "Capacity of x, y and z = "
		<< ((arrayListNoSTL<double>*) x)->capacity() << ", "
		<< y.capacity() << ", "
		<< z.capacity() << endl;


	// �������Ա�ĳߴ�(���Ա���Ԫ�صĸ���������
	cout << "Initial size of x, y, and z = "
		<< x->size() << ", "
		<< y.size() << ", "
		<< z.size() << endl;

	// ����empty����
	if (x->empty()) cout << "x is empty" << endl;
	else cout << "x is not empty" << endl;
	if (y.empty()) cout << "y is empty" << endl;
	else cout << "y is not empty" << endl;

	// ���Բ��뺯��
	y.insert(0, 2);
	y.insert(1, 6);
	y.insert(0, 1);
	y.insert(2, 4);
	y.insert(3, 5);
	y.insert(2, 3);
	cout << "Inserted 6 integers, list y should be 1 2 3 4 5 6" << endl;
	cout << "Size of y = " << y.size() << endl;
	cout << "Capacity of y = " << y.capacity() << endl;
	if (y.empty()) cout << "y is empty" << endl;
	else cout << "y is not empty" << endl;
	y.output(cout);
	cout << endl << "Testing overloaded <<" << endl;
	cout << y << endl;

	// ����indexOf����
	int index = y.indexOf(4);
	if (index < 0) cout << "4 not found" << endl;
	else cout << "The index of 4 is " << index << endl;

	index = y.indexOf(7);
	if (index < 0) cout << "7 not found" << endl;
	else cout << "The index of 7 is " << index << endl;

	// ����get����
	cout << "Element with index 0 is " << y.get(0) << endl;
	cout << "Element with index 3 is " << y.get(3) << endl;

	// ����set����
	int num0 = y.get(0);
	int num3 = y.get(3);
	y.set(0, 15); y.set(3, 15);
	cout << "Element with index 0 is " << y.get(0) << endl;
	cout << "Element with index 3 is " << y.get(3) << endl;
	y.set(0, num0); y.set(3, num3); // �ָ�Ϊԭ�����Ա��Ԫ��

	// ����erase����
	y.erase(1);
	cout << "Element 1 erased" << endl;
	cout << "The list is " << y << endl;
	y.erase(2);
	cout << "Element 2 erased" << endl;
	cout << "The list is " << y << endl;

	cout << "Size of y = " << y.size() << endl;
	cout << "Capacity of y = " << y.capacity() << endl;
	if (y.empty()) cout << "y is empty" << endl;
	else cout << "y is not empty" << endl;

	try { y.insert(-3, 0); }
	catch (illegalIndex e)
	{
		cout << "Illegal index exception" << endl;
		cout << "Insert index must be between 0 and list size" << endl;
		e.outputMessage();
	}

	// ���Կ������캯��
	arrayListNoSTL<int> w(y);
	y.erase(0);
	y.erase(0);
	cout << "w should be old y, new y has first 2 elements removed" << endl;
	cout << "w is " << w << endl;
	cout << "y is " << y << endl;

	// �����������
	y.insert(0, 4);
	y.insert(0, 5);
	y.insert(0, 6);
	y.insert(0, 7);
	cout << "y is " << y << endl;
	*/


    // 05 ���Ա��������ḻ����
    arrayListNoSTL<int> y(10);   
	y.trimToSize();             // ����trimToSize���� ����ĳ��ȴ�ʱ����1
	cout << "y.capacity() = "<<y.capacity() << endl;
	cout << endl;

	// �����Ա��в���Ԫ��
	y.insert(0, 1);
	y.insert(1, 2);
	y.insert(2, 3);
	y.insert(3, 4);
	y.insert(4, 5);

	y.setSize(3);   // ����setSize��������ʱ���Ա�ĳ��Ȼ��Ϊ3

	for (int i = 0; i < y.size(); i++)
	{
		cout <<"y["<<i<<"] = "<< y[i] << endl;   // ֻ���1,2,3 
	}
	cout << endl;

	// ���Բ�����[]����
	int a = y[2]; cout << "a = " << a << endl; 
	y[2] = 10;
	cout << "y[2] = " << y[2] << endl;
	cout << endl;

	// ���Բ�����==��!=��<����
	arrayListNoSTL<int> w(y);
	cout << "w==y is "<<(w == y)<< endl;     // ��ʱ�����true
	w[1] = 10;
	cout << "w!=y is " << (w != y) << endl;  // ��ʱ�������true
	cout << "w<y is " << (w < y) << endl;    // ��ʱ�����false
	cout << endl;

	// ����push_back��pop_back����
	y.push_back(5);
	y.push_back(6);
	y.push_back(7);
	y.push_back(8);

	for (int i = 0; i < y.size(); i++)
	{
		cout << "y[" << i << "] = " << y[i] << endl; // �����1,2,10,5,6,7,8
	}

	y.pop_back();
	y.pop_back();

	for (int i = 0; i < y.size(); i++)
	{
		cout << "y[" << i << "] = " << y[i] << endl; // �����1,2,10,5,6
	}
	cout << endl;

	// ����swap����
	y.swap(w);
	for (int i = 0; i < w.size(); i++)
	{
		cout << "w[" << i << "] = " << w[i] << endl; // �����1,2,10,5,6
	}
	cout << endl;

	// ����reserve����
	y.reserve(100);
	cout << "y.capacity() = " << y.capacity() << endl;
	cout << endl;

	// ����setA����
	a = y.setA(2, 101);
	cout << "a = " << a << "  y[2] = " << y[2] << endl;
	cout << endl;

	// ����clear����
	y.clear();
	cout << "The size of the list is " << y.size() << endl;
	cout << endl;

	// ����removeRange����
	y.insert(0, 1);
	y.insert(1, 2);
	y.insert(2, 3);
	y.insert(3, 4);
	y.insert(4, 5);
	y.insert(5, 6);

	y.removeRange(2, 4);
	for (int i = 0; i < y.size(); i++)
	{
	    cout << "y[" << i << "] = " << y[i] << endl; // �����1,2,5,6
	}
	cout << endl;

	// ����lastIndexOf����
	int theIndex = y.lastIndexOf(5);
	cout << "theIndex = " << theIndex << endl;

	return 0;
}