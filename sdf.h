#ifndef SDF_H
#define SDF_H

/********************************************************************************************************************************
�ļ����� sdf.h
����������ѧϰ���İ�����.�����ݽṹ���㷨��Ӧ��C++���������ڶ��桷��������Ҫ���Զ��壨��������ĳ���ࣩ�����������κ���ϰ��𰸺�
          ������ش��롣�������ݣ��ɹ�ע΢�Ź��ںŵ��������ģ�⣬���е�ר�����㷨�����ݽṹ�������¸����˹��ڱ�������ÿ��������
		  �ӵ���ϸ������
�ο����ϣ�����.�����ݽṹ���㷨��Ӧ��C++���������ڶ��桷[M].��������е��ҵ�����磬2019.
���ڣ�2021/5/1
��Ȩ��2021-2025
���ߣ���Ӣΰ

��ʷ��1. 2021/5/1�����ˡ��������ָ����ݹ麯�������µĹ��ܺ�����
      2. 2021/5/9�����ˡ��������򷽷������µĹ��ܺ�����

********************************************************************************************************************************/

#include <iostream>
#include <iterator>
#include<list>

using namespace std;

namespace DSLib
{
	// 2021/5/1�ռ���Ĺ��ܺ���
	template <class T>
	void permutations(T list[], const int k, const int m);
	int Fibonacci(const int n);
	int NonRecursionFibonacci(const int n);
	int Ackermann(const int i, const int j);
	int gcd(const int x, const int y);
	template <class T>
	bool xBelongA(T* a, T x, const int n);
	template <class T>
	void print_subset(const T* a, int* mark, const int i, const int n);
	void calcGrayCode(list<int>& result, const int& n);

	// 2021/5/9����Ĺ��ܺ���
	template<class T> 
	void calcRank(const T a[], const int n, int r[]);
	template<class T>
	void rearrange(T a[], const int n, int r[]);
	template<class T> 
	void bubbleSort(T a[], const int n);
	template<class T> 
	void selectionSort(T a[], const int n);
	template<class T> 
	void insertionSort(T a[], const int n);
}

template <class T>
void DSLib::permutations(T list[], const int k, const int m)
{
	// ��һ�³���1-32�Ĵ��룬�İ�����.�����ݽṹ���㷨��Ӧ��C++���������ڶ��桷��28ҳ
	// ����list[0:m]����������
	if (k == m)
	{
		copy(list, list + m + 1, ostream_iterator<T>(cout, ""));
		cout << endl;
	}
	else
	{
		for (int i = k; i <= m; i++)
		{
			swap(list[k], list[i]);
			permutations(list, k + 1, m);
			swap(list[k], list[i]);
		}
	}
}

int DSLib::Fibonacci(const int n)
{
	// ��һ����ϰ��20�ģ�1�������룬���İ�����.�����ݽṹ���㷨��Ӧ��C++���������ڶ��桷��28ҳ
	if (n == 1 || n == 2)
		return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);

}

int DSLib::NonRecursionFibonacci(const int n)
{
	// ��һ����ϰ��20�ģ�3�������룬���İ�����.�����ݽṹ���㷨��Ӧ��C++���������ڶ��桷��28ҳ
	int a = 1;
	int b = 1;
	int c = 1;

	for (int i = 2; i < n; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}

	return c;
}

int DSLib::Ackermann(const int i, const int j)
{
	// ��һ����ϰ��22�������룬���İ�����.�����ݽṹ���㷨��Ӧ��C++���������ڶ��桷��29ҳ
	if (i == 1 && j >= 1)
	{
		return static_cast<int>(pow(2, j));
	}
	else if (i >= 2 && j == 1)
	{
		return Ackermann(i - 1, 2);
	}
	else
	{
		return Ackermann(i - 1, Ackermann(i, j - 1));
	}
}

int DSLib::gcd(const int x, const int y)
{
	// ��һ����ϰ��23�������룬���İ�����.�����ݽṹ���㷨��Ӧ��C++���������ڶ��桷��29ҳ
	if (y == 0)
	{
		return x;
	}
	else if (y > 0)
	{
		return gcd(y, x%y);
	}
	else
	{
		throw "y cannot be negative.";
	}
}

