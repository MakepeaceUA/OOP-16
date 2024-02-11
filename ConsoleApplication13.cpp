#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point() 
	{
		x = 0;
		y = 0;
	}
	Point(int val1, int val2) 
	{
		x = val1;
		y = val2;
	}
	int getX() const { return x; }
	int getY() const { return y; }
};

template <typename T>
class DynArray
{
	T* arr;
	int size;
public:
	DynArray(int sizeP) : arr{ new T[sizeP] {} }, size{ sizeP }
	{
		cout << "DynArr constructed for " << size << " elements, for " << this << '\n';
	}
	DynArray() : DynArray(5) {}
	DynArray(const DynArray& object) : arr{ new T[object.size] }, size{ object.size }
	{
		for (int i{ 0 }; i < size; ++i)
		{
			arr[i] = object.arr[i];
		}
		cout << "DynArr copy constructed for " << size << " elements, for " << this << '\n';
	}
	T getElem(int idx) { return arr[idx]; }
	void setElem(int idx, T val) { arr[idx] = val; }
	void print();
	T sum_arr();
	void randomize();
	
	~DynArray()
	{
		cout << "Try to free memory from DynArray for " << arr << " pointer\n";
		delete[] arr;
		cout << "DynArr destructed for " << size << " elements, for " << this << '\n';
	}
};

template <typename T>
void DynArray<T>::print()
{
	for (int i{ 0 }; i < size; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << '\n';
}

template <typename T>
void DynArray<T>::randomize()
{
	for (int i{ 0 }; i < size; ++i)
	{
		arr[i] = rand() % 10;
	}
}

template <typename T>
T DynArray<T>::sum_arr() {
	T sum = arr[0];
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}

ostream& operator<<(ostream& out, const Point& obj)
{
	out << "(" << obj.getX() << ", " << obj.getY() << ")";
	return out;
}

int main()
{
	DynArray<int> ar1{ 10 };
	ar1.randomize();
	cout << "ar1 elements: ";
	ar1.print();
	cout << "Sum elements: " << ar1.sum_arr() << "\n\n";

	DynArray<double> ar2{ 10 };
	ar2.randomize();
	cout << "ar2 elements: ";
	ar2.print();
	cout << "Sum elements: " << ar2.sum_arr() << "\n\n";

	DynArray<char> ar3{ 10 };
	ar3.randomize();
	cout << "ar3 elements: ";
	ar3.print();
	cout << "Sum elements: " << int(ar3.sum_arr()) << "\n\n";

	/*DynArray<Point> ar4{ 10 };
	ar4.randomize();
	cout << "ar4 elements: ";
	ar4.print();
	cout << "Sum elements: " << ar4.sum_arr() << "\n\n";*/
}
