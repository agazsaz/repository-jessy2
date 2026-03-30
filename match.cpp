#include <iostream>
#include <vector>
using namespace std;

/**
 * ИГРА СО СПИЧКАМИ
 * Правила: 
 *   - начальное количество спичек: n
 *   - за ход можно взять от 1 до p спичек
 *   - проигрывает тот, кто берёт последнюю спичку
 *   - компьютер играет по выигрышной стратегии
 */

class MatchGame {
private:
    int n, p;
    vector<bool> win;  // win[k] = true, если позиция выигрышная
    
    /**
     * Построение таблицы выигрышных позиций
     * База: win[0] = true (нет спичек - предыдущий проиграл)
     *       win[1] = false (одна спичка - вынужден взять и проиграть)
     * Рекуррентность: позиция выигрышная, если есть ход в проигрышную
     */
    void buildTable() {
        win.resize(n + 1);
        win[0] = true;
        if (n >= 1) win[1] = false;
        
        for (int k = 2; k <= n; k++) {
            win[k] = false;
            for (int m = 1; m <= min(p, k); m++) {
                if (!win[k - m]) {      // нашли ход в проигрышную позицию
                    win[k] = true;
                    break;
                }
            }
        }
    }
    
    /**
     * Поиск выигрышного хода
     * Возвращает количество спичек, которое нужно взять,
     * чтобы соперник оказался в проигрышной позиции
     */
    int winningMove(int k) {
        for (int m = 1; m <= min(p, k); m++) {
            if (!win[k - m]) return m;
        }
        return 1;   // если позиция проигрышная, берём 1
    }
    
public:
    MatchGame(int matches, int maxTake) : n(matches), p(maxTake) {
        buildTable();
    }
    
    /**
     * Основной игровой цикл
     * Компьютер всегда использует выигрышную стратегию
     */
    void play() {
        int rem = n;
        bool playerTurn = true;     // true - игрок, false - компьютер
        bool lastMoveByPlayer;      // кто сделал последний ход
        
        cout << "\n=== ИГРА НАЧАЛАСЬ ===" << endl;
        cout << "Спичек: " << n << ", за ход можно брать 1.." << p << endl;
        cout << "ПРОИГРЫВАЕТ тот, кто берёт ПОСЛЕДНЮЮ спичку!" << endl;
        cout << "=====================" << endl;
        
        while (rem > 0) {
            cout << "\nОсталось: " << rem << " спичек" << endl;
            
            int move;
            if (playerTurn) {
                // Ход игрока
                cout << "Ваш ход (1.." << min(p, rem) << "): ";
                cin >> move;
                while (move < 1 || move > min(p, rem)) {
                    cout << "Ошибка! Повторите: ";
                    cin >> move;
                }
                cout << "Вы взяли " << move << endl;
                rem -= move;
                lastMoveByPlayer = true;
            } 
            else {
                // Ход компьютера с выигрышной стратегией
                cout << "Ход компьютера: ";
                if (win[rem]) {
                    move = winningMove(rem);
                    cout << "выигрышный ход - ";
                } else {
                    move = 1;
                    cout << "проигрышная позиция - ";
                }
                move = min(move, rem);
                rem -= move;
                cout << "взято " << move << " спичек" << endl;
                lastMoveByPlayer = false;
            }
            // Проверка конца игры
            if (rem == 0) {
                cout << "\n=====================" << endl;
                if (lastMoveByPlayer) 
                    cout << "Вы взяли последнюю! ВЫ ПРОИГРАЛИ." << endl;
                else 
                    cout << "Компьютер взял последнюю! ВЫ ВЫИГРАЛИ!" << endl;
                cout << "=====================" << endl;
                break;
            }
            playerTurn = !playerTurn;   // смена хода
        }
    }
    
    /**
     * Анализ начальной позиции
     */
    void analysis() {
        cout << "\n=== АНАЛИЗ ===" << endl;
        if (win[n]) {
            cout << "Позиция ВЫИГРЫШНАЯ для первого игрока" << endl;
            cout << "Первый ход: " << winningMove(n) << " спичек" << endl;
        } else {
            cout << "Позиция ПРОИГРЫШНАЯ для первого игрока" << endl;
        }
        cout << "==============" << endl;
    }
};

int main() {
    int n, p;
    cout << "=== ИГРА СО СПИЧКАМИ ===" << endl;
    cout << "Введите количество спичек: ";
    cin >> n;
    cout << "Введите максимум за ход: ";
    cin >> p;
    MatchGame game(n, p);
    game.analysis();
    cout << "\nКто ходит первым? (1 - игрок, 2 - компьютер): ";
    char choice;
    cin >> choice;
    if (choice == '2') {
        MatchGame game2(n, p);
        game2.play();
    } else {
        game.play();
    }
    return 0;
}
