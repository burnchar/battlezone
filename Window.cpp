#include "Window.h"

config myConfig("battlezone.cfg");

Window::Window()
{
	myController = new controller(0, 50);

	QHBoxLayout *mainLayout = new QHBoxLayout;
	mainLayout->addWidget( myController );
	setLayout( mainLayout );

	setWindowTitle("Battlezone");

	myConfig = config("battlezone.cfg");
	move = new QSound(myConfig.soundMove);
	fire = new QSound(myConfig.soundFire);
	kill = new QSound(myConfig.soundKill);
	move->setLoops( 5 );

	keys.insert( Qt::Key_Up, Forward );
	keys.insert( Qt::Key_Left, RotateLeft );
	keys.insert( Qt::Key_Right, RotateRight );
	keys.insert( Qt::Key_Down, Reverse );
	keys.insert( Qt::Key_Space, Shoot );
	keys.insert( Qt::Key_Escape, Exit );}

void Window::keyPressEvent( QKeyEvent *event )
{
	qDebug("Entering Window::keyPressEvent");
	if ( event->isAutoRepeat() || !keys.contains( event->key() ) ) {
		event->ignore();
		return;
	}
	qDebug("Entering Window::keyPressEvent, line %i", __LINE__);

	Action a = keys[ event->key()];

	switch ( a ) {
		case Forward:
			qDebug("Entering Window::keyPressEvent, line %i", __LINE__);
			move->play();
			qDebug("Entering Window::keyPressEvent, line %i", __LINE__);
			break;

		case RotateLeft:
			move->play();
			break;

		case RotateRight:
			move->play();
			break;

		case Reverse:
			move->play();
			break;

		case Shoot:
			fire->play();
			break;

		case Exit:
			QApplication::exit();
			break;

		default:
			event->ignore();
			return;
	}
	event->accept();
}


void Window::keyReleaseEvent( QKeyEvent *event )
{
	if ( event->isAutoRepeat() || !keys.contains( event->key() ) ) {
		event->ignore();
		return;
	}

	Action a = keys[ event->key()];

	switch ( a ) {

		case Forward:
			move->stop();
			break;

		case RotateLeft:
			move->stop();
			break;

		case RotateRight:
			move->stop();
			break;

		case Reverse:
			move->stop();
			break;

		case Shoot:
			break;

		case Exit:
			break;

		default:
			event->ignore();
			return;
	}

	event->accept();
}


