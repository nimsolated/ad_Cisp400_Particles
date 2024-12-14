#include "Engine.h"
#include "Particle.h"

using namespace std;
using namespace sf;

Engine::Engine()
{
	m_Window.create(VideoMode(VideoMode::getDesktopMode().width / 2, VideoMode::getDesktopMode().height / 2), "Particles!! by Armin and Daniel");
}

void Engine::run()
{
	srand(time(0));

	Clock cl;

	cout << "Starting Particle unit tests..." << endl;
	Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
	p.unitTests();
	cout << "Unit tests complete.  Starting engine..." << endl;

	while (m_Window.isOpen())
	{
		Time time1 = cl.restart();
		float seconds = time1.asSeconds();

		input();
		update(seconds);
		draw();
	}
}

void Engine::input()
{
	Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			m_Window.close();
		}
		if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
		{
			m_Window.close();
		}

		if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
		{
			for (int i = 0; i < NUM_PARTICLES; i++)
			{
				int pVertices = ((rand() % 26) + 25);
				
				Particle p(
					m_Window,
					pVertices,
					Vector2i(event.mouseButton.x, event.mouseButton.y)
				);

				m_particles.push_back(p);
			}
		}
	}
}

void Engine::update(float dtAsSeconds)
{
	for (vector<Particle>::iterator iter = m_particles.begin(); iter != m_particles.end(); ++iter)
	{
		if ((*iter).getTTL() > 0.0f)
		{
			(*iter).update(dtAsSeconds);
			++iter;
		}
		else
		{
			iter = m_particles.erase(iter);
		}
	}
}

void Engine::draw()
{
	m_Window.clear(Color(0, 0, 0, 255));

	for (size_t i = 0; i < m_particles.size(); i++)
	{
		m_Window.draw(m_particles[i]);
	}

	m_Window.display();
}