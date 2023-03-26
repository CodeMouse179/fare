#define NOMINMAX
//System API:
#include "System.hpp"
#include "String.hpp"
#undef T
//olcPixelGameEngine impl:
#define OLC_PGE_APPLICATION
//olcPixelGameEngine(origin):
#if defined(SYSTEM_WINDOWS) || defined(SYSTEM_LINUX)
#include "olcPixelGameEngine.h"
#endif
//olcPixelGameEngine(macOS):
#if defined(SYSTEM_MACOS)
#include "olcPGEMac.h"
#endif

class Example : public olc::PixelGameEngine
{
public:
    Example()
    {
        sAppName = "Example";
    }

public:
    bool OnUserCreate() override
    {
        // Called once at the start, so create things here
        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override
    {
        // called once per frame
        for (int x = 0; x < ScreenWidth(); x++)
            for (int y = 0; y < ScreenHeight(); y++)
                Draw(x, y, olc::Pixel(rand() % 255, rand() % 255, rand() % 255));
        return true;
    }
};

int main()
{
    Example demo;
    if (demo.Construct(256, 240, 4, 4))
        demo.Start();

    return 0;
}