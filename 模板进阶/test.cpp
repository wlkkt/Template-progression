//////////////////////////////////////////����������ģ�����
//#include <iostream>
//using namespace std;
//
//namespace bit
//{
//	template<class T, size_t N = 10>
//	class array
//	{
//	public:
//		T& operator[](size_t index)
//		{
//			return _array[index];
//		}
//
//		const T& operator[](size_t index)const
//		{
//			return _array[index];
//		}
//		
//		size_t size()const
//		{
//			return _size;
//		}
//
//		bool empty()const
//		{
//			return 0 == _size;
//		}
//	private:
//		T _array[N];
//		size_t _size;
//	};
//}
//
//int main()
//{
//	bit::array<int> a1;
//	bit::array<int, 10> a2;
//	bit::array<int, 100> a3;
//	return 0;
//}


/////////////////////////////////////std�е�array
//#include <iostream>
//#include <array>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	std::array<int, 10> a1;
//	int a2[10];
//
//	//Խ�������鲻����
//	a2[10];
//
//	//Խ��д����飬���޶�,�ܶ�λ�ò鲻������x86����������a2[15]������a[10] = 1����
//	a2[15] = 1;
//
//	//�����дԽ�綼�ܼ�����
//	a1[10];//����
//
//	return 0;
//}


///////////////////////////////////����ʵ����
//#include <iostream>
//#include <array>
//#include <vector>
//#include <assert.h>
//using namespace std;
//
//namespace bit
//{
//	template<class T, size_t N = 10>
//	class array
//	{
//	public:
//		T& operator[](size_t index)
//		{
//			assert(index < N);
//
//			size(1);//�﷨���󣬵��ǲ�����
//
//			return _array[index];
//		}
//
//		const T& operator[](size_t index)const
//		{
//			assert(index < N);
//			return _array[index];
//		}
//
//		size_t size()const
//		{
//			return _size;
//		}
//
//		bool empty()const
//		{
//			return 0 == _size;
//		}
//	private:
//		T _array[N];
//		size_t _size;
//	};
//}
//
//int main()
//{
//
//	bit::array<int> a1;
//	cout << a1.empty() << endl;
//	a1[1];
//	return 0;
//}


///////////////////////////////////�ػ�����
//#include <iostream>
//using namespace std;
//
//class Date
//{
//public:
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	bool operator<(const Date& d)const
//	{
//		return (_year < d._year) ||
//			(_year == d._year && _month < d._month) ||
//			(_year == d._year && _month == d._month && _day < d._day);
//	}
//
//	bool operator>(const Date& d)const
//	{
//		return (_year > d._year) ||
//			(_year == d._year && _month > d._month) ||
//			(_year == d._year && _month == d._month && _day > d._day);
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//ostream& operator<<(ostream& _cout, const Date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day;
//	return _cout;
//}
//
//
//// ����ģ�� -- ����ƥ��
//template<class T>
//bool Less(T left, T right)
//{
//    return left < right;
//}
//
//int main()
//{
//    cout << Less(1, 2) << endl; // ���ԱȽϣ������ȷ
//
//    Date d1(2022, 7, 7);
//    Date d2(2022, 7, 6);
//    cout << Less(d1, d2) << endl; // ���ԱȽϣ������ȷ�����������������<���أ�
//
//    Date* p1 = &d1;
//    Date* p2 = &d2;//����������������ָ����бȽϣ�
//    cout << Less(p1, p2) << endl; // ���ԱȽϣ��������
//
//    return 0;
//}


/////////////////////////////////////�ຯ��ģ��
#include <iostream>
using namespace std;


class Date
{
public:
	friend ostream& operator<<(ostream& _cout, const Date& d);

	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	bool operator<(const Date& d)const
	{
		return (_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day);
	}

	bool operator>(const Date& d)const
	{
		return (_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day);
	}
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}



//����ģ��
template<class T>
bool Less(T left, T right)
{
	cout << "bool Less(T left, T right)" << endl;

	return left < right;
}


////�ػ�(���Ǹ��ػ����ǻ����)
//template<>
//bool Less(Date* left, Date* right)
//{
//	cout << "bool Less(T* left, T* right)" << endl;
//	return *left < *right;
//}

template<class T>
bool Less(T* left, T* right)
{
	cout << "bool Less(T* left, T* right)" << endl;
	return *left < *right;
}



int main()
{
	cout << Less(1, 2) << endl; // ���ԱȽϣ������ȷ

	Date d1(2022, 7, 7);
	Date d2(2022, 7, 8);
	cout << Less(d1, d2) << endl; // ���ԱȽϣ������ȷ

	Date* p1 = new Date(2022, 7, 7);
	Date* p2 = new Date(2022, 7, 8);
	cout << Less(p1, p2) << endl; // ���ԱȽϣ��������

	int* p3 = new int(3);
	int* p4 = new int(4);
	cout << Less(p3, p4) << endl; //���ԱȽϣ��������

	return 0;
}

////////////////////////////////////////////////��ģ���ػ�
//#include <iostream>
//using namespace std;
//
//int main()
//[