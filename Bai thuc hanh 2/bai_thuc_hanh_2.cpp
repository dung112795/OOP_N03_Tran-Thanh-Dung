#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class phuong_tien {
private:
    int ma_xe;
    string loai_xe;
    int gio_vao;
    int tg_do;

public:
    phuong_tien();
    phuong_tien(int ma, string loai, int gio, int tg);

    int lay_ma_xe() const;
    string lay_loai_xe() const;
    double tinh_phi() const;
    void hien_thi() const;
};

phuong_tien::phuong_tien() : ma_xe(0), loai_xe(""), gio_vao(0), tg_do(0) {}

phuong_tien::phuong_tien(int ma, string loai, int gio, int tg)
    : ma_xe(ma), loai_xe(loai), gio_vao(gio), tg_do(tg) {}

int phuong_tien::lay_ma_xe() const { return ma_xe; }
string phuong_tien::lay_loai_xe() const { return loai_xe; }

double phuong_tien::tinh_phi() const {
    double gia = (loai_xe == "Car") ? 6.0 : (loai_xe == "Motorcycle") ? 4.0 : 2.0;
    bool cao_diem = (gio_vao >= 6 && gio_vao <= 9) || (gio_vao >= 15 && gio_vao <= 18);
    double tong = 0;
    for (int h = 0; h < tg_do; ++h) {
        if (h < 2) tong += gia * (cao_diem ? 1.30 : 0.95);
        else       tong += gia * 0.90;
    }
    return tong;
}

void phuong_tien::hien_thi() const {
    cout << "  ID: " << ma_xe << " | " << loai_xe
         << " | " << gio_vao << "h | " << tg_do << "h"
         << " | Phi: $" << fixed << setprecision(2) << tinh_phi() << "\n";
}

class bai_xe {
private:
    int ma_bai;
    char kich_thuoc;
    static const int max_xe=3;
    phuong_tien phuongTien[max_xe];
    int dem_xe;

public:
    bai_xe();
    bai_xe(int ma, char kt);

    bool full() const;
    bool them_xe(const phuong_tien& v);
    bool xoa_xe(int ma_xe);
    int tim_xe(int ma_xe) const;
    void in() const;
};

bai_xe::bai_xe() : ma_bai(0), kich_thuoc('S'), dem_xe(0) {}

bai_xe::bai_xe(int ma, char kt) : ma_bai(ma), kich_thuoc(kt),dem_xe(0) {}

bool bai_xe::full() const{
	int cap= (kich_thuoc=='S') ? 1 : (kich_thuoc=='M') ? 2 : 3;
	return dem_xe>=cap;
}
bool bai_xe::them_xe(const phuong_tien& v) {
    int cap = (kich_thuoc == 'S') ? 1 : (kich_thuoc == 'M') ? 2 : 3;
    if(dem_xe>=cap) return false;
    phuongTien[dem_xe]=v;
    dem_xe++;
    return true;
}

bool bai_xe::xoa_xe(int ma_xe) {
    int index= tim_xe(ma_xe);
    if(index=-1) return false;
    for(int i=index;i<dem_xe-1;i++){
    	phuongTien[i] = phuongTien[i+1];
	}
	dem_xe--;
	return true;
}
int bai_xe::tim_xe(int ma_xe) const{
	for(int i=0;i<dem_xe;i++){
		if(phuongTien[i].lay_ma_xe()==ma_xe)
			return i;
	}
	return -1;
}

void bai_xe::in() const {
    int cap = (kich_thuoc == 'S') ? 1 : (kich_thuoc == 'M') ? 2 : 3;
    int so_xe = dem_xe;
    cout << "Bai " << ma_bai << " [" << kich_thuoc << "] "
         << so_xe << "/" << cap << " xe\n";
	if(dem_xe==0)
		cout<<"\nBai xe trong";
	else{
		cout<<"\nDanh sach xe trong bai:\n";
		for(int i=0;i<dem_xe;i++){
			phuongTien[i].hien_thi();
		}
	}
	cout<<endl;
}


class SystemInterface {
private:
   	static const int Max_bai=10;
   	bai_xe baiXe[Max_bai];
   	int dem_bai=0;

public:
    void runMenu();
    bool bai_do_ton_tai(int ma_bai) const;
    bool pt_dang_do(int ma_xe) const;
    int sinh_ID();
};


