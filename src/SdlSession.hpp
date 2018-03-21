#pragma once

class SdlSession
{
	public:
		~SdlSession();
		bool init();
	private:
		bool initialized;
		bool ttfInitialized;
};
