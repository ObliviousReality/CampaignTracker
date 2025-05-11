#pragma once

enum class Dice
{
    D4 = 4,
    D6 = 6,
    D8 = 8,
    D10 = 10,
    D12 = 12,
    D20 = 20,
    D100 = 100,
};

namespace Core
{
    static const int getDiceValue(const Dice d)
    {
        switch (d)
        {
            case Dice::D4: return 4;
            case Dice::D6: return 6;
            case Dice::D8: return 8;
            case Dice::D10: return 10;
            case Dice::D12: return 12;
            case Dice::D20: return 20;
            case Dice::D100: return 100;
        }
        return 0;
    }

    static const int getDiceAverageValueR(const Dice d)
    {
        switch (d)
        {
            case Dice::D4: return 3;
            case Dice::D6: return 4;
            case Dice::D8: return 5;
            case Dice::D10: return 6;
            case Dice::D12: return 7;
            case Dice::D20: return 11;
            case Dice::D100: return 51;
        }
        return 0;
    }

    static const float getDiceAverageValue(const Dice d)
    {
        switch (d)
        {
            case Dice::D4: return 2.5f;
            case Dice::D6: return 3.5f;
            case Dice::D8: return 4.5f;
            case Dice::D10: return 5.5f;
            case Dice::D12: return 6.5f;
            case Dice::D20: return 10.5f;
            case Dice::D100: return 50.5f;
        }
        return 0;
    }

    static const int roll(const Dice d) { return (rand() % getDiceValue(d)); }
};
