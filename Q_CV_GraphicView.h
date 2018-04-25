#ifndef __Q_CV_GRAPHIC_VIEW_H__
#define __Q_CV_GRAPHIC_VIEW_H__
#pragma once

#include <QGraphicsView>
#include <QPixMap>
#include <QImage>
#include "opencv2/videoio.hpp"
class QPixMap;
namespace Q {
namespace cv2 {
	
class GraphicView : public QGraphicsView {
	Q_OBJECT;

public:
	explicit GraphicView(QWidget *parent = Q_NULLPTR);
	virtual ~GraphicView() override;

protected:
	virtual void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;
private:
	QPixmap image;
	QImage cacheImage;
	cv::VideoCapture videoCapture;
};

}
}

#endif // !__Q_CV_GRAPHIC_VIEW_H__
