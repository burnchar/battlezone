//
// Battlezone
// A multiplayer remake of Atari's 1980 game: Battlezone
// Authors: Charles Burns
//          Trey Russell
//
// License: GPL3
// http://www.gnu.org/copyleft/gpl.html
//
// Requires QT 4.3 by Nokia's Trolltech software

#ifndef CONFIG_H
#define CONFIG_H

#include <QFile>
#include <QStringList>
#include <QtDebug>

// config class. Gets settings from config file and exposes them.
// Exposure is public (not get/set) for simplicity.
class config {
	public:

	// These are the variables from the config file.
	qint32 playerStartingLives;
	qint32 playerTankSpeed;
	qint32 playerTankTurnRate;
	qint32 projectileSpeed;
	qint32 playerMaxInFlightProjectiles;
	qint32 playerTankMaxRof;
	qint32 playerStartingAmmo;
	qint32 playerTankMaxDetectibilityRange;
	qint32 playerTankMaxEngageabilityRange;

	QString soundMove;
	QString soundFire;
	QString soundKill;

	QStringList playerIpList;

	// Function prototypes
	config();
	config(QString configFile);
	void printPublicVars();
	qint32 parseConfigFile(QString configFile);
	QByteArray& strip(QByteArray &ba, char commentChar = '#');
};

#endif
