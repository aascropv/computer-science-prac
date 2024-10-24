#include <iostream>
using namespace std;

int initial_power, nature, evil;
int rabbit_power[3], cat_power[4];
int rabbit(int month) {
    if (month == 0) {
        rabbit_power[0] = 0;
        return 0;
    }
    else if (month == 1 || month == 2) {
        rabbit_power[1] = initial_power;
        rabbit_power[2] = initial_power;
        return initial_power;
    }
    else {
        rabbit_power[0] = rabbit_power[1];
        rabbit_power[1] = rabbit_power[2];
        if (month % 3 == 0) rabbit_power[2] = (rabbit_power[0] + rabbit_power[1]) / nature;
        else rabbit_power[2] = (rabbit_power[0] + rabbit_power[1]) * nature;
        return rabbit_power[2];
    }
}

int cat(int month) {
    if (month == 0) {
        cat_power[0] = 0;
        return 0;
    }
    else if (month == 1 || month == 2) {
        cat_power[1] = 1;
        cat_power[2] = 1;
        return 1;
    }
    else if (month == 3) {
        cat_power[3] = (cat_power[0] + cat_power[1] + cat_power[2]) + evil;
        return cat_power[3];
    }
    else {
        cat_power[0] = cat_power[1];
        cat_power[1] = cat_power[2];
        cat_power[2] = cat_power[3];
        if (month % 5 == 0) cat_power[3] = (cat_power[0] + cat_power[1] + cat_power[2]) - evil;
        else cat_power[3] = (cat_power[0] + cat_power[1] + cat_power[2]) + evil;
        return cat_power[3];
    }
}

int main() {

    int rabbit_wins = 0, cat_wins = 0;
    int month;
    cin >> month >> initial_power >> nature >> evil;
    for (int i = 1; i <= month; i++) {
        if (rabbit(i) > cat(i)) {
            rabbit_wins++;
        }
        else {
            cat_wins++;
        }
    }
    cout << "RabbitWin: " << rabbit_wins << " CatWin: " << cat_wins;
    return 0;
}