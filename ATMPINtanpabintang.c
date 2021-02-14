#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

//variabel global
int tidakvalid();
int menuutama();
char gantiemail();
main (){
	int pin, saldoawal;
	int pinfikri = 524017, pinfaza = 524016;
	int pilihan, pilihanganti, pilihtarik, pilihanbayar;
	int rekeningfikri = 201524017, saldofikri = 1000000000;
	int rekeningfaza = 201524016, saldofaza = 1000000000;
	char namafikri[50] = "Muhammad Fikri Hidayatulloh", alamatfikri[50] = "Subang. Jawa Barat", emailfikri[50] = "fikrihidayatulloh17@gmail.com", nofikri[15] = "082316503060" ; 
	char namafaza[50] = "Muhammad Faza Hardiansyah", alamatfaza[50] = "Bandung. Jawa Barat", emailfaza[50] = "fazahardiansyah16@gmail.com", nofaza[15] = "081315566976";
	int statusfikri = 1, statusfaza = 1,makstarikfikri = 15000000, makstarikfaza = 25000000, makstffikri = 200000000, makstffaza = 500000000; 
	int totaltarikfikri = 0, totaltarikfaza = 0, totaltffikri = 0, totaltffaza = 0;
	int tiketfikri = 0, pajakfikri = 0, plnfikri = 0, pamfikri = 0, gopayfikri = 0;
	int tiketfaza = 0,pajakfaza = 0  ,plnfaza = 0, pamfaza = 0,   gopayfaza = 0;
	char kelasfikri[20] = "Ekonomi", kelasfaza[20] = "Eksklusif";
	pin : pin = masukkanpin();
		if(statusfikri == 1 && pin == pinfikri) {
		printf("\nPIN Benar");
		system("cls");
		utama : pilihan = menuutama();
		switch (pilihan){
			case 49 :	
				system("cls");
				printf ("              Selamat Datang\a\n");
				printf ("             Silahkan Dipilih\n");
				printf ("================================================\n");
				printf("1 Ganti PIN                 Tutup Akun 3\n");
				printf("2 Ganti Email               Kembali ==> Any Keys\n");
				pilihanganti = getche();
				switch (pilihanganti){
					case 49 : pinfikri = gantipin(pinfikri); goto pin;
					case 50 : 
						system("cls");
						printf("Email Anda : %s", emailfikri);
						printf("                                             Lanjut ==> Enter\n");
						printf("\nMasukkan Email Baru :");
						scanf("%s", &emailfikri); goto utama;
					case 51 : statusfikri = gantistatus(statusfikri);
						if (statusfikri == 0) {goto pin; break;}
						else goto utama;
					default : goto utama; break;
				}
			case 50 : 
				if (totaltarikfikri < makstarikfikri){
					saldoawal = saldofikri;
					saldofikri = penarikan(saldofikri, makstarikfikri, totaltarikfikri);
					totaltarikfikri = totaltarikfikri + (saldoawal - saldofikri);
					goto utama;
				}
				else printf("\nMaaf Anda Sudah Mencapai Batas Penarikan Hari Ini"); getche();  goto utama;
			
			case 52 : info(namafikri, rekeningfikri, kelasfikri, alamatfikri, nofikri, emailfikri, totaltarikfikri, totaltffikri, saldofikri, pinfikri); goto utama;
			case 51 : 
				if (totaltffikri < makstffikri){
					saldoawal = saldofikri;
					saldofikri = transfer(saldofikri, makstffikri, rekeningfaza, saldofaza, totaltffikri, namafaza, alamatfaza, nofaza);
					totaltffikri = totaltffikri + (saldoawal- saldofikri);
					saldofaza = saldofaza + (saldoawal - saldofikri);
					goto utama;
				}
				else system("cls"); printf("Maaf Anda Sudah Mencapai Batas Transfer Hari Ini"); getche(); goto utama;
			case 53 :
				system("cls");
				printf ("              Selamat Datang\a\n");
				printf ("             Silahkan Dipilih\n");
				printf ("================================================\n");
				printf("1 Tiket                             Pulsa 5\n");
				printf("2 Pajak                Pembayaran Lainnya 6\n");
				printf("3 Listrik                         Kembali 7\n");
				printf("4 PAM ");
				pilihanbayar = getche();
				switch(pilihanbayar){
					case 49 : 
					saldoawal = saldofikri;
					saldofikri = pembayaran(pilihanbayar, saldofikri, tiketfikri, namafikri, nofikri); 
					if (saldoawal != saldofikri) {tiketfikri = 1; goto utama;}
					else tiketfikri = 0; goto utama;
					case 50 :
					 saldoawal = saldofikri;
					 saldofikri = pembayaran(pilihanbayar, saldofikri, pajakfikri, namafikri, nofikri);
					 if (saldoawal != saldofikri) {pajakfikri = 1; goto utama;}
					else goto utama;
					case 51 : 
					saldoawal = saldofikri;
					saldofikri = pembayaran(pilihanbayar, saldofikri, plnfikri, namafikri, nofikri);
					if (saldoawal != saldofikri) {plnfikri = 1; goto utama;}
					else goto utama;
					case 52 :
						saldoawal = saldofikri;
					 saldofikri = pembayaran(pilihanbayar, saldofikri, pamfikri, namafikri, nofikri);
					 if (saldoawal != saldofikri) {pamfikri = 1; goto utama;}
					else goto utama;
					case 53 : saldofikri = pembayaran(pilihanbayar, saldofikri, gopayfikri, namafikri, nofikri);
					case 54 : 
					saldoawal = saldofikri;
					saldofikri = pembayaran(pilihanbayar, saldofikri, gopayfikri, namafikri, nofikri);
					if (saldoawal != saldofikri) {gopayfikri = 1; goto utama;}
					else goto utama;
					default : goto utama;
						
				}
			default : system("cls"); printf("Terima Kasih"); getche(); goto pin;
		}
	}
	else if(statusfaza == 1 && pin == pinfaza) {
		printf("\nPIN Benar");
		system("cls");
		utama2 : pilihan = menuutama();
		switch (pilihan){
			case 49 :	
				system("cls");
				printf ("              Selamat Datang\a\n");
				printf ("             Silahkan Dipilih\n");
				printf ("================================================\n");
				printf("1 Ganti PIN                 Tutup Akun 3\n");
				printf("2 Ganti Email               Kembali ==> Any Keys\n");
				pilihanganti = getche();
				switch (pilihanganti){
					case 49 : pinfaza = gantipin(pinfaza); goto pin;
					case 50 : 
						system("cls");
						printf("Email Anda : %s", emailfaza);
						printf("                                             Lanjut ==> Enter\n");
						printf("\nMasukkan Email Baru :");
						scanf("%s", &emailfaza); goto utama2;
					case 51 : statusfaza = gantistatus(statusfaza);
						if (statusfaza == 0) {goto pin; break;}
						else goto utama2;
					default : goto utama2; break;
				}
			case 50 : 
				if (totaltarikfaza < makstarikfaza){
					saldoawal = saldofaza;
					saldofaza = penarikan(saldofaza, makstarikfaza, totaltarikfaza);
					totaltarikfaza = totaltarikfaza + (saldoawal - saldofaza);
					goto utama2;
				}
				else system("cls"); printf("\nMaaf Anda Sudah Mencapai Batas Penarikan Hari Ini"); getche();  goto utama2;
			
			case 52 : info(namafaza, rekeningfaza, kelasfaza, alamatfaza, nofaza, emailfaza, totaltarikfaza, totaltffaza, saldofaza, pinfaza); goto utama2;
			case 51 : 
				if (totaltffaza < makstffaza){
					saldoawal = saldofaza;
					saldofaza = transfer(saldofaza, makstffaza, rekeningfikri, saldofikri, totaltffaza, namafikri, alamatfikri, nofikri);
					totaltffaza = totaltffaza + (saldoawal- saldofaza);
					saldofikri = saldofikri + (saldoawal - saldofaza);
					goto utama2;
				}
				else system("cls"); printf("Maaf Anda Sudah Mencapai Batas Transfer Hari Ini"); getche(); goto utama2;
			case 53 :
				system("cls");
				printf ("              Selamat Datang\a\n");
				printf ("             Silahkan Dipilih\n");
				printf ("================================================\n");
				printf("1 Tiket                             Pulsa 5\n");
				printf("2 Pajak                Pembayaran Lainnya 6\n");
				printf("3 Listrik                         Kembali Any Keys\n");
				printf("4 PAM ");
				pilihanbayar = getche();
				switch(pilihanbayar){
					case 49 : 
					saldoawal = saldofaza;
					saldofaza = pembayaran(pilihanbayar, saldofaza, tiketfaza, namafaza, nofaza);
					if (saldoawal != saldofaza) {tiketfaza = 1; goto utama2;}
					else goto utama2;
					case 50 : 
					saldoawal = saldofaza;
					saldofaza = pembayaran(pilihanbayar, saldofaza, pajakfaza, namafikri, nofikri);
					if (saldoawal != saldofaza) {pajakfaza = 1; goto utama2;}
					else goto utama2;
					case 51 : 
					saldoawal = saldofaza;
					saldofaza = pembayaran(pilihanbayar, saldofaza, plnfaza, namafaza, nofaza);
					if (saldoawal != saldofaza) {plnfaza = 1; goto utama2;}
					else goto utama2;
					case 52 : 
					saldoawal = saldofaza;
					saldofaza = pembayaran(pilihanbayar, saldofaza, pamfaza, namafaza, nofaza);
					if (saldoawal != saldofaza) {pamfaza = 1; goto utama2;}
					else goto utama2;
					case 53 : saldofaza = pembayaran(pilihanbayar, saldofaza, gopayfaza, namafaza, nofaza); goto utama2;
					case 54 : 
					saldoawal = saldofaza;
					saldofaza = pembayaran(pilihanbayar, saldofaza, gopayfaza, namafaza, nofaza);
					if (saldoawal != saldofaza) {gopayfaza = 1; goto utama2;}
					else goto utama2;
					default : goto utama2;
						
				}
			default : system("cls"); printf("Terima Kasih"); getche(); goto pin;
		}
	}
	else if (statusfikri == 0 || statusfaza ==0 ) {
		if (pin == pinfikri) {
		statusfikri = gantistatus(statusfikri, pinfikri); goto pin;}
		else if (pin == pinfaza ) statusfaza = gantistatus(statusfaza, pinfaza); goto pin;
	}
	else pilihan = tidakvalid();
		if (pilihan == 49) goto pin;
		else printf("\a");system("cls"); printf("\a\nTerima Kasih");getche() ; return 0;

}

