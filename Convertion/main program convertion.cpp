#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>
#include <typeinfo>
#include "Convertion.cpp"

using namespace std;

int main(){
	int input, input1, octal_in, pil_tipe, pil_decimal, pil_biner, pil_hexa, pil_octal;
	char fake_input[1], cho, hex_val[100], hexa_decimal[100],  pilih_decimal[1], pilih_bin[1], pilih_hexa[1], pilih_octal[1], pilih_type[1];
	string octal_number;

	do{
		ulang:
		system("COLOR F0");
		cout<<"___________________________________________________________________\n\n";
		cout<<"|===================[Program Konversi Bilangan]===================|\n";
		cout<<"___________________________________________________________________\n";
		cout<<"\n Pilih Tipe bilangan : \n\n";
		cout<<" 1). Hexadecimal\n";
		cout<<" 2). Decimal\n";
		cout<<" 3). Octal\n";
		cout<<" 4). Binary\n";
		cout<<" 5). Exit Program\n"; 
		cout<<"\n Pilihan (1-5) : ";
		cin>>pilih_type;
		pil_tipe = atoi(pilih_type);
		switch(pil_tipe){
			case 1:
				rep2:
				cout<<"\n Konversi ke bilangan : \n\n 1). Decimal\n 2). Binary\n 3). Octal\n";
			    cout<<"\n Pilihan (1-3) : "; cin>>pilih_hexa;
			    pil_hexa = atoi(pilih_hexa);
			    switch(pil_hexa){
			    	case 1:
			    	    cout<<"\n Masukan nilai Hexadecimal (0-9 & A-F) : ";
					    cin>>hex_val;
					    Hexadecimal DecHex;
					    cout<<"\n Bentuk Decimalnya : [ "<<DecHex.hextodec(hex_val);
					    cout<<" ]\n";
					break;

					case 2:
						cout<<"\n Masukan nilai Hexadecimal (0-F): ";
					    cin>>hexa_decimal;
						Hexadecimal BinHex;
						cout<<"\n Bentuk Binernya : [ ";
						BinHex.hextobin(hexa_decimal);
						cout<<" ]\n";
					break;

					case 3:
						cout<<"\n Masukan nilai Hexadecimal (0-F): ";
					    cin>>hex_val;
						Hexadecimal OctHex;
						cout<<"\n Bentuk Octalnya : [ ";
						cout<<OctHex.hextooc(hex_val);
						cout<<" ]\n";
					break;
					default:
						cout<<"\n Invalid input !";
						goto rep2;
				}
			break;

			case 2:
				cout<<"\n Masukan nilai decimal (0-9) : "; 
				cin>>input;
				rep:
				cout<<"\n Konversi ke bilangan : \n\n 1). Biner\n 2). Hexadecimal\n 3). Octal\n";
				cout<<"\n Pilihan (1-3) : "; cin>>pilih_decimal;
				pil_decimal = atoi(pilih_decimal);
				  switch(pil_decimal){
					case 1:
					    Decimal Bin;
					    cout<<"\n Bentuk Binernya : [ ";
					    cout<<Bin.dectobin(input);
					    cout<<" ]\n";
					break;

					case 2:
					    Decimal Hexa;
					    cout<<"\n Bentuk Hexadecimalnya : [ ";
					    Hexa.dectohex(input);
					    cout<<" ]\n";
					break;

					case 3:
					    Decimal Oc;
					    cout<<"\n Bentuk Octalnya : [ ";
					    Oc.dectooc(input);
					    cout<<" ]\n";
					break;
					default:
						cout<<"\n\n Input sesuai pilihan ! ";
						goto rep;
					}
			break;

			case 3:
				rep3:
				cout<<"\n Konversi ke bilangan : \n\n 1). Decimal\n 2). Binary\n 3). Hexadecimal\n";
			    cout<<"\n Pilihan (1-3) : "; cin>>pilih_octal;
			    pil_octal = atoi(pilih_octal);
			    switch(pil_octal) {
			    	case 1:
			    	{
			    		cout<<"\n Masukan nilai Octal (0-7): ";
			    		cin>>octal_in;
			    		Octal Dec;
			    		cout<<"\n Bentuk Decimalnya : [ ";
			    		cout<<Dec.octaltodec(octal_in);
			    		cout<<" ]\n";
			    	}
			    	break;

			    	case 2:
			    	{
			    		cout<<"\n Masukan nilai Octal (0-7): ";
			    		cin>>octal_number;
			    		Octal Bin;
			    		cout<<"\n Bentuk Binernya : [ ";
			    		cout<<Bin.octaltobin(octal_number);
			    		cout<<" ]\n";
			    	}
			    	break;

			    	case 3:
			    	{
			    		cout<<"\n Masukan nilai Octal (0-7): ";
			    		cin>>octal_in;
			    		Octal Hex;
			    		cout<<"\n Bentuk Hexadecimalnya : [ ";
			    		Hex.octaltohex(octal_in);
			    		cout<<" ]\n";
			    	}
			    	break;
			    	default:
			    		cout<<"\n Masukan sesuai daftar !";
			    		goto rep3;
			    }
			break;

			case 4:
				rep1:
			    cout<<"\n Konversi ke bilangan : \n\n 1). Decimal\n 2). Hexadecimal\n 3). Octal\n";
			    cout<<"\n Pilihan (1-3) : "; cin>>pilih_bin;
			    pil_biner = atoi(pilih_bin);
			    switch(pil_biner){
			    	case 1:
			    	{
			    	    cout<<"\n Masukan nilai Biner (0-1) [max = 10 digit]: "; cin>>input1;
			    	    Binary Dec;
			    	    cout<<"\n Bentuk Decimalnya : [ ";
			    	    cout<<Dec.bintodec(input1);
			    	    cout<<" ]\n";
			    	}
			    	break;

			    	case 2:
			    	{
			    	    long int input2;
			    	    cout<<"\n Masukan nilai Biner (0-1) [max = 10 digit]: "; cin>>input2;
			    	    Binary Hex;
			    	    cout<<"\n Bentuk Hexadecimalnya : [ ";
			    	    Hex.bintohex(input2);
			    	    cout<<" ]\n";
			    	}
			    	break;

			    	case 3:
			    	{
			    	    int input3;
			    	    cout<<"\n Masukan nilai Biner (0-1) [max = 10 digit]: "; cin>>input3;
			    	    Binary Oct;
			    	    cout<<"\n Bentuk Octalnya : [ ";
			    	    cout<<Oct.bintooc(input3);
			    	    cout<<" ]\n";
			    	}
			    	break;
			    	
			    	default:

			    		cout<<"\n\n Ketik sesuai pilihan ! ";
			    		goto rep1;
			    	}
			break;

			case 5:
				cout<<"\n Terimakasih!\n";
				exit(1);
			default:
				system("CLS");
				system("COLOR FC");
				cout<<"\n\n Masukan sesuai pilihan !\n\n Tekan Enter..... \n";
				getch();
				system("CLS");
				goto ulang;
			}
		getch();

		cout<<"\n Konversi Lagi [Y/N] ? ";
		cin>>cho;
		system("CLS");
		} while(cho=='Y'||cho=='y');
		cout<<"\n Terimakasih!\n";
	return 0;
}