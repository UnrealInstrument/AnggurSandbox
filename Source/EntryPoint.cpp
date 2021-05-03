#include <Anggur/System/Application.hpp>
#include <Anggur/Helper/Log.hpp>

using namespace Anggur;
using R = Renderer;

class App: public Application
{
    Camera camera;

    void OnAttach() override
    {
        camera.SetRatio(mWindow->GetSize());
        camera.SetDistance(0.0125);
        camera.Move(Vector(0.0, 0.125));
    }

    void OnUpdate(float dx) override
    {        
        R::ClearBackground();
        R::BeginScene(camera);

        if (Input::IsMouseScrolled())
            camera.Zoom(Input::GetMouseWheel().y * 0.1);

        R::AddCircle(Vector(0, 12), 10, Color::purple);
        R::AddCircle(Vector(-12, -9), 10, Color::purple);
        R::AddCircle(Vector(12, -9), 10, Color::purple);

        R::AddPolyring({Vector(0, 40), Vector(-35, -22), Vector(35, -22)}, 1);

        R::EndScene();
    }
};

Anggur_EntryPoint(App);
