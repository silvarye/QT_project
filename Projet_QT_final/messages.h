/*#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include "bloc.h"

enum struct SplashScreenType { GO };

class messages : public bloc
{
public:
    messages(int, int, QString);
    ~messages();
    inline bool getIsSplashScreen(){ return isSplashScreen; }
    inline void setIsSplashScreen(bool splash){ this->isSplashScreen = splash; }
    inline void setType(SplashScreenType type){ this->type = type; }
    inline SplashScreenType getType(){ return this->type; }

private:
    bool isSplashScreen = true;
    SplashScreenType type = SplashScreenType::GO;
};

#endif // SPLASHSCREEN_H
*/
