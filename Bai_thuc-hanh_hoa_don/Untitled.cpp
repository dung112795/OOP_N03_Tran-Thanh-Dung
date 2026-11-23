#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class SanPham{
	private:
		int stt;
		string tenhang;
		string dvt;
		int soluong;
		double dongia;
	public:
		SanPham();
		SanPham(int tt, string ten, string dv, int sl, double gia);
		void nhap()
		double thanhtien() const;
		void hienthi() const;
		
};

SanPham::SanPham(): stt(0), tenhang(""), dvt(""), soluong(0), dongia(0) {}
SanPham::SanPham(int tt, string ten, string dv, int sl, double gia) : stt(tt), tenhang(ten), dvt(dv), soluong(sl), dongia(gia) {}

void SanPham::nhap(){
	stt=++stt;
	cout<<"Ten hang: ";
	getline(cin,tenhang);
	cout<<"Don vi tinh: ";
	getline(cin,dvt);
	cout<<"So luong: ";
	cin>>soluong;
	cout<<"Don gia: ";
	cin>>dongia;
	cin.ignore();
}

double SanPham::thanhtien(){
	return soluong*dongia;
} 

void SanPham::hienthi(){
	cout<<"  "<<stt<<" | "<<tenhang<<" | "<<dvt<<" | "<<soluong<<" | "<<fixed<<setprecision(0) << dongia<<" | "<<thanhtien()<<"\n";
}

class KhachHang{
	private:
		string tenkhachhang;
		string diachi;
		string sodienthoai;
	public:
		KhachHang();
		KhachHang(string ten, string dc, string sdt);
		void nhap();
		void hienthi() const;
};

KhachHang::KhachHang(): tenkhachhang(""), diachi(""), sodienthoai(""){}
KhachHang::KhachHang(string ten, string dc, string sdt): tenkhachhang(ten), diachi(dc), sodienthoai(sdt){}

void KhachHang::nhap(){

	cout<<"Ten khach hang: ";
	getline(cin,tenkhachhang);
	cout<<"Dia chi: ";
	getline(cin,diachi);
	cout<<"So dien thoai: ";
	getline(cin,sodienthoai);

}
void KhachHang::hienthi(){
	cout<<"Ten khach hang: "<<tenkhachhang<<endl<<"Dia chi: "<<diachi<<endl<<"So dien thoai: "<<sodienthoai<<endl;
}

class HoaDon{
	private:
		string sohoadon;
		string ngaymuahang;
		SanPham ds[100];
		int n;
		double thue;
	public:
		HoaDon();
		HoaDon(string shd,string ngay);
		
		string lay_so_hd() const;
		void nhap();
		void hienthi() const;
		
		double tongtien() const;
		double tienthue() const;
		double tongthanhtoan() const;
};

HoaDon::HoaDon() : sohoadon(""), ngaymuahang(""), n(0), thue(0) {}
HoaDon::HoaDon(string shd,string ngay) : sohoadon(sohd), ngaymuahang(ngaymua), n(0) , thue(0) {}

string HoaDon::lay_so_hd() const{
	return sohoadon;
}
void HoaDon::nhap(){
	cout<<"\n====NHAP HOA DON ====\n";
	cout<<"So hoa don: ";
	getline(cin,sohoadon);
	cout<<"Ngay mua hang: ";
	getline(cin,ngaymuahang);
	cout<<"\n====THONG TIN KHACH HANG ====\n";
	KhachHang::nhap();
	
	cout<<"Thue GTGT (%): ";
	cin>>thue;
	cin.ignore();
}
double HoaDon::tongtien() const{
	double tong=0;
	SanPham::stt;
	for(int i=0;i<stt;i++){
		tong+=ds[i].thanhtien();
	}
	return tong;
}
double HoaDon::tienthue() const{
	return tongtien()*thue/100;
}
double HoaDon::tongthanhtoan() const{
	return tongtien()+tienthue();
}
void HoaDon::hienthi(){
	cout<<"So hoa don: "<<sohoadon<<endl;
	cout<<"Ngay mua hang: "<<ngaymuahang<<endl;
	cout<<"\n====THONG TIN KHACH HANG ====\n";
	KhachHang::hienthi();
	cout<<"\n====DANH SACH HANG HOA====\n";
	cout<<"  "<<"STT"<<" | "<<"TEN HANG"<<" | "<<"DON VI TINH"<<" | "<<"SO LUONG"<<" | "<<fixed<<setprecision(0) << "DON GIA"<<" | "<<"THANH TIEN"<<"\n";
	for(int i=0;i<stt;i++){
		ds[i].hienthi();
	}
	cout<<fixed <<setprecious(0);
	cout<<"\nCong tien hang: "<<tongtien()<<endl;
	cout<<"Thue GTGT: "<<thue<<"%"<<endl;
	cout<<"Tien thue: "<<tienthue()<<endl;
}


