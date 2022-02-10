#include <iostream>
#include <ctime>
#include <Windows.h>

#define sizeY 21
#define sizeX 42
#define FoodDuration 5

short int A[sizeY][sizeX] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
                                -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,
                                -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,
                                -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,
                                -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,
                                -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,
                                -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,
                                -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,
                                -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,
                                -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,
                                -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,
                                -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,
                                -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,
                                -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,
                                -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,
                                -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,
                                -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,
                                -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,
                                -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,
                                -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,
                                -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
};                              //-1 border, 0 empty space, -2 food, >0 snake

void PrintMatrix(unsigned int pts, short int mf) {
    system("CLS");
    std::cout << "Score: " << pts - 1 << " | Missed food " << mf << " | use WASD to move\n";
    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++)
            switch (A[i][j])
            {
            case -2:
                std::cout << 'F';
                break;
            case -1:
                std::cout << (char)219u;
                break;
            case 0:
                std::cout << ' ';
                break;
            default:
                //std::cout << A[i][j];
                std::cout << 'X';
                break;
            }
        std::cout << std::endl;
    }
}

void GameOver() {
    //system("CLS");
    std::cout << "  ______                                            ______                                \n";
    std::cout << " /      \\                                          /      \\                               \n";
    std::cout << "/$$$$$$  |  ______   _____  ____    ______        /$$$$$$  | __     __  ______    ______  \n";
    std::cout << "$$ | _$$/  /      \\ /     \\/    \\  /      \\       $$ |  $$ |/  \\   /  |/      \\  /      \\ \n";
    std::cout << "$$ |/    | $$$$$$  |$$$$$$ $$$$  |/$$$$$$  |      $$ |  $$ |$$  \\ /$$//$$$$$$  |/$$$$$$  |\n";
    std::cout << "$$ |$$$$ | /    $$ |$$ | $$ | $$ |$$    $$ |      $$ |  $$ | $$  /$$/ $$    $$ |$$ |  $$/ \n";
    std::cout << "$$ \\__$$ |/$$$$$$$ |$$ | $$ | $$ |$$$$$$$$/       $$ \\__$$ |  $$ $$/  $$$$$$$$/ $$ |      \n";
    std::cout << "$$    $$/ $$    $$ |$$ | $$ | $$ |$$       |      $$    $$/    $$$/   $$       |$$ |      \n";
    std::cout << " $$$$$$/   $$$$$$$/ $$/  $$/  $$/  $$$$$$$/        $$$$$$/      $/     $$$$$$$/ $$/       \n";
    std::cout << "                                                                                          \n";
}

void input(short int& Direction) {
    if (GetKeyState('A') & 0x8000) Direction = 0;
    if (GetKeyState('W') & 0x8000) Direction = 1;
    if (GetKeyState('D') & 0x8000) Direction = 2;
    if (GetKeyState('S') & 0x8000) Direction = 3;
}

void sleep(float seconds, short int& Direction) {
    clock_t startClock = clock();
    float secondsAhead = seconds * CLOCKS_PER_SEC;
    while (clock() < startClock + secondsAhead) input(Direction);
}

void MoveTail(int Hx, int Hy, unsigned short int pts, bool is) {
    pts++;
    while (A[Hy][Hx] != pts) {
        if (A[Hy - 1][Hx] == A[Hy][Hx]) {
            Hy--;
            A[Hy][Hx]++;
        }
        if (A[Hy + 1][Hx] == A[Hy][Hx]) {
            Hy++;
            A[Hy][Hx]++;
        }
        if (A[Hy][Hx - 1] == A[Hy][Hx]) {
            Hx--;
            A[Hy][Hx]++;
        }
        if (A[Hy][Hx + 1] == A[Hy][Hx]) {
            Hx++;
            A[Hy][Hx]++;
        }
    }
    if (is) A[Hy][Hx] = pts;
    else A[Hy][Hx] = 0;
}

