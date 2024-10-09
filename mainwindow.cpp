#include "mainwindow.h"

#include <QFileDialog>
#include <QImageReader>
MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),

    _menuBar(new QMenuBar),
    _fileMenu(new QMenu(tr("File"))),
    _editMenu(new QMenu(tr("Edit"))),
    _viewMenu(new QMenu(tr("View"))),
    _helpMenu(new QMenu(tr("Help"))),

    _quitAction(new QAction(QIcon(":/images/img/power.svg"), tr("quit"))),
    _openFileAction(new QAction(QIcon(":/images/img/open.svg"), tr("open file"))),
    _openDirAction(new QAction(QIcon(":/images/img/dir.svg"), tr("open dir"))),
    _changeSaveDirAction(new QAction(QIcon(":/images/img/dir.svg"), tr("change save dir"))),

    _saveAsAction(new QAction(QIcon(":/images/img/save.svg"), tr("save"))),
    _createAction(new QAction(QIcon(":/images/img/rect.png"), tr("create rect"))),
    _createRotateAction(new QAction(QIcon(":/images /img/rectRo.png"), tr("create rotate rect"))),

    _labelListContainerWidget(new QWidget),
    _labelListLayout(new QVBoxLayout),
    _editButton(new QToolButton),
    _diffCheckBox(new QCheckBox(tr("difficult"))),

    _labelDialog(new LabelDialog),
    _editAction(new QAction(QIcon(":/images/img/tags.svg"), tr("Manage Label"))),
    _fileListContainerWidget(new QWidget),
    _fileListLayout(new QVBoxLayout),

    _controlButtonsLayout(new QHBoxLayout),
    _prevButton(new QToolButton),
    _nextButton(new QToolButton),
    _playButton(new QToolButton),
    _preImgAction(new QAction(QIcon(":/images/img/previous.svg"), tr("Open Prev"))),
    _nextImgAction(new QAction(QIcon(":/images/img/next.svg"), tr("Open next"))),
    _playAction(new QAction(QIcon(":/images/img/play.svg"), tr("auto next"))),
    _fileListView(new CFileView),
    _fileModel(new CFileListModel(this->_fileListView)),

    // mainWidget(new QWidget),
    // mainLayout(new QVBoxLayout),
    _centerScroll(new QScrollArea),

    _canvas(new Canvas),
    _dock(new QDockWidget(tr("Box Labels"))),
    _fileDock(new QDockWidget(tr("File List"))),

    _timer(new QTimer),
    _toolBar(new QToolBar(tr("tool"))),
    _setting(new Settings)
{
    this->setMinimumSize(MinimumWidth, MaximumHeight);
    this->setWindowTitle(tr("label_tool"));

    this->setMenuBar(this->_menuBar);
    this->_menuBar->addMenu(this->_fileMenu);
    this->_menuBar->addMenu(this->_editMenu);
    this->_menuBar->addMenu(this->_viewMenu);
    this->_menuBar->addMenu(this->_helpMenu);

    this->_fileMenu->addAction(this->_openFileAction);
    this->_fileMenu->addAction(this->_openDirAction);
    this->_fileMenu->addAction(this->_changeSaveDirAction);
    this->_fileMenu->addAction(this->_quitAction);

    this->_editMenu->addAction(this->_editAction);

    this->_labelListLayout->setContentsMargins(0, 0, 0, 0);

    this->_editButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    this->_editButton->setDefaultAction(_editAction);
    connect(this->_editAction, &QAction::triggered, this, &MainWindow::editLabel);
    this->_labelListLayout->addWidget(this->_editButton);

    this->_diffCheckBox->setChecked(false);
    this->_labelListLayout->addWidget(this->_diffCheckBox);
    this->_labelListLayout->addStretch(1);
    this->_labelListContainerWidget->setLayout(this->_labelListLayout);
    this->_fileListLayout->setContentsMargins(0, 0, 0, 0);

    this->_prevButton->setToolButtonStyle(Qt::ToolButtonIconOnly);
    this->_nextButton->setToolButtonStyle(Qt::ToolButtonIconOnly);
    this->_playButton->setToolButtonStyle(Qt::ToolButtonIconOnly);

    this->_playButton->setDefaultAction(this->_playAction);
    this->_prevButton->setDefaultAction(this->_preImgAction);
    this->_nextButton->setDefaultAction(this->_nextImgAction);

    this->_controlButtonsLayout->addWidget(_prevButton);
    this->_controlButtonsLayout->addWidget(_nextButton);
    this->_controlButtonsLayout->addWidget(_playButton);
    this->_controlButtonsLayout->addStretch(1);
    //文件列表
    this->_fileListLayout->addLayout(this->_controlButtonsLayout);
    this->_fileListLayout->addWidget(this->_fileListView, 1);
    this->_fileListView->setModel(this->_fileModel);
    this->_fileListContainerWidget->setLayout(this->_fileListLayout);
    this->addToolBar(Qt::TopToolBarArea, _toolBar);

    this->_toolBar->addAction(this->_openDirAction);
    this->_toolBar->addAction(this->_saveAsAction);
    this->_toolBar->addAction(this->_createAction);
    this->_toolBar->addAction(this->_createRotateAction);

    this->setCentralWidget(this->_centerScroll);

    this->_centerScroll->setWidget(_canvas);
    this->_centerScroll->setWidgetResizable(true);
    //标签列表

    this->addDockWidget(Qt::RightDockWidgetArea, this->_dock);
    this->addDockWidget(Qt::RightDockWidgetArea, this->_fileDock);
    this->_dock->setFeatures(QDockWidget::DockWidgetFloatable);
    this->_dock->setWidget(this->_labelListContainerWidget);

    this->_fileDock->setFeatures(QDockWidget::DockWidgetFloatable);
    this->_fileDock->setWidget(this->_fileListContainerWidget);
    connect(this->_quitAction, &QAction::triggered, this, [=](bool checked) { this->close(); });
    connect(this->_openDirAction, &QAction::triggered, this, &MainWindow::openDirDialog);
    connect(this->_fileListView, &QListView::clicked, this, [=](const QModelIndex& index) {
        int     row      = index.row();
        QString filePath = this->_currentPathList.at(row);
        QImage  img;
        img.load(filePath);
        std::shared_ptr<QImage> imgPtr = std::make_shared<QImage>(img);
        this->_canvas->setImage(imgPtr);
    });
}

