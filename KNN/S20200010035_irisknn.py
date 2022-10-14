# KNN is a machine learning technique which is used to classify data
# It uses euclidian distance to classify data

from csv import reader
from math import sqrt
from random import seed
from random import randrange

# Load a CSV file
# We are using iris.csv data set to train our model and to classify the data
def loadCsv(filename):
	irisdata = list()
	with open(filename, 'r') as file:
		read = reader(file)
		for row in read:
			if not row:
				continue
			irisdata.append(row)
	return irisdata


# Split a irisdata into n folds(5 in this case)
# As we are required to make 120 traing set and 30 test set randomly
# We are using this function to split the data to 5 parts out of which one part is used to test and others to train 
def randDatasplit(irisdata, data_split):
	irisdata_split = list()
	irisdata_copy = list(irisdata)
	dataset_size = int(len(irisdata) / data_split)
	for _ in range(data_split):
		fold = list()
		while len(fold) < dataset_size:
			index = randrange(len(irisdata_copy))
			fold.append(irisdata_copy.pop(index))
		irisdata_split.append(fold)
	return irisdata_split

# Converting string  to float
def strFloat(irisdata, column):
	for row in irisdata:
		row[column] = float(row[column].strip())

# Converting string to integer
def strInt(irisdata, column):
	class_values = [row[column] for row in irisdata]
	unique = set(class_values)
	lookup = dict() #used to create dictonaries
	for i, value in enumerate(unique):
		lookup[value] = i
	for row in irisdata:
		row[column] = lookup[row[column]]
	return lookup


# Find the minmum and maximum values for each column
def datamin_max(irisdata):
	min_max = list()
	for i in range(len(irisdata[0])):
		col_values = [row[i] for row in irisdata]
		min_value = min(col_values)
		max_value = max(col_values)
		min_max.append([min_value, max_value])
	return min_max

# Normalizing the data
def normalizeIrisdata(irisdata, min_max):
	for row in irisdata:
		for i in range(len(row)):
			row[i] = (row[i] - min_max[i][0]) / (min_max[i][1] - min_max[i][0])

# Evaluation Algorithm
def evalAlgo(irisdata, algorithm, data_split, *args):
	folds = randDatasplit(irisdata, data_split)
	score = list()
	for fold in folds:
		train_set = list(folds)
		train_set.remove(fold)
		train_set = sum(train_set, [])
		test_set = list()
		for row in fold:
			row_copy = list(row)
			test_set.append(row_copy)
			row_copy[-1] = None
		predicted = algorithm(train_set, test_set, *args)
		actual = [row[-1] for row in fold]
		accuracy = accuracyValue(actual, predicted)
		score.append(accuracy)
	return score

# Calculate the Euclidean distance between two vectors
def euclidianDistance(row1, row2):
	distance = 0.0
	for i in range(len(row1)-1):
		distance += (row1[i] - row2[i])**2
	return sqrt(distance)

# Calculate accuracy percentage
def accuracyValue(actual, predicted):
	correct = 0
	for i in range(len(actual)):
		if actual[i] == predicted[i]:
			correct += 1
	return correct / float(len(actual)) * 100.0

# Locate the most similar neighbors or most nearest neighbours
def getNeighbours(train, test_row, k_value):
	distances = list()
	for train_row in train:
		dist = euclidianDistance(test_row, train_row) #Computing distance from test_row to train_row
		distances.append((train_row, dist))
	distances.sort(key=lambda tup: tup[1])
	neighbors = list()
	for i in range(k_value):
		neighbors.append(distances[i][0])
	return neighbors

# Make a prediction with data available about the  neighbors
def classPrediction(train, test_row, k_value):
	neighbors = getNeighbours(train, test_row, k_value)
	output_values = [row[-1] for row in neighbors]
	prediction = max(set(output_values), key=output_values.count)
	return prediction

# KNN Algorithm
def knn(train, test, k_value):
	predictions = list()
	for row in test:
		output = classPrediction(train, row, k_value)
		predictions.append(output)
	return(predictions)

# Using seed to generate same random number every time to keep the Accuracy more consistent
seed(1)
# Path of csv file in my machine
filename = 'iris.csv'
irisdata = loadCsv(filename)
for i in range(len(irisdata[0])-1):
	strFloat(irisdata, i)
strInt(irisdata, len(irisdata[0])-1)
k_value = 3
data_split = 5
score = evalAlgo(irisdata, knn, data_split, k_value)
print('Accuracy: %.2f%%' % (sum(score)/float(len(score))))