void CreateFood() {
    short int Fx = rand() % sizeX + 1, Fy = rand() % sizeY + 1;
    while (A[Fy][Fx] != 0) {
        Fx = rand() % 21 + 1;
        Fy = rand() % 10 + 1;
    }
    A[Fy][Fx] = -2;
}

bool IsFood() {
    for (int i = 1; i < sizeY - 1; i++)
        for (int j = 1; j < sizeX - 1; j++)
            if (A[i][j] == -2) return true;
    return false;
}

void ClearFood() {
    for (int i = 1; i < sizeY - 1; i++)
        for (int j = 1; j < sizeX - 1; j++)
            if (A[i][j] == -2) A[i][j] = 0;
}

int main() {
    unsigned short int pts = 1, Hy = 10, Hx = 21, tics = 1;
    short int Direction = 10, OldDir = 10, MissedFood = 0; // 0 left, 1 up, 2 right, 3 down
    bool foo = 1;
    double speed = 0.07;
    srand(time(NULL));
    CreateFood();
    PrintMatrix(pts, MissedFood);
    while (Direction == 10) input(Direction);
    clock_t startClock = clock();
    float Ftimmer = FoodDuration * CLOCKS_PER_SEC;
    while (Hx < sizeX - 1 && Hx > 0 && Hy < sizeY - 1 && Hy > 0 && foo && MissedFood < 10) {
        PrintMatrix(pts, MissedFood);
        tics++;
        //Direction = _getch();
        //Direction = fgetc(stdin);
        //Direction = getchar();
        if (!IsFood()) {
            CreateFood();
            MissedFood = 0;
            startClock = clock();
        }
        else if (clock() >= startClock + Ftimmer) {
            ClearFood();
            CreateFood();
            MissedFood++;
            startClock = clock();
        }
        if (tics == 90) {
            tics = 0;
            speed -= 0.01;
        }
        OldDir = Direction;
        sleep((Direction == 1 || Direction == 3) ? speed * 1.75 : speed, Direction);
        switch (Direction) {
        case(0):
            Hx--;
            if (A[Hy][Hx] > 0) {
                foo = 0;
                break;
            }
            if (A[Hy][Hx] != -2) {
                A[Hy][Hx] = 1;
                if (pts == 1) A[Hy][Hx + pts] = 0;
                else MoveTail(Hx, Hy, pts, 0);
            }
            else {
                A[Hy][Hx] = 1;
                MoveTail(Hx, Hy, pts, 1);
                pts++;
            }
            break;
        case(1):
            Hy--;
            if (A[Hy][Hx] > 0) {
                foo = 0;
                break;
            }
            if (A[Hy][Hx] != -2) {
                A[Hy][Hx] = 1;
                if (pts == 1) A[Hy + pts][Hx] = 0;
                else MoveTail(Hx, Hy, pts, 0);
            }
            else {
                A[Hy][Hx] = 1;
                MoveTail(Hx, Hy, pts, 1);
                pts++;
            }
            break;
        case(2):
            Hx++;
            if (A[Hy][Hx] > 0) {
                foo = 0;
                break;
            }
            if (A[Hy][Hx] != -2) {
                A[Hy][Hx] = 1;
                if (pts == 1) A[Hy][Hx - pts] = 0;
                else MoveTail(Hx, Hy, pts, 0);
            }
            else {
                A[Hy][Hx] = 1;
                MoveTail(Hx, Hy, pts, 1);
                pts++;
            }
            break;
        case(3):
            Hy++;
            if (A[Hy][Hx] > 0) {
                foo = 0;
                break;
            }
            if (A[Hy][Hx] != -2) {
                A[Hy][Hx] = 1;
                if (pts == 1) A[Hy - pts][Hx] = 0;
                else MoveTail(Hx, Hy, pts, 0);
            }
            else {
                A[Hy][Hx] = 1;
                MoveTail(Hx, Hy, pts, 1);
                pts++;
            }
            break;
        }
    }
    GameOver();
    return 0;
}