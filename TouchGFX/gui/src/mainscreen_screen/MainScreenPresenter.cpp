#include <gui/mainscreen_screen/MainScreenView.hpp>
#include <gui/mainscreen_screen/MainScreenPresenter.hpp>

MainScreenPresenter::MainScreenPresenter(MainScreenView& v)
    : view(v)
{

}

void MainScreenPresenter::activate()
{

}

void MainScreenPresenter::deactivate()
{

}

void MainScreenPresenter::finalMassChanged(float mass)
{
	view.updateFinalMass(mass);
}

void MainScreenPresenter::fBeforeChanged(unsigned int fBefore)
{
	view.updatefBefore(fBefore);
}

void MainScreenPresenter::fAfterChanged(unsigned int fAfter)
{
	view.updatefAfter(fAfter);
}
