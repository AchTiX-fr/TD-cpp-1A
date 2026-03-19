#pragma once
#include <vector>

class View;

class Controller
{
private:
	std::vector<View*> registredViews;

public:
	void registerView(View& view);
	void updateViews();
};

