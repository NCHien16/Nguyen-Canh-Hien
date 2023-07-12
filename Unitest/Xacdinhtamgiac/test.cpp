#include "pch.h"
enum LoaiTamGiac {
    TamGiacKhongTonTai,
    TamGiacDeu,
    TamGiacCan,
    TamGiacVuong,
    TamGiacThuong
};

LoaiTamGiac XacDinhLoaiTamGiac(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return TamGiacKhongTonTai;
    }

    if (a == b && b == c) {
        return TamGiacDeu;
    }

    if (a == b || b == c || c == a) {
        return TamGiacCan;
    }

    double maxSide = std::max(a, std::max(b, c));
    double sumSquares = a * a + b * b + c * c;

    if (2 * maxSide * maxSide == sumSquares) {
        return TamGiacVuong;
    }

    return TamGiacThuong;
}
TEST(LoaiTamGiac, XacDinhLoaiTamGia) {
  LoaiTamGiac tamgiac =    XacDinhLoaiTamGiac(1, 0, 0);
  EXPECT_EQ(tamgiac, TamGiacKhongTonTai);
  tamgiac = XacDinhLoaiTamGiac(0, 1, 0);
  EXPECT_EQ(tamgiac, TamGiacKhongTonTai);
  tamgiac = XacDinhLoaiTamGiac(0, 0, 1);
  EXPECT_EQ(tamgiac, TamGiacKhongTonTai);

}
TEST(LoaiTamGiac, XacDinhLoaiTamGia2) {
    LoaiTamGiac tamgiac = XacDinhLoaiTamGiac(1, 1, 1);
    EXPECT_EQ(tamgiac, TamGiacDeu);
}
TEST(LoaiTamGiac, XacDinhLoaiTamGia3) {
    LoaiTamGiac tamgiac = XacDinhLoaiTamGiac(1, 1, 2);    
    EXPECT_EQ(tamgiac, TamGiacCan);
    tamgiac = XacDinhLoaiTamGiac(3, 3, 1);
    EXPECT_EQ(tamgiac, TamGiacCan);
}
TEST(LoaiTamGiac, XacDinhLoaiTamGia4) {
    LoaiTamGiac tamgiac = XacDinhLoaiTamGiac(3,4,5);
    EXPECT_EQ(tamgiac, TamGiacVuong);
}
TEST(LoaiTamGiac, XacDinhLoaiTamGia5) {
    LoaiTamGiac tamgiac = XacDinhLoaiTamGiac(1, 2, 3);
    EXPECT_EQ(tamgiac, TamGiacThuong);
}
