#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <iomanip>
using namespace std;

const int Max_Cong_Viec = 100;
int ids[Max_Cong_Viec];
string tenCongViec[Max_Cong_Viec];
string moTA[Max_Cong_Viec];
time_t Thoigian[Max_Cong_Viec];
int uuTien[Max_Cong_Viec];
int soluongCongViec = 0;
int day, month, year, hour, minute;
int id = 1;

void them_Cong_Viec() {
    cout << " Bạn đã chọn tạo công việc mới "<< endl;
    if (soluongCongViec >= Max_Cong_Viec) {
        cout << "Danh sách đầy." << endl;
        return;
    }

    ids[soluongCongViec] = id++;
    cout << "Nhập tên công việc: ";
    cin.ignore();
    getline(cin, tenCongViec[soluongCongViec]);
    cout << "Nhập mô tả: ";
    getline(cin, moTA[soluongCongViec]);
    cout << "Nhập thời gian (Gio Phut Ngay Thang Nam): ";
    cin >> hour >> minute >> day >> month >> year;

    struct tm thoigianla = {0};
    thoigianla.tm_hour = hour;
    thoigianla.tm_min = minute;
    thoigianla.tm_mday = day;
    thoigianla.tm_mon = month - 1;
    thoigianla.tm_year = year - 1900;

    Thoigian[soluongCongViec] = mktime(&thoigianla);
    if (Thoigian[soluongCongViec] == -1) {
        cout << "Lỗi thời gian. Không thể tạo công việc." << endl;
        return;
    }
    cout << "Công việc được tạo với ID: " << ids[soluongCongViec] << endl;
    soluongCongViec++;
    cout << " Chúc bạn sớm hoàn thành công việc nhé <3 " << endl;
}

void hien_thi() {
    cout << " Bạn đã chọn hiện thị danh sách công việc "<< endl;
    if (soluongCongViec == 0) {
        cout << "Danh sách công việc trống." << endl;
        return;
    }

    for (int i = 0; i < soluongCongViec; i++) {
        cout << "ID: " << ids[i] << endl;
        cout << "Tên công việc: " << tenCongViec[i] << endl;
        cout << "Mô tả: " << moTA[i] << endl;

        char buffer[80];
        struct tm *thoigianla = localtime(&Thoigian[i]);
        strftime(buffer, 80, "%H:%M, %d-%m-%Y ", thoigianla);
        cout << "Thời gian: " << buffer << endl;
        cout << "------------------------" << endl;
        cout << " Chúc bạn sớm hoàn thành công việc nhé <3 " << endl;

    }
}

void suacongviec() {
    cout << " Bạn đã chọn sửa công việc "<< endl;
    for (int i = 0; i < soluongCongViec; i++) {
        cout << "ID: " << ids[i] << endl;
        cout << "Tên công việc: " << tenCongViec[i] << endl;
        cout << "Mô tả: " << moTA[i] << endl;

        char buffer[80];
        struct tm *thoigianla = localtime(&Thoigian[i]);
        strftime(buffer, 80, "%H:%M, %d-%m-%Y ", thoigianla);
        cout << "Thời gian: " << buffer << endl;
        cout << "------------------------" << endl;
    }
    cout << "Nhập ID công việc cần sửa: ";
    int id2;
    cin >> id2;
    int id3 = -1;
    for (int i = 0; i < soluongCongViec; i++) {
        if (ids[i] == id2) {
            id3 = i;
            break;
        }
    }

    if (id3 != -1) {
        cout << "Nhập tên công việc mới: ";
        cin.ignore();  /* bỏ qua các ký tự không cần thiết trong bộ 
        đệm đầu vào, đặc biệt là ký tự xuống dòng.*/
        getline(cin, tenCongViec[id3]);

        cout << "Nhập mô tả công việc mới: ";
        getline(cin, moTA[id3]);
// nhập cái gì đó vào từ cin xong lưu vào mảng moTa
        cout << "Nhập thời gian mới (Gio Phut Ngay Thang Nam): ";
        cin >> hour >> minute >> day >> month >> year;

        struct tm thoigianla = {0};
        thoigianla.tm_hour = hour; 
        thoigianla.tm_min = minute;
        thoigianla.tm_mday = day;
        thoigianla.tm_mon = month - 1;
        thoigianla.tm_year = year - 1900;

        Thoigian[id3] = mktime(&thoigianla);
        cout << "Công việc đã được cập nhật." << endl;
        cout << " Chúc bạn sớm hoàn thành công việc nhé <3 " << endl;
    } else {
        cout << "Không tìm thấy công việc với ID " << id2 << endl;
        
    }
}

