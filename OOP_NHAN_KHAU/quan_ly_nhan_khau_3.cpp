#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class NHAN_KHAU {
public:
    string Ten, GioiTinh, DanToc, QuocTich, NgheNghiep, SoCCCD, DiaChi;
    int NamSinh, Tuoi;
    bool LaHocSinh;

    // H�m kh?i t?o
    NHAN_KHAU() {
        LaHocSinh = false;
    }

    // H�m nh?p th�ng tin cho nh�n kh?u
    void NhapThongTin() {
        cout << "Nhap ten nhan khau: ";
        cin.ignore();
        getline(cin, Ten);
        cout << "Nhap gioi tinh (Nam/Nu): ";
        getline(cin, GioiTinh);
        cout << "Nhap nam sinh: ";
        cin >> NamSinh;
        Tuoi = 2024 - NamSinh;
        cin.ignore();
        cout << "Nhap dia chi: ";
        getline(cin, DiaChi);
        cout << "La hoc sinh (1/0): ";
        cin >> LaHocSinh;
        cout << "Nhap dan toc: ";
        cin.ignore();
        getline(cin, DanToc);
        cout << "Nhap quoc tich: ";
        getline(cin, QuocTich);
        cout << "Nhap nghe nghiep: ";
        getline(cin, NgheNghiep);
        cout << "Nhap so CCCD: ";
        getline(cin, SoCCCD);
    }

    // H�m hi?n th? th�ng tin nh�n kh?u
    void HienThiThongTin() const {
        cout << "Ten: " << Ten << ", Gioi tinh: " << GioiTinh << ", Nam sinh: " << NamSinh << ", Tuoi: " << Tuoi << ", Dia chi: " << DiaChi
            << ", La hoc sinh: " << (LaHocSinh ? "Co" : "Khong") << ", Dan toc: " << DanToc
            << ", Quoc tich: " << QuocTich << ", Nghe nghiep: " << NgheNghiep
            << ", So CCCD: " << SoCCCD << endl;
    }
};

class HO_GIA_DINH {
public:
    int SoThanhVien;
    string TenChuHo, GioiTinhChuHo, DanToc, QuocTich, NgheNghiep, SoCCCD, DiaChi;
    int NamSinhChuHo, TuoiChuHo;
    vector<NHAN_KHAU> DanhSachNhanKhau;

    // H�m nh?p th�ng tin cho h? gia ?�nh
    void NhapThongTin() {
        cout << "Nhap so thanh vien cua ho gia dinh: ";
        cin >> SoThanhVien;
        cin.ignore();
        cout << "Nhap ten chu ho: ";
        getline(cin, TenChuHo);
        cout << "Nhap gioi tinh chu ho (Nam/Nu): ";
        getline(cin, GioiTinhChuHo);
        cout << "Nhap nam sinh chu ho: ";
        cin >> NamSinhChuHo;
        TuoiChuHo = 2024 - NamSinhChuHo;
        cin.ignore();
        cout << "Nhap dia chi chu ho: ";
        getline(cin, DiaChi);
        cout << "Nhap dan toc chu ho: ";
        getline(cin, DanToc);
        cout << "Nhap quoc tich chu ho: ";
        getline(cin, QuocTich);
        cout << "Nhap nghe nghiep chu ho: ";
        getline(cin, NgheNghiep);
        cout << "Nhap so CCCD chu ho: ";
        getline(cin, SoCCCD);

        DanhSachNhanKhau.resize(SoThanhVien);
        for (size_t i = 0; i < DanhSachNhanKhau.size(); ++i) {
            NHAN_KHAU nhanKhau;
            nhanKhau.NhapThongTin();
            DanhSachNhanKhau[i] = nhanKhau;
        }
    }

    // H�m hi?n th? th�ng tin h? gia ?�nh
    void HienThiThongTin() const {
        cout << "Ho chu: " << TenChuHo << ", Gioi tinh chu ho: " << GioiTinhChuHo << ", So thanh vien: " << SoThanhVien
            << ", Nam sinh chu ho: " << NamSinhChuHo << ", Tuoi chu ho: " << TuoiChuHo
            << ", Dia chi chu ho: " << DiaChi << ", Dan toc chu ho: " << DanToc
            << ", Quoc tich chu ho: " << QuocTich << ", Nghe nghiep chu ho: " << NgheNghiep
            << ", So CCCD chu ho: " << SoCCCD << endl;

        cout << "Danh sach nhung thanh vien trong ho:" << endl;
        for (size_t i = 0; i < DanhSachNhanKhau.size(); ++i) {
            DanhSachNhanKhau[i].HienThiThongTin();
        }
    }
};

