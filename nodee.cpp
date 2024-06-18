#include<bits/stdc++.h>
using namespace std;

struct Node{
    int x;
    Node* next;
};
typedef Node* node;
node taoNode(int data){   // phải khai báo node hay Node* vì hàm này đang muốn trả về cả giá trị lẫn  iterator .
    node tmp = new Node();                                                     // INT không thể trả về iterator.
    tmp -> x = data;
    tmp -> next = NULL;
    return tmp;
}
int Size(node head){ // đếm số lượng trong danh sách
    int dem = 0;
    while(head != NULL){
        ++dem;
        head = head -> next; // địa chỉ của node tiếp theo từ node hiện tại nhảy sang node tiếp theo
    }
    return dem;
}
void display(node head){ // in ra màn hình
    cout<<"-----------------------------------\n";
    cout<<"Danh sách liên kết: ";
    while(head != NULL){
        cout<< head -> x <<' ';// truy cập tới data để in ra data
        head =  head -> next; //  chuyển node kế tiếp
    }
    cout<<"-----------------------------------\n";
}
void themdau(node &head , int data){
    node moi = taoNode(data);
    if(head ==NULL){
        head = moi;
    }
    else{
        //B1 cập nhập phần tham chiếu;
        moi -> next = head;
        head = moi;
    }
}
void themcuoi(node &head , int data){
    node moi = taoNode(data);
    if(head == NULL){
        head = moi;
    }
    else{  //tmp node cũ
        node tmp = head;  // khai báo node tmp mới và gán nó là ở đầu
        while(tmp -> next != NULL){  // nếu next của tmp ko rỗng thì chuyển ra node kế tiếp
            tmp = tmp -> next;
        }
        tmp -> next = moi; // sau đó phần next của node cũ sẽ nối vào node mới
    }
}
void themgiua(node &head , int data , int vitri){
    int n = Size(head);
        if(vitri < 1 || vitri > n+1){
            cout<<"Vị trí chèn không hợp lệ !\n";
            return;
        }

        if(vitri == 1){ // nếu ở đầu
            themdau(head, data);
        }
        else{
            if(vitri == n+1){  // nếu ở cuối
                themcuoi(head,data);
            }
            else{
                node tmp = head;
                for(int  i = 1 ; i <= vitri -2 ; i++){
                    tmp = tmp -> next;
                }
                node moi = taoNode(data); // tạo một node mới
                moi -> next = tmp -> next; // đặt con trỏ next để xác định vị trí nó nằm ở đâu hiểu nôm na là đặt chồng lên 
                tmp -> next = moi; // sau đó gán vị trí đó =  node mới
            }
        }
    }
void xoadau(node &head){
    if(head == NULL){
        cout<<"Danh sách liên kết rỗng!\n";
        return;
    }
    else{
    node tmp = head;
    head = head->next;
    delete tmp;
    }
}
void xoacuoi(node &head) {
    if (head == NULL) { // Kiểm tra nếu danh sách rỗng
        cout << "Danh sách liên kết rỗng!\n";
        return;
    }

    if (head->next == NULL) { // Trường hợp danh sách chỉ có một phần tử
        delete head;
        head = NULL; // nghĩa là sau khi xóa phải gán nó bằng rỗng
        return;
    }

    node p = head, q = NULL;
    while (p->next != NULL) { // Duyệt đến node cuối cùng
        q = p;
        p = p->next;
    }

    delete p; // Xóa node cuối cùng
    q->next = NULL; // Cập nhật con trỏ next của node trước node cuối cùng thành NULL
}
void xoagiua(node &head, int pos) {
    int n = Size(head);
    if (pos < 1 || pos > n) { // nếu vi trí < 1 HOẶC > size thì break;
        printf("Vị trí xóa không hợp lệ!\n");
        return;
    }

    node p = head, q = NULL;
    for (int i = 1; i < pos; i++) { // Duyệt đến vị trí cần xóa
        q = p;
        p = p->next;
    }

    if (q != NULL){ // Kiểm tra nếu không phải là node đầu
        q->next = p->next;
    } 
    else{ // Nếu là node đầu
        head = head->next;
    }

    delete p; // Giải phóng bộ nhớ của node bị xóa
}
bool timkiem(node head , int value){
    while(head != NULL){
        if(head -> x == value){
            return true;
        }
        head = head -> next;
    }
    return false;
}
void sapxep(node &head){
    for(node i = head ; i != NULL ; i = i -> next){
        node min = i;
        for(node j = i -> next ; j != NULL; j = j -> next){
            if(j-> x < min -> x){
                min = j;
            }
        }
        int tmp = min -> x;
        min -> x = i-> x;
        i -> x =tmp; 
        // swap(min -> x , i -> x)
    }
}
int main(){
    node head = NULL;
    while(1){
        printf("----------------------MENU----------------------\n");
        cout<<"1. Thêm 1 node vào đầu danh sách liên kết\n";
        cout<<"2. Thêm 1 node vào cuối danh sách liên kết\n";
        cout<<"3. Chèn 1 node vào giữa của danh sách liên kết\n";
        cout<<"4. Xóa phần tử ở đầu danh sách liên kết\n";
        cout<<"5. Xóa phần tử ở cuối danh sách liên két\n";
        cout<<"6. Xóa phần tử ở giữa danh sách liên kết\n";
        cout<<"7. Tìm kiếm phần tử trong danh sách\n";
        cout<<"8. Sắp xếp phần tử trong danh sách tăng dần\n";
        cout<<"9. Hiển thị danh sách liên kết\n";
        cout<<"0. Kết thúc chương trình\n";
        cout<<"--------------------------------------------------\n";
        cout<<"Nhập lựa chọn: ";
        int n ; cin>>n;

        if(n == 1){
            int x;
            cout<<"Nhập giá trị cần thêm: ";cin>>x;
            themdau(head ,x);
        }
        else{
            if(n==2){
                int x;cout<<"Nhập giá trị cần thêm: ";cin>>x;
                themcuoi(head ,x);
            }
            else{
                if(n == 3){
                    int x;cout<<"Nhập giá trị cần thêm: ";cin>>x;
                    int pos;cout<<"Nhập vị trí cần chèn: ";cin>>pos;
                    themgiua(head,x,pos);
                }
                else{
                    if(n == 4){
                        xoadau(head);
                    }
                    else{
                        if(n == 5){
                           xoacuoi(head);
                        }
                        else{
                            if(n == 6){
                                int pos;
                                cout<<"Nhập vị trí cần xóa: ";cin>>pos;
                                xoagiua(head , pos);
                            }
                            else{
                                if(n == 7){
                                    int c ; 
                                    cout<<"Nhập giá trị cần tìm: ";cin>>c;
                                    if(timkiem(head , c)){
                                        cout<<"YES\n";
                                    }
                                    else{
                                        cout<<"NO\n";
                                    }
                                }
                                else{
                                    if(n == 8){
                                       sapxep(head);
                                    }
                                    else{
                                        if(n == 9){
                                        display(head);
                                        }
                                        else{
                                            if(n == 0){
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                           
                        }
                    }
                }
            }
        }
    }
}