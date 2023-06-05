#include <iostream>
#include <stdio.h>
#include <string>
#include <stdint.h>
#include <vector>
#include <string.h>

using namespace std;
#define INPUT(text, var, Condition) \
    do                              \
    {                               \
        cout << text;               \
        cin >> var;                 \
    } while (Condition == 0);
#define CHECK_INPUT(condition, text, status) \
    if (condition)                           \
    {                                        \
        cout << text;                        \
        status;                              \
    }
typedef enum
{
    NAM,
    NU
} GioiTinh;

typedef enum
{
    GIOI,
    KHA,
    TRUNG_BINH,
    YEU
} HocLuc;
typedef enum
{
    TEN,
    TUOI,
    GIOI_TINH,
    DIEM
} Object;
/*
 * Function: Class SinhVien
 * Description: The class represents the properties and methods of the student
 * Input:
 *    None
 * Output:
 *    None
 */
class SinhVien
{
private:
    uint8_t ID;
    string NAME;
    int TUOI;
    float DIEM_TOAN;
    float DIEM_LY;
    float DIEM_HOA;
    GioiTinh GIOI_TINH;

public:
    SinhVien(string name, GioiTinh gioitinh, int tuoi, float diemtoan, float diemly, float diemhoa);
    void setTen(string ten);
    string getTen();
    void setGioiTinh(GioiTinh gioitinh);
    GioiTinh getGioiTinh();
    void setTuoi(int tuoi);
    int getTuoi();
    void setDiemToan(float diemtoan);
    float getDiemToan();
    void setDiemLy(float diemly);
    float getDiemLy();
    void setDiemHoa(float diemhoa);
    float getDiemHoa();
    uint8_t getId();
    float DiemTrungBinh();
    HocLuc HocLuc();
};

/*
 * Function: Constructor SinhVien
 * Description: import parameters to the object of the class HocSinh( name , gioiTinh, tuoi, diemtoan, diemly, diem hoa)
 * Input:
 *    name: string
 *    gioiTinh: TypeGioiTinh
 *    tuoi: int
 *    diemtoan: float
 *    diemly: float
 *    diemhoa: float
 * Output:
 *    None
 */
SinhVien::SinhVien(string name, GioiTinh gioitinh, int tuoi, float diemtoan, float diemly, float diemhoa)
{
    static uint8_t id = 1;
    SinhVien::ID = id;
    SinhVien::NAME = name;
    SinhVien::TUOI = tuoi;
    SinhVien::DIEM_TOAN = diemtoan;
    SinhVien::DIEM_LY = diemly;
    SinhVien::DIEM_HOA = diemhoa;
    SinhVien::GIOI_TINH = gioitinh;
    id++;
}

/*
 * Function: SinhVien::setTen()
 * Description: set name for object
 * Input:
 *    ten: string
 * Output:
 *    none
 */
void SinhVien::setTen(string ten)
{
    this->NAME = ten;
}

/*
 * Function: SinhVien::getTen()
 * Description: use to get name
 * Input:
 *    none
 * Output:
 *    return name in type of string
 */
string SinhVien::getTen()
{
    return SinhVien::NAME;
}

/*
 * Function: SinhVien::setGioiTinh()
 * Description: set sex for object
 * Input:
 *    gioitinh: TypeGioiTinh
 * Output:
 *    none
 */
void SinhVien::setGioiTinh(GioiTinh gioitinh)
{
    this->GIOI_TINH = gioitinh;
}

/*
 * Function: SinhVien::getGioiTinh()
 * Description: use to get sex
 * Input:
 *    none
 * Output:
 *    return sex in type of TypeGioiTinh
 */
GioiTinh SinhVien::getGioiTinh()
{
    return SinhVien::GIOI_TINH;
}

/*
 * Function: SinhVien::setTuoi()
 * Description: set age for object
 * Input:
 *    tuoi: int
 * Output:
 *    none
 */
void SinhVien::setTuoi(int tuoi)
{
    this->TUOI = tuoi;
}

/*
 * Function: SinhVien::getTuoi()
 * Description: use to get age
 * Input:
 *    none
 * Output:
 *    return age in type of int
 */
int SinhVien::getTuoi()
{
    return SinhVien::TUOI;
}