class KHU_PHO {
public:
    string TenKhuPho;
    vector<HO_GIA_DINH> DanhSachHoGiaDinh;

    // H�m t�nh t?ng d�n c? trong khu ph?
    int TinhTongDanCu() const {
        int tongDanCu = 0;
        for (size_t i = 0; i < DanhSachHoGiaDinh.size(); ++i) {
            tongDanCu += DanhSachHoGiaDinh[i].SoThanhVien;
        }
        return tongDanCu;
    }

    // Function declaration for the comparer function
    static bool SoLuongNhanKhauGiamDanComparer(const HO_GIA_DINH& ho1, const HO_GIA_DINH& ho2);

    // H�m s?p x?p danh s�ch h? gia ?�nh theo s? l??ng nh�n kh?u gi?m d?n
    void SapXepTheoSoLuongNhanKhauGiamDan();

    // H�m li?t k� c�c h? c� ch? h? l� nam 60 tu?i
    void LietKeChuHoNam60Tuoi() const;

    // H�m li?t k� danh s�ch c�c nh�n kh?u l� h?c sinh trong khu ph?
    void LietKeNhanKhauHocSinh() const;

    // H�m th�m h? gia ?�nh
    void ThemHoGiaDinh();

    // H�m s?a th�ng tin h? gia ?�nh
    void SuaThongTinHoGiaDinh();

    // H�m x�a h? gia ?�nh
    void XoaHoGiaDinh();

    // H�m hi?n th? menu
    void HienThiMenu();

    // H�m hi?n th? danh s�ch h? gia ?�nh
    void HienThiDanhSachHoGiaDinh() const;
};

// Function definition for the comparer function
bool KHU_PHO::SoLuongNhanKhauGiamDanComparer(const HO_GIA_DINH& ho1, const HO_GIA_DINH& ho2) {
    return ho1.SoThanhVien > ho2.SoThanhVien;
}

// H�m s?p x?p danh s�ch h? gia ?�nh theo s? l??ng nh�n kh?u gi?m d?n
void KHU_PHO::SapXepTheoSoLuongNhanKhauGiamDan() {
    sort(DanhSachHoGiaDinh.begin(), DanhSachHoGiaDinh.end(), SoLuongNhanKhauGiamDanComparer);
}

// H�m li?t k� c�c h? c� ch? h? l� nam 60 tu?i
void KHU_PHO::LietKeChuHoNam60Tuoi() const {
    cout << "Cac ho gia dinh co chu ho nam 60 tuoi:" << endl;
    for (size_t i = 0; i < DanhSachHoGiaDinh.size(); ++i) {
        if (DanhSachHoGiaDinh[i].TuoiChuHo >= 60 && DanhSachHoGiaDinh[i].GioiTinhChuHo == "Nam"&&"nam") {
            cout << "Ho chu: " << DanhSachHoGiaDinh[i].TenChuHo << ", Gioi tinh: " << DanhSachHoGiaDinh[i].GioiTinhChuHo
                 << ", Dia chi: " << DanhSachHoGiaDinh[i].DiaChi << endl;
        }
    }
}

// H�m li?t k� danh s�ch c�c nh�n kh?u l� h?c sinh trong khu ph?
void KHU_PHO::LietKeNhanKhauHocSinh() const {
    cout << "Danh sach cac nhan khau la hoc sinh:" << endl;
    for (size_t i = 0; i < DanhSachHoGiaDinh.size(); ++i) {
        for (size_t j = 0; j < DanhSachHoGiaDinh[i].DanhSachNhanKhau.size(); ++j) {
            if (DanhSachHoGiaDinh[i].DanhSachNhanKhau[j].LaHocSinh) {
                cout << "Ho chu: " << DanhSachHoGiaDinh[i].TenChuHo << ", Ten hoc sinh: " << DanhSachHoGiaDinh[i].DanhSachNhanKhau[j].Ten
                     << ", Dia chi: " << DanhSachHoGiaDinh[i].DanhSachNhanKhau[j].DiaChi << endl;
            }
        }
    }
}

// H�m th�m h? gia ?�nh
void KHU_PHO::ThemHoGiaDinh() {
    HO_GIA_DINH ho;
    cout << "Nhap thong tin cho ho gia dinh moi:" << endl;
    ho.NhapThongTin();
    DanhSachHoGiaDinh.push_back(ho);
}

