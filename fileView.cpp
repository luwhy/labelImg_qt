#include <fileView.h>
CFileView::CFileView(QWidget* parent) :
    QListView(parent),

    _delegate(new CFileItemEditDelegate(this))
{
    //为表格中的特定列提供自定义的显示和编辑行为
    this->setItemDelegateForColumn(0, this->_delegate);
}

CFileView::~CFileView()
{
    delete this->_delegate;
}

/*
 *
 *
 *
 **/

CFileListModel::CFileListModel(QWidget* parent) : QStringListModel(parent)
{
}

void CFileListModel::setList(const QStringList& strings)
{
    this->_imgNameList.clear();
    this->_imgPathMap.clear();
    for (const QString& s : strings)
    {
        QFileInfo fileInfo(s);
        QString   dirString  = fileInfo.absoluteFilePath();
        QString   fileName   = fileInfo.fileName();
        QString   baseString = fileInfo.baseName();
        QString   jsonPath   = QString("%1/%2.json").arg(dirString, baseString);
        this->_imgNameList.append(fileName);
        this->_imgPathMap[fileName] = s;
    }
    this->setStringList(this->_imgNameList);
}

QStringList CFileListModel::getNameList()
{
    return this->_imgNameList;
}

QMap<QString, QString> CFileListModel::getNameMap()
{
    return this->_imgPathMap;
}

/*
 *
 *
 *
 **/

CFileItemEditDelegate::CFileItemEditDelegate(QWidget* parent) : QStyledItemDelegate(parent)
{
}

QWidget* CFileItemEditDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    QLineEdit* editor = new QLineEdit(parent);
    editor->setReadOnly(true);

    return editor;
}
