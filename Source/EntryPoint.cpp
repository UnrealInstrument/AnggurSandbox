#include <Anggur/System/Application.hpp>
#include <Anggur/Helper/Log.hpp>
#include <array>

using namespace Anggur;
using R = Renderer;

class App: public Application
{
    Camera camera;

    void OnConfigure(WindowConfig &config) override
    {
        config.width = 480;
        config.height = 360;

        camera.SetRatio((float) config.width / (float) config.height);
        camera.Scale(Vector(0.1, 0.1));
    }

    void OnUpdate(float dx) override
    {
        R::ClearBackground();
        R::BeginScene(camera);

        R::AddCircle(Vector(0, 0), 3, Color::purple);

        R::EndScene();
    }
};

int main() 
{
	App app;
	app.Run();
}
