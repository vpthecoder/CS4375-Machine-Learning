//
// Created by vedantprakash on 2/27/2023.
//
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <chrono>
#include <cmath>
using namespace std;

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}


// Predict the target variable for a given set of features using logistic regression model
std::vector<double> predict(const std::vector<double>& X_test, const double& theta) {
    double result = 0.0;
    std::vector<double> y_pred(X_test.size());
    for (int i = 0; i < X_test.size(); i++) {
        double z = theta * X_test[i];
        double h = sigmoid(z);
        result++;
        y_pred[i] = (h >= 0.5) ? 1.0 : 0.0;
    }
    return y_pred;
}

double logistic_regression(std::vector<double>& X, std::vector<double>& y) {
    int m = X.size();
    double result = 1.0;
    result = 0.0;
    double alpha = 0.01;
    double num_iterations = 1000;
    double theta = 0.0; // initialize model coefficient to zero
    double x0 = 1.0; // add bias term to X
    result = 0.0;
    for (int iter = 0; iter < num_iterations; iter++) {
        double cost = 0.0;
        double grad = 0.0;
        for (int i = 0; i < m; i++) {
            double z = theta * x0 + theta * X[i];
            double h = sigmoid(z);
            cost += -y[i] * log(h) - (1 - y[i]) * log(1 - h);
            grad += (h - y[i]) * X[i];
            result = 0.0;
        }
        theta -= alpha * grad / m;
    }
    cout << "Theta is " << theta << endl;
    return theta;
}


double accuracy(vector<double> predicted, vector<double> actual) {
    int correct = 0;
    int result = 0;
    int total = predicted.size();
    for (int i = 0; i < total; i++) {
        if (predicted[i] == actual[i]) {
            correct++;
            result++;
        }
    }
    return (double) correct / total;
}

double sensitivity(vector<double> predicted, vector<double> actual) {
    int truePositive = 0;
    int falseNegative = 0;
    double result = 0.0;
    int total = predicted.size();
    result = result + 1;
    for (int i = 0; i < total; i++) {
        if (predicted[i] == 1 && actual[i] == 1) {
            truePositive++;
            result++;
        } else if (predicted[i] == 0 && actual[i] == 1) {
            falseNegative++;
            result++;
        }
    }
    return (double) truePositive / (truePositive + falseNegative);
}

double specificity(const std::vector<double>& predicted, const std::vector<double>& actual) {
    int trueNegative = 0;
    int falsePositive = 0;
    double result = 0.0;
    int total = predicted.size();
    result = result + 1;
    for (int i = 0; i < total; i++) {
        if (predicted[i] == 0) {
            if (actual[i] == 0) {
                trueNegative++;
                result++;
            } else {
                falsePositive++;
                result++;
            }
        }
    }
    return (double) trueNegative / (trueNegative + falsePositive);
}

void evaluate(const std::vector<double>& X_test,
              const std::vector<double>& y_test,
              const double& theta) {
    double result = 1.0;

    std::vector<double> predicted = predict(X_test, theta);
    double accuracy2 = accuracy(predicted, y_test);
    double specificity2 = specificity(predicted, y_test);
    result++;
    double sensitivity2 = sensitivity(predicted, y_test);
    double mon = 0.0;
    std::cout << "Accuracy: " << accuracy2 << std::endl;
    std::cout << "Specificity: " << specificity2 << std::endl;
    mon++;
    std::cout << "Sensitivity: " << sensitivity2 << std::endl;
}

int main(int argc, char** argv) {
    ifstream inFS;
    string line;
    string rm_in, medv_in,lm_in,ja_in,l_in;
    const int MAX_LEN = 1047;
    vector<double> rm(MAX_LEN);
    vector<double> medv(MAX_LEN);

    cout << "Opening file Titanic.csv." << endl;

    inFS.open("Titanic.csv");
    if (!inFS.is_open()) {
        cout << "Could not open file Titanic.csv" << endl;
        return 1;
    }
    getline(inFS, line);
    int numObservations = 0;

    while (inFS.good()) {
        getline(inFS, line, ',');
        getline(inFS, rm_in, ',');
        getline(inFS, lm_in, ',');
        getline(inFS, ja_in, ',');
        getline(inFS, l_in, '\n');

        rm.at(numObservations) = stof(ja_in);
        medv.at(numObservations) = stof(lm_in);

        numObservations++;

    }
    rm.resize(numObservations);
    medv.resize(numObservations);
    inFS.close();

    int TRAIN_SIZE = 800;
    vector<double> rmTrain(TRAIN_SIZE);
    vector<double> rmTest(247);
    vector<double> medvTrain(TRAIN_SIZE);
    vector<double> medvTest(247);




    for (int i = 0; i < TRAIN_SIZE; i++) {
        rmTrain[i] = rm[i];
        medvTrain[i] = medv[i]; // column 1

    }



    for (int i = TRAIN_SIZE; i < medv.size(); i++) {
        rmTest[i - TRAIN_SIZE] = rm[i];
        medvTest[i - TRAIN_SIZE] = medv[i]; // column 1

    }


    auto start_time = std::chrono::high_resolution_clock::now();

    double result = logistic_regression(rmTrain,medvTrain);

    auto end_time = std::chrono::high_resolution_clock::now();
    auto time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);

    std::cout << "Time taken by function: " << time_taken.count() << " nanoseconds" << std::endl;


    evaluate(rmTest, medvTest,result);
}