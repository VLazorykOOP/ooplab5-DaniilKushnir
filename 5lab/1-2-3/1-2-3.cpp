/*#include <iostream>
#include <fstream>
#include <cstdlib>

class Pair {
protected:
    double first;
    double second;

public:
    Pair(double f = 0, double s = 0) : first(f), second(s) {
        std::cout << "Pair constructor called. (" << first << ", " << second << ")" << std::endl;
    }

    virtual ~Pair() {
        std::cout << "Pair destructor called. (" << first << ", " << second << ")" << std::endl;
    }

    void setPair(double f, double s) {
        first = f;
        second = s;
    }

    double calculateSum() const {
        return first + second;
    }
};

class Rectangle : public Pair {
public:
    Rectangle(double length = 0, double width = 0) : Pair(length, width) {
        std::cout << "Rectangle constructor called. (" << first << ", " << second << ")" << std::endl;
    }

    ~Rectangle() override {
        std::cout << "Rectangle destructor called. (" << first << ", " << second << ")" << std::endl;
    }

    double calculatePerimeter() const {
        return 2 * (first + second);
    }

    double calculateArea() const {
        return first * second;
    }
};

int main() {
    // Тестування класу Pair
    Pair pair;
    pair.setPair(3, 4);
    std::cout << "Sum of Pair: " << pair.calculateSum() << std::endl;

    // Тестування класу Rectangle
    Rectangle rectangle;
    rectangle.setPair(5, 6);
    std::cout << "Perimeter of Rectangle: " << rectangle.calculatePerimeter() << std::endl;
    std::cout << "Area of Rectangle: " << rectangle.calculateArea() << std::endl;

    // Тестування введення з клавіатури
    double length, width;
    std::cout << "Enter length and width for a rectangle: ";
    std::cin >> length >> width;
    Rectangle userRectangle(length, width);
    std::cout << "Perimeter of User Rectangle: " << userRectangle.calculatePerimeter() << std::endl;
    std::cout << "Area of User Rectangle: " << userRectangle.calculateArea() << std::endl;

    // Тестування введення з файлу
    std::ifstream inputFile("input.txt");
    if (inputFile.is_open()) {
        double fileLength, fileWidth;
        inputFile >> fileLength >> fileWidth;
        Rectangle fileRectangle(fileLength, fileWidth);
        std::cout << "Perimeter of File Rectangle: " << fileRectangle.calculatePerimeter() << std::endl;
        std::cout << "Area of File Rectangle: " << fileRectangle.calculateArea() << std::endl;
        inputFile.close();
    }
    else {
        std::cerr << "Unable to open input file." << std::endl;
    }

    // Тестування введення з використанням датчика випадкових чисел
    Rectangle randomRectangle(rand() % 10 + 1, rand() % 10 + 1);
    std::cout << "Perimeter of Random Rectangle: " << randomRectangle.calculatePerimeter() << std::endl;
    std::cout << "Area of Random Rectangle: " << randomRectangle.calculateArea() << std::endl;

    return 0;
}
*/

