#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	
	while (1 != 0) {
		char* _password = (char*)malloc(31 * sizeof(char));
		_password[30] = 0;
		printf("Input your password. MAX 30 symbols \n");
		char sym;
		sym = getch();
		int* count_ = (int*)malloc(4 * sizeof(int));
		for (int i = 0; i < 4; i++) {
			count_[i] = 0;
		}
		int count = 0;
		while ((int)sym != 13 && count < 30) {

			if ((int)sym != 8) {
				_password[count] = sym;
				count += 1;
				if (47 < (int)sym && (int)sym < 58) {
					count_[0] += 1;
				}
				else if (64 < (int)sym && (int)sym < 91) {
					count_[1] += 1;
				}
				else if (96 < (int)sym && (int)sym < 123) {
					count_[2] += 1;
				}
				else {
					count_[3] += 1;
				}
				printf("*");
				sym = getch();
				continue;
			}
			count -= 1;
			if (47 < (int)sym && (int)sym < 58) {
				count_[0] -= 1;
			}
			else if (64 < (int)sym && (int)sym < 91) {
				count_[1] -= 1;
			}
			else if (96 < (int)sym && (int)sym < 123) {
				count_[2] -= 1;
			}
			else {
				count_[3] -= 1;
			}
			printf("\b");
			printf(" ");
			printf("\b");
			sym = getch();

		}
		if (count == 30) {
			printf("\nToo much symbols...\n");
			free(_password);
			continue;
		}
		if (count_[0] > 3 && count_[1] > 3 && count_[2] > 3 && count_[3] > 3) {
			printf("\nOk. Good password\n");
			free(_password);
			break;
		}
		else {
			printf("\nBad password. Try more.\n");
			free(_password);
			continue;
		}
	}
	printf("\n");

	system("pause");
	return 0;
}