MainWindow::~MainWindow()
{
    delete this->_setting;

    delete this->_labelDialog;
    delete this->_editAction;
    delete this->_editButton;
    delete this->_labelListLayout;
    delete this->_labelListContainerWidget;

    delete this->_fileListView;
    delete this->_preImgAction;
    delete this->_nextImgAction;
    delete this->_playAction;

    delete this->_playButton;
    delete this->_nextButton;
    delete this->_prevButton;
    delete this->_controlButtonsLayout;

    delete this->_fileListLayout;

    delete this->_createAction;
    delete this->_createRotateAction;

    delete this->_saveAsAction;
    delete this->_quitAction;
    delete this->_openFileAction;
    delete this->_openDirAction;
    delete this->_changeSaveDirAction;

    delete this->_fileMenu;
    delete this->_editMenu;
    delete this->_viewMenu;
    delete this->_helpMenu;

    delete this->_toolBar;
    delete this->_menuBar;
    delete this->_centerScroll;
}

void MainWindow::editLabel(bool checked)
{
    this->_labelDialog->show();
}

void MainWindow::openDirDialog(bool checked)
{
    QString currentString = ".";
    QString currentDir    = QFileDialog::getExistingDirectory(this, tr("Open current directory"), currentString);

    if (!currentDir.isEmpty())
    {
        getCurrentDirImage(currentDir);
    }
}

void MainWindow::getCurrentDirImage(const QString& currentDir)
{
    this->_lastOpenDir      = currentDir + "/";
    QStringList imgTypeList = {"*.bmp", "*.cur", "*.gif", "*.ico", "*.jpeg", "*.jpg", "*.pbm", "*.pgm", "*.png", "*.ppm", "*.svg", "*.svgz", "*.xbm", "*.xpm"};
    QDir        fileDir(currentDir);
    if (!fileDir.exists())
    {
        return;
    }
    this->_currentPathList.clear();
    QStringList imageFiles = fileDir.entryList(imgTypeList, QDir::Files | QDir::Readable, QDir::Name);
    for (const QString& file : imageFiles)
    {
        QString filePath = this->_lastOpenDir + file;
        this->_currentPathList.append(filePath);
    }
    this->_fileModel->setList(this->_currentPathList);
    if (this->_currentPathList.size() > 0)
    {
        QImage image;
        image.load(this->_currentPathList.at(0));
        std::shared_ptr<QImage> imgPtr = std::make_shared<QImage>(image);
        this->_canvas->setImage(imgPtr);
    }
}