// H�m s?a th�ng tin h? gia ?�nh
void KHU_PHO::SuaThongTinHoGiaDinh() {
    size_t index;
    cout << "Nhap vi tri ho gia dinh can sua (1 - " << DanhSachHoGiaDinh.size() << "): ";
    cin >> index;
    if (index >= 1 && index <= DanhSachHoGiaDinh.size()) {
        cout << "Nhap thong tin moi cho ho gia dinh:" << endl;
        DanhSachHoGiaDinh[index - 1].NhapThongTin();
    } else {
        cout << "Vi tri nhap vao khong hop le." << endl;
    }
}

// H�m x�a h? gia ?�nh
void KHU_PHO::XoaHoGiaDinh() {
    size_t index;
    cout << "Nhap vi tri ho gia dinh can xoa (1 - " << DanhSachHoGiaDinh.size() << "): ";
    cin >> index;
    if (index >= 1 && index <= DanhSachHoGiaDinh.size()) {
        DanhSachHoGiaDinh.erase(DanhSachHoGiaDinh.begin() + index - 1);
        cout << "Ho gia dinh da duoc xoa." << endl;
    } else {
        cout << "Vi tri nhap vao khong hop le." << endl;
    }
}

// H�m hi?n th? menu
void KHU_PHO::HienThiMenu() {
    cout << "----------------- MENU -----------------" << endl;
    cout << "1. Hien thi thong tin khu pho" << endl;
    cout << "2. Them ho gia dinh" << endl;
    cout << "3. Sua thong tin ho gia dinh" << endl;
    cout << "4. Xoa ho gia dinh" << endl;
    cout << "5. Tinh tong dan cu" << endl;
    cout << "6. Sap xep ho gia dinh theo so luong nhan khau giam dan" << endl;
    cout << "7. Liet ke chu ho nam 60 tuoi" << endl;
    cout << "8. Liet ke nhan khau la hoc sinh" << endl;
    cout << "0. Thoat" << endl;
    cout << "----------------------------------------" << endl;
}

// H�m hi?n th? danh s�ch h? gia ?�nh
void KHU_PHO::HienThiDanhSachHoGiaDinh() const {
    cout << "----------------- DANH SACH HO GIA DINH -----------------" << endl;
    for (size_t i = 0; i < DanhSachHoGiaDinh.size(); ++i) {
        cout << "Ho gia dinh " << i + 1 << ":" << endl;
        DanhSachHoGiaDinh[i].HienThiThongTin();
        cout << "--------------------------------------------------------" << endl;
    }
}

int main() {
    KHU_PHO khuPho;
    cout << "Nhap ten khu pho: ";
    getline(cin, khuPho.TenKhuPho);

    int luaChon;
    do {
        khuPho.HienThiMenu();
        cout << "Nhap lua chon (0-8): ";
        cin >> luaChon;
        switch (luaChon) {
        case 1:
            // Hien thi thong tin khu pho
            khuPho.HienThiDanhSachHoGiaDinh();
            break;
        case 2:
            // Them ho gia dinh
            khuPho.ThemHoGiaDinh();
            break;
        case 3:
            // Sua thong tin ho gia dinh
            khuPho.SuaThongTinHoGiaDinh();
            break;
        case 4:
            // Xoa ho gia dinh
            khuPho.XoaHoGiaDinh();
            break;
        case 5:
            // Tinh tong dan cu
            cout << "Tong so dan cu trong khu pho: " << khuPho.TinhTongDanCu() << endl;
            break;
        case 6:
            // Sap xep ho gia dinh theo so luong nhan khau giam dan
            khuPho.SapXepTheoSoLuongNhanKhauGiamDan();
            cout << "Danh sach ho gia dinh sau khi sap xep:" << endl;
            khuPho.HienThiDanhSachHoGiaDinh();
            break;
        case 7:
            // Liet ke chu ho nam 60 tuoi
            khuPho.LietKeChuHoNam60Tuoi();
            break;
        case 8:
            // Liet ke nhan khau la hoc sinh
            khuPho.LietKeNhanKhauHocSinh();
            break;
        case 0:
            // Thoat chuong trinh
            cout << "Cam on da su dung chuong trinh. Hen gap lai!" << endl;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
        }
        cout << "----------------------------------------" << endl;
    } while (luaChon != 0);

    return 0;
}

