#include <QApplication>

#include "Q_CV_GraphicView.h"

int main(int argc, char **argv) {
	QApplication app(argc, argv);
	Q::cv2::GraphicView g;
	g.show();

	return app.exec();
}