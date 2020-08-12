#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
#define ull unsigned long long

class Decimal {
	public:
		int input;

	public:
		int dectobin(int input){
			ull bin = 0;
			for(int i=0;input>0;i++) {
				int rem = input % 2;
				ull c = pow(10,i);
				bin += rem * c;
				input /= 2;
			}
			return bin;
		}

		int dectohex(int input){
			char hexa[100];
			int x = 0;
			while(input>0){
				int temp = 0;
				temp = input % 16;
				if(temp<10){
					hexa[x] = temp + 48;
					x++;
				} else {
					hexa[x] = temp + 55;
					x++;
				} input /= 16;
			} for(int j=x-1; j>=0; j--){
				cout<<hexa[j];
			}
		}

		int dectooc(int input){
			int oc[100], i;
			for(i=0;input>0;i++){
				oc[i] = input % 8;
				input /= 8;
			} for(int j=i-1;j>=0;j--){
				cout<<oc[j];
			}
		}
};

class Binary {
	public:
		int input1, input3;
		long int input2;
	public:
		int bintodec(int input1){
			int num = input1;
			int dec_val = 0;
			int base = 1;
			int temp = num;
			while(temp){
				int last = temp % 10;
				temp = temp / 10;
				dec_val += last * base;
				base = base * 2;
			}
			return dec_val;
		}

		long int bintohex(long int input2){
			int hexadecimal[1000],dec=0,i=1,j,rem;
			// Bin to dec
			while(input2>0){
				rem = input2 % 2;
				dec = dec + rem*i;
				input2 /= 10;
				i *= 2;
			}
			// dec to hex
			i=0;
			while(dec!=0){
				hexadecimal[i] = dec % 16;
				dec /= 16;
				i++;
			}
			// display
			for(j=i-1;j>=0;j--){
				if(hexadecimal[j]>9){
					cout<<(char)(hexadecimal[j]+55);
				} else {
					cout<<hexadecimal[j];
				}
			}
		}

		int bintooc(int input3){
			int oct = 0, deci = 0, count = 0;
			// bin to dec
			while(input3!=0){
				deci += (input3 % 10)*pow(2,count);
				++count;
				input3 /= 10;
			}
			count = 1;
			while(deci!=0){
				oct += (deci % 8)*count;
				deci /= 8;
				count *= 10;
			}
			return oct;

		}
};

class Hexadecimal {
	public:
		char hex_val[], hexdec[];
	public:
		int hextodec(char hex_val[]){
			int len = strlen(hex_val);
			// initializing base val to 1, i.e 16^0
			int base = 1, dec_value = 0;
			// Extracting char as digits from last char
			for(int z=len-1;z>=0;z--){
				/*if char lies in '0'-'9', convert it to integral 0-9 by substracting 48 from ASCII value.*/
				if(hex_val[z]>='0' && hex_val[z]<='9'){
					dec_value += (hex_val[z] - 48) * base;
					//increamenting base by power
					base *= 16;
				} /* if char lies in 'A' - 'F', convert it to integral 10 - 15 by substracting 55 from ASCII value */
					else if(hex_val[z]>='A' && hex_val[z]<='F'){
						dec_value += (hex_val[z] - 55) * base;
						// increament base by power
						base *= 16;
					}
			}
			return dec_value;
		}
		// Conv Hexadecimal to Binary w/ Switch case branch
		void hextobin(char hexdec[]){
			long int j;
			while(hexdec[j]) {
				switch(hexdec[j]){
					case '0':
						cout<<"0000";
						break;
					case '1':
						cout<<"0001";
						break;
					case '2':
						cout<<"0010";
						break;
					case '3':
						cout<<"0011";
						break;
					case '4':
						cout<<"0100";
						break;
					case '5':
						cout<<"0101";
						break;
					case '6':
						cout<<"0110";
						break;
					case '7':
						cout<<"0111";
						break;
					case '8':
						cout<<"1000";
						break;
					case '9':
						cout<<"1001";
						break;
					case 'A':
					case 'a':
						cout<<"1010";
						break;
					case 'B':
					case 'b':
						cout<<"1011";
						break;
					case 'C':
					case 'c':
						cout<<"1100";
						break;
					case 'D':
					case 'd':
						cout<<"1101";
						break;
					case 'E':
					case 'e':
						cout<<"1110";
						break;
					case 'F':
					case 'f':
						cout<<"1111";
						break;
					default:
						cout<<"\n invalid Hexadecimal Digit "<<hexdec[j];
				}
				j++;
			}
		}
		// Conv Hexadecimal to Octal number by conv it to decimal number then to Octal number
		int hextooc(char hex_val[]) {
			int j, len, dec = 0, oct = 0;
			for(len=0; hex_val[len]!='\0'; len++);
				for(j=0; hex_val[j]!='\0'; j++, len--)
				{
					if(hex_val[j]>='0' && hex_val[j]<='9') {
						dec = dec + (hex_val[j] - '0')*pow(16, len-1);
					}
					if(hex_val[j]>='A' && hex_val[j]<='F') {
						dec = dec + (hex_val[j] - 55)* pow(16,len-1);
					}
					if(hex_val[j]>='a' && hex_val[j]<='f') {
						dec = dec + (hex_val[j] - 87)* pow(16,len-1);
					}
				} /* Now dec contains the decimal value of given hexadecimal number */
				j = 1;
				while(dec!=0) {
					oct = oct + (dec % 8)*j;
					dec /= 8;
					j *= 10;
				}
				return oct;
		}
};

class Octal {
	public:
		int octal_in;
		string octnum;

	public:
		int octaltodec(int octal_in) {
			// Initializing base value to 1, i.e 8^0
			int dec = 0, base = 1;
			while(octal_in) {
				// Extracting last digit
				int last_digit = octal_in % 10;
				octal_in /= 10;
				// Multiplying last digit with appropriate base value and adding it to dec
				dec += last_digit * base;
				base *= 8;
			}
			return dec;
		}

		string octaltobin(string octnum) {
			long int j = 0;
			string binary = "";
			while(octnum[j]) {
				switch(octnum[j]) {
					case '0':
						binary += "000";
						break;
					case '1':
						binary += "001";
						break;
					case '2':
						binary += "010";
						break;
					case '3':
						binary += "011";
						break;
					case '4':
						binary += "100";
						break;
					case '5':
						binary += "101";
						break;
					case '6':
						binary += "110";
						break;
					case '7':
						binary += "111";
						break;
					default:
						cout<<"\n Invalid Octal Digit. "<<octnum[j];
						break;
				}
				j++;
			}
			return binary;
		}

		int octaltohex(int octal_in) {
			char hex[20], c;
			int i = 0, dec = 0, rem;
			// Octal to Decimal
			while(octal_in!=0) {
				rem = octal_in % 10;
				octal_in /= 10;
				dec = dec + rem * pow(8,i);
				++i;
			}
			// Decimal to Hexadecimal
			while(dec>0){
				int temp = 0;
				temp = dec % 16;
				if(temp<10){
					hex[i] = temp + 48;
					i++;
				} else {
					hex[i] = temp + 55;
					i++;
				} dec /= 16;
			} for(int j=i-1; j>=0; j--){
				cout<<hex[j];
			}
		}
};