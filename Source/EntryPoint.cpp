#include <Anggur/System/Application.hpp>
#include <Anggur/Helper/Log.hpp>

using namespace Anggur;
using R = Renderer;

struct Pendulum
{
    Vector origin;
    float size = 2;
    float length = 30;
    float angle = 0;
    float angleAcc = 0;
    float angleVel = 0;

    float gravity = -9.8;
    float damping = 0.999;

    Color wire;
    Color bob;

    void Update(float dx)
    {
        angleAcc = Math::Cos(angle) * (gravity / length);
        angleVel += angleAcc;
        angleVel *= damping;
        angle += angleVel * dx;
    }

    void Render()
    {
        Vector tip = Vector::CreatePolar(angle, length);
        R::AddLine(origin, tip, 0.125, wire);
        R::AddCircle(tip, size, bob);
    }
};

class App: public Application
{
    Camera camera;

    bool run = false;

    std::vector<Pendulum> pendulums;

    void OnAttach() override
    {
        camera.SetRatio(mWindow->GetSize());
        camera.SetDistance((0.02));
        camera.SetOffset(Vector(0.0, 0.8));

        Color wireA = Color(0.7, 0.7, 0.7);
        Color wireB = Color::white;
        Color bobA = Color::Lerp(Color::purple, Color::black, 0.5);
        Color bobB = Color::purple;

        size_t total = 10;

        for (size_t i = 0; i < total; ++i)
        {
            Pendulum p;
            float amount = i / static_cast<float>(total);

            p.size = 2 + (2 * amount);
            p.length = 16 + (32 * amount);
            p.wire = Color::Lerp(wireA, wireB, amount);
            p.bob = Color::Lerp(bobA, bobB, amount);
            pendulums.push_back(p);
        }
    }

    void OnUpdate(float dx) override
    {
        if (Input::IsKeyPressed(Key::Space)) run = !run;

        R::ClearBackground();
        R::BeginScene(camera);

        for (Pendulum& p: pendulums)
        {
            if (run) p.Update(dx);
            p.Render();
        }

        R::AddCircle(Vector(0, 0), 1);

        R::EndScene();
    }
};

Anggur_EntryPoint(App);
