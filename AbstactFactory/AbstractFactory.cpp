#include <iostream>

using namespace std;

class Button {
    public:
        virtual void paint() = 0;
};

class WinButton: public Button {
    public:
        void paint() override {
            cout << "WinButton\n";
        }
};

class LinuxButton: public Button {
    public:
         void paint() override {
            cout << "LinuxButton\n";
        }
};

class Checkbox {
    public:
        virtual void paint() = 0;
};

class WinCheckbox: public Checkbox {
    public:
         void paint() override {
            cout << "WinCheckbox\n";
        };
};

class LinuxCheckbox: public Checkbox {
    public:
         void paint() override {
            cout << "LinuxCheckbox\n";
        }
};

class GUIFactory {
    public:
        virtual Button* createButton() = 0;
        virtual Checkbox* createCheckbox() = 0; 
};

class WinFactory: public GUIFactory {
    public:
        Button* createButton() override {
            return new WinButton;
        }

        Checkbox* createCheckbox() override {
            return new WinCheckbox;
        }
};

class LinuxFactory: public GUIFactory {
    public:
        Button* createButton() override {
            return new LinuxButton;
        }

        Checkbox* createCheckbox() override {
            return new LinuxCheckbox;
        }
};




class Application {
    public:
        Application(GUIFactory* factory) {
            button = factory->createButton();
        }

        void pressButton() {
            button->paint();
        }

    private:
        Button* button;
};

int main() {

    Application* app;

    int flag;
    cin >> flag;
    if (flag == 1) {
        app = new Application(new WinFactory);
    } else if (flag == 2) {
        app = new Application(new LinuxFactory);
    }

    app->pressButton();
}