#include <Anggur/System/Application.hpp>
#include <Anggur/Helper/Log.hpp>

using namespace Anggur;
using R = Renderer;

class App: public Application
{
    Camera camera;

    void OnInitialize() override
    {
        camera.SetRatio(mWindowConfig.GetRatio());
        camera.Scale(Vector(0.01, 0.01));
    }

    void OnUpdate(float dx) override
    {
        R::ClearBackground();
        R::BeginScene(camera);

        R::AddCircle(Vector(0, 12), 10, Color::purple);
        R::AddCircle(Vector(-12, -9), 10, Color::purple);
        R::AddCircle(Vector(12, -9), 10, Color::purple);

        R::AddPolyring({Vector(0, 40), Vector(-35, -22), Vector(35, -22)}, 1);

        R::EndScene();
    }
};

int main() 
{
	App app;
	app.Run();
}
