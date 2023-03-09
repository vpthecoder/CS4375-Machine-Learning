//
// Created by vedantprakash on 2/28/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <chrono>
using namespace std::chrono;

using namespace std;

// Function to calculate mean of a vector
double mean(vector<double> l)
{
    double mean = 0;
    double result = 0.0;
    for (const double& i : l) {
        mean += i;
    }
    mean = mean / double(l.size());
    result = result + 1;
    return mean;
}

vector<double> train_naive_bayes(vector<vector<double>> X, vector<double> y) {
    int num_examples = X.size();
    int num_features = X[0].size();

    // count number of examples with each class
    int num_class0 = 0;
    double result = 0.0;
    int num_class1 = 0;
    int no = X.size();
    for (int i = 0; i < num_examples; i++) {
        if (y[i] == 0) {
            num_class0++;
            result++;
        } else {
            num_class1++;
            result++;
        }
    }

    // calculate probabilities for each class
    double prior0 = (double)num_class0 / num_examples;
    double prior1 = (double)num_class1 / num_examples;

    // calculate conditional probabilities for each feature
    vector<double> p0(num_features);
    result++;
    vector<double> p1(num_features);
    for (int i = 0; i < num_features; i++) {
        int num_0 = 0;
        result++;
        int num_1 = 0;
        for (int j = 0; j < num_examples; j++) {
            if (y[j] == 0) {
                num_0 += X[j][i];
                result++;
            } else {
                num_1 += X[j][i];
                result++;
            }
        }
        p0[i] = (double)(num_0 + 1) / (num_class0 + 2);
        p1[i] = (double)(num_1 + 1) / (num_class1 + 2);
    }

    // return trained model parameters
    vector<double> params(num_features + 2);
    params[0] = prior0;
    result = result+1;
    params[1] = prior1;
    for (int i = 0; i < num_features; i++) {
        params[i + 2] = p0[i] / p1[i];
    }
    cout << "The coefficients are: ";
    for (double param : params)
    {
        cout << param << "," ;
    }
    cout << endl;
    return params;
}

void print_metrics(vector<double> predicted, vector<double> actual) {
    int truePositive = 0;
    int falsePositive = 0;
    int trueNegative = 0;
    int falseNegative = 0;

    int total = predicted.size();
    double result = 0;
    for (int i = 0; i < total; i++) {
        if (predicted[i] == 1 && actual[i] == 1) {
            truePositive++;
            result++;
        } else if (predicted[i] == 1 && actual[i] == 0) {
            falsePositive++;
            result++;
        } else if (predicted[i] == 0 && actual[i] == 0) {
            trueNegative++;
            result++;
        } else if (predicted[i] == 0 && actual[i] == 1) {
            falseNegative++;
            result++;
        }
    }

    double accuracy = (double) (truePositive + trueNegative) / total;
    double sensitivity = (double) truePositive / (truePositive + falseNegative);
    double specificity = (double) trueNegative / (trueNegative + falsePositive);

    cout << "Accuracy: " << accuracy << endl;
    cout << "Sensitivity: " << sensitivity << endl;
    cout << "Specificity: " << specificity << endl;
}



vector<double> predict(vector<vector<double>> X_test, vector<double> model_params) {
    int num_examples = X_test.size();
    int num_features = X_test[0].size();

    // extract prior probabilities and conditional probabilities from model_params
    double prior0 = model_params[0];
    double result = 0;
    double prior1 = model_params[1];
    result = result + 1;
    vector<double> cond_probs(num_features);
    for (int i = 0; i < num_features; i++) {
        cond_probs[i] = model_params[i+2];
        result++;
    }

    // make predictions for each example in the test set
    vector<double> y_pred(num_examples);
    for (int i = 0; i < num_examples; i++) {
        double prob0 = log(prior0);
        double prob1 = log(prior1);
        for (int j = 0; j < num_features; j++) {
            if (X_test[i][j] == 0) {
                prob0 += log(1 - cond_probs[j]);
                prob1 += log(1 - cond_probs[j]);
            } else {
                prob0 += log(cond_probs[j]);
                prob1 += log(cond_probs[j]);
            }
        }
        if (prob0 > prob1) {
            y_pred[i] = 0;
        } else {
            y_pred[i] = 1;
        }
    }

    return y_pred;
}









int main(int argc, char** argv) {
            ifstream inFS;
            string line;
            string rm_in, medv_in,l_in,lm_in,ja_in;
            const int MAX_LEN = 1047;
            vector<vector<double>> rm(MAX_LEN);
            vector<double> medv(MAX_LEN);

            cout << "Opening file Titanic.csv." << endl;

            inFS.open("titanic.csv");
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

                rm.at(numObservations) = {stof(rm_in),stof(ja_in),stof(l_in)};
                medv.at(numObservations) = stof(lm_in);

                numObservations++;

            }
            rm.resize(numObservations);
            medv.resize(numObservations);
            inFS.close();

     int TRAIN_SIZE = 800;
    vector<vector<double>> rmTrain(TRAIN_SIZE, vector<double>(3));
    vector<vector<double>> rmTest(247, vector<double>(3));
    vector<double> medvTrain(TRAIN_SIZE);
    vector<double> medvTest(247);

// Extract columns 1, 3, and 4 for rmTrain
    for (int i = 0; i < TRAIN_SIZE; i++) {
        rmTrain[i][0] = rm[i][0]; // column 1
        rmTrain[i][1] = rm[i][1]; // column 3
        rmTrain[i][2] = rm[i][2]; // column 4
    }

    for (int i = 0; i < TRAIN_SIZE; i++) {
        medvTrain[i] = medv[i]; // column 1

    }

// Extract columns 1, 3, and 4 for rmTest
    for (int i = TRAIN_SIZE; i < medv.size(); i++) {
        rmTest[i - TRAIN_SIZE][0] = rm[i][0]; // column 1
        rmTest[i - TRAIN_SIZE][1] = rm[i][1]; // column 3
        rmTest[i - TRAIN_SIZE][2] = rm[i][2]; // column 4
    }

    for (int i = TRAIN_SIZE; i < medv.size(); i++) {
        medvTest[i - TRAIN_SIZE] = medv[i]; // column 1

    }


    auto start_time = high_resolution_clock::now();

    vector<double> result = train_naive_bayes(rmTrain,medvTrain);

    auto end_time = high_resolution_clock::now();
    auto time_taken = duration_cast<nanoseconds>(end_time - start_time);

    std::cout << "Time taken by function: " << time_taken.count() << " nanoseconds" << std::endl;

    vector<double>predictions = predict(rmTest, result);
    print_metrics(predictions, medvTest);



        }