#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "canvas.h"
#include "fileView.h"
#include "labelDialog.h"
#include "settings.h"

#include <QAction>
#include <QCheckBox>
#include <QDockWidget>
#include <QImage>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QScrollArea>
#include <QTimer>
#include <QToolBar>
#include <QToolButton>
#include <QVBoxLayout>
#include <QWidget>
#include <memory>

const int MinimumWidth  = 840;
const int MaximumHeight = 680;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    void editLabel(bool checked);

private:
    QMenuBar* _menuBar;
    QMenu*    _fileMenu;
    QMenu*    _editMenu;
    QMenu*    _viewMenu;
    QMenu*    _helpMenu;

    QAction* _quitAction;
    QAction* _openFileAction;
    QAction* _openDirAction;
    QAction* _changeSaveDirAction;
    QAction* _openAnnotationAction;
    QAction* _verifyAction;
    QAction* _saveAsAction;
    QAction* _closeAction;
    QAction* _resetAllAction;
    QAction* _createAction;
    QAction* _createSolidAction;
    QAction* _createRotateAction;
    QAction* _deleteAction;
    QAction* _copyAction;
    QAction* _showInfoAction;

    QAction* _zoomInAction;
    QAction* _zoomOutAction;
    QAction* _zoomOrgAction;
    QAction* _fitWindowAction;
    QAction* _fitWidthAction;

    // QToolBar* _toolBar;

    QWidget*     _labelListContainerWidget;
    QVBoxLayout* _labelListLayout;
    QToolButton* _editButton;
    QCheckBox*   _diffCheckBox;
    LabelDialog* _labelDialog;
    QAction*     _editAction;

    QWidget*        _fileListContainerWidget;
    QVBoxLayout*    _fileListLayout;
    QHBoxLayout*    _controlButtonsLayout;
    QToolButton*    _prevButton;
    QToolButton*    _nextButton;
    QToolButton*    _playButton;
    QAction*        _preImgAction;
    QAction*        _nextImgAction;
    QAction*        _playAction;
    CFileView*      _fileListView;
    CFileListModel* _fileModel;
    // QWidget*     mainWidget;
    // QVBoxLayout* mainLayout;
    QScrollArea* _centerScroll; //中心滚动条区域
    Canvas*      _canvas;

    QDockWidget* _dock;
    QDockWidget* _fileDock;

    QTimer* _timer;

    QToolBar* _toolBar;

    QStringList _labelHist;

    bool _dirty; //是否需要保存

    Settings* _setting;

    QString     _lastOpenDir;
    QStringList _currentPathList;

    QString     _defaultLabel;
    QStringList _labelList;

private:
    /*
     *@brief:打开文件夹对话框
     **/
    void openDirDialog(bool checked);

    /*
     *@brief:获取当前目录下图片文件
     **/
    void getCurrentDirImage(const QString& currentDir);

    void getCurrentLabelList(const QString& defaultLabel, const QStringList& labelList);
};
#endif // MAINWINDOW_H