/*
 * Function: SinhVien::DiemTrungBinh()
 * Description: use to get average scores of 3 subjects
 * Input:
 *    none
 * Output:
 *    return average scores in type of float
 */
float SinhVien::DiemTrungBinh()
{

    return (SinhVien::DIEM_TOAN + SinhVien::DIEM_LY + SinhVien::DIEM_HOA) / 3;
}

/*
 * Function: SinhVien::setDiemToan()
 * Description: set math scores for object
 * Input:
 *    diemtoan: float
 * Output:
 *    none
 */
void SinhVien::setDiemToan(float diemtoan)
{
    this->DIEM_TOAN = diemtoan;
}

/*
 * Function: SinhVien::getDiemToan()
 * Description: use to get math scores
 * Input:
 *    none
 * Output:
 *    return math scores in type of float
 */
float SinhVien::getDiemToan()
{
    return this->DIEM_TOAN;
}

/*
 * Function: SinhVien::setDiemLy()
 * Description: set diem ly for object
 * Input:
 *    diemly: float
 * Output:
 *    none
 */
void SinhVien::setDiemLy(float diemly)
{
    this->DIEM_LY = diemly;
}

/*
 * Function: SinhVien::getDiemLy()
 * Description: use to get diem ly
 * Input:
 *    none
 * Output:
 *    return diem ly in type of float
 */
float SinhVien::getDiemLy()
{
    return this->DIEM_LY;
}

/*
 * Function:  SinhVien::setDiemHoa()
 * Description: set diem hoa for object
 * Input:
 *    diemhoa: float
 * Output:
 *    none
 */
void SinhVien::setDiemHoa(float diemhoa)
{
    this->DIEM_HOA = diemhoa;
}

/*
 * Function: SinhVien::getDiemHoa()
 * Description: use to get diem hoa scores
 * Input:
 *    none
 * Output:
 *    return diem hoa in type of float
 */
float SinhVien::getDiemHoa()
{
    return this->DIEM_HOA;
}

/*
 * Function: SinhVien::HocLuc()
 * Description: use to get academic ability of students
 * Input:
 *    none
 * Output:
 *    return academic ability in type of TypeHocLuc
 */
HocLuc SinhVien::HocLuc()
{
    if (SinhVien::DiemTrungBinh() >= 8.5)
        return GIOI;
    else if (SinhVien::DiemTrungBinh() >= 6.5)
        return KHA;
    else if (SinhVien::DiemTrungBinh() >= 5)
        return TRUNG_BINH;
    else
        return YEU;
}

/*
 * Function: SinhVien::getId()
 * Description: use to get Id of students
 * Input:
 *    none
 * Output:
 *    return Id in type of uint8_t
 */
uint8_t SinhVien::getId()
{
    return SinhVien::ID;
}

/*
 * Function: Class Option
 * Description: The class represents the properties and methods of the menu
 * Input:
 *    None
 * Output:
 *    None
 */
class Option
{
private:
    vector<SinhVien> Listsv;
    int checkInput(void *value, Object object);

public:
    Option();
    void nhapthongtinsv();
    void addsinhvien();
    void updateInfobyid();
    void deletesinhvien();
    void findsinhvien();
    void sapxepGPA();
    void sapxepTen();
    void hienthisinhvien();
};
Option::Option() {}
/*
 * Function: Option::addsinhvien()
 * Description: The method has the function add students in ascending
 * Input:
 *   none
 * Output:
 *    show the result
 */
