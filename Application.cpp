#include "Application.h"

#include <QFile>
Application::Application(int argc, char* argv[]) :
    QApplication(argc, argv),

    _translator(new QTranslator)

{
    if (this->_translator->load(":/i18n/label_tool_zh_CN.qm"))
    {
        this->installTranslator(this->_translator);
    }
    _mainWindow = new MainWindow();
    this->_mainWindow->showMaximized();
}

Application::~Application()
{
    delete this->_translator;
    delete this->_mainWindow;
}
