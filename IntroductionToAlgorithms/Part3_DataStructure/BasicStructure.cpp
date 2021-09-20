#include"BasicStructure.h"
#include"files.h"

// ջ���ܵ�ʵ��
template<class T>
myStack<T>::myStack(int capacity) // ���캯��
{
	m_capacity = capacity;
	m_stack = new T[m_capacity + 1];
	m_top = m_stack;
}
template<class T>
myStack<T>::~myStack() // ��������
{
	if (m_stack != NULL)
	{
		delete[] m_stack;
		m_stack = NULL;
		m_top = NULL;
	}
}
template<class T>
bool myStack<T>::is_empty() // �ж��Ƿ�Ϊ��
{
	return (m_top == m_stack);
}
template<class T>
bool myStack<T>::is_full() // �ж��Ƿ�����
{
	return (m_top == m_stack + m_capacity);
}
template<class T>
void myStack<T>::push(T elem) // ѹ��
{
	*++m_top = elem;
}
template<class T>
T myStack<T>::pop() // ����
{
	T elem = *m_top--;
	return elem;
}

// ���й��ܵ�ʵ��
template<class T>
myQueue<T>::myQueue(int capacity) // ���캯��
{
	m_capacity = capacity;
	m_queue = new T[m_capacity + 1];
	m_out = m_queue;
	m_in = m_out;
}
template<class T>
myQueue<T>::~myQueue() // ��������
{
	if (m_queue != NULL)
	{
		delete[] m_queue;
		m_queue = NULL;
		m_out = NULL;
		m_in = NULL;
	}
}
template<class T>
bool myQueue<T>::is_empty() // �ж��Ƿ�Ϊ��
{
	return (m_out == m_in);
}
template<class T>
bool myQueue<T>::is_full() // �ж��Ƿ�����
{
	if (m_out == m_queue && m_in == m_queue + m_capacity)
	{
		return true;
	}
	return (m_out == m_in + 1);
}
template<class T>
void myQueue<T>::enqueue(T elem) // ���
{
	*m_in = elem;
	m_in = (m_in == m_queue + m_capacity) ? m_queue : m_in + 1;
}
template<class T>
T myQueue<T>::dequeue() // ����
{
	T elem = *m_out;
	m_out = (m_out == m_queue + m_capacity) ? m_queue : m_out + 1;
	return elem;
}
template<class T>
T myQueue<T>::m_head() // ���ʶ�ͷԪ��
{
	return *m_out;
}
template<class T>
T myQueue<T>::m_tail() // ���ʶ�βԪ��
{
	if (m_in == m_queue)
	{
		return *(m_queue + m_capacity);
	}
	return *(m_in - 1);
}

void basicStructure()
{
	int capacity = 10;

	// ջ����
	myStack<int> s(capacity);
	for (int i = 0; i < capacity; ++i)
	{
		s.push(i);
		cout << *(s.m_top) << endl;
	}
	cout << "-----------" << endl;
	for (int i = 0; i < capacity; ++i)
	{
		cout << s.pop() << endl;
	}
	cout << "-----------" << endl;

	// ���в���
	myQueue<int> q(capacity);
	for (int i = 0; i < capacity; ++i)
	{
		q.enqueue(i);
		cout << q.m_tail() << endl;
	}
	cout << "-----------" << endl;
	for (int i = 0; i < capacity / 2; ++i)
	{
		cout << q.dequeue() << endl;
	}
	cout << "-----------" << endl;
	for (int i = 0; i < capacity / 2; ++i)
	{
		q.enqueue(i);
		cout << q.m_tail() << endl;
	}

}