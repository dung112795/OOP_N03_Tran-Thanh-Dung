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
		void nhap(int tt);
		double thanhtien() const;
		void hienthi() const;
		
};

SanPham::SanPham(): stt(0), tenhang(""), dvt(""), soluong(0), dongia(0) {}
SanPham::SanPham(int tt, string ten, string dv, int sl, double gia) : stt(tt), tenhang(ten), dvt(dv), soluong(sl), dongia(gia) {}

void SanPham::nhap(int tt){
	stt=tt;
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

double SanPham::thanhtien() const{
	return soluong*dongia;
} 

void SanPham::hienthi() const{
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
void KhachHang::hienthi() const{
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
        KhachHang kh;
};

HoaDon::HoaDon() : sohoadon(""), ngaymuahang(""), n(0), thue(0) {}
HoaDon::HoaDon(string sohd,string ngaymua) : sohoadon(sohd), ngaymuahang(ngaymua), n(0) , thue(0) {}

string HoaDon::lay_so_hd() const{
	return sohoadon;
}
void HoaDon::nhap() {
    cout << "\n==== NHAP HOA DON ====\n";

    cout << "So hoa don: ";
    getline(cin, sohoadon);

    cout << "Ngay mua hang: ";
    getline(cin, ngaymuahang);

    cout << "\n==== THONG TIN KHACH HANG ====\n";
    kh.nhap();

    n = 0;
    int chon;

    do {
        cout << "\n==== NHAP SAN PHAM THU " << n + 1 << " ====\n";

        ds[n].nhap(n + 1);
        n++;

        if(n == 100) {
            cout << "Da dat gioi han san pham!\n";
            break;
        }

        cout << "Ban co muon nhap tiep? (1.Co / 0.Khong): ";
        cin >> chon;
        cin.ignore();

    } while(chon == 1);

    cout << "Thue GTGT (%): ";
    cin >> thue;
    cin.ignore();
}
double HoaDon::tongtien() const{
	double tong=0;
	for(int i=0;i<n;i++){
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
void HoaDon::hienthi() const{
	cout<<"So hoa don: "<<sohoadon<<endl;
	cout<<"Ngay mua hang: "<<ngaymuahang<<endl;
	cout<<"\n====THONG TIN KHACH HANG ====\n";
	kh.hienthi();
	cout<<"\n====DANH SACH HANG HOA====\n";
	cout<<"  "<<"STT"<<" | "<<"TEN HANG"<<" | "<<"DON VI TINH"<<" | "<<"SO LUONG"<<" | "<<fixed<<setprecision(0) << "DON GIA"<<" | "<<"THANH TIEN"<<"\n";
	for(int i=0;i<n;i++){
		ds[i].hienthi();
	}
	cout<<fixed <<setprecision(0);
	cout<<"\nCong tien hang: "<<tongtien()<<endl;
	cout<<"Thue GTGT: "<<thue<<"%"<<endl;
	cout<<"Tien thue: "<<tienthue()<<endl;
    cout << "Tong thanh toan: " << tongthanhtoan() << endl;
}

class SystemInterface {
private:
    HoaDon ds[100];
    int n;

public:
    SystemInterface();
    void runMenu();
};
SystemInterface::SystemInterface() : n(0) {}
void SystemInterface::runMenu() {
    int chon;

    do {
        cout << "\n===== QUAN LY HOA DON =====\n";
        cout << "1. Tao hoa don\n";
        cout << "2. Hien thi tat ca hoa don\n";
        cout << "3. Tim kiem hoa don\n";
        cout << "4. Thoat\n";
        cout << "Chon: ";
        cin >> chon;
        cin.ignore();

        switch(chon) {
            case 1:
                if(n<100) {
                    ds[n].nhap();
                    n++;
                    cout<<"\nTao hoa don thanh cong\n";
                }
                else {
                    cout<<"Danh sach hoa don da day\n";
                }
                break;

            case 2:
                if(n == 0) {
                    cout<<"Chua co hoa don nao\n";
                }
                else {
                    for(int i=0;i<n;i++) {
                        cout<<"\n===== HOA DON THU " << i + 1 <<" =====\n";
                        ds[i].hienthi();
                    }
                }
                break;

            case 3: {
                string ma;
                bool timThay = false;

                cout <<"Nhap so hoa don can tim: ";
                getline(cin, ma);

                for(int i=0; i<n;i++) {
                    if(ds[i].lay_so_hd()==ma) {
                        ds[i].hienthi();
                        timThay = true;
                        break;
                    }
                }

                if(!timThay) {
                    cout<<"Khong tim thay hoa don\n";
                }
                break;
            }

            case 4:
                cout<<"Thoat chuong trinh\n";
                break;

            default:
                cout<<"Lua chon khong hop le\n";
        }

    }while(chon != 4);
}
int main(){
    SystemInterface sys;
    sys.runMenu();

    return 0;
}
