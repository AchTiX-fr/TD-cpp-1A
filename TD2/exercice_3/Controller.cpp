#include "Controller.h"
#include "View.h"

void Controller::registerView(View& view)
{
	registredViews.push_back(&view);
}

void Controller::updateViews()
{
	for (auto view : registredViews)
		view->update();
}