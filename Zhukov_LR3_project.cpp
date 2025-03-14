#include <iostream>
#include <map>
#include <functional>

using namespace std;

class UnimplementedExeption: public exception
{
  virtual const char* what() const throw()
  {
    return "This method are not implemented";
  }
} unimplemented;

int a, b;

void enter_a() {
    cout << "Enter a:" << endl;
    cin >> a;
}

void enter_b() {
    cout << "Enter b: " << endl;
    cin >> b;
}

void get_reminder() {
    throw unimplemented; // TODO implement me
}

void get_result() {
    throw unimplemented; // TODO implement me
}

struct MenuItem {
    function<void()> callback;
    string title;

    MenuItem() = default;

    MenuItem(string title, function<void()> callback)
        : title(move(title)), callback(move(callback)) {
    }
};

int main() {
    map<int, MenuItem> menu{
        {1, MenuItem("Ввести A: ", enter_a)},
        {2, MenuItem("Ввести B", enter_b)},
        {3, MenuItem("Получить остаток от деления a на b", get_reminder)},
        {4, MenuItem("Получить результат от деления b на а", get_result)},
    };


    return 0;
}