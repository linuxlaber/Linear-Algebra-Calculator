#include <iostream>
#include <vector>

using namespace std;

// Function to perform linear combination of vectors
vector<double> linearCombination(const vector<vector<double>>& vectors, const vector<double>& coefficients) {
    // Check if the number of vectors and coefficients match
    if (vectors.size() != coefficients.size()) {
        cout << "Error: Number of vectors and coefficients must be the same." << endl;
        return {};
    }
    
    // Check if the vectors are of the same dimension
    int dimension = vectors[0].size();
    for (int i = 1; i < vectors.size(); ++i) {
        if (vectors[i].size() != dimension) {
            cout << "Error: Vectors must be of the same dimension." << endl;
            return {};
        }
    }
    
    // Perform linear combination
    vector<double> result(dimension, 0);
    for (int i = 0; i < vectors.size(); ++i) {
        for (int j = 0; j < dimension; ++j) {
            result[j] += vectors[i][j] * coefficients[i];
        }
    }
    
    return result;
}

// Function to input vectors
vector<vector<double>> inputVectors(int numVectors, int dimension) {
    vector<vector<double>> vectors(numVectors, vector<double>(dimension));
    cout << "Enter the vectors row by row:" << endl;
    for (int i = 0; i < numVectors; ++i) {
        cout << "Vector " << i + 1 << ": ";
        for (int j = 0; j < dimension; ++j) {
            cin >> vectors[i][j];
        }
    }
    return vectors;
}

// Function to input coefficients
vector<double> inputCoefficients(int numCoefficients) {
    vector<double> coefficients(numCoefficients);
    cout << "Enter the coefficients:" << endl;
    for (int i = 0; i < numCoefficients; ++i) {
        cout << "Coefficient " << i + 1 << ": ";
        cin >> coefficients[i];
    }
    return coefficients;
}

int main() {
    int numVectors, dimension, numCoefficients;

    cout << "Enter the number of vectors: ";
    cin >> numVectors;
    cout << "Enter the dimension of each vector: ";
    cin >> dimension;
    cout << "Enter the number of coefficients: ";
    cin >> numCoefficients;

    vector<vector<double>> vectors = inputVectors(numVectors, dimension);
    vector<double> coefficients = inputCoefficients(numCoefficients);

    // Perform linear combination
    vector<double> result = linearCombination(vectors, coefficients);
    
    // Display step-by-step solution
    cout << "Step-by-step solution:" << endl;
    for (int i = 0; i < vectors.size(); ++i) {
        cout << coefficients[i] << " * [ ";
        for (int j = 0; j < vectors[i].size(); ++j) {
            cout << vectors[i][j] << " ";
        }
        cout << "] + ";
    }
    cout << " = [ ";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << "]" << endl;

    return 0;
}

