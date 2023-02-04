#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

//function to find the mean of a vector
double mean(vector<double> l)
{
    double mean = 0;
    for (const double& i : l) {
        mean += i;
    }
    mean = mean / double(l.size());
    return mean;
}

//function to find the sum of a vector
double sum(vector<double> l)
{
    double sum = 0;
    for (const double& i : l) {
        sum += i;
    }

    return sum;
}

//function to find the median of a vector
double median(vector<double> jk)
{
    size_t size = jk.size();

    if (size == 0)
    {
        return 0;
    }
    else
    {
        std::sort(jk.begin(), jk.end());
        if (size % 2 == 0)
        {
            return (jk[size / 2 - 1] + jk[size / 2]) / 2;
        }
        else
        {
            return jk[size / 2];
        }
    }
}

//function to find the range of  vector
double range(vector<double> jk)
{
    std::sort(jk.begin(), jk.end());
    double range2 = jk.back() - jk.front();
    return range2;

}

//function to find the covariance of a vector
double covariance(vector<double> jk, vector<double> rk)
{

    vector<double> result;
    double mean2 = mean(jk);
    double mean3 = mean(rk);


    for (int i = 0; i < jk.size(); i++) {
        double nl = jk[i] - mean2;
        double ab = rk[i] - mean3;
        double res = nl * ab;
        result.push_back(res);
    }
    double resu = sum(result);
    double resu1 = resu / (double(jk.size()) - 1);
    return resu1;


}

//function to find the correlation of a vector
double correlation(vector<double> jk, vector<double> rk)
{
    double var = 0;
    double var2 = 0;
    double mean2 = mean(jk);
    double mean3 = mean(rk);

    for( int n = 0; n < jk.size(); n++ )
    {
        var += (jk[n] - mean2) * (jk[n] - mean2);
    }
    for( int n = 0; n < rk.size(); n++ )
    {
        var2 += (rk[n] - mean3) * (rk[n] - mean3);
    }
    var /= jk.size();
    var2 /= rk.size();
    double sd1 = sqrt(var);
    double sd2 = sqrt(var2);
    double result = covariance(jk, rk) / (sd1 * sd2);
    return result;
}

int main(int argc, char** argv)
{
    ifstream inFS;
    string line;
    string rm_in, medv_in;
    const int MAX_LEN = 1000;
    vector<double> rm(MAX_LEN);
    vector<double> medv(MAX_LEN);

    cout << "Opening file Boston.csv." << endl;

    inFS.open("Boston.csv");
    if (!inFS.is_open()) {
        cout << "Could not open file Boston.csv" << endl;
        return 1;
       }
    getline(inFS, line);
    int numObservations = 0;

    while (inFS.good()) {
        getline(inFS, rm_in, ',');
        getline(inFS, medv_in, '\n');

        rm.at(numObservations) = stof(rm_in);
        medv.at(numObservations) = stof(medv_in);

        numObservations++;

      }
    rm.resize(numObservations);
    medv.resize(numObservations);
    inFS.close();

    //print stats
    cout << mean(rm) << endl;
    cout << mean(medv) << endl;
    cout << sum(rm) << endl;
    cout << sum(medv) << endl;
    cout << median(rm) << endl;
    cout << median(medv) << endl;
    cout << range(rm) << endl;
    cout << range(medv) << endl;
    cout << covariance(rm, medv) << endl;
    cout << correlation(rm, medv) << endl;


}

