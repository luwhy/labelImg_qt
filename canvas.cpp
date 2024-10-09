#include "canvas.h"

#include <QDebug>
Canvas::Canvas(QWidget* parent) :
    QWidget(parent),

    _painter(new QPainter)
{
    this->_scale           = 1.0;
    this->_translate       = QPointF(0., 0.);
    this->drawingRectColor = QColor(0, 0, 255);
    this->drawingLineColor = QColor(0, 0, 255);
    this->_hideBackround   = false;
    this->hideBackround    = false;

    this->setMouseTracking(true);
    this->setFocusPolicy(Qt::WheelFocus);
}

Canvas::~Canvas()
{
    delete this->_painter;
}

void Canvas::setImage(std::shared_ptr<QImage> image)
{
    if (image == nullptr)
    {
        return;
    }
    this->_imagePtr = image;
    this->updateSize();
}
//更新比例
void Canvas::updateScale(double scale)
{
    this->_scale = scale;
}
//更新起始点
void Canvas::updateTranse(QPointF p)
{
    this->_translate = p;
}

void Canvas::updateSize()
{
    double image_width  = static_cast<double>(this->_imagePtr->width());
    double image_height = static_cast<double>(this->_imagePtr->height());
    double thisWidth    = static_cast<double>(this->width());
    double thisHeight   = static_cast<double>(this->height());
    double new_width    = qMin(image_width, thisWidth);
    double new_height   = new_width / (image_width / image_height);

    new_height = qMin(new_height, thisHeight);
    this->updateScale(new_height / image_height);
    this->updateTranse(QPointF((thisWidth - image_width * this->_scale) / 2, (thisHeight - image_height * this->_scale) / 2));
    this->update();
}

void Canvas::paintEvent(QPaintEvent* event)
{
    this->_painter->begin(this);
    if (this->_imagePtr == nullptr)
    {
        this->_painter->end();
        return;
    }
    this->_painter->translate(this->_translate);
    this->_painter->scale(this->_scale, this->_scale);
    this->_painter->drawImage(0, 0, *(this->_imagePtr));
    this->_painter->end();
}

void Canvas::resizeEvent(QResizeEvent* event)
{
    if (this->_imagePtr == nullptr)
        return;
    this->updateSize();
}
