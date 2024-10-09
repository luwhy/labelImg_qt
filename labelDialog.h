#ifndef LABELDIALOG_H
#define LABELDIALOG_H
#include <QDialog>
#include <QDialogButtonBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QListView>
#include <QPushButton>
#include <QRegularExpressionValidator>
#include <QStandardItemModel>
#include <QVBoxLayout>
#include <QWidget>
constexpr int minDialogWidth  = 320;
constexpr int minDialogHeight = 480;
class LabelDialog : public QDialog
{
    Q_OBJECT
public:
    explicit LabelDialog(QDialog* parent = nullptr);
    ~LabelDialog();

private:
    void accept();
    void postProcess();
    void defaultLabel();
    void addLabel();

private:
    QVBoxLayout* layout;
    QWidget*     horWidget;
    QHBoxLayout* horlayout;

    QListView*          listView;
    QStandardItemModel* _listModel;

    QWidget*     _enterWidet;
    QHBoxLayout* _enterLayout;
    QLabel*      _label;
    QLineEdit*   edit;

    QPushButton*                 addBtn;
    QPushButton*                 setDefaultBtn;
    QDialogButtonBox*            buttonBox;
    QRegularExpressionValidator* editValidator;

    QStringList _labelList;

    int     _currentItemIndex;
    int     _originItemIndex;
    QString _currentLabel;
signals:
    void setCurrentLabel(QString defaultLabel, QStringList labelList);
};

#endif // LABELDIALOG_H