int tidakvalid(){
	int pilih;
	system("cls");
	printf("Maaf Input Tidak Valid");
	printf("\nMasukkan PIN Kembali?\n");
	printf("1 Iya              Keluar 2");
	printf("\n\nMasukkan Pilihan :");
	pilih = getche();
	return pilih;
	
}

masukkanpin(int x){
	system("cls");
	printf ("\t\tSelamat Datang \n\t Silahkan Masukkan PIN Anda \n");
	printf ("================================================\n");
	printf("                                             Lanjut ==> Enter\n");
	scanf("%d", &x);
	return x ;
}

int menuutama() {
	int pilihan;
	system("cls");
	printf ("              Selamat Datang\a\n");
	printf ("             Silahkan Dipilih\n");
	printf ("================================================\n");
	printf("1 Opsi Akun Nasabah      Info Nasabah 4\n");
	printf("2 Penarikan                Pembayaran 5\n");
	printf("3 Transfer                     Keluar => Any Keys");
	printf("\n\nMasukkan Pilihan :");
	pilihan = getche();
	return pilihan ;
}

gantipin(int pin){
	int pin1, pin2, pilihan;
	system("cls");
	printf ("              Selamat Datang\a\n");
	printf ("             Silahkan Dipilih\n");
	printf ("================================================\n");
	printf("                                  Lanjut ==> Enter\n");
	printf("Masukkan PIN Baru : ");
	scanf("%d", &pin1);
	system("cls");
	printf ("              Selamat Datang\a\n");
	printf ("             Silahkan Dipilih\n");
	printf ("================================================\n");
	printf("                                   Lanjut ==> Enter\n");
	printf("Konfirmasi PIN Baru : ");

	scanf("%d", &pin2);
	if (pin2 == pin1){
		pin = pin2;
		system("cls");
		printf("Selamat PIN Berhasil Diperbarui");
		printf("                                       Benar ==> Any Key");
		pilihan = getche();
		return pin;
		}
	else{
		system("cls");
		printf("PIN Tidak Sesuai\n");
		printf("                                       kembali ==> Any Key");
		pilihan = getche();
		return pin;
	}
}

