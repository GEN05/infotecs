/**
 * @author Eugene Gusarov
 */
#include <fstream>

bool is_console;

class write {
public:

    static void to_console(const std::vector<int> &answer) {
        for (int i : answer) {
            std::cout << i << std::endl;
        }
    }

    static void to_file(const std::vector<int> &answer) {
        std::string filename;
        std::cout << "Please input filename" << std::endl;
        std::cin >> filename;
        std::ofstream out;          // поток для записи
        out.open(filename); // окрываем файл для записи
        if (out.is_open()) {
            for (int i : answer) {
                out << i << std::endl;
            }
        }
        out.close();
    }

    static void check(bool flag) {
        is_console = flag;
    }

    static void write_to(const std::vector<int> &answer) {
        if (is_console) {
            to_console(answer);
        } else {
            to_file(answer);
        }
    }
};