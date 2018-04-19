#pragma once

class settings
{

public:
	settings();

	void writeINI(int leftPort, int middlePort, int rightPort);

	int readINI_left();

	int readINI_middle();

	int readINI_right();

	~settings();
};