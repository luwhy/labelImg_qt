#ifndef SHAPE_H
#define SHAPE_H
#include <QColor>
#include <QObject>
#include <QPointF>
#include <QWidget>
class Shape : public QObject
{
    Q_OBJECT
public:
    explicit Shape(QString label = "", QColor line_color = QColor(0, 255, 0, 128), bool difficult = false, bool paintLabel = false, QString extra_label = "");

private:
    enum class P_SHAPE : int
    {
        P_SQUARE,
        P_ROUND
    };
    enum class VERTIX : int
    {
        MOVE_VERTEX,
        NEAR_VERTEX
    };

    QColor         line_color;
    QColor         fill_color;
    QColor         select_line_color;
    QColor         select_fill_color;
    QColor         vertex_fill_color;
    QColor         hvertex_fill_color;
    int            point_size;
    float          scale;
    QString        label;
    QList<QPointF> points;
    bool           fill;
    bool           selected;
    bool           difficult;
    bool           paintLabel;
    QString        extra_label;
    double         direction;
    QPointF        center;
    bool           isRotated;
    bool           highlightCorner;
    bool           alwaysShowCorner;
    bool           _closed;
};

#endif // SHAPE_H
