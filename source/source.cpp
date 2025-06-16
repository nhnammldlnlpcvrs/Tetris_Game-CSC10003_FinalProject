#include <SFML/Graphics.hpp>
#include <ctime>
using namespace sf;

const int M = 20;
const int N = 10;

int field[M][N] = { 0 };

struct Point {
    int x, y;
} a[4], b[4];

int figures[7][4] =
{
    1,3,5,7, // I
    2,4,5,7, // Z
    3,5,4,6, // S
    3,5,4,7, // T
    2,3,5,7, // L
    3,5,7,6, // J
    2,3,4,5, // O
};

static bool check()
{
    for (int i = 0; i < 4; i++)
        if (a[i].x < 0 || a[i].x >= N || a[i].y >= M || field[a[i].y][a[i].x])
            return false;
    return true;
}

int main()
{
    srand(static_cast<unsigned>(time(0)));

    RenderWindow window(VideoMode({320u, 480u}), "Tetris SFML 2.x");

    Texture t1, t2, t3;
    if (!t1.loadFromFile("images/tiles.png") ||
        !t2.loadFromFile("images/background.png") ||
        !t3.loadFromFile("images/frame.png"))
    {
        return -1;
    }

    Sprite s(t1), background(t2), frame(t3);

    int dx = 0, colorNum = 1;
    bool rotate = false;
    float timer = 0, delay = 0.3f;
    Clock clock;

    int n = rand() % 7;
    for (int i = 0; i < 4; i++)
    {
        a[i].x = figures[n][i] % 2;
        a[i].y = figures[n][i] / 2;
    }

    while (window.isOpen())
    {
        float time = clock.restart().asSeconds();
        timer += time;

        std::optional<sf::Event> e;
        while ((e = window.pollEvent()))
        {
            if (e->is<sf::Event::Closed>())
                window.close();

            if (e->is<sf::Event::KeyPressed>())
            {
                const auto* keyEvent = e->getIf<sf::Event::KeyPressed>();
                if (keyEvent->code == sf::Keyboard::Key::Up) rotate = true;
                else if (keyEvent->code == sf::Keyboard::Key::Left) dx = -1;
                else if (keyEvent->code == sf::Keyboard::Key::Right) dx = 1;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) delay = 0.05f;

        // Move
        for (int i = 0; i < 4; i++) { b[i] = a[i]; a[i].x += dx; }
        if (!check()) for (int i = 0; i < 4; i++) a[i] = b[i];

        // Rotate
        if (rotate)
        {
            Point p = a[1];
            for (int i = 0; i < 4; i++)
            {
                int x = a[i].y - p.y;
                int y = a[i].x - p.x;
                a[i].x = p.x - x;
                a[i].y = p.y + y;
            }
            if (!check()) for (int i = 0; i < 4; i++) a[i] = b[i];
        }

        // Tick
        if (timer > delay)
        {
            for (int i = 0; i < 4; i++) { b[i] = a[i]; a[i].y += 1; }

            if (!check())
            {
                for (int i = 0; i < 4; i++) field[b[i].y][b[i].x] = colorNum;

                colorNum = 1 + rand() % 7;
                int n = rand() % 7;
                for (int i = 0; i < 4; i++)
                {
                    a[i].x = figures[n][i] % 2;
                    a[i].y = figures[n][i] / 2;
                }
            }

            timer = 0;
        }

        // Line clear
        int k = M - 1;
        for (int i = M - 1; i >= 0; i--)
        {
            int count = 0;
            for (int j = 0; j < N; j++)
            {
                if (field[i][j]) count++;
                field[k][j] = field[i][j];
            }
            if (count < N) k--;
        }

        dx = 0; rotate = false; delay = 0.3f;

        // Draw
        window.clear(Color::White);
        window.draw(background);

        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
            {
                if (field[i][j] == 0) continue;
                s.setPosition(Vector2f{ j * 18.f + 28.f, i * 18.f + 31.f });
                s.setPosition(Vector2f{ a[i].x * 18.f + 28.f, a[i].y * 18.f + 31.f });
                window.draw(s);
            }

        for (int i = 0; i < 4; i++)
        {
            sf::IntRect rect(colorNum * 18, 0, 18, 18);
            s.setTextureRect(rect);
            s.setPosition({ static_cast<float>(a[i].x * 18 + 28), 
                            static_cast<float>(a[i].y * 18 + 31) });
            window.draw(s);
        }

        window.draw(frame);
        window.display();
    }

    return 0;
}
