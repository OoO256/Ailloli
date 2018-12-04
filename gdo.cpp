#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int num_data;
const double learning_rate = 0.01;
const int num_shooting = 2000;

vector<double>x_data;
vector<double>y_data;

double get_gradiant_w(const double W, const double B) {
	double ret = 0;
	for (int i = 0; i < num_data; i++)
	{
		ret += (W * x_data[i] + B - y_data[i]) * x_data[i];
	}
	return ret * 2 / num_data;

}

double get_gradiant_b(const double W, const double B) {
	double ret = 0;
	for (int i = 0; i < num_data; i++)
	{
		ret += (W * x_data[i] + B - y_data[i]);
	}
	return ret * 2 / num_data;
}


double get_cost(const double W, const double B) {
	double ret = 0;
	for (int i = 0; i < num_data; i++)
	{
		ret += (W * x_data[i] + B - y_data[i])*(W * x_data[i] + B - y_data[i]);
	}
	return ret / num_data;
}



int main() {
	cout << "데이터의 갯수" << endl;
	cin >> num_data;

	x_data.resize(num_data);
	y_data.resize(num_data);

	cout << " x들 : ";
	for (auto& x : x_data)
	{
		cin >> x;
	}
	cout << endl;

	cout << " y들 : ";
	for (auto& y : y_data)
	{
		cin >> y;
	}
	cout << endl;

	double w, b;
	cout << "w, b 찍어보시오" << endl;
	cin >> w >> b;


	for (int s = 0; s < num_shooting; s++)
	{
		auto gw = get_gradiant_w(w, b);
		auto gb = get_gradiant_b(w, b);

		w -= learning_rate * gw;
		b -= learning_rate * gb;

		double cost = get_cost(w,b);

		if (s % ( num_shooting/10) == 0)
		{
			cout << "shot : " << s << endl;
			cout << "gw : " << gw << endl;
			cout << "gd : " << gb << endl;
			cout << "w : " << w << endl;
			cout << "b : " << b << endl;

			cout << "cost : " << cost << endl << endl;			
		}
	}
}