#include <iostream>

int sum(int n) {
	return ((n * n + n) / 2);
}


int* primeMultipliers(int n) {
	int primeMultipliersCount = 0;
	int nCopy = n;
	for (int i = 2; i <= n; i) {
		if (nCopy % i == 0) {
			primeMultipliersCount++;
			nCopy /= i;
		}
		else {
			i++;
		}
	}

	int* array = new int[primeMultipliersCount];

	int i = 2;
	for (int b = 0; b < primeMultipliersCount; b) {
		if (n % i == 0) {
			array[b] = i;
			//std::cout << array[b];
			n /= i;
			b++;
		}
		else {
			i++;
		}
	}

	return array;
}


int main() {

	int n;
	std::cin >> n;
	int orig_n = n;
	n = sum(n);
	n += 1;

	int primeMultipliersCount = 0;
	int nCopy = n;
	for (int i = 2; i <= n; i) {
		if (nCopy % i == 0) {
			primeMultipliersCount++;
			nCopy /= i;
		}
		else {
			i++;
		}
	}

	if (primeMultipliersCount == 0) {
		return 0;
	}
	else if (primeMultipliersCount == 1) {
		std::cout << "There is no such numbers";
		return 0;
	}

    int* array;
	array = primeMultipliers(n);

	/*for (int i = 0; i < primeMultipliersCount; i++) {
		std::cout << array[i] << "\n";
	}*/

	int a = 1;
	int b = 1;
	int it = 0;


	while (a * array[it] < orig_n) {
		a *= array[it];
		it++;
	}
	for (it; it < primeMultipliersCount; it++) {
		b *= array[it];
	}

	if (b >= orig_n) { std::cout << "there is no such numbers"; }
	else std::cout << "Numbers:\n" << a - 1 << "\n" << b - 1;



	delete[]array;
}