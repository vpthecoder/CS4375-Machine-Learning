# CS4375-Machine-Learning
 Contains assignments from CS 4375

Technical skills/soft skills gainined in this class
[here](TechnicalSkills.txt)

## Summary
I am a highly skilled and enthusiastic machine learning practitioner with proficiency in both R and Python programming languages. My experience includes working with popular machine learning frameworks such as scikit-learn, caret, mlr, TensorFlow, and PyTorch. I am passionate about leveraging machine learning to solve complex problems and am excited about the potential for this technology to transform industries. In my free time, I plan to continue exploring personal machine learning projects and experimenting with the latest techniques and tools to stay up-to-date with this rapidly changing field. I am eager to collaborate with others in the industry and am open to exploring employment opportunities that allow me to apply my skills and further develop my expertise in machine learning. Some of my work is listed below.

## Assignment 0

This is an overview of ML

[pdf here](OverviewofML.pdf)



## Assignment 1

This is an assignment to calculate mean, median, sum, range of a vector in C++ and
calculate the covariance and correlation between two vectors in C++. Reads in the boston.csv file.
The pdf attached summarizes the assignment and compares the built in functions in R to the ones created in C++ in this assignment.
[data here](Assignment1/Boston.csv)
[pdf here](Assignment1/CS4375-Assignment1.pdf)
[code here](Assignment1/main.cpp)


## Assignment 2

1st pdf instructions:
    1. Create an Rmd notebook, name it Regression, with appropriate headings for your name(s) and 
date. Throughout the notebook use headings to indicate important steps of the assignment and 
use text blocks to explain what happens in each code block. Write a paragraph explaining in 
general terms how linear regression works, and what are its strengths and weaknesses. 
2. Select a data set from the web that has at least 10K rows and has a target column suitable for 
regression. List the source of your data in markdown. Perform the following steps with 
interspersed commentary and code blocks:
a. Divide into 80/20 train/test 
b. Use at least 5 R functions for data exploration, using the training data
c. Create at least 2 informative graphs, using the training data
d. Build a simple linear regression model (one predictor) and output the summary. Write a 
thorough explanation of the information in the model summary. 
e. Plot the residuals and write a thorough explanation of what the residual plot tells you. 
Use this source to help you: https://data.library.virginia.edu/diagnostic-plots/
f. Build a multiple linear regression model (multiple predictors), output the summary and 
residual plots.
g. Build a third linear regression model using a different combination of predictors, 
interaction effects, polynomial regression, or any combination to try to improve the 
results. Output the summary and residual plots. 
h. Write a paragraph or more comparing the results. Indicate which model is better and 
why you think that is the case. 
i. Using your 3 models, predict and evaluate on the test data using metrics correlation and 
mse. Compare the results and indicate why you think these results happened.

[pdf here](Assignment2/rmdregre.pdf)

2nd pdf instructions:
    Create a second Rmd notebook, name it Classification, with appropriate headings for your name 
and date. Throughout the notebook use headings to indicate important steps of the assignment 
and use text blocks to explain what happens in each code block. Write a paragraph explaining in 
general terms how linear models for classification work, and what are the strengths and 
weaknesses of these linear models. 
4. Select a data set from the web that has at least 10K rows and has a target column suitable for 
classification. List the source of your data in markdown. Perform the following steps with 
interspersed commentary and code blocks:
a. Divide into 80/20 train/test 
b. Use at least 5 R functions for data exploration, using the training data
c. Create at least 2 informative graphs, using the training data
d. Build a logistic regression model and output the summary. Write a thorough explanation 
of the information in the model summary. 
e. Build a naïve Bayes model and output what the model learned. Write a thorough 
explanation of the data. 
f. Using these two classification models models, predict and evaluate on the test data 
using all of the classification metrics discussed in class. Compare the results and indicate 
why you think these results happened. 
g. Write a paragraph listing the strengths and weaknesses of Naïve Bayes and Logistic 
Regression. 
h. Write a paragraph listing the benefits, drawbacks of each of the classification metrics 
used, and briefly describe what each metric tells you

[pdf here](Assignment2/rmdclass.pdf)

## Assignment 3
For this assignment I implemented Naive Bayes and Logisitc regression from scratch in C++. I then used the titanic dataset to compare accuracies for each algorithm. I wrote a summary for the assignment as well.

[code here](Assignment3/naiivebayes.cpp) [code here](Assignment3/logisticregress.cpp)
[pdf here](Assignment3/Summary(1).pdf)


## Assignment 4
For this assignment I did a pca and lda analysis in RMD notebook as part of an similarity and ensemble group assignment.  I selected a data set and performed both PCA and LDA dimensionality reduction. I then tried classification or regression on the reduced data and compare the results. 

[pdf here](Assignment4/pcalda.pdf)

## Assignment 5
Getting familiar with sklearn
Insrtructions. 
1. Read the Auto data (5 points)
a. use pandas to read the data 
b. output the first few rows
c. output the dimensions of the data

2. Data exploration with code (5 points)
a. use describe() on the mpg, weight, and year columns
b. write comments indicating the range and average of each column

3. Explore data types (5 points)
a. check the data types of all columns
b. change the cylinders column to categorical (use cat.codes)
c. change the origin column to categorical (don’t use cat.codes)
d. verify the changes with the dtypes attribute

4. Deal with NAs (5 points)
a. delete rows with NAs
b. output the new dimensions

5. Modify columns (10 points)
a. make a new column, mpg_high, and make it categorical:
i. the column == 1 if mpg > average mpg, else == 0
b. delete the mpg and name columns (delete mpg so the algorithm doesn’t just learn 
to predict mpg_high from mpg)
c. output the first few rows of the modified data frame

6. Data exploration with graphs (15 points)
a. seaborn catplot on the mpg_high column
b. seaborn relplot with horsepower on the x axis, weight on the y axis, setting hue or 
style to mpg_high
c. seaborn boxplot with mpg_high on the x axis and weight on the y axis
d. for each graph, write a comment indicating one thing you learned about the data 
from the graph

[pdf here](Assignment5/CS4375-PythonML.pdf)

## Assignment 6
For this assignment I used the Intel dataset on Kaggle.com. 
Assignment Instructions: 
1. Go to Kaggle.com. Find an image classification data set that interests you. Divide into train/test. 
Create a graph showing the distribution of the target classes. Describe the data set and what the 
model should be able to predict. 
2. Create a sequential model and evaluate on the test data
3. Try a different architectures like RNN, CNN, etc and evaluate on the test data
4. Try a pretrained model and transfer learning, read more here: 
https://www.tensorflow.org/tutorials/images/transfer_learning
5. Write up your analysis of the performance of various approaches

[pdf here](Assignment6/cs4375-lastassignment.pdf)





