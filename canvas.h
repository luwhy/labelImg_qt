#ifndef CANVAS_H
#define CANVAS_H
#include <QImage>
#include <QPainter>
#include <QWidget>
#include <memory.h>
constexpr Qt::CursorShape CURSOR_DEFAULT = Qt::ArrowCursor;
constexpr Qt::CursorShape CURSOR_POINT   = Qt::PointingHandCursor;
constexpr Qt::CursorShape CURSOR_DRAW    = Qt::CrossCursor;
constexpr Qt::CursorShape CURSOR_MOVE    = Qt::ClosedHandCursor;
constexpr Qt::CursorShape CURSOR_GRAB    = Qt::OpenHandCursor;
class Canvas : public QWidget
{
    Q_OBJECT

public:
    static constexpr float epsilon = 0.7;
    explicit Canvas(QWidget* parent = nullptr);
    ~Canvas();
    void setImage(std::shared_ptr<QImage> image);

private:
    void updateScale(double scale);

    void updateTranse(QPointF p);

    void updateSize();

private:
    enum class CREATEMODE : int
    {
        CREATE,
        EDIT,
        CONTINUECREATE
    };

    int mode;

    bool _hideBackround;
    bool hideBackround;

    QColor                  drawingRectColor;
    QColor                  drawingLineColor;
    QPointF                 prevPoint;
    QPair<QPointF, QPointF> offsets;
    QPixmap                 pixmap;
    QPainter*               _painter;

    std::shared_ptr<QImage> _imagePtr;

    double  _scale;
    QPointF _translate;

protected:
    void paintEvent(QPaintEvent* event);

    void resizeEvent(QResizeEvent* event);

signals:
    void zoomRequest(int i);
    void scrollRequest(int i, int j);
    void newShape(bool i);
    void selectionChanged(bool i);
    void shapeMoved();
    void drawingPolygon(bool i);
    void hideRRect(bool i);
    void hideNRect(bool i);
    void status(QString str);
    void cancelDraw();
    void toggleEdit(bool i);
};

#endif // CANVAS_H
