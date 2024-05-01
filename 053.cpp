// TODO 1: Ubah nama file ini menjadi NIM Anda. Cth: 001.cpp, 042.cpp, 080.cpp

// TODO 2: Buat program anda di file ini. INGAT BERI KOMENTAR PADA SETIAP PROSES DALAM PROGRAM ANDA

#include <iostream>
#include <string>

using namespace std;

long long pangkat(int x){
    long long i;
    i=1;
    for (int xs=x;xs>=1;xs--){
        i=i*10;
    }
	return i;
}

int main(){
    long long kartu,x,z,check_sum,sebelum,sekarang,now;
    string jenis, validation;char ys;
    
    ulang:
    cout<<"Input Credit Card : ";cin>>kartu;
    if (kartu>=1000000000000000 || kartu<=9999999999999999) goto digit_16;
    else if(kartu>=100000000000000 || kartu<=999999999999999) goto digit_15;
    else goto ulang;
	
 	//Kode ini dibuat dengan menghitung 15 atau 16 digit kartu kredit untuk mengetes keabsahannya
    //Fungsi pangkat dibuat untuk menghasilkan pangkat 10 dengan jumlah yang di inginkan 
    //
	
	digit_16:
	now=kartu/pangkat(15);
    sebelum=0;
    check_sum=0;
    for(int u=15;u>=1;u-=2){
    	if (u==15){
    		sekarang = kartu/pangkat(u);
		}
		else{
			sekarang=(kartu/pangkat(u))-((kartu/pangkat(u+1))*10);
		}
    	
    	if ((sekarang*2)>9){
    		sebelum = (sekarang*2)/10;
    		sekarang=(sekarang*2)%10;
    		check_sum = sebelum+sekarang+check_sum;
		}
		else check_sum=check_sum+(sekarang*2);   	
	}
	
	cout<<check_sum<<endl;
	for(int u=14;u>=0;u-=2){
		sekarang=(kartu/pangkat(u))-((kartu/pangkat(u+1)*10));
		//cout<<sekarang<<endl;
		check_sum = check_sum +(sekarang);
	}
    //cout<<check_sum<<endl;
    goto ends;
    
    //cout<<kartu/y;
	//cout<<y;
	digit_15:
	now=kartu/pangkat(14);
	sebelum=0;
    check_sum=0;
    for(int u=14;u>=1;u-=2){
    	if (u==14){
    		sekarang = kartu/pangkat(u);
		}
		else{
			sekarang=(kartu/pangkat(u))-((kartu/pangkat(u+1))*10);
		}
    	//cout<<sekarang<<endl;
		check_sum=check_sum+sekarang; 
		//cout<<check_sum<<endl;  	
	}
	
	//cout<<check_sum<<endl;
	for(int u=13;u>=0;u-=2){
		sekarang=(kartu/pangkat(u))-((kartu/pangkat(u+1)*10));
		//cout<<sekarang<<endl;
		if ((sekarang*2)>9){
    		sebelum = (sekarang*2)/10;
    		sekarang=(sekarang*2)%10;
    		check_sum = sebelum+sekarang+check_sum;
		}
		else check_sum=check_sum+(sekarang*2); 
	}
    //cout<<check_sum<<endl;
    goto ends;
    ends:
    	if ((check_sum%10)==0){
    		if (now==5) jenis="MasterCard";
    		else if(now==4) jenis = "Visa";
    		else jenis="Tidak Terdeteksi";
    		validation="Valid";
		}
		else{
			jenis="-";
			validation="Not Valid";
		}
		cout<<"Jenis Kartu : "<<jenis<<endl;
		cout<<"Validation  : "<<validation<<endl;
		cout<<"Check Sum   : "<<check_sum<<endl;
		
		cout<<"Want to re-check? [y/n] ";cin>>ys;
		if(ys=='y' || ys=='Y') {
			cout<<endl<<endl;
			goto ulang;
		}
		
    return 0;
}

// TODO 3: Selesaikan dan kumpulkan sebelum deadline yang telah ditentukan; Details ada dalam file README.md

// Tetap semangat walau sulit ;p

