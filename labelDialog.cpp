#include "labelDialog.h"

#include "commenFunction.h"

#include <QStandardItem>
LabelDialog::LabelDialog(QDialog* parent) :
    QDialog(parent),

    layout(new QVBoxLayout),
    horWidget(new QWidget),
    horlayout(new QHBoxLayout),
    listView(new QListView),
    _listModel(new QStandardItemModel),

    _enterWidet(new QWidget),
    _enterLayout(new QHBoxLayout),
    _label(new QLabel(tr("Enter object label"))),
    edit(new QLineEdit),

    addBtn(new QPushButton(tr("add"))),
    setDefaultBtn(new QPushButton(tr("set as default"))),
    buttonBox(new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, this)),
    editValidator(new QRegularExpressionValidator(QRegularExpression("^[^ \t]{0,50}")))

{
    this->setMinimumWidth(minDialogWidth);
    this->setMaximumWidth(minDialogHeight);
    this->setAttribute(Qt::WA_QuitOnClose, false);
    this->_enterLayout->addWidget(this->_label);
    this->_enterLayout->addWidget(this->edit);
    this->_enterLayout->setContentsMargins(0, 0, 0, 0);
    this->_enterWidet->setLayout(this->_enterLayout);
    this->edit->setValidator(editValidator);

    this->layout->addWidget(this->_enterWidet);

    connect(this->buttonBox, &QDialogButtonBox::accepted, this, &LabelDialog::accept);
    connect(this->buttonBox, &QDialogButtonBox::rejected, this, &LabelDialog::reject);
    connect(this->edit, &QLineEdit::editingFinished, this, &LabelDialog::postProcess);
    connect(this->addBtn, &QPushButton::clicked, this, &LabelDialog::addLabel);
    connect(this->setDefaultBtn, &QPushButton::clicked, this, &LabelDialog::defaultLabel);

    this->horlayout->addWidget(this->addBtn);
    this->horlayout->addWidget(this->setDefaultBtn);
    this->horWidget->setLayout(this->horlayout);
    this->layout->addWidget(this->listView);

    this->layout->addWidget(horWidget);
    this->layout->addWidget(buttonBox);
    this->setLayout(this->layout);

    this->_labelList = {"dog", "person", "car", "tv", "chicken", "cavity", "hamburger", "ball"};
    for (const auto& label : _labelList)
    {
        QStandardItem* itemModel = new QStandardItem(label);
        this->_listModel->appendRow(itemModel);
    }
    this->listView->setModel(this->_listModel);
    this->_currentItemIndex = 0;
    this->_originItemIndex  = 0;
    this->_currentLabel     = this->_labelList[0];
    this->_listModel->item(this->_currentItemIndex, 0)->setBackground(QBrush(Qt::red));
    connect(this->listView, &QListView::clicked, this, [=](const QModelIndex& index) {
        this->_currentItemIndex = index.row();
        qDebug() << this->_currentItemIndex;
        this->_currentLabel = this->_listModel->data(index).toString();
    });
}

LabelDialog::~LabelDialog()
{
    delete this->editValidator;
    delete this->buttonBox;
    delete this->setDefaultBtn;
    delete this->addBtn;

    delete this->edit;
    delete this->_label;
    delete this->_enterLayout;
    delete this->_enterWidet;

    delete this->_listModel;
    delete this->listView;
    delete this->horlayout;
    delete this->horWidget;
    delete this->layout;
}

void LabelDialog::accept()
{
    DEBUG_FUNCTION;
    emit setCurrentLabel(this->_currentLabel, this->_labelList);
    this->close();
}

void LabelDialog::postProcess()
{
    DEBUG_FUNCTION;
}

void LabelDialog::defaultLabel()
{
    DEBUG_FUNCTION;
    if (this->_currentItemIndex != this->_originItemIndex)
    {
        this->_listModel->item(this->_originItemIndex, 0)->setBackground(QBrush(Qt::transparent));
        this->_listModel->item(this->_currentItemIndex, 0)->setBackground(QBrush(Qt::red));
        this->_currentLabel    = this->_listModel->data(this->_listModel->index(this->_currentItemIndex, 0)).toString();
        this->_originItemIndex = this->_currentItemIndex;
    }
}

void LabelDialog::addLabel()
{
    DEBUG_FUNCTION;
}
