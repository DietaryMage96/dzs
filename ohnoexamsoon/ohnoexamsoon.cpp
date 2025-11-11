#include <iostream>
#include <fstream>
#include <vector>
#include <mutex>
#include <string>
#include <future>
using namespace std;

class Alert {
public:
	vector<string> token_names;
	vector<double> token_prices;
	vector<string> ftoken_names;
	vector<double> ftoken_prices;
	mutex mtx;
	bool finished = false;
	Alert(vector<string> tn, vector<double> tp) : token_names(tn), token_prices(tp) {};
	void alert(string token, double price, string text) {
		cout << "==============================" << endl;
		cout << "ALERT! ( " << text << ")" << endl;
		cout << "Token: " << token << endl;
		cout << "Current price: $" << price << endl;
		cout << "==============================" << endl;
	}
	int tyahko(double price, double target_price) {
		if (price >= target_price) {
			return 1;
		}
		if (price >= target_price * 0.95) {
			return 2;
		}
		return 0;
	}
    void check() {
        while (!finished || !ftoken_names.empty()) {
            string token;
            double price;
            lock_guard<mutex> lock(mtx);
            if (!ftoken_names.empty()) {
                token = ftoken_names.back();
                price = ftoken_prices.back();
                ftoken_names.pop_back();
                ftoken_prices.pop_back();
            }
            if (token.empty()) {
                continue;
            }

            for (int i = 0; i < token_names.size(); i++) {
                if (token_names[i] == token) {
                    future<int> fut = async(&Alert::tyahko, this, price, token_prices[i]);
                    int need = fut.get();
                    if (need == 1)
                        alert(token, price, "The price has reached the required level");
                    else if (need == 2)
                        alert(token, price, "The price has almost reached the required level");
                }
            }
        }
    }
    void file() {
        ifstream file("data.txt");
        if (!file.is_open()) {
            cout << "Error opening file!" << endl;
            finished = true;
        }
        string token;
        double price;
        while (file >> token >> price) {
            {
                lock_guard<mutex> lock(mtx);
                ftoken_names.push_back(token);
                ftoken_prices.push_back(price);
            }
        }
        finished = true;
    }
    void start() {
        thread fileThread(&Alert::file, this);
        thread checkThread(&Alert::check, this);

        fileThread.join();
        checkThread.join();
    }
};
int main()
{
	vector<string> tokens = { "BTC", "ETH", "TRUMP" };
	vector<double> prices = { 60000, 3000, 10 };

	Alert a(tokens, prices);
	a.start();
}