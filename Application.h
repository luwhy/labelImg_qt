#ifndef APPLICATION_H
#define APPLICATION_H
#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>
class Application : public QApplication
{
    Q_OBJECT

private:
    MainWindow*  _mainWindow;
    QTranslator* _translator;

public:
    Application(int argc, char* argv[]);
    ~Application();
};

#endif // APPLICATION_H