char gantiemail(char email[50]){
	int pilihan;
	system("cls");
	printf("              Selamat Datang\a\n");
	printf("             Silahkan Dipilih\n");
	printf("================================================\n");
	printf("Email Anda : %s", email);
	printf("                                     Lanjut ==> Enter");
	printf("\nMasukkan Email Baru : ");
	scanf("%s", &email);
	return email[50];
	
	
}

gantistatus(int status, int pin){
	int pilihan, pin1, pin2;
	system("cls");
	if (status == 1){
		printf("Apakah anda Ingin Menutup Akun Ini\n\a");
		printf("1 Ya                       Tidak ==> Any Keys");
		pilihan = getche();
		switch(pilihan){
			case 49 : status = 0;
				printf("\nAkun Nasabah Berhasil Ditutup");
				getche(); return status; break;
			default : return status; break;
		}
	}
	else 
	printf("Maaf Akun Anda Sudah Dinonaktifkan \nApakah Ingin Mengaktifkan Kembali Akun?\n");
	printf("1 Ya                       Tidak ==> Any Keys");
	pilihan = getche();
	switch(pilihan){
			case 49 :
				system("cls");
					printf ("              Selamat Datang\a\n");
					printf ("  Silahkan Masukkan PIN Akun anda yang ditutup\n");
					printf ("================================================\n");
					printf("                                  Lanjut ==> Enter\n");
					printf("Masukkan PIN Akun anda: ");
					scanf("%d", &pin1);
					system("cls");
					printf ("              Selamat Datang\a\n");
					printf ("             Silahkan Dipilih\n");
					printf ("================================================\n");
					printf("                                   Lanjut ==> Enter\n");
					printf("Konfirmasi PIN : ");
				
					scanf("%d", &pin2);
					if (pin2 == pin1 && pin2 == pin){
						status = 1;
						system("cls");
						printf("Selamat Akun Berhasil Diaktifkan");
						printf("                                       Benar ==> Any Key");
						pilihan = getche();
						return status;
						}
					else if (pin2 != pin1){
						system("cls");
						printf("PIN Tidak Sesuai");
						printf("                                       kembali ==> Any Key");
						pilihan = getche();
						return status;
					}
					else 
						system("cls");
						printf("PIN Tidak Ditemukan");
						printf("                                       kembali ==> Any Key");
						pilihan = getche();
						return status;	
			default : return status; break;
	}
}

