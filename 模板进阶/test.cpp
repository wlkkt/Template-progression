//////////////////////////////////////////非类类类型模板参数
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


/////////////////////////////////////std中的array
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
//	//越界读，检查不出来
//	a2[10];
//
//	//越界写，抽查，局限多,很多位置查不出来（x86环境下运行a2[15]不报错，a[10] = 1报错）
//	a2[15] = 1;
//
//	//任意读写越界都能检查出来
//	a1[10];//报错
//
//	return 0;
//}


///////////////////////////////////按需实例化
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
//			size(1);//语法错误，但是不报错
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


///////////////////////////////////特化概念
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
//// 函数模板 -- 参数匹配
//template<class T>
//bool Less(T left, T right)
//{
//    return left < right;
//}
//
//int main()
//{
//    cout << Less(1, 2) << endl; // 可以比较，结果正确
//
//    Date d1(2022, 7, 7);
//    Date d2(2022, 7, 6);
//    cout << Less(d1, d2) << endl; // 可以比较，结果正确（会调用日期类对象的<重载）
//
//    Date* p1 = &d1;
//    Date* p2 = &d2;//（传入日期类对象的指针进行比较）
//    cout << Less(p1, p2) << endl; // 可以比较，结果错误
//
//    return 0;
//}


/////////////////////////////////////类函数模板
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



//函数模板
template<class T>
bool Less(T left, T right)
{
	cout << "bool Less(T left, T right)" << endl;

	return left < right;
}


////特化(但是该特化还是会出错)
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
	cout << Less(1, 2) << endl; // 可以比较，结果正确

	Date d1(2022, 7, 7);
	Date d2(2022, 7, 8);
	cout << Less(d1, d2) << endl; // 可以比较，结果正确

	Date* p1 = new Date(2022, 7, 7);
	Date* p2 = new Date(2022, 7, 8);
	cout << Less(p1, p2) << endl; // 可以比较，结果错误

	int* p3 = new int(3);
	int* p4 = new int(4);
	cout << Less(p3, p4) << endl; //可以比较，结果错误

	return 0;
}

////////////////////////////////////////////////类模板特化
//#include <iostream>
//using namespace std;
//
//int main()
//[