template <class T>
bool DSLib::xBelongA(T* a, T x, const int n)
{
	// ��һ����ϰ��24�������룬���İ�����.�����ݽṹ���㷨��Ӧ��C++���������ڶ��桷��29ҳ
	if (a[0]==x)
	{
		return true;
	}
	else if(n>1)
	{
		return xBelongA(a + 1, x, n - 1);
	}
	return false;
}

template <class T>
void DSLib::print_subset(const T* a, int* mark, const int i, const int n)
{
	// ��һ����ϰ��25�������룬���İ�����.�����ݽṹ���㷨��Ӧ��C++���������ڶ��桷��29ҳ
	if (i == n)
	{
		int num = 0;
		cout << "{";
		for (int k = 0; k < n; k++)
		{
			if (mark[k] == 1 && num==0)
			{
				cout << a[k];
				num = num + 1;
			}
			else if (mark[k] == 1 && num != 0)
			{
				cout << "," << a[k];
			}
		}
		cout << "}";
		cout << endl;
		return;
	}

	mark[i] = 0;
	print_subset(a, mark, i + 1, n);
	mark[i] = 1;
	print_subset(a, mark, i + 1, n);
}

void DSLib::calcGrayCode(list<int>& result, const int& n)
{
	// ��һ����ϰ��26�������룬���İ�����.�����ݽṹ���㷨��Ӧ��C++���������ڶ��桷��29ҳ
	if (n == 1)
	{
		result.push_back(1);
	}
	else if (n > 1)
	{
		calcGrayCode(result, n - 1);
		result.push_back(n);
		calcGrayCode(result, n - 1);
	}
}

template<class T>
void DSLib::calcRank(const T a[], const int n, int r[])
{
	// �ڶ���46ҳ
	// �õ�����a[0:n-1]��ÿ��Ԫ�ص����Σ�����������r��
	for (int i = 0; i < n; i++)
	{
		r[i] = 0;  // ��ʼ��
	}
	for (int i = 0; i <(n-1); i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i]>a[j])
			{
				r[i]++;
			}
			else
			{
				r[j]++;
			}
		}
	}
}

template<class T>
void DSLib::rearrange(T a[], const int n, int r[])
{
	// �ڶ���50ҳ
	// ��������a��������Ϣ����r,��������a��Ԫ��
	for (int i = 0; i < n; i++)
	{
		while (r[i] != i)  // ��ֹ�Խ���
		{
			int t = r[i];
			swap(a[i], a[t]);
			swap(r[i], r[t]);
		}
	}
}

template<class T>
void DSLib::bubbleSort(T a[], const int n)
{
	// �ڶ���52ҳ
	// ��ʱ��ֹ��ð������
	bool swapped = true;
	for (int i = n-1; i>0; i--)
	{
		swapped = false;
		for (int j = 0; j <i; j++)
		{
			if (a[j]>a[j+1])
			{
				swap(a[j], a[j+1]);
				swapped = true;  // ��������
			}
		}
	}

}

template<class T>
void DSLib::selectionSort(T a[], const int n)
{
	// �ڶ��µ�51ҳ
	// ��ʱ��ֹ��ѡ������
	int indexOfMax = 0;
	bool sorted = false;
	for (int size = n; size > 1 && !sorted; size--)
	{
		indexOfMax = 0;
		sorted = true;
		for (int i = 1; i < size; i++)
		{
			if (a[i]>=a[indexOfMax])
			{
				indexOfMax = i;
			}
			else
			{
				sorted = false; // ֻҪ��ִ��һ��˵�������������
			}
		}
		swap(a[indexOfMax], a[size - 1]);
	}
}

template<class T>
void DSLib::insertionSort(T a[], const int n)
{
	// �ڶ���53ҳ
	// ��������ĳ���
	int j = 0;
	T t = a[0];
	for (int i = 1; i < n; i++)
	{
		T t = a[i];
		for (j = i - 1; j >= 0 && a[j]>t; j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = t;
	}
}

#endif
