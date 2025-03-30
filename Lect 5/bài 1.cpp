#include<iostream>

using namespace std;

const int N = 1000; // Số lượng node tối đa

struct treeNode {
    int data;
    treeNode* firstChild; // Con đầu tiên
    treeNode* nextSibling; // Anh em kế tiếp
    treeNode(int val) :data(val), firstChild(nullptr), nextSibling(nullptr) {} // Constructor
};

class Tree {
public:
    treeNode* root; // Gốc của cây
    treeNode* nodeList[N]; // Danh sách các node
    bool isChild[N]; // Đánh dấu node nào là con của node khác

    Tree() :root(nullptr) {
        for (int i = 0; i < N; i++) {
            nodeList[i] = nullptr;
            isChild[i] = false;
        }
    }

    void updateRoot() { // Tìm node gốc của cây
        for (int i = 0; i < N; i++) {
            if (nodeList[i] != nullptr && !isChild[i]) {
                root = nodeList[i];
                return;
            }
        }
    }

    void addChild(int parent, int child) { // Thêm cạnh giữa parent và child
        if (!nodeList[parent]) nodeList[parent] = new treeNode(parent); // Tạo node parent nếu chưa có
        if (!nodeList[child]) nodeList[child] = new treeNode(child); // Tạo node child nếu chưa có
        treeNode* parentNode = nodeList[parent];
        treeNode* childNode = nodeList[child];

        if (parentNode->firstChild == nullptr) { // Nếu parent chưa có con, gán con đầu tiên
            parentNode->firstChild = childNode;
        }
        else { // Nếu đã có con, tìm vị trí cuối cùng trong danh sách anh em
            treeNode* tmp = parentNode->firstChild;
            while (tmp->nextSibling != nullptr) {
                tmp = tmp->nextSibling;
            }
            tmp->nextSibling = childNode; // Thêm child vào cuối danh sách anh em
        }
        isChild[child] = true; // Đánh dấu node này là con
    }

    int getHeight(treeNode* node) { // Tính chiều cao của cây
        if (node == nullptr) {
            return 0;
        }
        int maxChildHeight = 0;
        treeNode* child = node->firstChild;
        while (child != nullptr) { // Duyệt tất cả các con
            maxChildHeight = max(maxChildHeight, getHeight(child));
            child = child->nextSibling;
        }
        return maxChildHeight + 1; // Chiều cao = max(chiều cao các con) + 1
    }

    void preorder(treeNode* node) { // Duyệt cây theo tiền thứ tự
        if (node == nullptr) {
            return;
        }
        cout << node->data << " "; // In giá trị node hiện tại
        treeNode* child = node->firstChild;
        while (child != nullptr) { // Duyệt qua tất cả các con
            preorder(child);
            child = child->nextSibling;
        }
    }

    void postorder(treeNode* node) { // Duyệt cây theo hậu thứ tự
        if (node == nullptr) {
            return;
        }
        treeNode* child = node->firstChild;
        while (child != nullptr) { // Duyệt qua tất cả các con trước
            postorder(child);
            child = child->nextSibling;
        }
        cout << node->data << " "; // In node sau khi đã duyệt hết con
    }

    bool isBinaryTree(treeNode* node) { // Kiểm tra xem cây có phải cây nhị phân không
        if (node == nullptr) {
            return true;
        }
        int childCount = 0;
        treeNode* child = node->firstChild;
        while (child != nullptr) { // Đếm số lượng con của node
            childCount++;
            if (childCount > 2) {
                return false; // Nếu có hơn 2 con, không phải cây nhị phân
            }
            child = child->nextSibling;
        }
        child = node->firstChild;
        while (child != nullptr) { // Kiểm tra tất cả các con
            if (!isBinaryTree(child)) {
                return false;
            }
            child = child->nextSibling;
        }
        return true;
    }

    void inorder(treeNode* node) { // Duyệt cây theo trung thứ tự (chỉ nếu là cây nhị phân)
        if (node == nullptr) {
            return;
        }
        treeNode* leftChild = node->firstChild; // Lấy con trái
        treeNode* rightChild = (leftChild) ? leftChild->nextSibling : nullptr; // Lấy con phải
        inorder(leftChild); // Duyệt con trái
        cout << node->data << " "; // In node gốc
        inorder(rightChild); // Duyệt con phải
    }

    void process() { // Xử lý và in kết quả
        if (root == nullptr) {
            return;
        }
        cout << getHeight(root) - 1 << endl; // In chiều cao cây (trừ 1 để đếm từ 0)
        preorder(root);
        cout << endl;
        postorder(root);
        cout << endl;
        if (isBinaryTree(root)) { // Nếu là cây nhị phân, duyệt trung thứ tự
            inorder(root);
            cout << endl;
        }
        else {
            cout << "NOT BINARY TREE" << endl; // Nếu không, in thông báo
        }
    }
};

int main() {
    int N, M;
    cin >> N >> M; // Nhập số node và số cạnh
    Tree tree;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        tree.addChild(u, v); // Thêm cạnh vào cây
    }
    tree.updateRoot(); // Xác định gốc cây
    tree.process(); // Thực hiện xử lý và in kết quả
    return 0;
}