int Option::checkInput(void *value, Object object)
{
    uint8_t check = 1;
    switch (object)
    {
    case TEN:
        break;
    case TUOI:
        CHECK_INPUT(*(int *)value < 1 || *(int *)value > 80, "ERROR: Tuoi khong hop le, vui long nhap lai\n", check = 0);
        break;
    case GIOI_TINH:
        CHECK_INPUT(*(string *)value != "NAM" && *(string *)value != "NU", "ERROR: Gioi Tinh khong hop le, vui long nhap lai\n", check = 0);
        break;
    case DIEM:
        CHECK_INPUT(*(float *)value < 0 || *(float *)value > 10, "Error: Diem khong hop le, vui long nhap lai\n", check = 0);
        break;
    default:
        check = 0;
        break;
    }
    return check;
};
void Option::nhapthongtinsv()
{
    string hoten;
    int tuoi;
    float diemtoan;
    float diemly;
    float diemhoa;
    string _gt;
    GioiTinh gt;
    HocLuc loai;
    string exit;
    SinhVien sv(hoten, gt, tuoi, diemtoan, diemly, diemhoa);

    INPUT("Nhap Ten: ", hoten, Option::checkInput(&hoten, TEN));
    sv.setTen(hoten);
    INPUT("Gioi tinh(NAM/NU): ", _gt, Option::checkInput(&_gt, GIOI_TINH));
    sv.setGioiTinh(_gt == "NAM" ? NAM : NU);
    INPUT("So tuoi: ", tuoi, Option::checkInput(&tuoi, TUOI));
    sv.setTuoi(tuoi);
    INPUT("Nhap Diem Toan: ", diemtoan, Option::checkInput(&diemtoan, DIEM));
    sv.setDiemToan(diemtoan);
    INPUT("Nhap Diem Ly: ", diemly, Option::checkInput(&diemly, DIEM));
    sv.setDiemLy(diemly);
    INPUT("Nhap Diem Hoa: ", diemhoa, Option::checkInput(&diemhoa, DIEM));
    sv.setDiemHoa(diemhoa);
    Listsv.push_back(sv);
}

void Option::addsinhvien()
{
    int exit = 0;
    while (1)
    {
        if (Option::Listsv.size() > 0)
        {
            cout << "Ban co muon tiep tuc khong: \n '0' de thoat \n '1' de tiep tuc" << endl;
            cin >> exit;
            if (exit == 0)
                return;
        }
        nhapthongtinsv();
    }
}
/*
 * Function: Option::updateInfobyid()
 * Description: The method has the function update students in ascending  by id
 * Input:
 *    id
 * Output:
 *    show the result
 */
void Option::updateInfobyid()
{
    int id;
    cout << "Nhap id sinh vien can cap nhat";
    cin >> id;
    int i = 0;
    int checkid = 0;
    for (int i = 0;i < Listsv.size(); i++)
    {
        SinhVien &sv = Listsv[i];
        {
            if (sv.getId() == id)
            {
                Listsv.erase(Listsv.begin() + i);
                Option::nhapthongtinsv();
                cout << "--Ban da cap nhat thong tin sinh vien thanh cong--" << endl;
            }

            checkid++;
        }
    }

    if (checkid == 0)
        cout << "--Khong co thong tin sinh vien trong Data--" << endl;
}
/*
 * Function: Option::deletesinhvien()
 * Description: The method has the function delete students in ascending  by id
 * Input:
 *    id
 * Output:
 *    show the result
 */
void Option::deletesinhvien()
{
    int id;
    cout << "Nhap id sinh vien can xoa";
    cin >> id;
    for (int i = 0; i < Listsv.size(); i++)
    {
        SinhVien &sv = Listsv[i];
        if (sv.getId() == id)
        {
            Listsv.erase(Listsv.begin() + i);
            printf("............................Complete!!.............................\n");
            return;
        }
        printf("Not found ID!!");
    }
}
/*
 * Function: Option::findsinhvien()
 * Description: The method has the function offind students in ascending  by id
 * Input:
 *   id
 * Output:
 *    show the result
 */
void Option::findsinhvien()
{
    int id;
    cout << "Nhap id sinh vien can tim";
    cin >> id;
    for (int i = 0; i < Listsv.size(); i++) // lặp qua danh sách sinh viên
    {
        SinhVien &sv = Listsv[i];
        if (sv.getId() == id) // nếu id sinh viên trùng khớp
        {
            // xuất thông tin ra màn hình
            printf("thong tin cua sinh vien co %d\n", id);
            printf("ID\t Ten\t gtinh\t tuoi\t toan\t ly\t hoa\t gpa\t Xeploai\t \n");
            printf("%d\t %s\t %s\t %d\t %.2lf\t %.2lf\t %.2lf\t %.2lf\t %s\t \n", sv.getId(), sv.getTen(), sv.getGioiTinh(), sv.getTen(), sv.getDiemToan(),
                   sv.getDiemLy(), sv.getDiemHoa(), sv.DiemTrungBinh(), sv.HocLuc());
        }
        else
            printf("Not found ID!!");
    }
}
/*
 * Function: Option::sapxepGPA()
 * Description: The method has the function of sorting students in ascending order by GPA
 * Input:
 *    none
 * Output:
 *    show the result
 */
