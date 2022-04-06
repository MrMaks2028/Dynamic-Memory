#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define crtdarr(t, n, s) t * n = new t [s]

void fillAr(int a[], int len, int min, int max);
template <typename T> void showAr(T a[], int len);
template <typename T> T* addEl(T a[], int len, int n);
template <typename T> T* delEl(T a[], int len, int n);

int main() {
	setlocale(LC_ALL, "Russian");
	
	/*//������ 1
	cout << "������ 1.\n������� ����� �������: ";
	int size1;
	cin >> size1;
	int* z1 = new int[size1];
	fillAr(z1, size1, 1, 20);
	cout << "����������� ������:\n";
	showAr(z1, size1);
	z1 = addEl(z1, size1, 3);
	size1 += 3;
	cout << "�������� ������:\n";
	showAr(z1, size1);*/

	//������ 2
	cout << "������ 2.\n������� ����� �������: ";
	int size2;
	cin >> size2;
	int* z2 = new int [size2];
	fillAr(z2, size2, 0, 20);
	cout << "����������� ������:\n";
	showAr(z2, size2);
	z2 = delEl(z2, size2, 2);
	size2 -= 2;
	cout << "�������� ������:\n";
	showAr(z2, size2);




	/*int n;
	cout << "������� ����� �������: ";
	cin >> n;
	int* dArr = new int[n];
	fillAr(dArr, n, 0, 10);
	cout << "������ ������ � " << n << ":\n";
	showAr(dArr, n);
	cout << *dArr << endl;

	delete[] dArr;
	dArr = nullptr;

	crtdarr(int, myDArr, n); // int* dArr = new int[n];*/
	/*int* pn = new int;
	cout << pn << endl;
	*pn = 10;
	cout << *pn << endl;

	delete pn;
	pn = nullptr;

	if (pn != nullptr)
		cout << pn << " - " << *pn << endl;

	pn = new int;
	*pn = 17;
	cout << pn << endl;
	cout << *pn << endl;*/

	return 0;
}
//��������� ���������� ������ ���������� ������� �� min �� max
void fillAr(int a[], int len, int min, int max) {
	srand(time(NULL));
	for (int i = 0; i < len; i++)
		a[i] = rand() % (max - min) + min;
}
//������� ������ � �������
template <typename T> void showAr(T a[], int len) {
	cout << "[";
	for (int i = 0; i < len; i++)
		cout << a[i] << ", ";
	cout << "\b\b]\n";
}
//������ 1. ���������� ����� �������
template <typename T> T* addEl(T a[], int len, int n) {
	if (n <= 0)
		return a;
	T* tmp = new T[len];
	for (int i = 0; i < len; i++)
		tmp[i] = a[i];
	delete[] a;
	a = new T[len + n];
	for (int i = 0; i < len; i++)
		a[i] = tmp[i];
	delete[] tmp;
	return a;
}
//������ 2. ���������� ����� �������
template <typename T> T* delEl(T a[], int len, int n) {
	if (n >= len || n <= 0)
		return a;
	len -= n;
	T* tmp = new T[len];
	for (int i = 0; i < len; i++)
		tmp[i] = a[i];
	delete[] a;
	return tmp;
}
