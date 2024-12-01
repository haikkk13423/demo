#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <iomanip>
using namespace std;













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
        cout << " 5. Nhắc nhở công việc hôm nay " << endl;
        cout << " 6. Thoát " << endl;
        cout << " Chọn: ";
        cin >> i;
        
        switch (i)
        {
            case 1: 
            case 2:
            case 3:
            case 4:
            case 5:
            case 6: 
            cout << " Cảm ơn vì đã sử dụng " << endl;
            break;
            default: 
            cout << " Lựa chọn không hợp lệ. Vui lòng thử lại." << endl;

        }
    }
    while (i!=6); 
}