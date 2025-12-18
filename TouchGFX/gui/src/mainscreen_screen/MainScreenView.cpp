#include <gui/mainscreen_screen/MainScreenView.hpp>

MainScreenView::MainScreenView()
{

}

void MainScreenView::setupScreen()
{
    MainScreenViewBase::setupScreen();
}

void MainScreenView::tearDownScreen()
{
    MainScreenViewBase::tearDownScreen();
}

void MainScreenView::updateFinalMass(float mass)
{
	Unicode::snprintfFloat(finalMassTextAreaBuffer, FINALMASSTEXTAREA_SIZE, "%.2f", mass);
	finalMassTextArea.setWildcard(finalMassTextAreaBuffer);
	finalMassTextArea.invalidate();
}

void MainScreenView::updatefBefore(unsigned int fBefore)
{
	Unicode::snprintf(fBeforeTextAreaBuffer, FBEFORETEXTAREA_SIZE, "%d", fBefore);
	fBeforeTextArea.setWildcard(fBeforeTextAreaBuffer);
	fBeforeTextArea.invalidate();
}

void MainScreenView::updatefAfter(unsigned int fAfter)
{
	Unicode::snprintf(fAfterTextAreaBuffer, FAFTERTEXTAREA_SIZE, "%d", fAfter);
	fAfterTextArea.setWildcard(fAfterTextAreaBuffer);
	fAfterTextArea.invalidate();
}