/*#include <iostream>
#include <cstdlib>

// Клас, що представляє вузол бінарного дерева
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    // Конструктор
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {
        std::cout << "Node created with data: " << data << std::endl;
    }

    // Деструктор
    ~TreeNode() {
        std::cout << "Node destroyed with data: " << data << std::endl;
    }
};

// Клас для представлення бінарного дерева
class BinaryTree {
private:
    TreeNode* root;

public:
    // Конструктор
    BinaryTree() : root(nullptr) {
        std::cout << "Binary Tree created." << std::endl;
    }

    // Деструктор
    ~BinaryTree() {
        // Викликаємо рекурсивну функцію для видалення всього дерева
        destroyTree(root);
        std::cout << "Binary Tree destroyed." << std::endl;
    }

    // Рекурсивна функція для видалення всього дерева
    void destroyTree(TreeNode* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    // Метод для вставки нового вузла в бінарне дерево
    void insertNode(int value) {
        root = insertRecursive(root, value);
    }

    // Рекурсивна функція для вставки вузла в піддерево
    TreeNode* insertRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        }
        else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }

        return node;
    }

    // Метод для обходу дерева в порядку "за шириною" (BFS)
    void breadthFirstTraversal() {
        if (root == nullptr) {
            std::cout << "Tree is empty." << std::endl;
            return;
        }

        std::cout << "Breadth-First Traversal:" << std::endl;
        breadthFirstTraversal(root);
        std::cout << std::endl;
    }

    // Рекурсивна функція для обходу дерева в порядку "за шириною"
    void breadthFirstTraversal(TreeNode* node) {
        if (node != nullptr) {
            std::cout << node->data << " ";
            breadthFirstTraversal(node->left);
            breadthFirstTraversal(node->right);
        }
    }
};

int main() {
    // Створення об'єкту бінарного дерева
    BinaryTree binaryTree;

    // Вставка вузлів
    binaryTree.insertNode(50);
    binaryTree.insertNode(30);
    binaryTree.insertNode(70);
    binaryTree.insertNode(20);
    binaryTree.insertNode(40);
    binaryTree.insertNode(60);
    binaryTree.insertNode(80);

    // Обхід дерева в порядку "за шириною"
    binaryTree.breadthFirstTraversal();

    return 0;
}*/


#include <iostream>
#include <string>

class Point {
protected:
    double x, y;

public:
    Point() {
        std::cout << "Point default constructor called\n";
    }

    Point(double x, double y) : x(x), y(y) {
        std::cout << "Point constructor called\n";
    }

    Point(const Point& other) : x(other.x), y(other.y) {
        std::cout << "Point copy constructor called\n";
    }

    Point& operator=(const Point& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        std::cout << "Point assignment operator called\n";
        return *this;
    }

    virtual ~Point() {
        std::cout << "Point destructor called\n";
    }

    virtual void input() {
        std::cout << "Enter x and y coordinates: ";
        std::cin >> x >> y;
    }

    virtual void output() const {
        std::cout << "Point: (" << x << ", " << y << ")\n";
    }
};

class ColoredPoint : public Point {
private:
    std::string color;

public:
    ColoredPoint() {
        std::cout << "ColoredPoint default constructor called\n";
    }

    ColoredPoint(double x, double y, const std::string& color) : Point(x, y), color(color) {
        std::cout << "ColoredPoint constructor called\n";
    }

    ColoredPoint(const ColoredPoint& other) : Point(other), color(other.color) {
        std::cout << "ColoredPoint copy constructor called\n";
    }

    ColoredPoint& operator=(const ColoredPoint& other) {
        if (this != &other) {
            Point::operator=(other);
            color = other.color;
        }
        std::cout << "ColoredPoint assignment operator called\n";
        return *this;
    }

    ~ColoredPoint() override {
        std::cout << "ColoredPoint destructor called\n";
    }

    void input() override {
        Point::input();
        std::cout << "Enter color: ";
        std::cin >> color;
    }

    void output() const override {
        Point::output();
        std::cout << "Color: " << color << "\n";
    }
};

int main() {
    // Тестуємо Point
    Point point1;
    point1.input();
    point1.output();

    Point point2(2.5, 3.0);
    point2.output();

    Point point3 = point2;
    point3.output();

    Point point4;
    point4 = point3;
    point4.output();

    // Тестуємо ColoredPoint
    ColoredPoint coloredPoint1;
    coloredPoint1.input();
    coloredPoint1.output();

    ColoredPoint coloredPoint2(1.0, 2.0, "Red");
    coloredPoint2.output();

    ColoredPoint coloredPoint3 = coloredPoint2;
    coloredPoint3.output();

    ColoredPoint coloredPoint4;
    coloredPoint4 = coloredPoint3;
    coloredPoint4.output();

    return 0;
}
