#ifndef FILEVIEW_H
#define FILEVIEW_H
#include <QDir>
#include <QFileInfo>
#include <QLineEdit>
#include <QListView>
#include <QStringListModel>
#include <QStyledItemDelegate>
#include <QWidget>
class CFileListModel;
class CFileItemEditDelegate;
class CFileView : public QListView
{
    Q_OBJECT
public:
    explicit CFileView(QWidget* parent = nullptr);
    ~CFileView();

private:
    CFileItemEditDelegate* _delegate;
};

class CFileListModel : public QStringListModel
{
    Q_OBJECT
public:
    explicit CFileListModel(QWidget* parent = nullptr);

    void setList(const QStringList& strings);

    QStringList            getNameList();
    QMap<QString, QString> getNameMap();

private:
    QStringList            _imgNameList;
    QMap<QString, QString> _imgPathMap;
};
class CFileItemEditDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit CFileItemEditDelegate(QWidget* parent = nullptr);

    virtual QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const override;
};

#endif // FILEVIEW_H
