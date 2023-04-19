#include "function.h"

int MidSearch(int* A,int* B,int n) {
	int s1 = 0, d1 = n - 1, s2 = 0, d2 = n - 1;//s为数组首位下表，d为数组末尾下表
	int m1 = (s1 + d1) / 2;                    //m为数组中位数
	int m2 = (s2 + d2) / 2;
	while (s1 != d1 || s2 != d2) {             //当数组内皆仅剩1个数字时，循环终止
		if (A[m1] == B[m2]) {				   //数组中位数相等时，该数字为两个序列的中位数
			return A[m1];
		}
		else if (A[m1] < B[m2]) {
			d2 = m2;                           //舍去较大的一边
			if ((s1 + d1) % 2 == 1) {          //若序列中剩余个数为偶数
				s1 = m1 + 1;                   //舍去包括中位数的较小的一边
			}
			else {
				s1 = m1;					   //舍去包括中位数的较小的一边
			}
		}
		else {
			d1 = m1;
			if ((s2 + d2) % 2 == 1) {
				s2 = m2 + 1;
			}
			else {
				s2 = m2;
			}
		}
		m1 = (s1 + d1) / 2;
		m2 = (s2 + d2) / 2;
	}
	return A[m1] < B[m2] ? A[m1] : B[m2];
}
