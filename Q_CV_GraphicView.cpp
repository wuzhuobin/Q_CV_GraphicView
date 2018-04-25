#include "Q_CV_GraphicView.h"

#include <QGraphicsScene>
#include <QtConcurrentRun>
#include <QDebug>
Q::cv2::GraphicView::GraphicView(QWidget * parent) :
	QGraphicsView(parent)
{
	this->setScene(new QGraphicsScene(this));
	this->scene()->addPixmap(this->image);
	this->videoCapture.open(0);
	this->startTimer(20);
}

Q::cv2::GraphicView::~GraphicView()
{
	this->videoCapture.release();
}

void Q::cv2::GraphicView::timerEvent(QTimerEvent * event)
{
	QGraphicsView::timerEvent(event);
	using namespace cv;
	//QtConcurrent::run([=]() {
		Mat mat;
		this->videoCapture >> mat;
		
		this->cacheImage = QImage(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
		this->cacheImage = this->cacheImage.rgbSwapped();
		this->scene()->clear();
		this->image.convertFromImage(this->cacheImage);
		this->scene()->addPixmap(this->image);
	//});
}

