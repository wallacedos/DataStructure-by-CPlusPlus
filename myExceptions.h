// exception classes for various error types

#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H

/********************************************************************************************************************************
�ļ����� myExceptions.h
�����������Զ����쳣�࣬����Ҫ��ʱ�����쳣��
�ο����ϣ�����.�����ݽṹ���㷨��Ӧ��C++���������ڶ��桷[M].��������е��ҵ�����磬2019.
���ڣ�2021/6/19
��Ȩ��2021-2025
���ߣ���Ӣΰ

��ʷ��1. 2021/6/19�½�myExceptionsͷ�ļ���

********************************************************************************************************************************/
#include <string>
#include <iostream>

using namespace std;

namespace DSLib
{
	// �Ƿ������쳣��
	class illegalParameterValue
	{
	public:
		illegalParameterValue(string theMessage = "Illegal parameter value")
		{
			message = theMessage;
		}
		void outputMessage() { cout << message << endl; }
	private:
		string message;
	};

	// �������ݷǷ�
	class illegalInputData
	{
	public:
		illegalInputData(string theMessage = "Illegal data input")
		{
			message = theMessage;
		}
		void outputMessage() { cout << message << endl; }
	private:
		string message;
	};

	// ����ֵ�Ƿ�
	class illegalIndex
	{
	public:
		illegalIndex(string theMessage = "Illegal index")
		{
			message = theMessage;
		}
		void outputMessage() { cout << message << endl; }
	private:
		string message;
	};

	// ��������ֵ�Ƿ�
	class matrixIndexOutOfBounds
	{
	public:
		matrixIndexOutOfBounds
		(string theMessage = "Matrix index out of bounds")
		{
			message = theMessage;
		}
		void outputMessage() { cout << message << endl; }
	private:
		string message;
	};

	// ����ߴ粻ƥ��
	class matrixSizeMismatch
	{
	public:
		matrixSizeMismatch(string theMessage =
			"The size of the two matrics doesn't match")
		{
			message = theMessage;
		}
		void outputMessage() { cout << message << endl; }
	private:
		string message;
	};

	// ջ���쳣
	class stackEmpty
	{
	public:
		stackEmpty(string theMessage =
			"Invalid operation on empty stack")
		{
			message = theMessage;
		}
		void outputMessage() { cout << message << endl; }
	private:
		string message;
	};

	// ����Ϊ��ʱ���쳣
	class queueEmpty
	{
	public:
		queueEmpty(string theMessage =
			"Invalid operation on empty queue")
		{
			message = theMessage;
		}
		void outputMessage() { cout << message << endl; }
	private:
		string message;
	};

	// ��ϣ������ʱ���쳣
	class hashTableFull
	{
	public:
		hashTableFull(string theMessage =
			"The hash table is full")
		{
			message = theMessage;
		}
		void outputMessage() { cout << message << endl; }
	private:
		string message;
	};

	// ͼ�еı�Ȩ��ֵδ����
	class undefinedEdgeWeight
	{
	public:
		undefinedEdgeWeight(string theMessage =
			"No edge weights defined")
		{
			message = theMessage;
		}
		void outputMessage() { cout << message << endl; }
	private:
		string message;
	};

	// ����δ����
	class undefinedMethod
	{
	public:
		undefinedMethod(string theMessage =
			"This method is undefined")
		{
			message = theMessage;
		}
		void outputMessage() { cout << message << endl; }
	private:
		string message;
	};
}
#endif

