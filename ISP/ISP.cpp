#include <iostream>
using namespace std;
//1
//Создайте интерфейс для графического редактора, который будет разделяться на меньшие интерфейсы.
//Например, интерфейс для рисования фигур, интерфейс для редактирования цвета и интерфейс для работы со слоями.
//Убедитесь, что каждый из этих интерфейсов содержит только те методы,которые необходимы для выполнения соответствующих задач, и не включает в себя методы,
//которые могут быть использованы в другом контексте.

__interface ICreate {
    void Create();
};

__interface ICut {
    void Cut();
};

__interface IChangeColor {
    void ChangeColor();
};

__interface ILayer {
    void Layer();
};

__interface IDraw {
    void Draw();
};

__interface IDrawFigure : public IDraw {
    void DrawFigure();
};

__interface IDelete {
    void Delete();
};

__interface IEdit : public IDelete, public IDrawFigure, public ICut, public ICreate, public IChangeColor{
    void Edit();    
};

class GraphicRedactor : public IEdit, public ILayer{
public:

    virtual void Cut() {
        cout << "cut\n";
    }

    virtual void Create() {
        cout << "create\n";
    }

    virtual void ChangeColor() {
        cout << "color is changed\n";
    }

    virtual void Delete() {
        cout << "delete\n";
    }

    virtual void Edit() {
        cout << "edit\n";
    }

    virtual void Layer(){
        cout << "work with layers\n";
    }

    virtual void Draw() {
        cout << "draw\n";
    }

    virtual void DrawFigure() {
        cout << "draw figure\n";
    }
};

//2
//Разработайте систему управления задачами, которая имеет разные интерфейсы для пользователей разного уровня доступа.
//Например, интерфейс для администратора, который может добавлять, редактировать и удалять задачи, интерфейс для менеджера, который может просматривать и назначать задачи,
//и интерфейс для работника, который может только просматривать свои задачи.
//Убедитесь, что каждый интерфейс содержит только те методы, которые необходимы для выполнения соответствующих задач,
//и не включает в себя методы, которые могут быть использованы в другом контексте.

class IView abstract {
public:
    virtual void View() = 0;
};

class IAddTask abstract {
public:
    virtual void AddTask() = 0;
};

class IDeleteTask abstract {
public:
    virtual void DeleteTask() = 0;
};

class IRedact abstract {
public:
    virtual void Redact() = 0;
};

class ISetTask abstract {
public:
    virtual void SetTask() = 0;
};

class Manager : public IView, public ISetTask {
public:
    virtual void View() {
        cout << "manager view\n";
    }

    virtual void SetTask() {
        cout << "manager selected task\n";
    }
};

class Administrator : public IAddTask, public IDeleteTask, public IView, public IRedact {
public:
    virtual void AddTask() {
        cout << "admin add task\n";
    }

    virtual void DeleteTask() {
        cout << "admin delete task\n";
    }

    virtual void View() {
        "admin view\n";
    }

    virtual void Redact() {
        cout << "admin redact\n";
    }
};

class Worker : public IView {
public:
    virtual void View() {
        cout << "worker view\n";
    }
};

//3
//Разработайте систему для автоматизации управления складом, которая имеет разные интерфейсы для различных складских работников.
//Например, интерфейс для оператора склада, который может добавлять, редактировать и удалять товары, интерфейс для менеджера склада, 
//который может просматривать и управлять запасами товаров, и интерфейс для сборщика товаров, который может только просматривать и отмечать, что товары были собраны.
//Убедитесь, что каждый интерфейс содержит только те методы, которые необходимы для выполнения соответствующих задач, и не включает в себя методы, 
//которые могут быть использованы в другом контексте.

__interface IViewProduct {
    void ViewProduct();
};
__interface IRedactProduct {
    void RedactProduct();
};
__interface IMarkProduct {
    void MarkProduct();
};
__interface IDeleteProduct {
    void DeleteProduct();
};
__interface IInventoryManagment {
    void ManageInventory();
};
__interface IAddProduct {
    void AddProduct();
};
__interface IDeleteProduct {
    void DeleteProduct();
};

class WarehouseOperator : public IRedactProduct, public IViewProduct, public IDeleteProduct, public IAddProduct {
public:
    virtual void ViewProduct() {
        cout << "Operator view product\n";
    }

    virtual void DeleteProduct(){
        cout << "Operator delete product\n"; 
    }

    virtual void RedactProduct(){
        cout << "Operator redact product\n"; 
    }

    virtual void AddProduct(){ cout << "Operator add product\n"; 
    }
};
class WarhouseManager : public IViewProduct, public IInventoryManagment{
public:
    virtual void ViewProduct(){
        cout << "Manager view product\n";
    }

    virtual void ManageInventory(){
        cout << "Manager manage inventory\n";
    }
};
class ProductsCollector : public IViewProduct, public IMarkProduct{
public:
    virtual void ViewProduct(){
        cout << "Collector view product\n";
    }
    virtual void MarkProduct(){
        cout << "Collector mark product\n";
    }
};

int main()
{
    GraphicRedactor object;
    object.Draw();
    object.Layer();
    Administrator admin;
    Worker people;
    Manager man;
    admin.AddTask();
    man.SetTask();
    people.View();

    ProductsCollector collector;
    WarehouseOperator human;
    WarhouseManager manager;
    manager.ManageInventory();
    human.AddProduct();
    collector.MarkProduct();
}