void Option::sapxepGPA()
{
    for (int i = 0; i < Listsv.size(); i++) // lặp qua danh sách sinh viên
    {
        for (int j = i + 1; j < Listsv.size(); j++)
        {
            if (Listsv[i].DiemTrungBinh() > Listsv[j].DiemTrungBinh())
            {
                Listsv.push_back(Listsv[i]);
                Listsv[i] = Listsv[j];
                Listsv[j] = Listsv[Listsv.size()];
                Listsv.pop_back();
            }
        }
    }
    cout << " Da sap xep xong ";
}
/*
 * Function: Option::sapxepTen()
 * Description: The method has the function of sorting students in ascending order by Name
 * Input:
 *    none
 * Output:
 *    show the result
 */
void Option::sapxepTen()
{

    for (int i = 0; i < Listsv.size(); i++) // lặp qua danh sách sinh viên
    {
        for (int j = i + 1; j < Listsv.size(); j++)
        {
            if (Listsv[i].getTen() > Listsv[j].getTen())
            {
                Listsv.push_back(Listsv[i]);
                Listsv[i] = Listsv[j];
                Listsv[j] = Listsv[Listsv.size()];
                Listsv.pop_back();
            }
        }
    }
    cout << " Da sap xep xong ";
}
/*
 * Function: Option::hienthisinhvien()
 * Description: The method has the function of show students
 * Input:
 *    none
 * Output:
 *    show the result
 */
void Option::hienthisinhvien()
{
    printf("\nID\tTEN\t\tGIOITINH\tTUOI\tTOAN\tLY\tHOA\tGPA\tHOCLUC\n");
    for (SinhVien sv : Listsv)
    {
        string s_GioiTinh;
        string s_HocLuc;
        string name = sv.getTen();
        if (sv.getGioiTinh() == NAM)
            s_GioiTinh = "Nam";
        else
            s_GioiTinh = "Nu";

        if (sv.HocLuc() == GIOI)
            s_HocLuc = "Gioi";
        else if (sv.HocLuc() == KHA)
            s_HocLuc = "Kha";
        else if (sv.HocLuc() == TRUNG_BINH)
            s_HocLuc = "Tr.Binh";
        else
            s_HocLuc = "Yeu";
        printf("|  %-3d|  %-15s|  %-9s|  %-6d| %-6.2f| %-6.2f|  %-6.2f|  %-6.2f|  %-9s|\n", sv.getId(), sv.getTen().c_str(), s_GioiTinh.c_str(), sv.getTuoi(), sv.getDiemToan(), sv.getDiemLy(), sv.getDiemHoa(), sv.DiemTrungBinh(), s_HocLuc.c_str());
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{

    Option mn;
    int option;
    do
    {
        cout << "1. Them sinh vien" << endl;
        cout << "2. Cap nhat thong tin" << endl;
        cout << "3. Xoa thong tin sinh vien" << endl;
        cout << "4. Tim kiem sinh vien" << endl;
        cout << "5. Sap xep sinh vien theo diem GPA" << endl;
        cout << "6. Sap xep sinh vien theo ten" << endl;
        cout << "7. Hien thi sinh vien" << endl;
        cout << "8. Ket thuc chuong trinh" << endl;
        cout << "Nhap lua chon cua ban: " << endl;
        cin >> option;

        switch (option)
        {
        case 1:
            mn.addsinhvien();
            break;
        case 2:
            mn.updateInfobyid();
            break;
        case 3:
            mn.deletesinhvien();
            break;
        case 4:
            mn.findsinhvien();
            break;
        case 5:
            mn.sapxepGPA();
            break;
        case 6:
            mn.sapxepTen();
            break;
        case 7:
            mn.hienthisinhvien();
            break;
        case 8:
            printf("Exit!!!!!!!!!!!\n");
            break;

        default:
            printf("Error please enter\n");
            break;
        }
    } while (option != 8);
    return 0;
}