info(char nama[50], int rekening, char kelas[20], char alamat[50],char nohp[15], char email[50], int makstarik, int makstf, int saldo, int pin){
	system("cls");
	printf("              Selamat Datang\a\n");
	printf("             Silahkan Dipilih\n");
	printf("================================================\n");
	printf("Nama            : %s\n", nama);
	printf("No. Rekening    : %d\n", rekening);
	printf("Kelas           : %s\n", kelas);
	printf("Alamat          : %s\n", alamat);
	printf("nohp            : %s\n", nohp);
	printf("Email           : %s\n", email);
	printf("Total Penarikan : %d\n", makstarik);
	printf("Total Transfer  : %d\n", makstf);
	printf("Saldo           : Rp%d\n", saldo);
	printf("PIN             : %d\n", pin);
	printf("\n\nAny Keys <== Kembali");
	getche();
	return ;
}

penarikan(int saldo, int maks, int totaltarik){
	mula : system("cls");
	int pilihan, total, saldoawal, saldoakhir, jumlah;
	saldoawal = saldo;
	printf("              Selamat Datang\a\n");
	printf("             Silahkan Dipilih\n");
	printf("================================================\n");
	printf("1 50.000                              1.000.000 5\n");
	printf("2 100.000                             2.000.000 6\n");
	printf("3 300.000                        Jumlah Lainnya 7\n");
	printf("4 500.000                               Kembali 8\n");
	printf("Masukkan Pilihan :");
	pilihan = getche();
	switch (pilihan){
		case 49 : total = saldo - 50000; saldo = total; break;
		case 50 : total = saldo - 100000; saldo = total; break;
		case 51 : total = saldo - 300000; saldo = total; break;
		case 52 : total = saldo - 500000; saldo = total; break;
		case 53 : total = saldo - 1000000; saldo = total; break;
		case 54 : total = saldo - 2000000; saldo = total; break;
		case 55 : 
			system("cls");
			printf("Masukkan Jumlah \nRp");
			scanf("%d", &jumlah);
			if (jumlah % 50000 == 0) {
			total = saldo - jumlah; saldo = total; break;}
		
		
		else 
		printf("Maaf Harus Kelipatan Rp50.000,00");
		getche(); goto mula;
		break;
		case 56 : return saldo; break;
		default : system("cls"); printf("Tidak Valid"); getche(); return saldo;
	}
	saldoakhir = saldoawal - saldo;
	totaltarik = totaltarik + (saldoawal - saldo);
	if (saldo > 0 && totaltarik <= maks){
		system("cls");
		printf("Selamat Penarikan Berhasil\n");
		printf("Any Keys <== Kembali");
		getche(); return saldo;
	}
	else if(saldo > 0 && totaltarik > maks){
		printf("\nMaaf Anda Sudah Mencapai Batas Penarikan Hari Ini");
		saldoakhir = saldoawal;
		getche();
		return saldoakhir;
	}
	else printf("\nMaaf Saldo Anda Tidak Mencukupi");
	 saldoakhir = saldoawal; getche();
	return saldoakhir;
}