void xoaCongViec() {
    cout << " Bạn đã chọn xóa công việc " << endl;
    for (int i = 0; i < soluongCongViec; i++) {
        cout << "ID: " << ids[i] << endl;
        cout << "Tên công việc: " << tenCongViec[i] << endl;
        cout << "Mô tả: " << moTA[i] << endl;

        char buffer[80];
        struct tm *thoigianla = localtime(&Thoigian[i]);
        strftime(buffer, 80, "%H:%M, %d-%m-%Y ", thoigianla);
        cout << "Thời gian: " << buffer << endl;
        cout << "------------------------" << endl;
    }
    cout << "Nhập id công việc cần xóa: ";
    int id;
    cin >> id;
    
    int id3 = -1;
    for (int i = 0; i < soluongCongViec; i++) {
        if (ids[i] == id) {
            id3 = i;
            break;
        }
    }
    
    if (id3 != -1) {
        for (int i = id3; i < soluongCongViec - 1; i++) {
            ids[i] = ids[i + 1];
            tenCongViec[i] = tenCongViec[i + 1];
            moTA[i] = moTA[i + 1];
            Thoigian[i] = Thoigian[i + 1];
        }
        soluongCongViec--;
        cout << "Công việc đã được xóa." << endl;
        cout << " Chúc bạn sớm hoàn thành công việc nhé <3 " << endl;
    } else {
        cout << "Không tìm thấy công việc với id " << id << endl;
    }
}


// ... (giữ nguyên phần khai báo và các hàm khác)

void hienThiNhacNho() {
    cout << "Bạn đã chọn hiển thị thông báo nhắc nhở" << endl;
    time_t hienTai = time(0);
    bool coNhacNho = false;

    for (int i = 0; i < soluongCongViec; i++) {
        double khoangCach = difftime(Thoigian[i], hienTai);
        if (khoangCach > 0 && khoangCach <= 24 * 3600) { // Trong vòng 24 giờ tới
            char buffer[80];
            struct tm *thoigianla = localtime(&Thoigian[i]);
            strftime(buffer, 80, "%H:%M, %d-%m-%Y", thoigianla);
            
            cout << "Nhắc nhở: Công việc sắp đến hạn!" << endl;
            cout << "ID: " << ids[i] << endl;
            cout << "Tên công việc: " << tenCongViec[i] << endl;
            cout << "Thời gian: " << buffer << endl;
            cout << "------------------------" << endl;
            coNhacNho = true;
        }
    }

    if (!coNhacNho) {
        cout << "Không có công việc nào cần nhắc nhở trong 24 giờ tới." << endl;
    }
}

int main() 
{
    int i;
    do 
    {
        cout << " ====================Ứng Dụng Lập Công Việc=====================" << endl;
        cout << " 1. Tạo công việc " << endl;
        cout << " 2. Hiển thị danh sách công việc " << endl;
        cout << " 3. Sửa công việc " << endl;
        cout << " 4. Xóa công việc " << endl;
        cout << " 5. Hiển thị thông báo nhắc nhở " << endl;
        cout << " 6. Thoát " << endl;
        cout << " Chọn: ";
        cin >> i;
 
        switch (i)
        {
            case 1: 
                them_Cong_Viec();
                break;
            case 2:
                hien_thi();
                break;
            case 3:
                suacongviec();
                break;
            case 4:
                xoaCongViec();
                break;
            case 5:
                hienThiNhacNho();
                break;
            case 6: 
                cout << " Cảm ơn vì đã sử dụng " << endl;
                cout << " Hẹn gặp lại nhé !! " << endl;
                break;
            default: 
                cout << " Lựa chọn không hợp lệ. Vui lòng thử lại." << endl;
        }
    }
    while (i!=6); 
}
helllo
