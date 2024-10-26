#include <iostream>
#include <limits>
#include <vector>
#include <string>

using namespace std;

float mean(const vector<float>& values) {
    if (values.size() == 0) return 0;
    float sum = 0;
    for(int i = 0; i < values.size(); i++) sum += values[i];
    return sum / values.size();
}

pair<float, float> minMax(const vector<float>& values) {
    if (values.size() == 0) {
        return make_pair(0.0f, 0.0f);
    }
    float min = values[0], max = values[0];
    for(int i = 1; i < values.size(); i++) {
        if(values[i] < min) min = values[i];
        if(values[i] > max) max = values[i];
    }
    return make_pair(min, max);
}

int argmax(const vector<float>& data) {
    if (data.empty()) return -1;
    int max_index = 0;
    float max_value = data[0];

    for (int i = 1; i < data.size(); ++i) {
        if (data[i] > max_value) {
            max_index = i;
            max_value = data[i];
        }
    }

    return max_index;
}

void sort(vector<float>& values) {
    int n = values.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (values[j] < values[j + 1]) {
                float temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }
}

bool remove_first_negative_element(vector<int>& vec, int& removed_element) {
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] < 0) {
            removed_element = vec[i];
            vec.erase(vec.begin() + i);
            return true;
        }
    }
    return false;
}

string replace(const string& str, const string& old_substr, const string& new_substr) {
    string result = str;
    size_t pos = 0;

    while ((pos = result.find(old_substr, pos)) != string::npos) {
        result.replace(pos, old_substr.length(), new_substr);
        pos += new_substr.length();
    }

    return result;
}

vector<string> split(const string& str, char sep) {
    vector<string> result;
    size_t start = 0;
    size_t end;
    while ((end = str.find(sep, start)) != string::npos) {
        if (end != start) {
            result.push_back(str.substr(start, end - start));
        }
        start = end + 1;
    }
    if (start <= str.length()) {
        result.push_back(str.substr(start));
    }

    return result;
}

string join(const vector<string>& vec, const string& sep) {
    string result;

    for (size_t i = 0; i < vec.size(); ++i) {
        result += vec[i];
        if (i < vec.size() - 1) {
            result += sep;
        }
    }

    return result;
}

int main() {
    while (true) {
        int d;
        cout<< "Выберите задание:\n"
        << "1. \n"
        << "2. \n"
        << "3. \n"
        << "4. \n"
        << "5. \n"
        << "6. \n"
        << "7. \n"
        << "8. \n"
        << "0. Выход\n";
        std:cin >> d;
        if (d == 0) break;

        switch(d) {
            case 1: {
                vector<float> values;
                int n;
                cout << "Введите количество значений: ";
                cin >> n;
                cout << "Введите " << n << " чисел с плавающей точкой:\n";
                for(int i = 0; i < n; ++i) {
                    float val;
                    cin >> val;
                    values.push_back(val);
                }
                float result = mean(values);
                cout << "Среднее = " << result << endl;
                break;
            }
            case 2: {
                vector<float> values;
                int n;
                cout << "Введите количество значений: ";
                cin >> n;
                if (n == 0) {
                    cout << "Нет введенных значений.\n";
                    break;
                }
                cout << "Введите " << n << " чисел с плавающей точкой:\n";
                for(int i = 0; i < n; ++i) {
                    float val;
                    cin >> val;
                    values.push_back(val);
                }
                pair<float, float> result = minMax(values);
                cout << "Минимум = " << result.first << ", Максимум = " << result.second << endl;
                break;
            }
            case 3: {
                vector<float> data;
                int n;
                cout << "Введите количество значений: ";
                cin >> n;
                if (n == 0) {
                    cout << "Нет введенных значений.\n";
                    break;
                }
                cout << "Введите " << n << " чисел с плавающей точкой:\n";
                for(int i = 0; i < n; ++i) {
                    float val;
                    cin >> val;
                    data.push_back(val);
                }
                int index = argmax(data);
                if (index != -1)
                    cout << "Индекс максимального элемента: " << index << endl;
                else
                    cout << "Пустые данные\n";
                break;
            }
            case 4: {
                vector<float> values;
                int n;
                cout << "Введите количество значений: ";
                cin >> n;
                if (n == 0) {
                    cout << "Нет введенных значений.\n";
                    break;
                }
                cout << "Введите " << n << " чисел с плавающей точкой:\n";
                for(int i = 0; i < n; ++i) {
                    float val;
                    cin >> val;
                    values.push_back(val);
                }
                sort(values);
                cout << "Отсортированные значения в порядке убывания:\n";
                for(float val : values) {
                    cout << val << " ";
                }
                cout << endl;
                break;
            }
            case 5: {
                vector<int> vec;
                int n;
                cout << "Введите количество целых чисел: ";
                cin >> n;
                cout << "Введите " << n << " целых чисел:\n";
                for(int i = 0; i < n; ++i) {
                    int val;
                    cin >> val;
                    vec.push_back(val);
                }
                int removed_element;
                bool result = remove_first_negative_element(vec, removed_element);
                if (result) {
                    cout << "Удаленный элемент: " << removed_element << endl;
                    cout << "Вектор после удаления:\n";
                    for(int val : vec) {
                        cout << val << " ";
                    }
                    cout << endl;
                } else {
                    cout << "Отрицательный элемент не найден.\n";
                }
                break;
            }
            case 6: {
                string str, old_substr, new_substr;
                cout << "Введите исходную строку: ";
                cin.ignore();
                getline(cin, str);
                cout << "Введите подстроку для замены: ";
                getline(cin, old_substr);
                cout << "Введите новую подстроку: ";
                getline(cin, new_substr);
                string result = replace(str, old_substr, new_substr);
                cout << "Результирующая строка: " << result << endl;
                break;
            }
            case 7: {
                string str;
                char sep;
                cout << "Введите строку для разделения: ";
                cin.ignore();
                getline(cin, str);
                cout << "Введите символ-разделитель: ";
                cin >> sep;
                vector<string> result = split(str, sep);
                cout << "Результат разделения:\n";
                for(const string& s : result) {
                    cout << s << endl;
                }
                break;
            }
            case 8: {
                vector<string> vec;
                int n;
                cout << "Введите количество строк: ";
                cin >> n;
                cout << "Введите " << n << " строк:\n";
                cin.ignore();
                for(int i = 0; i < n; ++i) {
                    string s;
                    getline(cin, s);
                    vec.push_back(s);
                }
                string sep;
                cout << "Введите строку-разделитель: ";
                getline(cin, sep);
                string result = join(vec, sep);
                cout << "Результирующая строка: " << result << endl;
                break;
            }
        }
    }
    return 0;
}