bool SystemInterface::bai_do_ton_tai(int dem_bai) const{
	for(int i=0;i<dem_bai;i++){
		if(baiXe[i].lay_ma_bai()==ma_bai){
			return true;
		}
	}
	return false;
}
void SystemInterface::runMenu() {
    int chon;
    while (true) {
        cout << "\n===== QUAN LY BAI DO XE =====\n";
        cout << "1. Tao bai do\n";
        cout << "2. Them xe\n";
        cout << "3. Xoa bai do\n";
        cout << "4. Lay xe ra\n";
        cout << "5. Hien thi tat ca bai do\n";
        cout << "6. Hien thi xe theo bai\n";
        cout << "7. Liet ke xe theo loai\n";
        cout << "8. Bao cao phi trung binh\n";
        cout << "9. Thoat\n";
        cout << "Chon: ";
        cin >> chon;
        if (chon == 1) {
            int ma; char kt;
            cout << "Ma bai: "; cin >> ma;
            cout << "Kich thuoc (S/M/L): "; cin >> kt;
            if (!co1)      { bai1 = bai_xe(ma, kt); co1 = true; }
            else if (!co2) { bai2 = bai_xe(ma, kt); co2 = true; }
            else           { bai3 = bai_xe(ma, kt); co3 = true; }
            cout << "Da tao bai " << ma << "\n";
        }
        else if (chon == 2) {
            int ma, gio, tg; string loai;
            cout << "Ma xe: "; cin >> ma;
            cout << "Loai (Car/Motorcycle/Bicycle): "; cin >> loai;
            cout << "Gio vao (0-23): "; cin >> gio;
            cout << "Thoi luong (1-23): "; cin >> tg;
            phuong_tien v(ma, loai, gio, tg);
            bool ok = false;
            if (co1 && !ok) ok = bai1.them(v);
            if (co2 && !ok) ok = bai2.them(v);
            if (co3 && !ok) ok = bai3.them(v);
            if (ok) cout << "Da them xe " << ma << " | Phi: $" << fixed << setprecision(2) << v.tinh_phi() << "\n";
            else    cout << "Tat ca bai da day!\n";
        }
        else if (chon == 3) {
            int ma;
            cout << "Ma bai can xoa: "; cin >> ma;
            if (co1 && bai1.lay_ma() == ma) {
                if (co2) { bai1 = bai2; if (co3) { bai2 = bai3; co3 = false; } else co2 = false; }
                else co1 = false;
                cout << "Da xoa bai " << ma << "\n";
            }
            else if (co2 && bai2.lay_ma() == ma) {
                if (co3) { bai2 = bai3; co3 = false; } else co2 = false;
                cout << "Da xoa bai " << ma << "\n";
            }
            else if (co3 && bai3.lay_ma() == ma) {
                co3 = false;
                cout << "Da xoa bai " << ma << "\n";
            }
        }
        else if (chon == 4) {
            int ma;
            cout << "Ma xe can lay ra: "; cin >> ma;
            bool ok = false;
            if (co1 && !ok) ok = bai1.xoa(ma);
            if (co2 && !ok) ok = bai2.xoa(ma);
            if (co3 && !ok) ok = bai3.xoa(ma);
            cout << (ok ? "Da lay xe ra\n" : "Khong tim thay xe\n");
        }
        else if (chon == 5) {
            if (co1) bai1.hien_thi();
            if (co2) bai2.hien_thi();
            if (co3) bai3.hien_thi();
        }
        else if (chon == 6) {
            int ma;
            cout << "Ma bai: "; cin >> ma;
            if (co1 && bai1.lay_ma() == ma) bai1.hien_thi();
            else if (co2 && bai2.lay_ma() == ma) bai2.hien_thi();
            else if (co3 && bai3.lay_ma() == ma) bai3.hien_thi();
        }
        else if (chon == 7) {
            string loai;
            cout << "Loai xe: "; cin >> loai;
            int dem; double tong;
            if (co1 && bai1.co_loai(loai, dem, tong)) bai1.hien_thi();
            if (co2 && bai2.co_loai(loai, dem, tong)) bai2.hien_thi();
            if (co3 && bai3.co_loai(loai, dem, tong)) bai3.hien_thi();
        }
        else if (chon == 8) {
            string loai_arr[3] = {"Car", "Motorcycle", "Bicycle"};
            for (int t = 0; t < 3; ++t) {
                int dem = 0; double tong = 0;
                int d; double s;
                if (co1) { bai1.co_loai(loai_arr[t], d, s); dem += d; tong += s; }
                if (co2) { bai2.co_loai(loai_arr[t], d, s); dem += d; tong += s; }
                if (co3) { bai3.co_loai(loai_arr[t], d, s); dem += d; tong += s; }
                cout << loai_arr[t] << ": ";
                if (dem == 0) cout << "khong co xe\n";
                else cout << dem << " xe | TB: $" << fixed << setprecision(2) << tong / dem << "\n";
            }
        }
        else if (chon == 9) break;
    }
}

int main() {
    SystemInterface sys;
    sys.runMenu();
    return 0;
}