transfer(int saldo, int maks, int rekening, int saldotujuan, int totaltf, char nama[50], char alamat[50], char nohp[15]){
	mula : system("cls");
	int pilihan, total, saldoawal, saldoakhir, jumlah, kode, inputrekening;
	char bank[10], bank1[10] = "BRI", bank2[10] = "BNI", bank3[10] = "BCA", bank4[10] = "Mandiri";
	saldoawal = saldo;
	printf("              Selamat Datang\a\n");
	printf("             Silahkan Dipilih\n");
	printf("================================================\n");
	printf("1 Masukkan Rekening           Daftar Kode Bank 2\n");
	printf("                                   Kembali ==> 3\n");
	pilihan = getche();
	switch (pilihan){
		case 49 : 
			system("cls");
			printf("                                Lanjut ==> Enter");
			printf("\nMasukkan Kode Bank 3 Digit : ");
			scanf("%d", &kode);
			switch (kode){
				case 100 : 
					system("cls");
					printf("Masukkan Rekening : ");	
					scanf("%d", &inputrekening);
					if(inputrekening == rekening){
						system("cls");
						printf("Nama            : %s \n", nama);
						printf("No. Rekening    : %d \n", rekening);
						printf("Alamat          : %s \n", alamat);
						printf("nohp            : %s \n", nohp);
						printf("Biaya Admin     : Rp 0 \n");
						printf("1 Benar          Salah ==> AnyKeys");
						pilihan = getche();
						switch(pilihan){
							case 49 : 
							system("cls"); 
							printf("                 Lanjut ==> Enter");
							printf("\nMasukkan Jumlah : Rp");
							scanf("%d", &jumlah);
							saldo = saldo - jumlah;
							saldoakhir = saldoawal - saldo;
							totaltf = totaltf + (saldoawal - saldo);
							if (saldo > 0 && totaltf <= maks){
								if (jumlah % 10000 == 0){
								system("cls");
								printf("Selamat Transfer Berhasil\n");
								printf("Any Keys <== Kembali");
								getche(); return saldo;
								}
								else system("cls"); printf("Maaf Harus Kelipatan Rp10.000,00\n");
								printf("Any Keys <== Lanjut"); saldoakhir = saldoawal; getche(); return saldoakhir;
							}
							else if(saldo > 0 && totaltf > maks){
								printf("\nMaaf Anda Sudah Mencapai Batas Penarikan Hari Ini");
								saldoakhir = saldoawal;
								getche();
								return saldoakhir;
							}
							else printf("\nMaaf Saldo Anda Tidak Mencukupi");
					 		saldoakhir = saldoawal; getche();
							return saldoakhir;
						default : return saldo;
						}
					}
					else printf("\nNomor Rekening Salah"); getche(); return saldo;
				case 200 : 
					system("cls");
					printf("Masukkan Rekening : ");	
					scanf("%d", &inputrekening);
					if (inputrekening == rekening){
						system("cls");
						printf("Nama            : %s \n", nama);
						printf("No. Rekening    : %d \n", rekening);
						printf("Bank            : %s \n", bank2);
						printf("Alamat          : %s \n", alamat);
						printf("nohp            : %s \n", nohp);
						printf("Admin           : Rp.6000,00");
						printf("\n1 Benar          Salah ==> AnyKeys");
						pilihan = getche();
						switch(pilihan){
							case 49 : 
							system("cls"); 
							printf("                 Lanjut ==> Enter");
							printf("\nMasukkan Jumlah : Rp");
							scanf("%d", &jumlah);
							saldo = saldo - jumlah - 6000;
							saldoakhir = saldoawal - saldo;
							totaltf = totaltf + (saldoawal - saldo);
							if (saldo > 0 && totaltf <= maks){
								if (jumlah % 10000 == 0){
								system("cls");
								printf("Selamat Transfer Berhasil\n");
								printf("Any Keys <== Kembali");
								getche(); return saldo;
								}
								else system("cls"); printf("Maaf Harus Kelipatan Rp10.000,00\n");
								printf("Any Keys <== Lanjut"); saldoakhir = saldoawal; getche(); return saldoakhir;
							}
							else if(saldo > 0 && totaltf > maks){
								printf("\nMaaf Anda Sudah Mencapai Batas Penarikan Hari Ini");
								saldoakhir = saldoawal;
								getche();
								return saldoakhir;
							}
							else printf("\nMaaf Saldo Anda Tidak Mencukupi");
					 		saldoakhir = saldoawal; getche();
							return saldoakhir;
						default : return saldo;}
					}
				case 300 : 
					system("cls");
					printf("Masukkan Rekening : ");	
					scanf("%d", &inputrekening);
					if (inputrekening == rekening){
						system("cls");
						printf("Nama            : %s \n", nama);
						printf("No. Rekening    : %d \n", rekening);
						printf("Bank            : %s \n", bank3);
						printf("Alamat          : %s \n", alamat);
						printf("nohp            : %s \n", nohp);
						printf("Admin           : Rp.6000,00");
						printf("\n1 Benar          Salah ==> AnyKeys");
						pilihan = getche();
						switch(pilihan){
							case 49 : 
							system("cls"); 
							printf("                 Lanjut ==> Enter");
							printf("\nMasukkan Jumlah : Rp");
							scanf("%d", &jumlah);
							saldo = saldo - jumlah - 6000;
							saldoakhir = saldoawal - saldo;
							totaltf = totaltf + (saldoawal - saldo);
							if (saldo > 0 && totaltf <= maks){
								if (jumlah % 10000 == 0){
								system("cls");
								printf("Selamat Transfer Berhasil\n");
								printf("Any Keys <== Kembali");
								getche(); return saldo;
								}
								else system("cls"); printf("Maaf Harus Kelipatan Rp10.000,00\n");
								printf("Any Keys <== Lanjut"); saldoakhir = saldoawal; getche(); return saldoakhir;
							}
							else if(saldo > 0 && totaltf > maks){
								printf("\nMaaf Anda Sudah Mencapai Batas Penarikan Hari Ini");
								saldoakhir = saldoawal;
								getche();
								return saldoakhir;
							}
							else printf("\nMaaf Saldo Anda Tidak Mencukupi");
					 		saldoakhir = saldoawal; getche();
							return saldoakhir;
						default : return saldo;}
					}
				case 400 : 
					system("cls");
					printf("Masukkan Rekening : ");	
					scanf("%d", &inputrekening);
					if (inputrekening == rekening){
						system("cls");
						printf("Nama            : %s \n", nama);
						printf("No. Rekening    : %d \n", rekening);
						printf("Bank            : %s \n", bank4);
						printf("Alamat          : %s \n", alamat);
						printf("nohp            : %s \n", nohp);
						printf("Admin           : Rp.6000,00");
						printf("\n1 Benar          Salah ==> AnyKeys");
						pilihan = getche();
						switch(pilihan){
							case 49 : 
							system("cls"); 
							printf("                 Lanjut ==> Enter");
							printf("\nMasukkan Jumlah : Rp");
							scanf("%d", &jumlah);
							saldo = saldo - jumlah - 6000;
							saldoakhir = saldoawal - saldo;
							totaltf = totaltf + (saldoawal - saldo);
							if (saldo > 0 && totaltf <= maks){
								if (jumlah % 10000 == 0){
								system("cls");
								printf("Selamat Transfer Berhasil\n");
								printf("Any Keys <== Kembali");
								getche(); return saldo;
								}
								else system("cls"); printf("Maaf Harus Kelipatan Rp10.000,00\n");
								printf("Any Keys <== Lanjut"); saldoakhir = saldoawal; getche(); return saldoakhir;
							}
							else if(saldo > 0 && totaltf > maks){
								printf("\nMaaf Anda Sudah Mencapai Batas Penarikan Hari Ini");
								saldoakhir = saldoawal;
								getche();
								return saldoakhir;
							}
							else printf("\nMaaf Saldo Anda Tidak Mencukupi");
					 		saldoakhir = saldoawal; getche();
							return saldoakhir;
						default : return saldo;}
					}
				default : printf("\n Tidak Valid"); getche(); return saldo;
			}
			break;
		case 50 : system("cls");
		printf("Daftar Bank :\n"); 
		printf("100 : BRI\n200 : BNI\n300 : BCA\n400 : Mandiri\nAny Keys <== Kembali"); getche(); goto mula;
		default :  printf("Tidak Valid"); getche(); return saldo;
	}
}

pembayaran(int pilihan, int saldo, int lainnya, char nama[50], char nohp[15]){
	int kode, jumlah , tiket = 20002149, pajak = 20002150, listrik = 20002151, pam = 20002152 ,gopay = 20002153;
	char kodenohp[15];
	switch (pilihan){
		case 49 : 
		system("cls");
		printf("\tMasukkan Kode Pembayaran :");
		scanf("%d", &kode);
		if (kode == tiket && lainnya == 0){
			system("cls");
			printf("Tiket             : Kereta Api \n");
			printf("Nomor Bayar       : 1035943289\n");
			printf("Kelas             : Mainstream\n");
			printf("No Tempat Duduk   : B11\n");
			printf("Nama Kereta       : Ekspress\n");
			printf("Tujuan            : Jawa Timur\n");
			printf("Jumlah Pembayaran : Rp45.000,00\n");
			printf("\nAny Keys <== Benar");
			getche();
			if (saldo >= 45000){
				saldo = saldo - 45000;
				system("cls");
				printf("Selamat, Pembayaran Berhasil\n");
				printf("Any Keys <== Kembali"); getche();
				return saldo;
			}
			else system("cls"); printf("Maaf, Saldo Tidak Mencukupi\n"); 
			printf("Any Keys <== Kembali"); getche();
			return saldo;
			
			break;
		}
		else if (kode == tiket && lainnya == 1){
			system("cls");
			printf("Pembayaran Sudah Dilakukan \n\n");
			printf("Tiket       : Kereta Api \n");
			printf("Nomor Bayar : 1035943289\n");
			printf("Any Keys <== Kembali"); getche();
			return saldo;
		}
		else system("cls"); printf("Nomor Pembayaran Tidak Ditemukan\n");
		printf("Any Keys <== Kembali"); getche(); return saldo;
		
		case 50 : 
		system("cls");
		printf("\tMasukkan Kode Pembayaran :");
		scanf("%d", &kode);
		if (kode == pajak && lainnya == 0){
				system("cls");
			printf("Pembayaran        : Pajak Bumi Bangunan \n");
			printf("Nomor Bayar       : 239872349\n");
			printf("Provinsi          : Jawa Barat\n");
			printf("Jumlah Pembayaran : Rp56.674,00\n");
			printf("\nAny Keys <== Benar");
			getche();
			if (saldo >= 56674){
				saldo = saldo - 56674;
				system("cls");
				printf("Selamat, Pembayaran Berhasil\n");
				printf("Any Keys <== Kembali"); getche();
				return saldo;
			}
			else system("cls"); printf("Maaf, Saldo Tidak Mencukupi\n"); 
			printf("Any Keys <== Kembali"); getche();
			return saldo;
			
			break;
		}
		else if (kode == pajak && lainnya == 1){
			system("cls");
			printf("Pembayaran Sudah Dilakukan \n\n");
			printf("Pembayaran        : Pajak Bumi Bangunan \n");
			printf("Nomor Bayar       : 239872349\n");
			printf("Jumlah Pembayaran : Rp56.674,00\n");
			printf("Any Keys <== Kembali"); getche();
			return saldo;
		}
		else system("cls"); printf("Nomor Pembayaran Tidak Ditemukan\n");
		printf("Any Keys <== Kembali"); getche(); return saldo;
		
		case 51 : 
		system("cls");
		printf("\tMasukkan Kode Pembayaran :");
		scanf("%d", &kode);
		if (kode == listrik && lainnya == 0){
			system("cls");
			printf("Pembayaran        : Listrik \n");
			printf("Nomor Bayar       : 123763298\n");
			printf("Provinsi          : Jawa Barat\n");
			printf("Jumlah Pembayaran : Rp246.753,00\n");
			printf("\nAny Keys <== Benar");
			getche();
			if (saldo >= 246753){
				saldo = saldo - 246753;
				system("cls");
				printf("Selamat, Pembayaran Berhasil\n");
				printf("Any Keys <== Kembali"); getche();
				return saldo;
			}
			else system("cls"); printf("Maaf, Saldo Tidak Mencukupi\n"); 
			printf("Any Keys <== Kembali"); getche();
			return saldo;
			
			break;
		}
		else if (kode == listrik && lainnya == 1){
			system("cls");
			printf("Pembayaran Sudah Dilakukan \n\n");
			printf("Pembayaran        : Listrik \n");
			printf("Nomor Bayar       : 123763298\n");
			printf("Provinsi          : Jawa Barat\n");
			printf("Jumlah Pembayaran : Rp246.753,00\n");
			printf("Any Keys <== Kembali"); getche();
			return saldo;
		}
		else system("cls"); printf("Nomor Pembayaran Tidak Ditemukan\n");
		printf("Any Keys <== Kembali"); getche(); return saldo;
		
		case 52 : 
		system("cls");
		printf("\tMasukkan Kode Pembayaran :");
		scanf("%d", &kode);
		if (kode == pam && lainnya == 0){
			system("cls");
			printf("Pembayaran        : PAM \n");
			printf("Nomor Bayar       : 13472098\n");
			printf("Provinsi          : Jawa Barat\n");
			printf("Jumlah Pembayaran : Rp228.234,00\n");
			printf("\nAny Keys <== Benar");
			getche();
			if (saldo >= 228234){
				saldo = saldo - 228234;
				system("cls");
				printf("Selamat, Pembayaran Berhasil\n");
				printf("Any Keys <== Kembali"); getche();
				return saldo;
			}
			else system("cls"); printf("Maaf, Saldo Tidak Mencukupi\n"); 
			printf("Any Keys <== Kembali"); getche();
			return saldo;
		}
		else if (kode == pam && lainnya == 1){
			system("cls");
			printf("Pembayaran Sudah Dilakukan \n\n");
			printf("Pembayaran        : PAM \n");
			printf("Nomor Bayar       : 13472098\n");
			printf("Provinsi          : Jawa Barat\n");
			printf("Jumlah Pembayaran : Rp228.234,00\n");
			printf("Any Keys <== Kembali"); getche();
			return saldo;
		}
		else system("cls"); printf("Nomor Pembayaran Tidak Ditemukan\n");
		printf("Any Keys <== Kembali"); getche(); return saldo;
		
		case 53 : 
		system("cls");
		printf("\tMasukkan Nomor Seluler :");
		scanf("%s", &kodenohp);
		/*if (){*/
			system("cls");
			printf("Pembayaran        : Pulsa \n");
			printf("Nomor Seluler     : %s\n", kodenohp);
			printf("operator          : Telkomsel\n");
			printf("Minimal           : 10.000\n");
			printf("Maksmimal         : 3.000.000\n");
			printf("\n\n                               Benar ==> Enter\n");
			printf("Masukkan Jumlah :");
			scanf("%d", &jumlah);
			if (saldo >= jumlah && jumlah % 10000 == 0 && jumlah <= 3000000){
				saldo = saldo - jumlah;
				system("cls");
				printf("Selamat, Pembayaran Berhasil\n");
				printf("Any Keys <== Kembali"); getche();
				return saldo;
			}
			else if (saldo >= jumlah && jumlah % 10000 != 0 || jumlah <= 3000000){
				system("cls"); printf("Maaf, Jumlah yang Dimasukkan Tidak Valid\n"); 
				printf("Any Keys <== Kembali"); getche();
				return saldo;
			}
			else system("cls"); printf("Maaf, Saldo Tidak Mencukupi\n"); 
			printf("Any Keys <== Kembali"); getche();
			return saldo;
			
			break;
		/*}
		else 
		system("cls"); 
		printf("%s \n %d \n", nohp, nohp);
		printf("Nomor Seluler Tidak Ditemukan\n%s\n%d", kodenohp, kodenohp);
		printf("Any Keys <== Kembali"); getche(); return saldo;*/
		
		case 54 : 
		system("cls");
		printf("\tMasukkan Kode Pembayaran :");
		scanf("%d", &kode);
		if (kode == gopay && lainnya == 0){
			system("cls");
			printf("Pembayaran        : Saldo Gopay \n");
			printf("Nomor Bayar       : 19876234\n");
			printf("Nama Akun         : %s \n", nama);
			printf("Jumlah Pembayaran : Rp200.000,00\n");
			printf("\nAny Keys <== Benar");
			getche();
			if (saldo >= 200000){
				saldo = saldo - 200000;
				system("cls");
				printf("Selamat, Pembayaran Berhasil\n");
				printf("Any Keys <== Kembali"); getche();
				return saldo;
			}
			else system("cls"); printf("Maaf, Saldo Tidak Mencukupi\n");
			printf("Any Keys <== Kembali"); getche();
			return saldo;
			
			break;
		}
		else if (kode == gopay && lainnya == 1){
			system("cls");
			printf("Pembayaran Sudah Dilakukan \n\n");
			printf("Pembayaran        : Saldo Gopay \n");
			printf("Nomor Bayar       : 19876234\n");
			printf("Nama Akun         : %s \n", nama);
			printf("Jumlah Pembayaran : Rp200.000,00\n");
			printf("Any Keys <== Kembali"); getche();
			return saldo;
		}
		else system("cls"); printf("Nomor Pembayaran Tidak Ditemukan\n");
		printf("Any Keys <== Kembali"); getche(); return saldo;
	}
}
